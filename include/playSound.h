#include <settingMacros.h>

void soundSetUp() {
  pinMode(BUZZER_PIN, OUTPUT);
}

/*
void meawmeawmeawmeaw() { // meawmeawmeawmeaw
  // Quater note = 70 bpm -> 1/(70/60) = 857.1
  // Eight note = 70 bpm -> 428.6

  tone(BUZZER_PIN, 1244.51); // E6b
  vTaskDelay(pdMS_TO_TICKS(428.6));

  tone(BUZZER_PIN, 1318.51); // E6
  vTaskDelay(pdMS_TO_TICKS(428.6));

  tone(BUZZER_PIN, 830.609); // A5b
  vTaskDelay(pdMS_TO_TICKS(428.6));

  tone(BUZZER_PIN, 987.767); // B5
  vTaskDelay(pdMS_TO_TICKS(428.6));

  vTaskDelay(pdMS_TO_TICKS(428.6));

  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(857.1));
  vTaskDelay(pdMS_TO_TICKS(428.6));


  tone(BUZZER_PIN, 1244.51); // E6b
  vTaskDelay(pdMS_TO_TICKS(428.6));

  tone(BUZZER_PIN, 1318.51); // E6
  vTaskDelay(pdMS_TO_TICKS(428.6));

  tone(BUZZER_PIN, 830.609); // A5b
  vTaskDelay(pdMS_TO_TICKS(428.6));

  tone(BUZZER_PIN, 987.767); // B5
  vTaskDelay(pdMS_TO_TICKS(857.1));

  tone(BUZZER_PIN,  880.000); // A5
  vTaskDelay(pdMS_TO_TICKS(857.1));

  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(857.1));
}
*/

void music1(){ // Indiana Jones - Raiders March
  // Quater note = 130 bpm -> 1/(130/60) = 461.5
  // Half note = 130 bpm -> 923.1
  // Eight note = 130 bpm -> 230.8
  // Sixteen note = 130 bpm -> 115.4
  
  tone(BUZZER_PIN, 659.255); // E
  vTaskDelay(pdMS_TO_TICKS(230.8));
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 698.456); // F
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 783.991); // G
  vTaskDelay(pdMS_TO_TICKS(230.8));
  
  tone(BUZZER_PIN, 1046.50); // C
  vTaskDelay(pdMS_TO_TICKS(923.1));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(230.8));
  
  tone(BUZZER_PIN, 587.330); // D
  vTaskDelay(pdMS_TO_TICKS(230.8));
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 659.255); // E
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 698.456); // F
  vTaskDelay(pdMS_TO_TICKS(923.1));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(230.8));
  
  tone(BUZZER_PIN, 783.991); // G
  vTaskDelay(pdMS_TO_TICKS(230.8));
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 880.000); // A
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 987.767); // B
  vTaskDelay(pdMS_TO_TICKS(230.8));
  
  tone(BUZZER_PIN, 1396.91); // F
  vTaskDelay(pdMS_TO_TICKS(923.1));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(230.8));
  
  tone(BUZZER_PIN, 880.000); // A
  vTaskDelay(pdMS_TO_TICKS(230.8));
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 987.767); // B
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 1046.50); // C
  vTaskDelay(pdMS_TO_TICKS(461.5));
  tone(BUZZER_PIN, 1174.66); // D
  vTaskDelay(pdMS_TO_TICKS(461.5));
  tone(BUZZER_PIN, 1318.51); // E
  vTaskDelay(pdMS_TO_TICKS(230.8));
  
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(230.8));
}

