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

Servo face;
Servo back;
Servo front;
Servo grip;

const float default_face = 0;  //assign
const float default_back = 0;  //assign
const float default_front = 180;

const float gripOn = 0;   //assign
const float gripOff = 180;  //assign

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
  delay(500);
  grip.write(gripOn);
  delay(200);
}

void drop(float a, float b, float c)
{
  face.write(a);
  back.write(b);
  delay(500);
  front.write(c);
  delay(500);
  grip.write(gripOff);
  delay(200);
}

void subscription_callback(const void * msgin)
{  
  const arm_interfaces__msg__ServoParameters * msg = (const arm_interfaces__msg__ServoParameters *)msgin;
//  digitalWrite(LED_PIN, (msg->take1 == 0) ? LOW : HIGH);
  delay(100);
  
  take(msg->take1, msg->take2 * 2, 180 - 2 * (110 - msg->take3));
  back.write(default_back);
  delay(500);

  drop(msg->drop1, msg->drop2, msg->drop3);
  back.write(default_back);
  delay(500);

}

void setup() {
//  set_microros_transports();
  set_microros_wifi_transports("bababoiy", "sembarang", "192.168.11.12", 8888);
  
  pinMode(LED_PIN, OUTPUT);

  face.attach(12);
  back.attach(13);
  front.attach(33);

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

  grip.attach(27);

  digitalWrite(LED_PIN, HIGH);  
  
  delay(2000);

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
  
  face.write(default_face);
  back.write(default_back);
  front.write(default_front);
  grip.write(gripOff);
}
