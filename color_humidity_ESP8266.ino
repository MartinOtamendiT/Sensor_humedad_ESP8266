#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebSrv.h>
#include "config.h"
#include "templates.h"
#include "Server.hpp"
#include <ESP8266mDNS.h>

//Creación del objeto servidor.
AsyncWebServer server(80);

int sensorHumedad = A0;
float h = 0.0;
// Guardará el tiempo en que se actualizó por última vez el sensor.
unsigned long previousMillis = 0;    
//Actualiza la lectura del sensor cada 10 segundos.
const long interval = 10000;  

// Reemplaza %HUMIDITY% del HTML con el valor leído.
String processor(const String& var){
  Serial.println(var);
  if(var == "HUMIDITY"){
    return String(h);
  }
  return String();
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(sensorHumedad, INPUT);
  Serial.begin(115200);
  //Se configura la placa en modo Estación.
  WiFi.mode(WIFI_STA); 
  //Se conecta el servidor en la red.
  connectServer();
  
  //Ruta para el directorio raíz
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_mini_html, processor);
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(h).c_str());
  });

  //Inicializa el server.
  server.begin();
}


void loop() {
  //Led que parpadea.
  digitalWrite(2, HIGH); 
  delay(1000);
  digitalWrite(2, LOW);
  delay(1000);
  //Obtiene el tiempo actual.     
  unsigned long currentMillis = millis();
  //Si se cumple el intervalo de 10 segundos, actualiza valores.
  if (currentMillis - previousMillis >= interval) {
    // Guarda el último tiempo de actualización del sensor.
    previousMillis = currentMillis;
    // Lee el valor del sensor de humedad.
    float newH = analogRead(sensorHumedad);
    // Si la lectura falla, el valor no es cambiado y se notifica en el servidor (Arduino).
    if (isnan(newH)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      //Mapeo de valores de 0-1024 a 0-100. Considerando que 1024 indica un ambiente seco.
      h = map(newH, 0, 1024, 100, -1);
      Serial.println(h);
    }
  }
}
