#ifndef Task_h
#define Task_h

/*
 * Clase Task
 * Administra las tareas que conforman el funcionamineto principal del programa.
 */

class Task  {
  
  public:
  
  unsigned long task_10s = 0,                       // Tiempo estimado para la tarea de 10 segundos.
                task_20s = 0,                       // Tiempo estimado para la tarea de 20 segundos.
                task_30s = 0,                       // Tiempo estimado para el servo
                currentMillis = 0;                 // Tiempo actual Arduino.
  public:
  
    void _10s ( void );   //cambiar nombre de tarea que realiza//
    void _20s ( void );
    void _30s (void );
};

void Task::_10s( void )  {

  if ( ( currentMillis - task_10s ) >= 10000 ) {
    
     Serial.println("Esta es la tarea 1");
      MSD.JSON ( );
      task_10s = currentMillis;
      
   }
  
}

void Task::_20s( void )  {


  if ( ( currentMillis - task_20s ) >= 20000 ) {
    
     Serial.println("Esta es la tarea 2");
      mqtt.reconnect_MQTT ( );
      mqtt.publish_MQTT ( );
      task_20s = currentMillis;
      
   }
  
}
void Task::_30s( void )  {

  if ( ( currentMillis - task_30s ) >= 5000 ) {
    
     Serial.println("Esta es la tarea del servo");
     /* actuador.servor_i ( );*/
     actuador.pantalla_i ( );
      task_30s = currentMillis;
      
   }
  
}



#endif
