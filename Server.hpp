#include <ESP8266mDNS.h>
//Función que conecta el servidor a la red WiFi.
void connectServer(){
  //Cambia el nombre del dispositivo.
  WiFi.hostname(hostname);
  //Conecta el dispositivo a la red.
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.print("\nConexión exitosa: ");
  Serial.print(WiFi.localIP());
}

//Función que activa el acceso por nombre del dominio.
void InitMDNS(){
  if (!MDNS.begin("monitor")){             
    Serial.println("Error iniciando mDNS");
  }
  Serial.println("mDNS iniciado");
}
