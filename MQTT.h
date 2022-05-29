#include <WiFi.h>
  WiFiClient ESP32_WIFI;  

#include <PubSubClient.h>
  PubSubClient client ( ESP32_WIFI );
const char* HOTSPOT_WIFI = "INFINITUM200F_2.4";
const char* HOTSPOT_PWD = "57XDGa93J9";  
const char* MQTT_SERVER = "test.mosquitto.org";
#define MQTT_PORT 1883
#define TOPIC "/6A/HOUSE/GARDEN" // IDENTICADOR DONDE SE RECIBE MENSAJES//

class MQTT {
  
  public:
  public:
    void subscribe_MQTT ( void ); //que es //
    void publish_MQTT ( void );   //que es // publicar y subcribirse 
    void reconnect_MQTT ( void ); //que es //
    void setup_WiFi ( void ); //configura el wifi//
    void set_MQTT_server ( void ); // configura el servidor mqtt//
  };

void MQTT :: set_MQTT_server ( void ) {

  client.setServer ( MQTT_SERVER, MQTT_PORT );
  
}

void MQTT :: subscribe_MQTT ( void ) {

  
}

void MQTT :: publish_MQTT ( void ) {

  String hola = "Es más dura la verdura";
  Serial.println ( "Publicando información" );
  client.publish( TOPIC, MSD.json_string.c_str());// que hace la funcion c_st//
  
}

void MQTT :: reconnect_MQTT ( void ) {
                                                  
  if ( ! client.connected ( ) ) {         // explicar la sentencia if while//

    while ( ! client.connected ( ) ) {
      
    Serial.print ( "Conectado nuevamente al servidor" );

    if ( client.connect ( "6A/E1" ) ) {       // A que se da como como nombre "6A/E1"//
      
      Serial.println ( "Cliente conectado" );   // imprime por el puerto serial//
      
      //client.subscribe("esp32/output");
      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
  }
  client.loop();
  
}

void MQTT :: setup_WiFi ( void ) {

  delay ( 10 );
  Serial.println ( "Configurando WiFi: " );
  WiFi.begin ( HOTSPOT_WIFI, HOTSPOT_PWD );
  
  
  while ( WiFi.status ( ) != WL_CONNECTED ) {
    
    delay ( 500 );
    Serial.print ( "." );
    
  }
  
  Serial.println ( "WiFi configurado con la IP: " );
  
}
