"""
Este script en Python establece una comunicación serial con un Arduino
conectado al puerto COM5 a una velocidad de 9600 baudios. El objetivo
es recibir y mostrar en la consola los datos enviados por el Arduino
cuando se presionan dos botones físicos conectados al mismo.

El Arduino envía un valor "1" cuando se presiona el botón de "marcha" 
y un valor "0" cuando se presiona el botón de "paro". Estos valores 
son leídos y decodificados por este script y luego se imprimen en la 
consola para su visualización.

El programa permanece en un bucle infinito leyendo los datos entrantes 
hasta que se interrumpe manualmente (por ejemplo, con Ctrl+C). Cuando 
se detecta una interrupción, el script cierra la conexión serial de 
forma segura antes de terminar.

Autor: Alexdevrep
Fecha:04/09/2024
Más contenido interesante en :
    -GitHub: https://www.github.com/alexdevrep
    -Instagram: https://www.instagram.com/alexdevrep/
    -Mi blog de WordPress: https://www.eltallerdealexdevrep.com/
    -Youtube: https://www.youtube.com/channel/UCNlqgVY-CaQ2Lgc5xJChaKA
"""
#Importamos las librerías necesarias
import serial
import time 
from pymodbus.client import ModbusTcpClient

#Inicializamos la comunicación con Arduino
arduino= serial.Serial('COM5',9600)

#Instanciamos un objeto de la clase Modbus
PLC =ModbusTcpClient("127.0.0.1")

#Nos conectamos al PLC 
PLC.connect()

#Esperamos a que el Arduino se inicie
time.sleep(2)

#Definimos el código de control principal
try:
    while True:
        #Recibimos los datos desde la comnunicación serial
        if arduino.in_waiting >0:
            valor=arduino.readline().decode('utf-8').strip()
            valor=int(valor)
            #Controlamos el comportamiento de la cinta en función del valor recibido
            if valor == 1:
                registro= PLC.write_coils(0,True,1)
            elif valor ==0:
                registro=PLC.write_coils(0,False,1)
        
        time.sleep(1)

#definimos como salir del bucle
except KeyboardInterrupt:
    print("Conexión con Arduino finalizada")

#Cerramos la conexión con Arduino
finally:
    arduino.close()










