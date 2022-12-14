# 1 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
# 2 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 2
# 3 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 2
# 4 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 2

HUSKYLENS huskylens;
LiquidCrystal_I2C lcd(0x27, 16, 2);

//HUSKYLENS green line >> SDA; blue line >> SCL
void printResult(HUSKYLENSResult result);

void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    lcd.print("test");
    delay(1000);

    Wire.begin();
    while (!huskylens.begin(Wire))
    {
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 21 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 21 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                      "Begin failed!"
# 21 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                      ); &__c[0];}))
# 21 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                      )));
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 22 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 22 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                      "1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"
# 22 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                      ); &__c[0];}))
# 22 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                      )));
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 23 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 23 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                      "2.Please recheck the connection."
# 23 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                      ); &__c[0];}))
# 23 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                      )));
        delay(100);
    }
}

void loop() {
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print("start");
    Serial.println("start lcd");

    if (!huskylens.request()) Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 34 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                            (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 34 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                            "Fail to request data from HUSKYLENS, recheck the connection!"
# 34 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                            ); &__c[0];}))
# 34 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                            )));
    else if(!huskylens.isLearned()) Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 35 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 35 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                  "Nothing learned, press learn button on HUSKYLENS to learn one!"
# 35 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                  ); &__c[0];}))
# 35 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                  )));
    else if(!huskylens.available()) Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 36 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 36 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                  "No block or arrow appears on the screen!"
# 36 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                  ); &__c[0];}))
# 36 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                  )));
    else
    {
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 39 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 39 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                      "###########"
# 39 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                      ); &__c[0];}))
# 39 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                      )));
        while (huskylens.available())
        {
            HUSKYLENSResult result = huskylens.read();
            printResult(result);
            lcd.setCursor(0,1);
            lcd.print(String() + (reinterpret_cast<const __FlashStringHelper *>(
# 45 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 45 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                "Center : "
# 45 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                ); &__c[0];}))
# 45 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                )) + result.xCenter);
            Serial.println("go lcd");

        }
    }
}

void printResult(HUSKYLENSResult result){
    if (result.command == COMMAND_RETURN_BLOCK){
        Serial.println(String()+(reinterpret_cast<const __FlashStringHelper *>(
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                               (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                               "Block:xCenter="
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                               ); &__c[0];}))
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                               ))+result.xCenter+(reinterpret_cast<const __FlashStringHelper *>(
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                  ",yCenter="
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                  ); &__c[0];}))
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                  ))+result.yCenter+(reinterpret_cast<const __FlashStringHelper *>(
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                ",width="
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                ); &__c[0];}))
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                ))+result.width+(reinterpret_cast<const __FlashStringHelper *>(
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                                          (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                                          ",height="
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                                          ); &__c[0];}))
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                                          ))+result.height+(reinterpret_cast<const __FlashStringHelper *>(
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                                                                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                                                                      ",ID="
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                                                                      ); &__c[0];}))
# 54 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                                                                      ))+result.ID);
    }
    else if (result.command == COMMAND_RETURN_ARROW){
        Serial.println(String()+(reinterpret_cast<const __FlashStringHelper *>(
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                               (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                               "Arrow:xOrigin="
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                               ); &__c[0];}))
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                               ))+result.xOrigin+(reinterpret_cast<const __FlashStringHelper *>(
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                  ",yOrigin="
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                  ); &__c[0];}))
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                  ))+result.yOrigin+(reinterpret_cast<const __FlashStringHelper *>(
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                ",xTarget="
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                ); &__c[0];}))
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                ))+result.xTarget+(reinterpret_cast<const __FlashStringHelper *>(
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                                              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                                              ",yTarget="
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                                              ); &__c[0];}))
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                                              ))+result.yTarget+(reinterpret_cast<const __FlashStringHelper *>(
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                                                                            (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                                                                            ",ID="
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino" 3
                                                                                                                                                            ); &__c[0];}))
# 57 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\Sketch.ino"
                                                                                                                                                            ))+result.ID);
    }
    else{
        Serial.println("Object unknown!");
    }
}
# 1 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\test_2.ino"
# 2 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\test_2.ino" 2
# 3 "c:\\Users\\a24cc\\Documents\\Github\\2022_Hackathon\\User\\Mule\\test_2.ino" 2

// 0x3F I2C ????????? ????????? ?????? 16x2 LCD????????? ???????????????.(I2C ????????? LCD??? ?????? ???????????? ?????????.)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ????????? ?????? ?????? ???????????? ????????????, ?????? 1?????? ???????????????.
// ????????? ??????????????? ???????????? ?????? ????????? ???????????????.
void setup() {
  // I2C LCD??? ????????? ?????????..
  lcd.init();
  // I2C LCD??? ??????????????? ????????????.
  lcd.backlight();
}

// setup() ????????? ????????? ??????, loop() ????????? ????????????,
// ?????? ?????? ????????? ????????? ?????? ???????????????.
void loop() {
  // random ????????? ???????????? 0?????? 2????????? ????????? ???????????? ?????? ????????????.
  int value = random(0, 3);
  // ?????? ?????? 0????????? ????????? ????????? ???????????????.
  if (value == 0) {
    // 0?????? ??? 0?????? ????????? ???????????? ?????????.
    lcd.setCursor(0,0); // 0?????? ??? 0?????? ????????? ???????????? ?????????.
    lcd.print("  dtd.cc  "); // ????????? ???????????????.
  }
  // ?????? ?????? 1????????? ????????? ????????? ???????????????.
  else if (value == 1) {
    lcd.setCursor(0,1); // 1?????? ??? 0?????? ????????? ???????????? ?????????.
    lcd.print("  Hello dd!!  "); // ????????? ???????????????.
  }
  // ?????? ?????? 2????????? ????????? ????????? ???????????????.
  else if (value == 2) {
    // 0?????? ??? 0?????? ????????? ???????????? ?????????.
    lcd.setCursor(0,0);
    // ????????? ????????? ???????????????.
    lcd.print("  dd.cc  ");
    // 1?????? ??? 0?????? ????????? ???????????? ?????????.
    lcd.setCursor(0,1);
    // ????????? ????????? ???????????????.
    lcd.print("  dd World!!  ");
  }
  // 1?????? ???????????????.
  delay(1000);
  // LCD??? ?????? ????????? ???????????????.
  lcd.clear();
}
