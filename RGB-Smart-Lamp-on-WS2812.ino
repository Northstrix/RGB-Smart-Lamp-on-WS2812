// Developed by Maxim Bortnikov
// For more information visit: https://github.com/Northstrix/RGB-Smart-Lamp-on-WS2812
// You can download RemoteXY app here: https://remotexy.com/en/download/
#include <Adafruit_NeoPixel.h>
#define LED_PIN    9 // WS2812 data pin
#define LED_COUNT 30 // The number of LEDs
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>
#include <RemoteXY.h>
#define REMOTEXY_SERIAL_RX 2 // TXD pin
#define REMOTEXY_SERIAL_TX 3 // RXD pin
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_ACCESS_PASSWORD "1234" // Access password

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,4,0,0,0,35,0,10,25,0,
  4,0,4,8,17,50,50,26,4,0,
  28,8,17,50,135,26,4,0,52,8,
  17,50,190,26,4,0,76,1,19,58,
  31,26 };
  
struct {

    // input variables
  int8_t slider_1; // =0..100 slider position 
  int8_t slider_2; // =0..100 slider position 
  int8_t slider_3; // =0..100 slider position 
  int8_t slider_4; // =0..100 slider position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)


void setup() 
{
  strip.begin(); // Initializes the string
  strip.show(); // Switching the whole strip off
  RemoteXY_Init (); // Initializes RemoteXY library
}

void loop() 
{ 
 RemoteXY_Handler (); // Taking values from the slides
 delay(10);
 int r = RemoteXY.slider_1; // Red color
 int g = RemoteXY.slider_2; // Green color
 int b = RemoteXY.slider_3; // Blue color
 int br = RemoteXY.slider_4; // Brightness
 delay(100);
 strip.setBrightness(br*2.55); // That one is setting the brightness
 uint32_t color = strip.Color(r*2.55, g*2.55, b*2.55); // Color
 strip.fill(color, 0, LED_COUNT); // Sends color to the strip
 delay(50);
 strip.show();  // That one updates the whole strip at once
 delay(100);

}
