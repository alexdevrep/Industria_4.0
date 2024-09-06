/*
  Control de cinta transportadora con Arduino y Python

  Este código controla el estado de dos pulsadores, en caso 
  de que uno de los dos sea accionado se imprime a través del puerto
  serie un 1 o un 0 en función del botón accionado.

  Autor: Alexdevrep
  Fecha: 6/9/2024
  Más contenido interesante en:
    -GitHub: https://www.github.com/alexdevrep
    -Instagram:   @alexdevrep  
    -Mi blog de WordPress: https://www.eltallerdealexdevrep.com/
    -Youtube:   @alexdevrep  

*/
// Declaración de variables
const int marcha = 8;
const int paro = 9;

int estadoAnteriorMarcha = LOW;
int estadoAnteriorParo = LOW;

void setup() {
  // Definimos los pines como entrada digital
  pinMode(marcha, INPUT);
  pinMode(paro, INPUT);

  // Inicializamos la comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Leemos los valores de ambos botones
  int estadoMarcha = digitalRead(marcha);
  int estadoParo = digitalRead(paro);

  // Detecta cuando el botón de marcha se presiona por primera vez
  if (estadoMarcha == HIGH && estadoAnteriorMarcha == LOW) {
    Serial.println("1");
  }

  // Detecta cuando el botón de paro se presiona por primera vez
  if (estadoParo == HIGH && estadoAnteriorParo == LOW) {
    Serial.println("0");
  }

  // Actualizamos el estado anterior con el estado actual
  estadoAnteriorMarcha = estadoMarcha;
  estadoAnteriorParo = estadoParo;
}

  


