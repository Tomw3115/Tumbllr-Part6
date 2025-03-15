#include "Motor.h"
#include "Balanced.h"
#include <Adafruit_NeoPixel.h>

Timer2 Timer2;
extern Mpu6050 Mpu6050;
extern Motor Motor;
extern Balanced Balanced;


void setup() 
{
  Motor.Pin_init();
  Motor.Encoder_init();
  Timer2.init(TIMER);
  Mpu6050.init();
  Balanced.initLED();
  Serial.begin(9600);

  Balanced.SetSpeed(15.0);
  Balanced.Stop(); 
  delay(5000); // pause to add payload to Tumbllr after balance is acheived

  // path to calibrate WHEEL_DIA
  //Balanced.ForwardDist(20);
  // if distance moved is less than 20 inches, decrease WHEEL_DIA
  // if distance moved is greater than 20 inches, increase WHEEL_DIA

  // path to calibrate TRACK_WIDTH
  //Balanced.LeftAngle(360);
  // if turn is less than 360 degrees, make TRACK_WIDTH larger
  // if turn is more than 360 degrees, make TRACK_WIDTH smaller

  // add variable to allow distance measurements in floor tiles
  float tile = 17.0; //floor tile length
  
  Balanced.ForwardDist(3*tile);
  Balanced.LeftAngle(90);
  Balanced.ForwardDist(5*tile);
  Balanced.RightAngle(90);
  Balanced.ForwardDist(6*tile);
  Balanced.RightAngle(90);
  Balanced.ForwardDist(9*tile);
  Balanced.LeftAngle(90);
  Balanced.ForwardDist(3*tile);
  Balanced.Stop();

}
void loop() 
{
  
}

  

