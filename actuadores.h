class actuadores {
  public:
  bool servo_activo=false; //se crea una bandera//
 public:
  void servor_init ( void );
  void servor_i ( void );
  void pantalla_init ( void );
  void pantalla_i ( void );
  
  }; 

void actuadores::servor_init ( void ){
  servoMotor.attach(13);
  servoMotor.write(0);
}

void actuadores::servor_i ( void ){
  // Vamos a tener dos bucles uno para mover en sentido positivo y otro en sentido negativo
  // Para el sentido positivo
  servo_activo=true;
  for (int i = 0; i <= 180; i++)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(600);
  }
   // Para el sentido negativo
  for (int i = 179; i > 0; i--)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(600);
  }
  servo_activo=false;
}
void actuadores::pantalla_init ( void ){
  lcd.init();//inicializar la pantalla lcd
  lcd.backlight();//Encender la luz de fondo
  
}
void actuadores::pantalla_i ( void ){
  if(servo_activo){
    lcd.setCursor (0, 3);//poner el cursor en las coordenadas (x,y)
  lcd.print("Rellenando..");//muestra en la pantalla max 20 caracteres
  }
  else{
    lcd.setCursor (0, 3);//poner el cursor en las coordenadas (x,y)
  lcd.print("Surtido");//muestra en la pantalla max 20 caracteres
  }
  //La funcion millis() regresa los ms que lleva encendido
  //Lo dividimos entre 1000 para que nos muestre en segundos.
  lcd.print(millis()/1000);
  lcd.print("s");
  delay(1000);//Esperamos 1 segundo antes de repetir el loop
}
