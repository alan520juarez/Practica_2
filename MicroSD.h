class MicroSD {
  public:     // diferencias metodo public y privado//
    String filename = "", json_string = "";
    
  public:
  void MicroSD_init ( void );
  void FileID ( void );
  void JSON ( void );
  void JSON_SaveFile ( DynamicJsonDocument *); // Que se significa el *//


  
  }; 

void MicroSD::MicroSD_init ( void ){

  while (!SD.begin(MICROSD_PIN)) {      // que significa la sentencia//
    Serial.println( F("Falló la inicialización del módulo MicroSD")); // que significa La F mayucula//
 
  }
  Serial.println ( F ( "La librería MicroSD se ha inicializado con éxito" ) );
  
}
void MicroSD::FileID ( void ){

  RTC.get_time ( );
  filename = '/';   // Que significa la "/" para que se utiliza la funcion fileID//
  if ( RTC.dia < 10 ) filename += '0';
  filename += RTC.dia;
  filename += '-';
   if ( RTC.mes < 10 ) filename += '0';
  filename += RTC.mes;
  filename += '-';
  filename += RTC.ano;
  filename += EXTENSION;    //De que como es la extension del archivo//
  
}

void MicroSD::JSON ( void ){

  DynamicJsonDocument obj(1024); // tamaño del buffer//
 
  obj["Cantida de alimento"] = "";// PONER LA VARIABLE DE ALIMENTO 
  RTC.get_format_date( ); // para que se usan get_format_date//
  RTC.get_format_time( ); // " "//
  obj["Fecha"] = RTC.fecha.c_str();
  obj["Tiempo"] = RTC.tiempo.c_str();
  JSON_SaveFile ( &obj ); // Direccion de memoria//
}

void MicroSD::JSON_SaveFile (  DynamicJsonDocument * obj){

  FileID ( );
  json_string = "";
  MicroSD_File = SD.open ( filename, FILE_APPEND );
  if ( MicroSD_File ) {
    
    serializeJson(*obj, json_string); //que hace  serializeJson//
    MicroSD_File.print ( json_string ); // que aguarda json_string//
    MicroSD_File.println ( "," );
    MicroSD_File.close ( );
  }
}
