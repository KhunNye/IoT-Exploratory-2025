#include <settingMacros.h>
#include <playSound.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Function for Numpad
int insertDigit(int x, int digit, int position) {
  int numDigits = log10(x) + 1;  // Count total digits in x
  int adjustedPos = numDigits - position;  // Convert LTR to RTL position

  int leftPart = x / pow(10, adjustedPos);  // Extract left part
  int rightPart = x % (int)pow(10, adjustedPos); // Extract right part

  return leftPart * pow(10, adjustedPos + 1) + digit * pow(10, adjustedPos) + rightPart;
}

int getPosition(int x) {
  int position = 0;
  while (x > 0) {
      x /= 10;
      position++;
  }
  return position;
}

int deleteDigit(int number, int position) {
  String numStr = String(number); // Convert number to string
  int len = numStr.length();
  if (position < 1 || position > len) {
      return number; // Return original number if position is invalid
  }
  numStr.remove(position - 1, 1); // Remove the digit at the given position
  return numStr.toInt(); // Convert back to integer and return
}

void automationSetUp(){
  //Relay and LED
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  //OLCD
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    delay(1000);
    ESP.restart();
  }
  display.clearDisplay();
  // Initialize serial communication
}

void automationLoop(){
  // Pin
  int relayState = digitalRead(RELAY_PIN);
  char customKey = customKeypad.getKey();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Pin when press
  if (customKey){
    if (customKey == 'A') {
      inputData.Modes = 1;
    } 
    else if (customKey == 'B') {
      inputData.Modes = 2;
    }
    else if (customKey == 'C') {
      int set_min = inputData.MinCO2;
      int digit_min = getPosition(set_min);
      int set_max = inputData.MaxCO2;
      int digit_max = getPosition(set_max);
      while (true){
        Serial.println("looped");
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.print("Configulation");
        display.setCursor(0, 8);
        display.print("Minimum CO2:");
        display.setTextSize(2);
        display.setCursor(0,16);
        if (set_min > 0){
          display.print(set_min);
        }
        customKey = customKeypad.getKey();
        if (customKey){
          if (customKey == '#' && set_min >= 0){
            set_min = deleteDigit(set_min,digit_min);
            digit_min--;
          }
          else if (customKey >= '0' && customKey <= '9'){
            if (set_min==0){
              set_min = set_min + (customKey - '0');
              digit_min++;
            }
            else if (set_min>0){
              set_min = insertDigit(set_min,customKey - '0',digit_min);
              digit_min++;
            } 
          }
          else if (customKey == 'D'){
            inputData.MinCO2 = set_min;
            break;
          }
        }
        display.display();
      }
      while (true){
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.print("Configulation");
        display.setCursor(0, 8);
        display.print("Maximum CO2:");
        display.setTextSize(2);
        display.setCursor(0, 16);
        if (set_max > 0){
          display.print(set_max);
        }
        customKey = customKeypad.getKey();
        if (customKey){
          if (customKey == '#' && set_max >= 0){
            set_max = deleteDigit(set_max,digit_max);
            digit_max--;
          }
          else if (customKey >= '0' && customKey <= '9'){
            if (set_max==0){
              set_max = set_max + (customKey - '0');
              digit_max++;
            }
            else if (set_max>0){
              set_max = insertDigit(set_max,customKey - '0',digit_max);
              digit_max++;
            }  
          }
          else if (customKey == 'D'){
            inputData.MaxCO2 = set_max;
            break;
          }
        }
        display.display();
      }
    }
    else if (customKey == 'D') {
      if (inputData.Modes == 2){
          if (relayState == HIGH) {
              digitalWrite(RELAY_PIN, LOW);   // Turn relay OFF
          } 
          else {
              digitalWrite(RELAY_PIN, HIGH);  // Turn relay ON
          }    
      }
    }
    else if (customKey == '*') {
      if (inputData.stopMusic == false) {
        inputData.stopMusic = true;
      } 
      else {
        inputData.stopMusic = false;
      } 
    }
  }
//Cullent modes
    if (inputData.Modes == 1) {
      display.setCursor(0, 0);
      display.print("Mode: Auto [");
      display.print(inputData.MinCO2);
      display.print("-");
      display.print(inputData.MaxCO2);
      display.print("]");
      if (sensorData.CO2 < inputData.MinCO2) {
        if (relayState == LOW) {
          Serial.println("I will turn off");
          digitalWrite(RELAY_PIN, HIGH);
          music1();
        }
      } else if (sensorData.CO2 > inputData.MaxCO2) {
         if (relayState == HIGH) {
          Serial.println("I will turn on");
          digitalWrite(RELAY_PIN, LOW);
        }
      }
//---------------------------------------------------------------------------------------
    } else if (inputData.Modes == 2) {
      display.setCursor(0, 0);
      display.print("Mode:Manual (Press D)");
    } 
//=======================================================================================
//Air monitor on OLCD
    display.setCursor(0, 8);
    display.print("CO2: "); 
    display.print(sensorData.CO2);
    display.print("ppm");
    display.setCursor(0, 16);
    display.print("O2: ");
    display.print(sensorData.O2);
    display.print("% , ");
    display.print("PM2.5: ");
    display.print(sensorData.pm2_5);
    display.setCursor(0, 24);
    display.print("Temp: ");
    display.print(sensorData.Temp);
    display.print("C , ");
    display.print("Humid: ");
    display.print(sensorData.Hum);
    display.print("%");
    display.display();

    // Alert System
    if (sensorData.CO2 <= inputData.MinCO2){
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(RED_LED, LOW);
    }
    else if (sensorData.CO2 > inputData.MinCO2 && sensorData.CO2 <= inputData.MaxCO2){
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(YELLOW_LED, HIGH);
      digitalWrite(RED_LED, LOW);
    }
    else if (sensorData.CO2 > inputData.MaxCO2){
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(RED_LED, HIGH);
    }
}


