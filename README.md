Multi OLED library<br>
Project started 1/1/2019<br>
Copyright (c) 2019 BitBank Software, Inc.<br>
Written by Larry Bank<br>
bitbank@pobox.com<br>
<br>
![Multi_OLED](/demo.jpg?raw=true "Multi_OLED")
<br>
The purpose of this code is to easily control mulitple SH1106/SSD1306 OLED
displays using a minimum of GPIO lines. The number of displays is not tied to
the number of I2C buses if they have unique addresses. For example, if you
have 4 displays that all use address 0x3C, then you'll need 4 I2C buses to
control them. This can be done with as few as 5 GPIO lines if you arrange them
to share the SCL wire. In the other extreme, you can control 16 unique OLED
displays with 9 wires (8 I2C buses) if you have 8 set to address 0x3C and 8
set to address 0x3D. The library addresses each display individually by bus
and I2C address.<br>

Here is a Youtube video of it in action on an nRF52840 Feather. The line draw function is very efficient, so even driving 2 displays over a bit-banged I2C bus, it can draw quite quickly.

[![Line drawing video](https://img.youtube.com/vi/adc9y-w7V3g/0.jpg)](https://www.youtube.com/watch?v=adc9y-w7V3g)
<br>

Features:<br>
---------<br>
- Supports 64x32, 128x32, 128x64 and 132x64 (SH1106) display sizes<br>
- Includes 3 sizes of fixed fonts (6x8, 8x8, 16x32)<br>
- Includes a function to load a Windows BMP file<br>
- Optional backing RAM for drawing lines and pixels for systems with enough RAM<br>
- Light enough to run on an ATtiny85<br> 
<br>
To initialize the library, you pass lists of the following:<br>
<br>
1) Bus number<br>
2) I2C Address<br>
3) Boolean indicating to flip the display 180 degrees<br>
4) Boolean indicating to invert the display<br>
5) The total display count<br>
<br>
Each access function (e.g. drawing text) takes the display number as the first
parameter. This will index the correct bus number and I2C address based on the
lists you provided to the initialization function.<br>
<br>
See the example sketch for more info on how to call the functions.<br>
<br>
This code depends on the Multi_BitBang library. You can download it here:<br>
<br>
https://github.com/bitbank2/Multi_BitBang
<br>

If you find this code useful, please consider buying me a cup of coffee

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=SR4F44J2UR8S4)

