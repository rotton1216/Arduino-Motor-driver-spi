#include <SPI.h>
SPISettings mySPISettings = SPISettings(8000000, MSBFIRST, SPI_MODE1);//spi通信の初期設定　レート,忘れたggrks,SPIのモード設定
void setup() {
  SPI.begin();//spi通信のピン設定など
}

void loop() {
  // put your main code here, to run repeatedly:
  SPI.beginTransaction(mySPISettings);//設定をマイコンに書き込む
  digitalWrite(SS,LOW);//spi通信開始
  SPI.transfer(0b00000000);//free
  delay(1000);
  SPI.transfer(0b10110010);//forword
  delay(1000);
  SPI.transfer(0b00110010);//reverse
  delay(1000);
  SPI.transfer(0b10000000);//brake
  delay(1000);
  digitalWrite(SS,HIGH);//spi通信終了
   SPI.endTransaction();

}
