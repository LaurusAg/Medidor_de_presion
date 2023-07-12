/***********Codigo para lectura de presion con sensor analogico**************/

// DECLARACION DE VARIABLES, Explicadas: 

int sensor; //Variable para guardar el valor del sensor pasado por el adc.
float v; //Conversion del valor leído a la escala del voltaje.
float p;    //Variable para alojar el mapeo de la presion. 

//Funcion de mapeo para transferencia de valor de presion:

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) *(out_max - out_min) / (in_max - in_min) + out_min ; 
}

//Variables para la implementacion de un timer para modificacion rapida de tiempo de lectura de manera no bloqueante:

unsigned long last_measurement = 0;   //variable para flag de tiempo.
const int measurement_period = 30000; //Periodo en milisegundos


void setup() {
    Serial.begin(9600);
    Serial.println("Medicion N°2. toma de datos cada 30 segundos por 30 minutos.");
}


void loop() {

  //if( millis() - last_measurement > measurement_period ) {
    
    sensor = analogRead(A0);
  delay(10);
    v = sensor * 5.0 / 1023.0;
  delay(10);
    p=mapfloat(v, 0.2, 5, 0.0, 3500.0);

        //utilizar para el data streamer de excel:
    Serial.print(v);
    Serial.print(",");
    Serial.print(sensor);
    Serial.print(",");
    Serial.print(p);
    Serial.println();

    /* Descomentar para ver en monitor serial de manera interpretable:
   Serial.print("El valor de tension en el sensor es: ");
    Serial.print(v);
    Serial.print(" (");
    Serial.print(sensor);
    Serial.println(" )");

    Serial.print("El valor de presion es: ");
    Serial.print(p);
    Serial.println(" pascal");*/

    //last_measurement = millis();
  //}
delay(3500);
}
