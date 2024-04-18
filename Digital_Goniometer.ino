#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MPU6050.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

MPU6050 mpu;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  Wire.begin();
  mpu.initialize();
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Accel X: ");
  display.print(ax);
  display.setCursor(0,10);
  display.print("Accel Y: ");
  display.print(ay);
  display.setCursor(0,20);
  display.print("Accel Z: ");
  display.print(az);
  display.display();
  delay(100);
}
