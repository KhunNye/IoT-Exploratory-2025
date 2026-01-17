#ifndef SETTINGMACROS_H
#define SETTINGMACROS_H

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <HTTPClient.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <Keypad.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define the macro
#define On_Board_LED_PIN 2

// LED and Relay
#define RELAY_PIN 5 // Relay control pin
#define GREEN_LED 17 // Green LED pin
#define YELLOW_LED 16 // Yellow LED pin
#define RED_LED 4 // Red LED pin

#define BUZZER_PIN 23  // Choose any PWM-capable GPIO

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C  // I2C address of the display

// Define a struct to send multiple data values
struct SensorData {
    int CO2;
    float O2;
    int pm2_5;
    float Temp;
    float Hum;
  };

struct InputData {
  int Modes = 1;
  int MaxCO2 = 1000;
  int MinCO2 = 800;
  bool stopMusic = false;
};

// Declare a global variable (defined in main.cpp)
SensorData sensorData;
InputData inputData;

// SSID and PASSWORD of your WiFi network.
const char* ssid = "Exploratory";  //--> Your wifi name
const char* password = "!tggs2025"; //--> Your wifi password

// MQTT Broker details
const char* mqttServer = "202.44.44.233";
const int mqttPort = 1883;
const char* subscribeTopic = "indoor/env_sensors";

// Keypad
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {13, 12, 14, 27}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26, 25, 33, 32}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

#endif // SETTINGMACROS_H