
#include <MQ135.h>

#define READ_PIN A0     //読み込みに使うアナログピン
#define R_LOAD 10.0     //センサーのオフセット用抵抗の抵抗値(KOhm)
#define R_ZERO 153.33   //センサーの抵抗値(kOhm)
#define ATOMO_CO2 420.0 //大気の二酸化炭素濃度(変更しなくてよい)

MQ135 mq135(READ_PIN, R_LOAD, R_ZERO, ATOMO_CO2); //クラスの呼び出し

float t = 20.0; //温度
float h = 50.0; //湿度

void setup()
{
  Serial.begin(115200); //シリアル通信のバンドレートを設定
}

void loop()
{

  float correctedPPM;
  //センサーの初期抵抗値を取得する
  mq135.getRZero();
  //気温と湿度のデータを用いてオフセットした抵抗値を取得する
  mq135.getCorrectedRZero(t, h);
  //センサーの抵抗値を取得する
  mq135.getResistance();
  //ppm値を取得する
  mq135.getPPM();
  //気温と湿度のデータを用いてオフセットしたppm値を取得する
  correctedPPM = mq135.getCorrectedPPM(t, h);

  //Serial print
  Serial.print("CO2 PPM: ");
  Serial.print(correctedPPM);
  Serial.println("ppm");

  delay(100);
}