# RGB-Smart-Lamp-on-WS2812

This device can serve you as a primary source of lightning in your room that you can control via Bluetooth.

You can find the code and a circuit of this device here:  https://github.com/Northstrix/RGB-Smart-Lamp-on-WS2812

To build this device you need:
1) One Arduino
2) WS 2812 LED strip I used half of meter of WS2812B SMD 5050 RGB 60 led/m
3) One HC-06 Bluetooth module
4) One resistor 330-680 ohm

Note: If you're using more than 60 LEDs in your project you should use a phone charger that can provide at least 1 Amp as a power supply.
And don't forget to put a capacitor for at least 1000 mkf if you're using a crappy power source.

After you've completed building this device you need an app to control it.
You can get RemoteXY app here: https://remotexy.com/

After you installed the app connect Arduino to your phone via Bluetooth and enter a password (1234 by default).

Use Red, Green, and Blue slider to control the color. Use the White slider to set the brightness.
