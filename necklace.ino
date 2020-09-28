#include <Adafruit_CircuitPlayground.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");
  CircuitPlayground.begin();
}


void loop() {

  // Get accelerometer value, from lecture slide
  float total = abs(CircuitPlayground.motionX()) + abs(CircuitPlayground.motionY()) + abs(CircuitPlayground.motionZ());

  // Rules to sense movement, if it does change LED to green
  if (total > 10) {
    for (int i=0; i<10; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 0);
    }
  } else  {
    for (int i=0; i<10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  }
  
  // Print accelerometer value
  Serial.println(total);

  
}
