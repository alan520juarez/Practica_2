/*****************************************************************************
*                                                                            *
*      NOMBRE:      Dispensador digital.                                              *
*      FECHA:       30 de  de mayo 2022.                                     *
*      VERSIÓN:     1.0.                                                     *
*                                                                            *
*      AUTOR:       Esli Castellanos Berján
*      Integrantes: Alan Estrada Juarez
*                   AngeL Antonio Alvarez Estrada.                           *
*      E-MAIL:      esli_castellanos@ucol.mx.                                *
*      FACULTAD:    Telemática.                                              *      
*      CARRERA:     Ingeniería en Tecnologías de Internet.                   *
*      MATERIA:     Sistemas embebidos para el Internet de las cosas.        *
*                                                                            *
*      MICROCONTROLADOR:          Xtensa® dual­core 32­bit LX7.              *
*      MARCA COMERCIAL:           ESP32.                                     *
*                                                                            *
*                                                                            *
******************************************************************************
*                                                                            *
*      DESCRIPCIÓN DEL PROGRAMA:                                             *
*      Arquitectura de software para implementar un datalogger mediante el   *       
*      uso del módulo de lectura MicroSD y un reloj en tiempo real.          *
*                                                                            *
*      DETALLES:                                                             *
*      RTC:        DS1307.                                                   *
*      MicroSD:    Genérico.                                                 *
*                                                                            *
******************************************************************************/ 
#define MICROSD_PIN 5         //aprender las librerias y los protocolos de los sensores//
#define EXTENSION ".json"
#include <ArduinoJson.h>
#include <SD.h>   //Memoriasd//que es RTC// que LCD//
#include <SPI.h>  //microsd//
#include <Wire.h> // i2C//
#include "RTClib.h"// LIBRERIA DE RELOJ
 RTC_DS1307 rtc; // APRENDERSE EL NOMBRE DEL RELOJ/PROTOCOLO BASCULA SERVO//
#include <ESP32Servo.h> //LIBRERIA SERVO//
Servo servoMotor;
#include <LiquidCrystal_I2C.h>  //libreria de lcd//
LiquidCrystal_I2C lcd(0x27, 20, 4);//crear un objeto lcd (DIRECCIÓN pantalla, Tamaño x, Tamño y)

File MicroSD_File; 

#include "RTC.h"
  DS1307_RTC RTC;

#include "actuadores.h"
 actuadores actuador;
 

#include "MicroSD.h"
  MicroSD MSD;
