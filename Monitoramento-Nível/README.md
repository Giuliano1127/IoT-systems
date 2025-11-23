# Monitoramento de Nível de Tanque Industrial (ESP32 + MQTT + Node-RED)

Este projeto implementa um sistema de monitoramento de nível para aplicações industriais utilizando IoT. O objetivo é medir o nível de um tanque, publicar o valor via MQTT e visualizar em um dashboard supervisório no Node-RED, incluindo alarmes visuais baseados no nível lido.

---

## Arquitetura do Sistema

A solução é dividida em três camadas:

### 1. Borda (Edge)
- ESP32 Dev Module.
- Sensor ultrassônico HC-SR04.
- Cálculo do nível em centímetros e porcentagem.

  <img width="1366" height="728" alt="Circuito-tanque" src="https://github.com/user-attachments/assets/8ed0e995-a1dc-4c41-adf3-86f529ba57b3" />


### 2. Comunicação
- Protocolo MQTT.
- Publicação no broker público `broker.hivemq.com`.
- Tópico publicado:

  <img width="1366" height="607" alt="Fluxo-tanque" src="https://github.com/user-attachments/assets/4fb6eab2-e52c-4234-b0df-4ab1c12d9440" />


### 3. Supervisão (Node-RED)
- Dashboard com Gauge e Chart.
- Lógica de alarme usando apenas os nós **Change** e **Switch**.
- Fluxo sem uso de Function Node.

<img width="1363" height="588" alt="Dash -tanque" src="https://github.com/user-attachments/assets/603578da-c61c-4b51-ad17-514a539d2055" />

---

## Tecnologias Utilizadas

| Categoria         | Tecnologia        | Detalhes                         |
|------------------|-------------------|----------------------------------|
| Microcontrolador | ESP32 DevKit     | Programa em C++                  |
| Sensor           | HC-SR04           | Medição de distância             |
| Protocolo        | MQTT              | Publicação/assinatura            |
| Broker           | HiveMQ Cloud      | Broker MQTT público              |
| Supervisão       | Node-RED          | Dashboard e lógica de alarme     |

---

## Firmware (ESP32)

Localizado em: `firmware/esp32_tank_monitor.ino`

## Simulação
https://wokwi.com/projects/447989013219306497

### Ajuste das credenciais

```cpp
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";
const char* mqtt_server = "broker.hivemq.com";
