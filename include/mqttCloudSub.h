#include <settingMacros.h>

// Create a Wi-Fi and MQTT client
WiFiClient espClient;
PubSubClient client(espClient);

// Function to reconnect to the MQTT broker
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    if (client.connect(client_id.c_str())) {
      Serial.println("Connected to MQTT broker");
      // Subscribe to the topic once connected
      client.subscribe(subscribeTopic);
    } else {
      Serial.print("Failed to connect. Retrying in 1 seconds...");
      vTaskDelay(pdMS_TO_TICKS(100));
    }
  }
}

// Callback function for MQTT message handling
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received on topic: ");
  Serial.print(topic);
  Serial.print(" - ");
  
  // Print the received message
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println(message);

  // Parse JSON
  StaticJsonDocument<256> doc;
  DeserializationError error = deserializeJson(doc, message);

  if (error) {
    Serial.println("JSON parsing failed!");
    return;
  }

  if (doc.containsKey("co2")) sensorData.CO2 = doc["co2"];
  if (doc.containsKey("pm2_5")) sensorData.pm2_5 = doc["pm2_5"];
  if (doc.containsKey("o2")) sensorData.O2 = doc["o2"];
  if (doc.containsKey("temp")) sensorData.Temp = doc["temp"];
  if (doc.containsKey("humidity")) sensorData.Hum = doc["humidity"];
}

void mqttSetUp() {
  // Set up MQTT client
  client.setServer(mqttServer, mqttPort);
  client.setCallback(mqttCallback);
}

void mqttConnected() {
  // Ensure the MQTT client remains connected
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}