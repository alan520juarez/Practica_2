#include "DataLogger.h"
#include "MQTT.h"
MQTT mqtt;      // que signfica "Message Queuing Telemetry Transport"
#include "Task.h"
Task tsk;

void setup() {
  
Serial.begin(115200); //"Baud rate"el numero de unidades de señales por segundo//
  
  mqtt.setup_WiFi ( );
  mqtt.set_MQTT_server ( );
  client.setCallback(callback);
  MSD.MicroSD_init ( );
  RTC.rtc_init ( );
  actuador.servor_init ( );
  actuador.pantalla_init ( );
  
  }

void loop ( ) {

 tsk.currentMillis = millis( );   // millis() devuelve el número de milisegundos desde que la placa,
                                    //Arduino empezó a ejecutar, luego de un reinicio o el encendido//
  tsk._10s(); 

  tsk._20s();

  tsk._30s();

 
  // put your main code here, to run repeatedly:

}
//callback Los callbacks aseguran que una función no se va a 
//ejecutar antes de que se complete una tarea, sino que se ejecutará justo después de que la tarea se haya completado//
void callback(char* topic, byte* message, unsigned int length) { // recibe todas la tramas del subscribe// para que sirve callback//
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic esp32/output, you check if the message is either "on" or "off". 
  // Changes the output state according to the message
  if (String(topic) == "6D/subscribe") {
    Serial.print("Changing output to ");
    if(messageTemp == "on"){
      Serial.println("on");
       actuador.servor_i ( );
    }
    else if(messageTemp == "off"){
      Serial.println("off");
      
    }
  }
}
