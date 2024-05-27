#include <MQ135.h>

#define READ_PIN 4     //読み込みに使うアナログピン
#define R_LOAD 22.0     //センサーのオフセット用抵抗の抵抗値(KOhm)
#define R_ZERO 0   //センサーの抵抗値(kOhm) このスケッチでは設定しない
#define ATOMO_CO2 420.0 //大気の二酸化炭素濃度(変更しなくてよい)

//測定は外か、よく換気されている部屋で行う

MQ135 mq135(READ_PIN, R_LOAD, R_ZERO, ATOMO_CO2);

void setup (){
  Serial.begin(115200);
  pinMode(READ_PIN, INPUT);
}
void loop() {
  float rzero = mq135.getRZero();
  Serial.println (rzero);

  delay(1000);
}