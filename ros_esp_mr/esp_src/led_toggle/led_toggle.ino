/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle  nh;

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

void setup()
{ 
  pinMode(2, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}