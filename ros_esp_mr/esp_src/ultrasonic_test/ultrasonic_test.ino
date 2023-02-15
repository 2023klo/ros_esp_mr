#include <ros.h>
#include <std_msgs/Float64.h>

const int trig_Pin = 2;
const int echo_Pin = 4;

#define SPEED_OF_SOUND 0.034

long duration;
float distance_in_cm;
float randomDecimal, result;
int randInt;

ros::NodeHandle  nh;

/*
void messageCb( const std_msgs::Empty& toggle_msg){
  if (digitalRead(2) == HIGH){
    delay(2);
    digitalWrite(2,0);
  }
  else {
    digitalWrite(2,1);
  }
  //digitalWrite(2, HIGH-digitalRead(2));   // blink the led
}

ros::Subscriber<std_msgs::Empty> sub("toggle_us", &messageCb );
*/
std_msgs::Float64 ultrasonic_msg;
ros::Publisher ultrasonic_node("ultrasonic_value", &ultrasonic_msg );

void setup()
{
    pinMode(trig_Pin,OUTPUT);
    pinMode(echo_Pin,OUTPUT);
    //nh.initNode();
    //nh.advertise(ultrasonic_node);
    Serial.begin(115200);
}

void loop()
{
    digitalWrite(trig_Pin,LOW);
    delayMicroseconds(2);
    digitalWrite(trig_Pin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_Pin,LOW);
    
//    randInt = random(0,91);   // a random integer from -90 to 90
//    randomDecimal = random(0, 100) / 100.0; // a random decimal number from 0.00 to 0.99
//    result = randInt + randomDecimal; // a random decimal number from -90.00 to 90.99

    duration = pulseIn(echo_Pin,HIGH);
    //Serial.print(duration);Serial.print(", ");
    distance_in_cm = (duration * SPEED_OF_SOUND)/2;
    Serial.println(distance_in_cm);
    //Serial.print(", ");
    //Serial.println(result);
    //delay(300);
    
//    ultrasonic_msg.data=distance_in_cm;
//    ultrasonic_node.publish(&ultrasonic_msg);
//    nh.spinOnce();
    delay(1);


}
