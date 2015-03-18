(*AUTHOR: IAN JOHNSON, WOLFRAM RESEARCH INC.*)
(*DRIVER CODE FOR INTERFACING MATHEMATICA WITH AN ARDUINO*)

BeginPackage["ArduinoDriver`"];

Begin["`Private`"]
	(*open opens a serial port device, and returns that device. It also sets the baud rate to 19200 and ReadBufferSize to 2^13*)
	(*TODO: Don't use a global variable serial for this, use device handle numbers, and also make the baud rate and the ReadBufferSize default to these values, but make them still configurable*)
	open[port_]:=(serial=DeviceOpen["Serial",{port,"BaudRate"->19200,"ReadBufferSize"->2^13}];serial);
	open::usage="opens a serial port on the given COM port, returns the object. Also declares globablly that object with symbol serial";
	exit = DeviceClose;
	(*pins is the list of possible protocol codes for pins. For example, to configure pin 7, the character 'h' is outputted over serial to the arduino*)
	pins={0->"a",1->"b",2->"c",3->"d",4->"e",5->"f",6->"g",7->"h",8->"i",9->"j",10->"k",11->"l",12->"m",13->"n","A0"->"o","A1"->"p","A2"->"q","A3"->"r","A4"->"s","A5"->"t","0"->"a","1"->"b","2"->"c","3"->"d","4"->"e","5"->"f","6"->"g","7"->"h","8"->"i","9"->"j","10"->"k","11"->"l","12"->"m","13"->"n"};
	(*analogPins is the list of possible pin values for reading, this corresponds to the actual index in the list of values that is printed off by the arduino. For example, the value of 'A5' is located at position 20 in the list*)
	analogPins={0->1,1->2,2->3,3->4,4->5,6->7,8->9,9->10,10->11,12->13,13->14,"A0"->15,"A1"->16,"A2"->17,"A3"->18,"A4"->19,"A5"->20};
	(*modes is the list of possible protocol codes for configuring the state of pins, for example to configure a pin to be analogOutput, the character 'e' is output over serial to the arduino*)
	modes={"digitalOutputHigh"->"a","digitalOutputLow"->"b","digitalInput"->"c","analogInput"->"d","analogOutput"->"e","HIGH"->"a","LOW"->"b",1->"a",0-> "b","digitalOutput"->"b","output"->"b","input"->"c",True->"a",False->"b"};
	ArduinoWrite[assoc_Association]:=DeviceWrite[serial,StringJoin[Keys[assoc]/.pins,Values[assoc]/.modes]];
	ArduinoWrite[pin_,mode_]:=DeviceWrite[serial,StringJoin[pin/.pins,mode/.modes]];
	ArduinoWrite[pin_,mode_,value_Integer]:=DeviceWrite[serial,StringJoin[pin/.pins,mode/.modes,Switch[Length[IntegerDigits[value]],
		3,ToString@value,
		2,StringJoin[ToString/@PadLeft[IntegerDigits[value],3]],
		1,StringJoin[ToString/@PadLeft[IntegerDigits[value],3]],
		_,Print["error in ArduinoWrite"];Null]]];
	secondSeperator[sublist_]:=Select[StringSplit[sublist,","],(#!="")&];
	(*TODO: Rewrite the fullList function to use Device Handles to get values off the serial port, rather than using the serial global variable*)
	fullList:=Select[Length[#]!=0&]@(secondSeperator/@StringSplit[FromCharacterCode@DeviceReadBuffer[serial,300],"X"]);
	readList:=Part[fullList,-2];
	serialBufferRead[]:=Select[#!="\r\n"&]@readList;
	ArduinoRead[pin_]:=If[IntegerQ[pin],ToExpression[serialBufferRead[][[pin+1]]],ToExpression[serialBufferRead[][[(pin/.analogPins)]]]];
	ArduinoRead[pin_List]:=MapThread[Rule,{pin,ToExpression[Part[serialBufferRead[],#]&/@(pin/.analogPins)]}];
	ArduinoOpen[_,comPort_]:=open[comPort];
	ArduinoClose[_]:=exit[serial];
	ArduinoWriteDriver[_,pin_,mode_String,value_]:=ArduinoWrite[pin,mode,value];
	ArduinoWriteDriver[_,pin_,mode_]:=ArduinoWrite[pin,mode];
	ArduinoWriteDriver[_,assoc_Association]:=ArduinoWrite[assoc];
	ArduinoReadDriver[_,pin_]:=ArduinoRead[pin];
	ArduinoConfigure[_,assoc_Association]:=MapThread[ArduinoWrite,{Keys[assoc],Values[assoc]}];
	(*This ArduinoConfigure function s hardcoded to use a specific serial port, and is not fully tested, so it is commented out*)
	(*ArduinoConfigure[_,libraryLocation_String]:=arduinoUpload[libraryLocation<>"serial_comm_mathematica.cpp","COM4",libraryLocation];*)
	(*NOTE: THE ICON FUNCTION REQUIRES AN INTERNET CONNECTION TO DOWNLOAD THE ICON*)
	(*TODO: Include the icon image file inside the compiler package, so that it doesn't have to be included in the driver file, and also doesn't have to be downloaded*)
	iconFunction[_,_]:=Import["http://wolfr.am/1pyBa6F"];
	iconFunction[_]:=Import["http://wolfr.am/1pyBa6F"];
	DeviceFramework`DeviceClassRegister["Arduino","DeviceIconFunction"-> iconFunction,"ReadFunction"->ArduinoReadDriver,"WriteFunction"->ArduinoWriteDriver,"OpenFunction"->ArduinoOpen,"CloseFunction"->ArduinoClose,"ConfigureFunction"->ArduinoConfigure];

End[]

EndPackage[]


