### Hardware-Version

In der HW-Version 4.2 gibt es leider unterschiedliche Bestückvarianten. 

Standard sollte eigentlich 0-12V sein.
Bei manchen Sensormodulen "außen" wurde ein falscher Widerstandswert bestückt.
Damit ändert sich die Umrechnung und der ADC-Range. 
Man kann die Unterschiede leider nicht sehen. Man sieht es nur an den real ausgegebenen Werten. 
Wenn die ausgegeben Werte deutliche Abweichungen zeigen, dann solltet ihr hier mal die andere Einstellung ausprobieren. 
Eine von beiden wird aber funktionieren. 

Dieser Parameter ist nur relevant für ADC-Spannungswerte. Wenn man reine 4-20mA Eingänge hat, dann ist es egal wie dieser Parameter gesetzt wurde. 




