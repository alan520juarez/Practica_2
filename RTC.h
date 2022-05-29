class DS1307_RTC {
  public:
     uint8_t hora, minuto, segundo, dia, mes, wday;
     uint16_t ano;
     String fecha, tiempo;
  public:
  void rtc_init ( void );
  void get_time ( void );
  void get_format_time ( void );
  void get_format_date ( void );
  }; 

void DS1307_RTC::rtc_init ( void ) {

   while ( ! rtc.begin ( ) ) {
    
        Serial.println ( F ( "Hay un error de reconocimiento del RTC, revisa conexiones y alimentación" ) );
        delay(10);
        
    }
    
    Serial.println ( F ( "El RTC se iniciado correctamente" ) );
    
  
}
void DS1307_RTC::get_time ( void ) {

  DateTime now = rtc.now();
  ano = now.year ( );
  mes = now.month ( );
  dia = now.day ( );
  hora = now.hour ( ) ;
  minuto = now.minute ( );
  segundo = now.second ( );
  
}
void DS1307_RTC::get_format_date ( void ) {
  
  get_time ( );
  fecha = "";
  if ( dia < 10 ) fecha += '0';
  fecha += dia;
  fecha += '/';
  if ( mes < 10 ) fecha += '0';
  fecha += mes;
  fecha += '/';
  fecha += ano;
  
}
  
void DS1307_RTC::get_format_time ( void ) {

  get_time ( );
  tiempo = "";
  if ( hora < 10 ) tiempo += '0';
    tiempo += hora;
    tiempo += ':';
  
  if ( minuto < 10 ) tiempo += '0';
    tiempo += minuto;
    tiempo += ':';
  
  if ( segundo < 10 ) tiempo += '0';
    tiempo += segundo;
    
}
