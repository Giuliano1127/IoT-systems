Monitoramento de Nível de Tanque Industrial (ESP32 + MQTT + Node-RED)

Este projeto implementa um sistema de monitoramento de nível para aplicações industriais utilizando IoT. O objetivo é medir o nível de um tanque, publicar o valor via MQTT e visualizar em um dashboard supervisório no Node-RED, incluindo alarmes visuais baseados no nível lido.

🏗️ Arquitetura do Sistema

A solução é dividida em três camadas:

1. Borda (Edge)

ESP32 Dev Module.

Sensor ultrassônico HC-SR04.

Cálculo do nível em centímetros e porcentagem.

2. Comunicação

Protocolo MQTT.

Publicação no broker público broker.hivemq.com.

Tópico publicado:

industria/tanque1/nivel_percento

3. Supervisão (SCADA Web)

Node-RED.

Dashboard com Gauge e Chart.

Lógica de alarme usando apenas Change e Switch (sem Function node).

🛠️ Tecnologias Utilizadas
Categoria	Tecnologia	Detalhes
Microcontrolador	ESP32 DevKit	Código em C++
Sensor	HC-SR04	Medição de distância
Protocolo	MQTT	Publicação/assinatura
Broker	HiveMQ	Broker MQTT na nuvem
Supervisão	Node-RED	Dashboard e lógica de alarme
💻 Firmware (ESP32)

Localizado em: firmware/esp32_tank_monitor.ino

Ajuste das credenciais:
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";
const char* mqtt_server = "broker.hivemq.com";

Publicação MQTT:
client.publish("industria/tanque1/nivel_percento", String(nivelPorcentagem).c_str());


O valor de nível é enviado a cada 5 segundos.

📊 Dashboard (Node-RED)

Localizado em: node_red_flow/node_red_flow.json

Importação:

Node-RED → Menu → Importar → Cole o JSON do fluxo.

Lógica de Alarme (Switch Node)

A conversão de string para número é feita com:

Change Node
msg.payload = $number(payload)

Em seguida, o Switch avalia:

Condição	Estado	Ação
msg.payload < 10	CRÍTICO	Define "CRÍTICO" no payload
msg.payload <= 30	BAIXO	Define "BAIXO" no payload
otherwise	NORMAL	Define "NORMAL" no payload

O valor numérico também alimenta o gauge e o gráfico em tempo real.

🖥️ Interface

O dashboard inclui:

Gauge com faixa de 0% a 100%.

Gráfico histórico.

Indicador visual de alarme.

📦 Estrutura do Repositório
/
├── firmware/
│   └── esp32_tank_monitor.ino
├── node_red_flow/
│   └── node_red_flow.json
└── README.md

✔️ Objetivo

Este projeto demonstra integração completa entre hardware embarcado, comunicação MQTT e supervisão com Node-RED, servindo como base para aplicações industriais, portfólio profissional e evolução futura para sistemas SCADA ou IIoT mais complexos.
