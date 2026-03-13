# ESP32 MQTT Communication

Simple IoT project using an ESP32 to connect to a WiFi network and communicate with an MQTT broker.

The ESP32 connects to the internet, establishes a secure MQTT connection, subscribes to a topic, and periodically publishes messages to it.

This project demonstrates the basics of **IoT communication using MQTT and ESP32**.

---

## 🚀 Features

* WiFi connection using ESP32
* Secure MQTT connection (TLS)
* MQTT topic subscription
* MQTT message publishing
* Automatic reconnection if MQTT disconnects
* Periodic message publishing every 5 seconds

---

## 🧰 Technologies

* **ESP32**
* **Arduino Framework**
* **MQTT Protocol**
* **HiveMQ Cloud**
* **WiFi Library (WiFi.h)**
* **WiFiClientSecure**
* **PubSubClient**

---

## 📡 System Architecture

```
ESP32  →  WiFi Network  →  MQTT Broker (HiveMQ Cloud)
   ↑                           ↓
Publish Message           Subscribe Topic
```

The ESP32 connects to the MQTT broker and both **publishes and subscribes** to the same topic.

---

## ⚙️ How It Works

1. The ESP32 connects to a WiFi network.
2. The device checks if the internet connection is available.
3. A secure TLS connection is established with the MQTT broker.
4. The ESP32 subscribes to the topic.
5. Every **5 seconds**, the ESP32 publishes a message to the topic.

---

## 📡 MQTT Configuration

Broker: HiveMQ Cloud
Port: **8883** (Secure MQTT)

Topic used:

```
esp32/teste
```

Published message:

```
Ola do ESP32
```

---

## 📚 Libraries Used

The following libraries are required:

```
WiFi.h
WiFiClientSecure.h
PubSubClient.h
```

You can install **PubSubClient** through the Arduino Library Manager.

---

## ▶️ How to Run

1. Install the required libraries in Arduino IDE.
2. Connect your **ESP32** to your computer.
3. Configure your WiFi credentials in the code:

```
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
```

4. Configure your MQTT broker credentials.
5. Upload the code to the ESP32.
6. Open the **Serial Monitor** to see the connection logs.

---

## 👨‍💻 Author

Developed as a study project to learn **ESP32 IoT communication using MQTT**.
