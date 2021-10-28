//Libs do espnow e wifi
#include <esp_now.h>
#include <WiFi.h>

//Pinos que iremos escrever (digitalWrite) cujos valores são recebios do Master
//É importante que o código fonte do Master tenha este mesmo array com os mesmos gpios na mesma ordem
uint8_t gpios[] = {23, 2};

//No setup iremos calcular a quantidade de pinos e colocar nesta variável, assim não precisamos trocar aqui toda vez 
//que mudarmos a quantidade de pinos, tudo é calculado no setup
int gpioCount;


void setup() {
  Serial.begin(115200);
  
  //sizeof(gpios) retorna a quantidade de bytes que o array gpios aponta e dividimos por sizeof(uint8_t) que retorna 
  //a quantidade de bytes que o tipo uint8_t possui. Dessa forma armazenamos quantos gpio o count tem, no nosso caso 2.
  gpioCount = sizeof(gpios)/sizeof(uint8_t);

  //Colocamos o ESP em modo station
  WiFi.mode(WIFI_STA);
  
  //Mostramos no Monitor Serial o Mac Address deste ESP quando em modo station
  //Se quiser que o Master mande para ESPs em específico, altere no array de slaves (no código fonte do Master) para que 
  //ele possua apenas os Mac Addresses printados aqui
  Serial.print("Mac Address in Station: "); 
  Serial.println(WiFi.macAddress());

  //Chama a função que inicializa o ESPNow
  InitESPNow();

  //Registra o callback que nos informará quando o Master enviou algo, a função que será executada é OnDataRecv
  esp_now_register_recv_cb(OnDataRecv);

  //Para cada pino que está no array gpios, colocando todos os pinos que escolhemos no modo de saida
  for(int i=0; i<gpioCount; i++){
    pinMode(gpios[i], OUTPUT);
  }
}


//Esta função informará se a inicialização foi bem sucedida, caso não, também informaá e realiza o restart 
void InitESPNow() {
  if (esp_now_init() == ESP_OK) {
    Serial.println("ESPNow Init Success");
  }
  else {
    Serial.println("ESPNow Init Failed");
    ESP.restart();
  }
}


//Função que serve de callback para nos avisar quando chegou algo do Master
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
  char macStr[18];
  //Copiamos o Mac Address origem para uma string, convertendo binário para texto
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  //Mostramos o Mac Address que foi a origem da mensagem
  Serial.print("Received from: "); 
  Serial.println(macStr);
  Serial.println("");

  //Para cada pino. Colocamos o valor recebido do Master na saída do respectivo pino
  for(int i=0; i<gpioCount; i++){
    digitalWrite(gpios[i], data[i]);
  }
}


//Não precisamos fazer nada no loop. Sempre que chegar algo do Master a função OnDataRecv é executada 
//automaticamente já que adicionamos como callback utilizando a função esp_now_register_recv_cb
void loop() {
}
