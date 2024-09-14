#include <SPI.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;
float Voltage = 0.0;

void setup(void) {
Serial.begin(115200); 
 if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
}

void loop(void) 
{
int16_t adc0;
int16_t adc1;
int16_t adc2;
int16_t adc3;

adc0 = ads.readADC_SingleEnded(0);
adc1 = ads.readADC_SingleEnded(1);
adc2 = ads.readADC_SingleEnded(2);
adc3 = ads.readADC_SingleEnded(3);
Voltage = (adc0 * 0.1875)/1000;

Serial.print("AIN0: "); 
Serial.print(adc0);
Serial.print("\tAIN1: ");
Serial.print(adc1);
Serial.print("\tAIN2: ");
Serial.print(adc2);
Serial.print("\tAIN3: ");
Serial.print(adc3);
//Serial.print("\tVoltage: ");
//Serial.println(Voltage, 7); 
//Serial.println();

delay(1000);
}