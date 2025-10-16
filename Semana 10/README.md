# Semana 10

Trabajar con Datos de GPS.

Visualización de datos, es recoger la info, y mostrarla de forma atractiva. La tabla de excel, cuando se ve desplehada en maps, se ve que más puede ser, un movimiento. 
Artista Brayan Armestren. Sonidos con codificación de datos del cerro Santa Lucía. 


En una tabla de registro de info, se tiene variables, donde las categorías serían por ejemplo; Tiempo/Dato1/Dato2. Siendo Dato 1 T° y Dato 2 Agua caída. ;

Tiempo
16/10
17/10
18/10

Dato 1 °C
25
28
39

Dato 2 mm
0
0
0

Para esta tabla, el computador usa un formato el CSV (comma separated values), y ve esos valores con el formato:
tiempo,dato1,dato2
16/10,25,0
17/10,29,0
18/10,39,0

El sistema mide el tiempo en EPOCH o Unix, el POCH es donde los computadores saben la hora, donde crezca el numero en 1 segundo por cada unidad, entonces el 0 es el 1 de enero de 1970 a las 00:00:00 
En unix time se ve la ora en unidades del tiempo que da sido desde que se creo esté sistema. En esa fecha porque antes no habían computadores. Esto también lo usan los arduinos con el modulo RTC DS1302, con esto el arduino sabe el tiempo real, una vez, y luego lo toma por siempre. 

En la carpeta de la Clase 10 se encuentra subido el documento de Gabi sobre el GPS que tuvo ella grabando. Nos fijamos en la carpeta que dice locación. 

Google by maps, para subir mapas del GPS. Subiendo el archivo de locación. Tomar en cuenta latitud y longitud, y luego el tiempo que es lo distinto de cada muestra. Y con ello, se ve el recorrido que hizo Gabi. 

Psicogeográfico.
Situacionismo.

Isla Null es el 0 geográfico del mundo. En processing, el 0,0 está arriba en la izquierda. Se normaliza la longitud y la latitud para poder verla en el Processing, para que pueda aaparecer en el cuadro de Processing de la forma correspondiente, y no sea solo un pixel. Para ello, si tiene muchos decimales, se resta uno de los numeros por el mismo y el otro con la diferencia, y con regla de 3 se logra el mapeo. 

En el excel de drive, se tiene que separar por comas el excel que se sube, para tener la tabla a mapear. Con los datos, se calcula la latitud mínima y la longitud minima, para ello, hay una formula:  =min(:) estando toda la tabla como número y no como palabras.

Se crea columnas nuevas, de latitud desplaaza y longitud desplazada. Eso es utlizar la columna del valor - valor minimo, usando además el simbolo $ antes del valor minimo para solo usar solo ese valor para la resta del resto de las clumnas. 

=(B2-$G$2)

Y para hacer que se encuentren sobre el % entre 0 y 100, se busca lo mismo pero el numero máximo. =max(b:b).

Latitud y longitud normalizada. =(d2*100/$max)

