#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Pinos do NodeMCU: SDA => D1 SCL => D2
//Credenciais do FireBase e WiFi
#define FIREBASE_HOST "seu_link.firebaseio.com" //No firebase vá em: Realtime Database > copie e cole o link do seu database
#define FIREBASE_AUTH "insira a chave secreta do seu projeto firebase"//No firebase vá em: Configurações de Projeto > Contas e Serviço > Chaves Secretas do banco de dados
#define WIFI_SSID "insira o nome da sua rede WiFi"
#define WIFI_PASSWORD "insira a senha da sua Rede WiFi"

WiFiServer server(80);// Porta 80 do webserver

 int h = 1;
 
void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("conectando");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("conectado: ");
  Serial.println(WiFi.localIP());

  //Iniciar Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop()  {
  Serial.print("Cont: ");
  Serial.println(h);

    h = random(0,100);

  Firebase.pushInt("teste", h);//envia para o database
  delay(3000);
}