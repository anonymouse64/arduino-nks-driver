This is the initial version of the Mathematica Arduino driver I developed at the Wolfram Science Summer School 2014.

Here is a link to the Wolfram Community blog post I wrote detailing this driver: http://community.wolfram.com/groups/-/m/t/315748?p_p_auth=MsQ1wUxH

This version of the driver code has a few drawbacks, namely that it has the Arduino send data constantly to Mathematica, and Mathematica doesn't have a very efficient method of parsing the data.

This is simply a permanent place to store the files I developed at the summer school, the updated driver will be present in the release of Mathematica 10.1.0.

There is also a notebook file that I used at the Summer School for demoing the driver included here.


USAGE:

You can load the package after downloading it and ensuring that the file is in a directory present in $Path.

Load it with:

Needs["ArduinoDriver`"]

You can then open a connection to the Arduino with 

DeviceOpen["Arduino","COM4"]

Replace "COM4" with an appropriate serial port on your machine.

See demo.nb for more examples.
