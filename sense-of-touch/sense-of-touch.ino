#include <Adafruit_CircuitPlayground.h>

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

int vals[8] = {3,2,0,1,12,6,9,10};

void loop() {

  if (CircuitPlayground.readCap(3) > 400) {
    Serial.println("I am hungry");
    CircuitPlayground.speaker.enable(true);
    CircuitPlayground.playTone(261.626, 100);
    
    for (int i=0; i<10; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 0);
    }
    
    delay(200);
    CircuitPlayground.clearPixels();
  }

  if (CircuitPlayground.readCap(10) > 400) {
    Serial.println("I am thirsty");
    CircuitPlayground.speaker.enable(true);
    CircuitPlayground.playTone(523.251, 100);

    for (int i=0; i<10; i++) {
        CircuitPlayground.setPixelColor(i, 255, 230, 0);
    }

    delay(200);
    CircuitPlayground.clearPixels();
  }  

  else if (CircuitPlayground.readCap(1) > 400) {
    Serial.println("I am sleepy");
    CircuitPlayground.speaker.enable(true);
    CircuitPlayground.playTone(440.0, 100);
    
    for (int i=0; i<10; i++) {
        CircuitPlayground.setPixelColor(i, 0, 0, 255);
    }
 
    delay(200);
    CircuitPlayground.clearPixels();
  }

  else if (CircuitPlayground.readCap(6) > 400) {
    Serial.println("I am happy");
    CircuitPlayground.speaker.enable(true);
    CircuitPlayground.playTone(349.228, 100);
    
    for (int i=0; i<10; i++) {
        CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
    
    delay(200);
    CircuitPlayground.clearPixels();
  }

  else {
    CircuitPlayground.speaker.enable(false);
    CircuitPlayground.clearPixels();
  }

  delay(100);
}
