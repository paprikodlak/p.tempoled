#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>


Adafruit_SSD1306 display;

const int pinTempDS = 7;
OneWire oneWireDS(pinTempDS);
DallasTemperature tempDS(&oneWireDS);

const double temp_constant=-1.6;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(1,0);
  display.clearDisplay();
  display.println("p.tempoled");
  display.display();

  tempDS.begin();
  tempDS.requestTemperatures();

  display.print("T: ");
  display.setTextSize(3);
  double teplota=tempDS.getTempCByIndex(0)+temp_constant;
  display.print(teplota);
  display.setTextSize(1);
  display.print(" ");
  display.print((char)247);display.print("C");
  display.display();
}

void loop() {
}


