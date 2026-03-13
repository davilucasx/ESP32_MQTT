#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

const char* ssid = "NOME DA REDE";
const char* password = "SENHA";

const char* mqtt_broker = "URL BROKEN";
const int mqtt_port = 8883;
const char* mqtt_username = "USER";
const char* mqtt_password = "SENHA";

WiFiClientSecure espClient;
PubSubClient client(espClient);

void conectarMQTT() {

  while (!client.connected()) {

    Serial.println("Conectando MQTT...");

    if (client.connect("ESP32Client_01", mqtt_username, mqtt_password)) {
      Serial.println("MQTT conectado");
      client.subscribe("esp32/teste");
    } else {
      Serial.print("Erro: ");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);
  WiFiClient test;

if (test.connect("google.com", 80)) {
  Serial.println("Internet OK");
} else {
  Serial.println("Sem internet");
}

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado");

  espClient.setInsecure();

  client.setServer(mqtt_broker, mqtt_port);
}

void loop() {

  if (!client.connected()) {
    conectarMQTT();
  }

  client.loop();

  client.publish("esp32/teste", "Ola do ESP32");

  delay(5000);
}
