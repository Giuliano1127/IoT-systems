# Monitor de Nível de Tanque com ESP32 e MQTT

Este projeto utiliza um ESP32 e um sensor ultrassônico HC-SR04 para medir o nível de um líquido em um tanque e enviar os dados via protocolo MQTT.

## 🛠 Hardware Utilizado
* **Microcontrolador:** ESP32
* **Sensor:** HC-SR04 (Ultrassônico)
* **Conectividade:** Wi-Fi

## 🔌 Esquema de Ligação
| Sensor HC-SR04 | ESP32 GPIO |
| :--- | :--- |
| VCC | 5V |
| TRIG | GPIO 26 |
| ECHO | GPIO 25 |
| GND | GND |

## ⚙️ Como Configurar
1. Abra o arquivo `.ino` na IDE Arduino.
2. Instale a biblioteca `PubSubClient` (Gerenciador de Bibliotecas).
3. Preencha as suas credenciais nas variáveis de configuração:
   ```cpp
   const char* ssid = "SUA_REDE_WIFI";
   const char* password = "SUA_SENHA";
   const char* mqtt_server = "BROKER";

   client.publish("SEU_TOPICO_AQUI", String(nivelPorcentagem).c_str());

