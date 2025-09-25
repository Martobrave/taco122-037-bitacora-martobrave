### Semana 06

Pseudocódigo, es la escrito de codigos sueltos para tener una idea de lo que se quiere llegar.
Pensando en una caja negra, tenemos un input (sensor), y un ouput (actuador), y lo que se quiere es tener una información del mujnod y aplicarla ne algo. Cuando se tiene un fenómero a medir, como la luz, se requiere de un sensor, que va a la caja negra, y lo convierte en una señal, en electricidad, y esa electricidad es recibida en el emciroconrolador, que en su interior lo reinterpreta como información. Y este sensor se guarda como información en una variable, y luego con esa informaciión uso la variable, y con ello llego a un output, y luego puede llegar a un driver o a un interfaz, que lleve al actuador, que se va a transformar en un nuevo fenómeno; movimiento, luz, sonido, etc.


En Arduino:


Se tiene que primero declarar las variables, en donde definir las infos nuevas a guardar, y además la información que se va a utilizar. Se necesita saber primero el tipo de variable. Es ideal inicialiae las variables con algun numero con int, string palabras, si es con comas usar float, si son si o no se usa bool. El Set Up sería para inicializar, y con ello lo hacemos con el Serial.begin (9600). Decidimos si los pines van a ser input o outputs, en donde se recibe, y así se ocupan cosas como pinMode. Recordar que los analogIN son solop de entrada, no salida.


Para el caso del loop, podríamos usar un potenciómetro, y para eso, hay que decir en donde queremos guardar el valor, pero primero, en donde lo recibo, entonces se usa una variable para guardar la información, en donde podemos colocar arriba int informaciónm en donde dejaremos esa información. Ahí podemos usar AnalogRead, en donde podemos colocarlo como información. Eneotnces información = analogRead (A0);, y así se tiene guardada la información.

También uno tiene que actualizar, operar, preguntar la información que estoy recibienindo, tipo es mayor o menor que otra cosa, proporcional, a otro rango, quiero saber en que lugar está. Quiero saber si es mayor o menor que un umbral, entonces ahí coloco If (informaicón >=umbral), siendo int umbral=100;, y si no lo es, colocar else otra cosa. De esta forma, recibo la infomracipon, la admnistro y la uso, y la puedo ver con el display pantallita para verlo ahí. 
