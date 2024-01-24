#define pulso 10 //se define el pin digital 10 como la salida del pulso
#define entradaAC A3 //se define el pin analalógico A3 como la entrada para la señal del poteciometro

int lectura = 0; //variable para leer la entrada analogica 
int alto = 0;  //variable para el tiempo en alto
int bajo = 0; //variable para el tiempo en bajo

void setup() {
pinMode(pulso, OUTPUT); // se define pulso como salida
pinMode(entradaAC, INPUT); // se define entradaAC como entrada
}

void loop() {
lectura = analogRead(entradaAC); //se lee el pin analógico y se asigna a la variable
alto=2000-lectura*54; //operacion para determinar el tiempo en alto basada en el valor del potenciometro y la tensión de la fuente que alimenta al potenciometro
 bajo=2000-alto;  //asignacion del tiempo en bajo
 digitalWrite(pulso, HIGH);  //inicio del pulso 
delay(alto); 
if (bajo !=0){
digitalWrite(pulso, LOW);  //inicio del pulso en bajo, solo baja el pulso si el tiempo bajo es diferente de 0
}
delay(bajo);
}
