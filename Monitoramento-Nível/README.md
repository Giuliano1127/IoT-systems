# Monitoramento de Nível de Tanque Industrial (ESP32 + MQTT + Node-RED)

Este projeto implementa um sistema de monitoramento de nível para aplicações industriais utilizando IoT. O objetivo é medir o nível de um tanque, publicar o valor via MQTT e visualizar em um dashboard supervisório no Node-RED, incluindo alarmes visuais baseados no nível lido.

---

## Arquitetura do Sistema

A solução é dividida em três camadas:

### 1. Borda (Edge)
- ESP32 Dev Module.
- Sensor ultrassônico HC-SR04.
- Cálculo do nível em centímetros e porcentagem.

### 2. Comunicação
- Protocolo MQTT.
- Publicação no broker público `broker.hivemq.com`.
- Tópico publicado:
