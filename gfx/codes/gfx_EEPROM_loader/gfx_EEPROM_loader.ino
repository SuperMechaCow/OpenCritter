#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <U8glib.h>

#include <Adafruit_SSD1306.h>
#include <EEPROM.h>


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#include "Z_gfx.h"

#define offset 0
byte thearray[128] = {0};

void setup()
{
  //Spin up a serial port for debugging/comms
  Serial.begin(9600);

  //ESP8266
  EEPROM.begin(4096);
  Wire.begin(D6, D5);

  //start an OLED screen object
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  //Display the buffer image
  display.display();
  // Clear the buffer
  display.clearDisplay();
  Serial.println("Now writing: ");
  for (int i = 0; i < icon_size; i++) {
    EEPROM.write(i + icon_food_addr, icon_food[i]);
  }
  for (int i = 0; i < icon_size; i++) {
    EEPROM.write(i + icon_clok_addr, icon_clok[i]);
  }
  for (int i = 0; i < icon_size; i++) {
    EEPROM.write(i + icon_stat_addr, icon_stat[i]);
  }
  for (int i = 0; i < icon_size; i++) {
    EEPROM.write(i + icon_game_addr, icon_game[i]);
  }
  for (int i = 0; i < icon_size; i++) {
    EEPROM.write(i + icon_meds_addr, icon_meds[i]);
  }
  for (int i = 0; i < icon_size; i++) {
    EEPROM.write(i + icon_conf_addr, icon_conf[i]);
  }
  for (int i = 0; i < icon_size; i++) {
    EEPROM.write(i + icon_sick_addr, icon_sick[i]);
  }
  for (int i = 0; i < icon_size; i++) {
    EEPROM.write(i + icon_poop_addr, icon_poop[i]);
  }
  for (int i = 0; i < icon_size; i++) {
    EEPROM.write(i + icon_unon_addr, icon_unon[i]);
  }

  for (int i = 0; i < crit_size; i++) {
    EEPROM.write(i + egg_main_addr, egg_main[i]);
  }
  for (int i = 0; i < crit_size; i++) {
    EEPROM.write(i + egg_idle_addr, egg_idle[i]);
  }
  for (int i = 0; i < crit_size; i++) {
    EEPROM.write(i + wibbur_main_addr, wibbur_main[i]);
  }
  for (int i = 0; i < crit_size; i++) {
    EEPROM.write(i + wibbur_idle_addr, wibbur_idle[i]);
  }
  EEPROM.commit();
  EEPROM.end();
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < numberoficons; i++) {
    for (int j = 0; j < icon_size; j++) {
      thearray[j] = EEPROM.read(j + (i * icon_size));
    }
    display.drawBitmap(16 * i, 0, thearray, 16, 16, 1);
    display.display();
    delay(250);
  }
  display.fillRect(0, 0, 128, 64, 0);
  display.display();


  for (int j = 0; j < crit_size; j++) {
    thearray[j] = EEPROM.read(j + crit_start);
  }
  display.drawBitmap(0, 0, thearray, 32, 32, 1);
  display.display();
  delay(1000);
  display.fillRect(0, 0, 128, 64, 0);
  display.display();




}
