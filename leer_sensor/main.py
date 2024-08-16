"""
Lectura de un Fotosensor con Python

En este proyecto, utilizaremos una fotoresistencia (LDR) para medir la intensidad de luz en el entorno.
Los datos obtenidos de la LDR serán recolectados y almacenados en una lista.
Posteriormente, visualizaremos estos datos mediante gráficos usando la librería matplotlib en Python. 
Esto nos permitirá analizar cómo cambia la intensidad de la luz a lo largo del tiempo.

Autor: Alexevrep
Fecha: 16/08/2024
Más contenido interesante en:
    -Github: https://github.com/alexdevrep
    -Instagram: https://www.instagram.com/alexdevrep/
    -WordPress: https://eltallerdealexdevrep.com
    -Youtube: https://www.youtube.com/channel/UCNlqgVY-CaQ2Lgc5xJChaKA

"""
#importamos las dependencias 
import matplotlib.pyplot as plt
import serial
import time 

# Iniciamos la conexión serial con el Arduino
arduino = serial.Serial("COM5", 9600,timeout=1)  

# Esperamos para que el Arduino se inicialice
time.sleep(2)

#Creamos una lista para almacenar todos los valores 
lista_valores=[]
#Recibimos los 30 primeros valores medidos por arduino y lo incluimos en una lista
for i  in range (1,31):
    if arduino.in_waiting >0:
        sensor_value = arduino.readline().decode('utf-8').strip()
        sensor_value=int(sensor_value)
    
    lista_valores.append(sensor_value)
    print(sensor_value)
    time.sleep(0.5)

print(lista_valores)
    
    
    

   

#Cerramos la comunicación serial con Arduino
arduino.close()