void music2(){ // time back
  // Quater note = 130 bpm -> 1/(130/60) = 461.5
  // Half note = 130 bpm -> 923.1
  // Eight note = 130 bpm -> 230.8
  // Sixteen note = 130 bpm -> 115.4

  tone(BUZZER_PIN, 1396.91); // F6
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 1567.98); // G6
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 1864.66); // B6b
  vTaskDelay(pdMS_TO_TICKS(115.4));

  tone(BUZZER_PIN, 1396.91); // F6
  vTaskDelay(pdMS_TO_TICKS(461.5));
  noTone(BUZZER_PIN);
  vTaskDelay(pdMS_TO_TICKS(461.5));
  
  tone(BUZZER_PIN, 1864.66); // B6b
  vTaskDelay(pdMS_TO_TICKS(230.8));
  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(230.8));
  tone(BUZZER_PIN, 1567.98); // G6
  vTaskDelay(pdMS_TO_TICKS(230.8));
  tone(BUZZER_PIN, 1396.91); // F6
  vTaskDelay(pdMS_TO_TICKS(461.5));
  
  noTone(BUZZER_PIN);
  vTaskDelay(pdMS_TO_TICKS(461.5));
  
  tone(BUZZER_PIN, 1864.66); // B6b
  vTaskDelay(pdMS_TO_TICKS(461.5));
  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(230.8));
  tone(BUZZER_PIN, 1567.98); // G6
  vTaskDelay(pdMS_TO_TICKS(230.8));
  tone(BUZZER_PIN, 1396.91); // F6
  vTaskDelay(pdMS_TO_TICKS(230.8));
  
  tone(BUZZER_PIN, 1567.98); // G6
  vTaskDelay(pdMS_TO_TICKS(461.5));

  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(461.5));

  tone(BUZZER_PIN, 1864.66); // B6b
  vTaskDelay(pdMS_TO_TICKS(461.5));
  
  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(461.5));
  
  tone(BUZZER_PIN, 1567.98); // G6
  vTaskDelay(pdMS_TO_TICKS(461.5));
  
  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(461.5));
  
  tone(BUZZER_PIN, 1567.98); // G6
  vTaskDelay(pdMS_TO_TICKS(461.5));

  noTone(BUZZER_PIN);
}

void music3(){ // time back
  // Quater note = 130 bpm -> 1/(130/60) = 461.5
  // Eight note = 130 bpm -> 230.8
  // Sixteen note = 130 bpm -> 115.4

  tone(BUZZER_PIN, 1396.91); // F6
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 1567.98); // G6
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 1864.66); // B6b
  vTaskDelay(pdMS_TO_TICKS(115.4));
  tone(BUZZER_PIN, 2093.00); // C7
  vTaskDelay(pdMS_TO_TICKS(115.4));
  
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));
  
  for (int i=0;i<2;i++){
    tone(BUZZER_PIN, 1396.91); // F6
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  	noTone(BUZZER_PIN); 
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  
  	tone(BUZZER_PIN, 1396.91); // F6
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  	noTone(BUZZER_PIN); 
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  
  	tone(BUZZER_PIN, 1567.98); // G6
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  	noTone(BUZZER_PIN); 
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  
  	tone(BUZZER_PIN, 1567.98); // G6
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  	noTone(BUZZER_PIN); 
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  
  	tone(BUZZER_PIN, 1661.22); // A6b
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  	noTone(BUZZER_PIN); 
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  
  	tone(BUZZER_PIN, 1661.22); // A6b
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  	noTone(BUZZER_PIN); 
  	vTaskDelay(pdMS_TO_TICKS(115.4));
  
  	tone(BUZZER_PIN, 1864.66); // B6b
  	vTaskDelay(pdMS_TO_TICKS(230.8));
  	noTone(BUZZER_PIN); 
  	vTaskDelay(pdMS_TO_TICKS(230.8));
  }

  tone(BUZZER_PIN, 1864.66); // B6b
  vTaskDelay(pdMS_TO_TICKS(115.4));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));
  
  tone(BUZZER_PIN, 1864.66); // B6b
  vTaskDelay(pdMS_TO_TICKS(115.4));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));
  
  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(115.4));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));
  
  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(115.4));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));

  tone(BUZZER_PIN, 1567.98); // G6
  vTaskDelay(pdMS_TO_TICKS(115.4));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));
  
  tone(BUZZER_PIN, 1567.98); // G6
  vTaskDelay(pdMS_TO_TICKS(115.4));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));
  
  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(230.8));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(230.8));
  
  tone(BUZZER_PIN, 1864.66); // B6b
  vTaskDelay(pdMS_TO_TICKS(115.4));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));
  
  tone(BUZZER_PIN, 1864.66); // B6b
  vTaskDelay(pdMS_TO_TICKS(115.4));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));
  
  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(115.4));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));
  
  tone(BUZZER_PIN, 1661.22); // A6b
  vTaskDelay(pdMS_TO_TICKS(115.4));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));

  tone(BUZZER_PIN, 1567.98); // G6
  vTaskDelay(pdMS_TO_TICKS(115.4));
  noTone(BUZZER_PIN); 
  vTaskDelay(pdMS_TO_TICKS(115.4));
}

void playMusic(){
    // Alert System
    if (inputData.stopMusic == false){
      if (sensorData.CO2 > inputData.MinCO2 && sensorData.CO2 <= inputData.MaxCO2){
        music2();
      }
      else if (sensorData.CO2 > inputData.MaxCO2){
        music3();
      }
    }

}