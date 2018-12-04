#include "CompactBox.h"
#include "ACS712.h"

String IDdispositivo = "YRB16WOG";
boolean statusDisp = false;

ACS712 sensorCorrente(ACS712_30A, A0);
int portaRele = 7;

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  pinMode(portaRele,OUTPUT);  //set build in led as output
  digitalWrite(portaRele, statusDisp);
  
  delay(500);
  Serial.println("Aguarde. Calibrando ACS712...");
  sensorCorrente.calibrate();
  Serial.println("Fim da calibração");
  delay(500);
  
  serialESPInitialize();
  
}

void loop(){
  long int time = millis();
  //coleta dados
  float corrente = sensorCorrente.getCurrentAC(60);
  
  String status = sendData(IDdispositivo, corrente);
  Serial.println(millis()-time);
  Serial.println("=============================================");
  delay(5000);
  while(1){
    ;
  }
}
