#include <WiFi.h> // biblioteca para uso do Wifi
#include <PubSubClient.h> // biblioteca do MQTT

#define TRIG_PIN 26
#define ECHO_PIN 25

#define ALTURA_TOTAL_CM 100.0 // Altura total do tanque

//Credenciaias
const char* ssid = "SUA REDE"; // Your Net
const char* password = "SUA SENHA"; // Your Password
const char* mqtt_server = "SEU BROKER OU BROKER PUBLICO"; // Your Broker

//Clientes
WiFiClient espClientGiu;
PubSubClient client(espClientGiu);

int duracao; // duração do tempo que echo fica ligado
float distancia; // distancia medida em CM

//protótipos
float leDistanciaCM(); // função que lê distancia baseado na medição do sensor
float calculaNivelPorcentagem(float distanciaLida);  // calculo de nivel do liquido
void setup_wifi(); // Configura Wifi
void reconnect(); // Conexão ao broker
void exibeserial(float nivelCM,float nivelPorcentagem); // função para exibição no monitor serial dos valores medidos

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  //distancia recebe valor lido bruto e covertido pelo sensor 
  distancia = leDistanciaCM(); 
  
  //  nivel do produto 
  float nivelCM = ALTURA_TOTAL_CM - distancia; 
  
  // recebe o valor do calculo de porcentagem  da função usando distancia 
  float nivelPorcentagem = calculaNivelPorcentagem(distancia) * 100; 
  

  client.publish("TANQUE1", String(nivelPorcentagem).c_str()); 
  exibeserial(nivelCM, nivelPorcentagem);

  delay(5000);
}

float leDistanciaCM() { // leitura do pulso do som 
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duracao = pulseIn(ECHO_PIN, HIGH);
  return duracao * 0.034 / 2; // calcualo: duração do tempo * velocidade do som / ida e volta 
}

float calculaNivelPorcentagem(float distanciaLida){
  float nivelCM = ALTURA_TOTAL_CM - distanciaLida; 

  // Calcula a fração (0.0 a 1.0)
  float nivelPorcentagem = (nivelCM / ALTURA_TOTAL_CM); 
  
  // CORREÇÃO: Usar '=' para atribuir valor e garantir limites
  if (nivelPorcentagem < 0) {
    nivelPorcentagem = 0;
  }
  if (nivelPorcentagem > 1) { // 1.0 representa 100%
    nivelPorcentagem = 1;
  }
  
  return nivelPorcentagem;
}

void setup_wifi() { // configura conexão ao WIFI
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() { // Função de conexão ao broker
  while (!client.connected()) {
    if (client.connect("espClientGiu")) {
      Serial.println("Broker connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void exibeserial(float nivelCM, float nivelPorcentagem) { 
  Serial.print("Nivel (CM): ");
  Serial.println(nivelCM);
  Serial.print("Nivel (%): ");
  Serial.print(nivelPorcentagem);
  Serial.println("%");
}
