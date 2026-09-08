### Dokumentation


Weitere Informationen unter folgendem Link verfügbar: https://github.com/OpenKNX/OFM-ADCInput

Mit dem Modul für ADC-Eingänge erlaubt Analoge Messwerte einzulesen. 

Es kann zwischen Spannungswerten und Stromwerten unterschieden werden.

ACHTUNG: Es kann vorkommen, dass hier mehr Kanäle angezeigt werden, als in der Hardware zur Verfügung stehen. Die zusätzlichen Kanäle können dann ignoriert werden.  

WICHITG: Wenn 4-20mA Eingänge erforderlich sind, dann muss der jeweilige ADC-Kanal in der HW angepasst werden !!! 
Eine Anleitung dazu findet man hier: https://github.com/OpenKNX/OFM-ADCInput/tree/v1/doc


#### Zur Vorauswahl stehen:

##### inaktiv
Damit wird der Kanal deaktiviert. 

##### ADC-Wert (mV)
Hier kann man sich den Analogwert einlesen lassen und dazu sich den Wert auch gleich passend umwandeln lassen. D.h. wenn man einen analogen Temperatursensor anschließt, kann man hier später in den Kanaleinstellungen den passenden Ausgangs DPT wählen und eine Kennlinie des Sensors hinterlegen. 
Damit bekommt man direkt den Temperatur-Wert des Sensors ausgegeben. 

##### SMT50-Feuchte
Wenn ein SMT50 Bodenfeuchte-Sensor verwendet wird, kann man sich die ganzen Einstellungen mit DPT und Kennlinie sparen. Hier muss man sich nur noch um das Senden kümmern und das KO verbinden. 

#### SMT50-Temp
Wenn ein SMT50 Bodenfeuchte-Sensor verwendet wird, kann man sich die ganzen Einstellungen mit DPT und Kennlinie sparen. Hier muss man sich nur noch um das Senden kümmern und das KO verbinden.

#### 4-20mA
Hier kann man sich den Stromwert einlesen lassen und dazu sich den Wert auch gleich passend umwandeln lassen. D.h. wenn man einen 4-20mA Sensor anschließt, kann man hier später in den Kanaleinstellungen den passenden Ausgangs DPT wählen und eine Kennlinie des Sensors hinterlegen. 
Damit bekommt man direkt den passenden Wert des Sensors ausgegeben. 

#### 4-20mA - Füllstand(TL-136)
Wenn man einen Füllstandsensor anbinden möchte, kann dieser hier direkt ausgewählt werden. In den Parametern muss nur noch die Messhöhe des Sensors eingetragen werden. Alle notwendigen Berechnungen dazu passieren automatisch im Hintergrund.



