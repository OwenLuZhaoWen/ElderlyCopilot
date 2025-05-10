/*
forward R -10--60
        P 0-10
leftforward P -10--35
rightforward P 10-40
leftturn R -10-10
         P-10--50
rightturn R -10-10
          P 10-50
backward R -10-40
         P 0-10
leftbackward P -10--35
rightbackward P 10-40
*/
#include <M5Core2.h>
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
String slaveName = "OWEN";
String myName = "OWEN-M5";

float pitch = 0.0F;
float roll = 0.0F;
float yaw = 0.0F;

/* After M5Core2 is started or reset
the program in the setUp () function will be run, and this part will only be run
once. 在 M5Core2
启动或者复位后，即会开始执行setup()函数中的程序，该部分只会执行一次。 */
void setup() {
  M5.begin();                // Init M5Core.  初始化 M5Core
  M5.IMU.Init();             // Init IMU sensor.  初始化惯性传感器
  M5.Lcd.fillScreen(BLACK);  // Set the screen background color to black.
                             // 设置屏幕背景色为黑色
  M5.Lcd.setTextColor(
    GREEN,
    BLACK);               // Sets the foreground color and background color of the
                          // displayed text.  设置显示文本的前景颜色和背景颜色
  M5.Lcd.setTextSize(2);  // Set the font size.  设置字体大小
  SerialBT.begin(myName, true);
  SerialBT.setPin("1234");
  Serial.printf("Connecting to slave BT device named \"%s\"\n", slaveName.c_str());
  M5.Lcd.setCursor(0, 120);
  if (SerialBT.connect(slaveName)) {
    M5.lcd.print("BT Connected!");
    Serial.println("BT Connected!");
  } else {
    while (!SerialBT.connected(10000)) {
      M5.lcd.print("Failed to connect BT!");
      Serial.println("Failed to connect BT!");
    }
  }
}

void loop() {
  // Stores the triaxial gyroscope data of the inertial sensor to the relevant
  // variable 将惯性传感器的三轴陀螺仪数据存储至相关变量
  M5.IMU.getAhrsData(&pitch, &roll, &yaw);  // Stores the inertial sensor attitude.  存储惯性传感器的姿态
  // Pose output is related
  // 姿态输出相关
  M5.Lcd.setCursor(0, 120);
  M5.Lcd.printf("pitch,  roll,  yaw");
  M5.Lcd.setCursor(0, 142);
  M5.Lcd.printf("%5.2f  %5.2f  %5.2f deg", pitch, roll, yaw);

  if (roll < -20 && roll > -90) {  //前
    if (pitch > 0 && pitch < 10) {
      Serial.println("Front!");  //front
      SerialBT.println(1);
    } else if (pitch < -10 && pitch > -35) {
      Serial.println("LeftFront!");  //leftfront
      SerialBT.println(5);
    } else if (pitch > 10 && pitch < 40) {
      Serial.println("RightFront!");  //rightfront
      SerialBT.println(6);
    }
  } else if (roll > 10 && roll < 90) {  //后
    if (pitch > 0 && pitch < 10) {
      Serial.println("Backward!");  //backward
      SerialBT.println(2);
    } else if (pitch < -10 && pitch > -35) {
      Serial.println("LeftBack!");  //leftback
      SerialBT.println(7);
    } else if (pitch > 10 && pitch < 40) {
      Serial.println("RightBack!");  //rightback
      SerialBT.println(8);
    }
  } else {
    if (pitch < -15 && pitch > -90) {
      Serial.println("Left!");  //left
      SerialBT.println(3);
    } else if (pitch > 15 && pitch < 90) {
      Serial.println("Right!");  //right
      SerialBT.println(4);
    } else {
      Serial.println("Stop!");  //stop
      SerialBT.println(0);
    }
  }           //左右
  delay(10);  // Delay 10ms.  延迟10ms
}