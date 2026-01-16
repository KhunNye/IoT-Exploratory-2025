#include <settingMacros.h>

// Google script Web_App_URL.
String Web_App_URL = "https://script.google.com/macros/s/AKfycbwsQRs3pbaJDZUWB9nfNkdcbuCjUBjfDXAOtLOtxHe_SpgLM-dNTkcJUlrP_mg7CFKq/exec";

void googleSheetWrite(){ 
  // ✅ Check if WiFi is connected
  if (WiFi.status() == WL_CONNECTED) {
      digitalWrite(On_Board_LED_PIN, HIGH);

      // ✅ Check if any sensor data is zero
      if (sensorData.CO2 == 0 || sensorData.O2 == 0 || sensorData.pm2_5 == 0 || 
          sensorData.Temp == 0 || sensorData.Hum == 0) {
          Serial.println("❌ Sensor data contains zero! Data NOT sent.");
          digitalWrite(On_Board_LED_PIN, LOW);
          return;  // Exit the function without sending data
      }
      
      // ✅ Create the URL for sending data
      String Send_Data_URL = Web_App_URL + "?sts=write";
      Send_Data_URL += "&co2=" + String(sensorData.CO2);
      Send_Data_URL += "&o2=" + String(sensorData.O2);
      Send_Data_URL += "&pm2_5=" + String(sensorData.pm2_5);
      Send_Data_URL += "&temp=" + String(sensorData.Temp);
      Send_Data_URL += "&hum=" + String(sensorData.Hum);
      Send_Data_URL += "&modes=" + String(inputData.Modes);
      Send_Data_URL += "&maxco2=" + String(inputData.MaxCO2);
      Send_Data_URL += "&minco2=" + String(inputData.MinCO2);
      Send_Data_URL += "&stopmusic=" + String(inputData.stopMusic);

      Serial.println();
      Serial.println("-------------");
      Serial.println("✅ Sending data to Google Spreadsheet...");
      Serial.print("URL : ");
      Serial.println(Send_Data_URL);
      
      // ✅ Initialize HTTPClient
      HTTPClient http;
      
      // ✅ HTTP GET Request
      http.begin(Send_Data_URL.c_str());
      http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
      
      int httpCode = http.GET();  // Get HTTP response
      Serial.print("HTTP Status Code : ");
      Serial.println(httpCode);
      
      if (httpCode > 0) {
          String payload = http.getString();
          Serial.println("✅ Response: " + payload);
      }

      http.end();      
      digitalWrite(On_Board_LED_PIN, LOW);
      Serial.println("-------------");
  }
}
