#define pulso 10 //se define el pin digital 10 como la salida del pulso
#define entradaAC A0 //se define el pin analalógico A0 como la entrada para la onda rectificada

int lectura = 0; //variable para leer la entrada analogica 
int duracion =  65; //variable para el tiempo en alto de la señal, 130 para el punto 3 y 65 para el punto 4

void setup() {
pinMode(pulso, OUTPUT); // se define pulso como salida
pinMode(entradaAC, INPUT); // se define entradaAC como entrada
}

void loop() {
lectura = analogRead(entradaAC); //se lee la señal analógica y se asgina a lectura
if (lectura <= 10){ //se toma como valor de cruce por cero cualquier lectura menor a 48mV, 10 es el equivalente en Arduino para esa lectura
digitalWrite(pulso, HIGH); // se activa el pulso
delay(duracion);
digitalWrite(pulso, LOW);  // se desactiva el pulso
}
delay(20); //delay para disminuir la frecuencia de repetición del ciclo y tener más claridad en el osciloscopio
}
