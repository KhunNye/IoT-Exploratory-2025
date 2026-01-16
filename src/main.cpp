#include <googleSheet.h>
#include <mqttCloudSub.h>
#include <Automation.h>

// Task handles
TaskHandle_t Task1;  // Core 0 - Read sensor data
TaskHandle_t Task2;  // Core 1 - Send data to cloud

// Mutex for thread safety
SemaphoreHandle_t dataMutex;

void connectWiFi(){
  // Set Wifi to STA mode
  Serial.println();
  Serial.println("-------------");
  Serial.println("WIFI mode : STA");
  WiFi.mode(WIFI_STA);
  Serial.println("-------------");
  
  // Connect to Wi-Fi (STA).
  Serial.println();
  Serial.println("------------");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  // The process of connecting ESP32 with WiFi Hotspot / WiFi Router.
  // The process timeout of connecting ESP32 with WiFi Hotspot / WiFi Router is 20 seconds.
  // If within 20 seconds the ESP32 has not been successfully connected to WiFi, the ESP32 will restart.
  // I made this condition because on my ESP32, there are times when it seems like it can't connect to WiFi, so it needs to be restarted to be able to connect to WiFi.

  int connecting_process_timed_out = 20; //--> 20 = 20 seconds.
  connecting_process_timed_out = connecting_process_timed_out * 2;

  while (WiFi.status() != WL_CONNECTED) {

    Serial.print(".");

    digitalWrite(On_Board_LED_PIN, HIGH);
    delay(250);

    digitalWrite(On_Board_LED_PIN, LOW);
    delay(250);

    if (connecting_process_timed_out > 0)
      connecting_process_timed_out--;

    if (connecting_process_timed_out == 0) {
      delay(1000);
      ESP.restart();
    }
  }

  digitalWrite(On_Board_LED_PIN, LOW);

  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("------------");
}

void functionTask1(void * parameter){

  while (1){
    // Take the mutex before modifying the global variable
    if (xSemaphoreTake(dataMutex, portMAX_DELAY) == pdTRUE) {
      automationLoop();
      // Release the mutex after updating
      xSemaphoreGive(dataMutex);

    }

    vTaskDelay(pdMS_TO_TICKS(100)); // Delay 0.1 ms
  }
}

void functionTask2(void * parameter){
  while (1){
    // Take the mutex before reading the global variable
    //if (xSemaphoreTake(dataMutex, portMAX_DELAY) == pdTRUE) {

    mqttConnected();
    googleSheetWrite();

      // Release the mutex after reading
      //xSemaphoreGive(dataMutex);
    //}

    playMusic();
    //vTaskDelay(pdMS_TO_TICKS(100)); // Read every 20s
}
}

void setup() {
    // put your setup code here, to run once:
    
    Serial.begin(115200);

    pinMode(On_Board_LED_PIN, OUTPUT);

    // Create a mutex to protect sensorData
    dataMutex = xSemaphoreCreateMutex();
    if (dataMutex == NULL) {
        Serial.println("Error: Mutex creation failed!");
        return;
    }

    connectWiFi();
    mqttSetUp();
    soundSetUp();
    automationSetUp();

    // Create tasks
    xTaskCreatePinnedToCore(functionTask1, "Input Data", 10000, NULL, 1, &Task1, 0);  // Core 0
    xTaskCreatePinnedToCore(functionTask2, "Automation & Send Data to Cloud", 10000, NULL, 1, &Task2, 1);  // Core 1
}

void loop() {
  // Empty because FreeRTOS manages tasks
}
