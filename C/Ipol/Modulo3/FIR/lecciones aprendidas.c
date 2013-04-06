se vio que la salida no coincidia con lo esperado, se vio que el buffer se llenaba de manera correcta.
        Después de la primera iteración coefsLocales[0] se modificaba. Esto se debia a que cuando se inicializaba el buffer se llenaban mas lugares de los necesarios. 
        Como las variables son contiguas en memoria el valor del buffer que estaba fuera de rango modificaba el coefsLocales[0].
