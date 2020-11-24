
// Motion detection reference https://learn.adafruit.com/circuit-playgrounds-motion-sensor/intro-and-setup

#include <Adafruit_CircuitPlayground.h>

#define THRESHOLD 40

const unsigned long runInterval = 3000;   //Time of idle until device resets to idle state
unsigned long startRunningTime;

float X, Y, Z;
bool running;

void setup() {
  // Initialize Circuit Playground
  CircuitPlayground.begin();
  Serial.begin(9600);
  startRunningTime = 0; 
}

void loop() {

  /**** Detech Running Movement ***/
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  // Get the magnitude (length) of the 3 axis vector
  // http://en.wikipedia.org/wiki/Euclidean_vector#Length
  double storedVector = X*X;
  storedVector += Y*Y;
  storedVector += Z*Z;
  storedVector = sqrt(storedVector);
  
  delay(100);
  
  // Import new data
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();
  double newVector = X*X;
  newVector += Y*Y;
  newVector += Z*Z;
  newVector = sqrt(newVector);


  /**** Auto start running timer when user start running ***/
  if (startRunningTime == 0) {
      //Timer not running. Check for movement to start timer
      if (abs(10*newVector - 10*storedVector) > THRESHOLD) {
        startRunningTime = millis(); //start the timer
        running = true; 
      }
   } else {        //if timer is running
      //check if stop button is pressed or if user idle for awhile
      if ((millis() - startRunningTime >= runInterval) || (CircuitPlayground.rightButton()) || (CircuitPlayground.leftButton())) {
        //if condition statisfy execute code below
        startRunningTime = 0; // stop timer
        running = false;
        Serial.print("Stopped running");
      }
   }

  // If user is running
  if (running) {

    //Neo Pixel Timer animation
    for (int i=0; i<10; i++) {
      
      if (CircuitPlayground.rightButton() || CircuitPlayground.leftButton()) {  // stop loop on button press, exit running mode
        return; // stop loop
        running = false;
        Serial.print("Stop loop pressed");  
      }
      
      CircuitPlayground.setPixelColor(i, 255, 247, 0);   // Turn on neo pixel to Yellow color
      delay(3000); // Increment every 3 seconds, set 2 minutes to apply to real world running scale.
      CircuitPlayground.setPixelColor(i, 255, 0, 0);   // Turn on neo pixel to Red color
           
    } 
  }
   
  // If user is NOT running
  if (running == false) {
      // Turn on neo pixel to white color
      for (int i=0; i<10; i++) {
        CircuitPlayground.setPixelColor(i, 255, 255, 255);
     }
  }
  
}
