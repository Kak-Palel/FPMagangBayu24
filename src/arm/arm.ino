#include <micro_ros_arduino.h>

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

#define LED_PIN 13
#define myLED1 16
#define myLED2 17
#define myLED3 18
#define myLED4 19

#define myLED5 21
#define myLED6 22
#define myLED7 23
#define myLED8 25

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}


void error_loop(){
  while(1){
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
  }
}

void subscription_callback(const void * msgin)
{  
  const arm_interfaces__msg__ServoParameters * msg = (const arm_interfaces__msg__ServoParameters *)msgin;
//  digitalWrite(LED_PIN, (msg->take1 == 0) ? LOW : HIGH);
  delay(100);
  if (msg->take1 > 0)
  {
    digitalWrite(myLED1, HIGH);
  }
  if (msg->take2 > 0)
  {
    digitalWrite(myLED2, HIGH);
  }
  if (msg->take3 > 0)
  {
    digitalWrite(myLED3, HIGH);
  }
  if (msg->take4 > 0)
  {
    digitalWrite(myLED4, HIGH);
  }

  if (msg->drop1 > 0)
  {
    digitalWrite(myLED5, HIGH);
  }
  if (msg->drop2 > 0)
  {
    digitalWrite(myLED6, HIGH);
  }
  if (msg->drop3 > 0)
  {
    digitalWrite(myLED7, HIGH);
  }
  if (msg->drop4 > 0)
  {
    digitalWrite(myLED8, HIGH);
  }
}

void setup() {
//  set_microros_transports();
  set_microros_wifi_transports("bababoiy", "sembarang", "192.168.11.12", 8888);
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(myLED1, OUTPUT);
  pinMode(myLED2, OUTPUT);
  pinMode(myLED3, OUTPUT);
  pinMode(myLED4, OUTPUT);
  pinMode(myLED5, OUTPUT);
  pinMode(myLED6, OUTPUT);
  pinMode(myLED7, OUTPUT);
  pinMode(myLED8, OUTPUT);
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
  digitalWrite(myLED1, LOW);
  digitalWrite(myLED2, LOW);
  digitalWrite(myLED3, LOW);
  digitalWrite(myLED4, LOW);
  digitalWrite(myLED5, LOW);
  digitalWrite(myLED6, LOW);
  digitalWrite(myLED7, LOW);
  digitalWrite(myLED8, LOW);
}
