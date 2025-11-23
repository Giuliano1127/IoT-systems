
### 3. Supervisão (Node-RED)
- Dashboard com Gauge e Chart.
- Lógica de alarme usando apenas os nós **Change** e **Switch**.
- Fluxo sem uso de Function Node.

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

### Ajuste das credenciais

```cpp
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";
const char* mqtt_server = "broker.hivemq.com";
