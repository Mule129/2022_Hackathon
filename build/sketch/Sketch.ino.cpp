#include <Arduino.h>
#line 1 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
#include "HUSKYLENS.h"
#include "SoftwareSerial.h"
#include "LiquidCrystal_I2C.h"

HUSKYLENS huskylens;
LiquidCrystal_I2C lcd(0x27, 16, 2);

//HUSKYLENS green line >> SDA; blue line >> SCL
void printResult(HUSKYLENSResult result);

#line 11 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
void setup();
#line 28 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
void loop();
#line 11 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    lcd.print("test");
    delay(1000);
    
    Wire.begin();
    while (!huskylens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(100);
    }
}

void loop() {
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print("start");
    Serial.println("start lcd");
    
    if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
    else if(!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
    else if(!huskylens.available()) Serial.println(F("No block or arrow appears on the screen!"));
    else
    {
        Serial.println(F("###########"));
        while (huskylens.available())
        {
            HUSKYLENSResult result = huskylens.read();
            printResult(result);
            lcd.setCursor(0,1);
            lcd.print(String() + F("Center : ") + result.xCenter);
            Serial.println("go lcd");
            
        }    
    }
}

void printResult(HUSKYLENSResult result){
    if (result.command == COMMAND_RETURN_BLOCK){
        Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);
    }
    else if (result.command == COMMAND_RETURN_ARROW){
        Serial.println(String()+F("Arrow:xOrigin=")+result.xOrigin+F(",yOrigin=")+result.yOrigin+F(",xTarget=")+result.xTarget+F(",yTarget=")+result.yTarget+F(",ID=")+result.ID);
    }
    else{
        Serial.println("Object unknown!");
    }
}
#line 1 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\test_2.ino"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// 0x3F I2C 주소를 가지고 있는 16x2 LCD객체를 생성합니다.(I2C 주소는 LCD에 맞게 수정해야 합니다.)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.
// 변수를 선언하거나 초기화를 위한 코드를 포함합니다.
void setup() {
  // I2C LCD를 초기화 합니다..
  lcd.init();
  // I2C LCD의 백라이트를 켜줍니다.
  lcd.backlight();
}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행됩니다.
void loop() { 
  // random 함수를 사용하여 0부터 2까지의 숫자중 랜덤하게 값을 받습니다.
  int value = random(0, 3);
  // 랜덤 값이 0이라면 아래의 조건을 실행합니다.
  if (value == 0) {
    // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.setCursor(0,0);           // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("  dtd.cc  ");       // 문구를 출력합니다.
  }
  // 랜덤 값이 1이라면 아래의 조건을 실행합니다.
  else if (value == 1) {
    lcd.setCursor(0,1);           // 1번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("  Hello dd!!  ");     // 문구를 출력합니다.
  }
  // 랜덤 값이 2이라면 아래의 조건을 실행합니다.
  else if (value == 2) {
    // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.setCursor(0,0);
    // 아래의 문장을 출력합니다.
    lcd.print("  dd.cc  ");
    // 1번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.setCursor(0,1);
    // 아래의 문장을 출력합니다.
    lcd.print("  dd World!!  ");
  }
  // 1초간 대기합니다.
  delay(1000);
  // LCD의 모든 내용을 삭제합니다.
  lcd.clear();
}
