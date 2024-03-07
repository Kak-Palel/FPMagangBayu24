#include <micro_ros_arduino.h>
#include <ESP32_Servo.h>

#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <arm_interfaces/msg/servo_parameters.h>

rcl_subscription_t subscriber;
arm_interfaces__msg__ServoParameters msg;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;

#define LED_PIN 2

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

Servo face;
Servo back;
Servo front;
Servo grip;

const float default_face = 0; 
const float default_back = 0;
const float default_front = 180;

const float gripOn = 180;   //assign
const float gripOff = 0;  //assign

void error_loop(){
  while(1){
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(500);
  }
}

void take(float a, float b, float c)
{
  face.write(a);
  back.write(b);
  delay(500);
  front.write(c);
  delay(2000);
  grip.write(gripOn);
  delay(200);
}

void drop(float a, float b, float c)
{
  face.write(a);
  back.write(b);
  delay(500);
  front.write(c);
  delay(2000);
  grip.write(gripOff);
  delay(200);
}

void subscription_callback(const void * msgin)
{  
  const arm_interfaces__msg__ServoParameters * msg = (const arm_interfaces__msg__ServoParameters *)msgin;
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  
  take(msg->take1, msg->take2 * 2, 180 - 2 * (110 - msg->take3));
  back.write(default_back);
  delay(5000);
//  front.write(default_front);
//  delay(500);

  drop(msg->drop1, msg->drop2 * 2, 180 - 2 * (110 - msg->drop3));
  back.write(default_back);
  delay(5000);
  
  digitalWrite(LED_PIN, LOW);
  face.write(default_face);
  delay(500);
  back.write(default_back);
  delay(500);
  front.write(default_front);
  delay(500);
  grip.write(gripOff);
  delay(500);
}

void setup() {
//  set_microros_transports();
  set_microros_wifi_transports("bababoiy", "sembarang", "192.168.110.12", 8888);
  
  pinMode(LED_PIN, OUTPUT);

  face.attach(12, 750, 2250);
  back.attach(13);
  front.attach(33);

  grip.attach(27);

  digitalWrite(LED_PIN, HIGH);  
  
  delay(2000);

  face.write(default_face);
  delay(500);
  back.write(default_back);
  delay(500);
  front.write(default_front);
  delay(500);
  grip.write(gripOff);
  delay(500);

  digitalWrite(LED_PIN, LOW);

  allocator = rcl_get_default_allocator();

  //create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // create node
  RCCHECK(rclc_node_init_default(&node, "micro_ros_arduino_node", "", &support));

  // create subscriber
  RCCHECK(rclc_subscription_init_default(
    &subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(arm_interfaces, msg, ServoParameters),
    "topic_tes"));

  // create executor
  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor, &subscriber, &msg, &subscription_callback, ON_NEW_DATA));
}

void loop() {
  delay(100);
  RCCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));
  delay(1000);
  
}
