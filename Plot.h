#ifndef THE_HERETIC_PLOT_H
#define THE_HERETIC_PLOT_H

#include "Player.h"

void inputcontinue(int *n);
int skipstory(int *skip);
void Story_0(Player *player);
void Story_01();
void Story_1();
void Story_2();
void Story_3();
void Story_4();
void Story_5();
void Story_6();
void Story_7();
void Story_8();
void Story_9(Player *player);
void Story_10();
void Story_11();

void inputcontinue(int *n){
    printf("\n(1 para continuar)\n");
    scanf("%d", n);
    fflush(stdin);
    while (*n!=1){
        printf("\n(1 para continuar)\n");
        scanf("%d", n);
        fflush(stdin);
    }
}

int skipstory(int *skip){
    char c;
    printf("\nDeseas saltar la historia? S/N\n");
    scanf("%c", &c);
    while (c!='S' && c!='s' && c!='N' && c!='n'){
            printf("Ingrese una respuesta valida\n");
            scanf("%c", &c);
            fflush(stdin);
        }
    if (c=='S' || c=='s'){
        *skip = 1;
    } else {
        *skip = 0;
    }
    return *skip;
}

void Story_0(Player *player){
    printf("\nExiste un rumor de que, en el vasto oceano de la region, existe una edificacion conocida como la Torre del Olvido\n");
    delay(6);
    printf("\nInvisible para los ojos humanos, pero no para los seres divinos. Tu eres uno de ellos.\n");
    delay(4);
    printf("\nCual es tu nombre?\n");
    scanf("%s", player->name);
    fflush(stdin);
    delay(1);

    printf("\nAh, es verdad. Eres %s. Aquel que ha sido destinado a cumplir la profecia.\n\n", player->name);
    delay(4);
    printf("\n  'Quien logre llegar a la cuspide podra pedir un deseo al dios de la creacion'  \n\n");
    delay(4);
    printf("\nEsas fueron las palabras de las almas perdidas. Aquellas que vieron su final con el unico proposito de traerte aqui.\n");
    printf("Aquellas que empezaron tu aventura.\n");
    delay(6);
    printf("\nLa odisea de %s, hij@ de dios.\n\n\n\n", player->name);
    delay(5);
}

void Story_01() {
    int n;
    printf("\nLlegas a los pies de una torre majestuosa. Estas seguro que es la Torre del Olvido.\n");
    delay(3);
    printf("\nMiras directamente a la puerta. Un porton doble gigantesco, de roble reforzado y aproximadamente 10 metros.\n");
    delay(3);
    printf("\nSientes una inexplicable punzada cada vez que observas directamente a una grabacion en la puerta.\n");
    delay(4);
    printf("\nEl signo del cosmos.\n");
    delay(3);
    printf("\nNo divisas a nadie en las cercanias, pero no puedes dejar de pensar en la profecia\n");
    delay(3);
    printf("\n       Seis son los protectores del senor.");
    delay(3);
    printf(" Seis seran derrotados antes del fin de la historia.\n");
    delay(3);
    printf("\nDecides abrir las puertas empujandolas.\n");
    delay(3);
    printf("\nLentamente, empujas hasta que las puertas cedan hasta permitir tu entrada.");
    delay(3);
    printf("En el momento que pisas la entrada, puedes apreciar la inmensidad de la torre.\n");
    delay(3);
    printf("\nTe encuentras en el primer piso; rebosante de luz, cuya intensidad te brinda deseos de mirar hacia los demas pisos desde el centro.\n");
    delay(4);
    printf("\nSin embargo, la luz no persiste mas alla del primer piso. Por que sera?\n");
    delay(3);
    printf("\nEn ese instante, la puerta de entrada se cierra abruptamente, lo que te vuelve a tus sentidos.\n");
    delay(3);
    printf("\nPuedes sentir una presencia detras de ti.\n");
    delay(4);
    for(int t=0; t<3; t++){
        letter('.', 6);
    }
    printf("\n -No te parece medio criminal aparecer asi sin tocar el timbre? \n");
    delay(3);
    printf("\n -Bah, ya nadie tiene modales igual.\n\n");
    delay(3);
    printf("\nBrincas hacia atras y te das vuelta para poder ver la voz que te hablo\n");
    delay(2);
    printf("\n -Tranca, no te alarmes! Creo que te pegue un pequeno susto. Permitime presentarme!\n");
    delay(3);
    printf("\n -Um.. a decir verdad no tengo nombre. O bueno, la verdad es que no lo recuerdo. Pero no quiero hacerte dano!\n");
    delay(3);
    printf("\n -Lo unico que recuerdo es que alguien me trajo a esta torre, y me dio un proposito\n");
    delay(3);
    printf("\n -Ayudar al elegido.\n");
    delay(3);
    printf("\n -No tengo idea si sos vos, pero sos el primero en cruzar por esta puerta.\n");
    delay(3);
    printf("\n...\n");
    delay(3);
    printf("\n...\n");
    delay(3);
    printf("\n -No me crees, verdad? Bueno, parece que tendre que contarte mas..\n");
    delay(3);
    printf("\n -Adelante tuyo se encuentra el Primer Guardian. Subiendo las escaleras.\n");
    delay(2);
    printf("\n -Los guardianes son los protectores designados por el senor mismo, para protegerlo por toda la eternidad.\n");
    delay(4);
    printf("\n -Si quieres llegar al ultimo piso de esta torre, tendras que atravesarlos.\n");
    delay(3);
    printf("\n -Y pondran su vida en juego para impedirlo. Probablemente acaben con la tuya si lo consiguen.\n");
    delay(4);
    printf("\n -Tus poderes mortales no podran hacer nada contra ellos. Yo puedo ayudarte contra ellos.\n");
    delay(3);
    printf("\n...\n");
    delay(3);
    printf("\n -Y bien, que dices?\n\n");
    delay(4);
    printf("\nTe tomas un segundo para aclarar las cosas, pero sabes que tiene razon.\n");
    delay(3);
    printf("\nNecesitas toda la ayuda posible contra los guardianes.\n");
    delay(4);
    printf("\nLigeramente terco, aceptas su peticion.\n");
    delay(4);
    printf("\n-Buenisimo! Vamos a ello, entonces.\n");
    delay(2);
    inputcontinue(&n);
}

void Story_1(){
    int n;
    printf("\nTe dirijes hacia las gigantescas escaleras que conducen al siguiente piso.\n");
    delay(3);
    printf("\nEn el momento en el que estas a punto de poner un pie sobre la escalera, puedes verlo.\n");
    delay(4);
    printf("\nEl Primer Guardian.\n");
    delay(2);
    printf("\nPuedes reconocerlo. Su nombre es conocido..");
    delay(2);
    printf(" como EDU, El Extranjero.\n");
    delay(3);
    printf("\nUn mortal nacido en una tierra distante, caracterizada por su lenguaje retorcido y peligros tectonicos.\n");
    delay(4);
    printf("\nSegun cuenta la leyenda, EDU fue el ultimo de su civilizacion antes que su territorio fuera consumido por el mar.\n");
    delay(5);
    printf("\nJusto antes de su muerte, fue reclutado por el senor de la Torre, para convetirse en su protector.\n");
    delay(4);
    printf("\nEl Primer Guardian cubre el acceso al segundo piso, y se rige por los principios olvidados\n");
    delay(4);
    printf ("\n\n        |-| 'Nadie osara perturbar el santuario al final de la torre.' |-|\n");
    delay(4);
    printf("\nAqui comienza tu primer combate real. DERROTA AL PRIMER GUARDIAN !\n");
    delay(2);
    inputcontinue(&n);
    delay(2);
}

void Story_2(){
    int n;
    printf("\nContinuas tu camino hacia el segundo piso.\n"); /* Hacer que IERIGOL_1 enseñe sobre chance critica, evasion, ataque/defensa, etc */
    delay(3);
    printf("\nCuando llegas, notas que en la habitacion hay menos luz que en la anterior.\n");
    delay(4);
    printf("\nLos muebles tienen un color menos llamativo, pero siguen siendo igual de bellos.\n");
    delay(4);
    printf("\nPuedes apreciar que hay una pequena casita, como la de un perro.\n");
    delay(4);
    printf("\nEn eso, tambien ves al desconocido que te ha ayudado.\n");
    delay(4);
    printf("\n -Buenas! Parece que has vencido al Primer Guardian.\n");
    delay(4);
    printf("\n -Creo que tal vez tengas una oportunidad de llegar hasta arriba.\n");
    delay(4);
    printf("\n -Sin embargo, los Guardianes se vuelven cada vez mas fuertes conforme subas. \n");
    delay(4);
    printf(" \n-Debes asegurarte de aumentar tus fuerzas si quieres poder derrotarlos.\n");
    delay(4);
    printf("\n -Me dejarias ayudarte nuevamente?\n");
    delay(4);
    printf("\n.\n");
    delay(1);
    printf("\n.\n");
    delay(1);
    printf("\nSu apoyo ha sido invaluable. Asi que si, aceptas su ayuda.\n");
    delay(4);
    inputcontinue(&n);
}

void Story_3(){
    int n;
    printf("\nTe dirijes hacia las escaleras que conducen al tercer piso de la torre.\n");
    delay(4);
    printf("\nEn el momento en el que pisas el primer escalon, se escucha un feroz rugido mecanico de la casita.\n");
    delay(4);
    printf("\nLentamente, de ella sale una enorme criatura.\n");
    delay(4);
    printf("\nUna maquina con forma humana, pelaje y rasgos animales.\n");
    delay(4);
    printf("\nColmillos y garras metalizadas, un pelaje plateado como la luz de la luna, y.. anteojos?\n");
    delay(4);
    printf("\nLa leyenda entre los mortales hablaba de un hombre lobo, pero nunca nada como esto. \n");
    delay(4);
    printf("\nUna maquinacion que ni las leyendas hubiesen podido concebir.\n");
    delay(4);
    printf("\nPuedes leer que la casita tiene nombre; ");
    delay(3);
    printf("'Gabot, El Guardian Mecanico'.\n");
    delay(4);
    printf("\nSe ve reacio a dejarte pasar, pero sabes que debes avanzar.\n");
    delay(3);
    printf("\nPreparate para el combate!\n");
    delay(2);
    inputcontinue(&n);
}

void Story_4(){
    int n;
    printf("\nAntes de continuar, te asomas para poder observar el interior del guardian.\n");
    delay(4);
    printf("\nDescubres que, dentro de la maquina, algo lo estaba controlando.\n");
    delay(4);
    printf("\nUn hamster.\n");
    delay(4);
    printf("\nEs increible que hayas tenido que combatir contra un hamster. Y que haya estado tan cerca de matarte.\n");
    delay(4);
    printf("\nTe dirijes hacia el proximo piso, con la incertidumbre de quien sera el siguiente guardian.\n");
    delay(4);
    printf("\nY si el senor de la torre te estara viendo..\n");
    delay(4);
    inputcontinue(&n);
    printf("\n ...\n");
    delay(2);
    printf("\n -UN HAMSTER. Como es que.. mejor no quiero saberlo.\n");
    delay(4);
    printf("\n -Aunque no es tan raro como parece. No fueron ellos quienes crearon esa maquina de destruccion, claro..\n");
    delay(4);
    printf("\n -Pero si, eran los unicos capaces de controlarla, gracias a su pequeno tamano.\n");
    delay(4);
    printf("\n -Un poco de entrenamiento conductista y no es tan dificil lograr que un roedor accione palancas.\n");
    delay(4);
    printf("\n -Bueno, cosa del pasado. Lo importante ahora es que continues tu ascenso a la torre. \n");
    delay(4);
    printf("\n -Los proximos guardianes seran mas duros, te lo garantizo. Ven conmigo.\n");
    delay(4);
    inputcontinue(&n);
}

void Story_5(){
    int n;
    printf("\nLuego de tanta charla, subes al tercer piso.\n");
    delay(4);
    printf("\nUn aroma nocivo cubre la atmosfera de este piso. Una niebla espesa y verde amarillenta nubla tu vision.\n");
    delay(5);
    printf("\nEn el centro del piso ves un pedestal, con una antorcha que ilumina debilmente con su pequeno fuego.\n");
    delay(6);
    printf("\nDesde la plena espesura, sientes que algo se mueve alrededor tuyo. A una velocidad inimaginable..\n");
    delay(5);
    printf("\nEn un acto instintivo, logras tirarte al suelo para esquivar un proyectil a toda velocidad!\n");
    delay(5);
    printf("\nNo tardas tanto en recobrar tus sentidos, y darte cuenta que el piso es asi por una razon.\n");
    delay(5);
    printf("\nDebe ser el. El Tercer Guardian. Tox, El Destello Nuclear!  \n");
    delay(5);
    printf("\nVes que manifiesta una forma antropomorfica por unos segundos, disipando la densa niebla.\n");
    delay(5);
    printf("\nParece que estuvo esperando tu entrada. Preparate para luchar!\n");
    delay(2);
    inputcontinue(&n);
}

void Story_6(){
    int n;
    printf("\nReflexionas un breve momento sobre el mensaje.\n");
    delay(4);
    printf("\nEl fuego fatuo de la antorcha en el pedestal se ha consumido por completo. Probablemente debido a la derrota del guardian.\n");
    delay(5);
    printf("\nSera esta la oscuridad que premonitaba el guardian? O mas arriba existe algo mucho peor?\n");
    delay(4);
    printf("\nNo dejas que el miedo y la duda nuble tu confianza. Debes continuar..\n");
    delay(3);
    inputcontinue(&n);
    printf("\nLogras subir la escalera hasta el cuarto piso de la torre. El cuarto esta completamente a oscuras. Dificilmente puedes ver las escaleras al otro lado. \n");
    delay(5);
    printf("\nPero hay alguien a quien si logras ver.\n");
    delay(4);
    printf("\n -Lo lograste! Tus poderes aumentaron bastante, verdad?\n");
    delay(4);
    printf("\n -Ya has derrotado a 3 guardianes, cada vez estas mas cerca de la cima!\n");
    delay(4);
    printf("\n - ...es por eso que necesitas mi ayuda mas que nunca.\n");
    delay(4);
    printf("\n -Cuanto mas arriba estes en la torre, mas fuertes seran los guardianes que te encontraras.\n");
    delay(5);
    printf("\n -Sigamos. Tengo algunas cosas para ti.\n");
    delay(3);
    inputcontinue(&n);
}

void Story_7(){
    int n;
    printf("\nHabra recuperado algun conocimiento olvidado? Sera que darte poderes lo ha lastimado? O tal vez el senor de la torre lo ha castigado por ayudarte?\n");
    delay(7);
    printf("\nNo tienes tiempo para pensar en lo que le habra pasado al desconocido.\n");
    delay(4);
    printf("\nLa oscuridad reina en el piso. Cada paso que das retumba con las paredes de la torre. \n");
    delay(4);
    printf("\nHasta que divisas un brillo rojizo...\n");
    delay(5);
    printf("\nUna figura custodiando el pie de las escaleras hacia el cuarto piso. Entre sus manos agarra un espadon gigantesco. Mas que suficiente para reconocer quien es.\n");
    delay(8);
    printf("\n           'K, el caballero carmesi.'     \n");
    delay(4);
    printf("\nCuentan las historias que fue el lider de los paladines divinos, pero sus pecados terminaron por consumir su alma, borrando su nombre y existencia fisica.\n");
    delay(8);
    printf("\nDesterrado y sin rumbo como un alma perdida, fue reclutado por el senor de la torre. Ahora es uno de los fieles servidores de la torre del olvido.\n");
    delay(8);
    printf("\nDotado de poderes oscuros, su armadura no es la misma de antes.\n");
    delay(6);
    printf("\nCompletamente negra, posee ilustraciones remarcadas en un tono carmesi, producto de sus pecados pasados.\n");
    delay(6);
    printf("\nTodas las almas que ha juntado en su viaje pasado, se encuentran imbuidas en su mandoble, rebosante con una luz espectral intensa.\n");
    delay(6);
    printf("\nNo parece de los caballeros que otorgan piedad.\n");
    delay(4);
    printf("\nMientras apunta su mandoble hacia ti, descubres que tu destino esta mas en juego que nunca.\n");
    delay(5);
    printf("\nNo debes perder!\n");
    delay(2);
    inputcontinue(&n);
}

void Story_8(){
    int n;
    printf("\nHas derrotado al cuarto guardian, pero no habia nadie adentro de la armadura.\n");
    delay(4);
    printf("\nSera posible que al derrotarlo, hayas logrado remover la maldicion?\n");
    delay(5);
    printf("\nLa habitacion se vuelve mas luminosa. El vacio oscuro que la envolvia tambien se fue.\n");
    delay(6);
    printf("\nContinuas tu camino hacia las proximas escaleras.\n");
    delay(6);
    inputcontinue(&n);
    delay(2);
    printf("\nSubes al Quinto piso. Todos tus sentidos estan activos, en busca del proximo guardian.\n");
    delay(5);
    printf("\nPero.. esto es extrano.\n");
    delay(4);
    printf("\nLa habitacion esta cubierta de antorchas. Un estallido permanente de luz.\n");
    delay(6);
    printf("\nPero no hay rastros del guardian.\n");
    delay(5);
    printf("\nComo es posible? Todos los pisos hasta ahora tuvieron un guardian.\n");
    delay(6);
    printf("\nDecides explorar todo el piso en busca de pistas.\n");
    delay(6);
    printf("\nEncuentras manchas de polvo y rasguniaduras de un tamano enorme.\n");
    delay(6);
    printf("\nSin embargo, el guardian no parece encontrarse en ningun lado.\n");
    delay(6);
    printf("\nEso, no es solamente lo unico que te intriga.\n");
    delay(6);
    printf("\nDonde esta tu ayudante? Que le paso que no esta aqui contigo?\n");
    delay(7);
    printf("\nSiempre estuvo para ayudarte justo antes de un combate.\n");
    delay(6);
    printf("\nEs gracias a el que has logrado llegar hasta aqui.\n");
    delay(6);
    printf("\nAcaso.. el senor de la torre.. lo ha matado para que no subas?\n");
    delay(6);
    printf("\nComo haras para continuar sin el?\n");
    delay(6);
    printf("\n...\n");
    delay(3);
    printf("\nNo hay nada mas que hacer en este piso. Decides continuar tu camino.\n");
    delay(6);
    printf("\nLa cima esta cerca, puedes sentirlo. \n");
    delay(5);
    printf("\nPero a su vez puedes sentir una presencia amenazante inminente..\n");
    delay(4);
    inputcontinue(&n);
    delay(2);
    printf("\nSubes las escaleras lentamente, mirando de manera atenta a tus alrededores por si aparece el guardian.\n");
    delay(7);
    printf("\nJusto antes de poner pie en el Sexto piso, frenas subitamente y haces silencio absoluto.\n");
    delay(6);
    printf("\nDentro del Sexto piso, ves a un enorme dragon rojizo. Sus escamas reflejan la luminosidad de los tesoros alrededor suyo.\n");
    delay(8);
    printf("\nNunca se supo su nombre, pero si quien es.\n");
    delay(5);
    printf("\nEs conocido como la mascota del senor, y su mano derecha.\n");
    delay(6);
    printf("\nLogras percatarte que hay una pila de huesos al lado suyo, brillando monocromaticamente en distintos tonos violaceos. \n");
    delay(7);
    printf("\nPero un segundo, esos no eran huesos ordinarios.\n");
    delay(6);
    printf("\nSegun las leyendas, eran conocidos como los Huesos del legendario Mercenario.. 'Lauju'.\n");
    delay(5);
    printf("\nUn rufian macabro en busqueda de los mas grandes tesoros del mundo.\n");
    delay(5);
    printf("\nSin embargo, era sabido que era un mortal. Entonces, como es que sus huesos lograron entrar en la torre?\n");
    delay(6);
    printf("\nLa unica respuesta era la pieza que completaba el misterio.\n");
    delay(7);
    printf("\nLauju era el guardian del Quinto Piso\n");
    delay(6);
    printf("\nNublado por su avaricia, intento hacerse con los tesoros del dragon, y el resultado fue esa montanita de huesos.\n");
    delay(7);
    printf("\nPero.. todavia no hay rastro de tu ayudante.\n");
    delay(6);
    printf("\nRealmente habra desaparecido por siempre?\n");
    delay(6);
    printf("\n...\n");
    delay(6);
    printf("\nEl dragon aguarda, y sabes que debes derrotarlo para poder continuar.\n");
    delay(6);
    printf("\nPero podras derrotarlo sin su ayuda?\n");
    delay(5);
    printf("\nNo tienes alternativa. Tienes que hacerle frente. Es tu destino.\n");
    delay(7);
    printf("\nDecides salir de tu escondite detras de la columna, hacia el Dragon.\n");
    delay(6);
    printf("\nPero algo te esta tirando de vuelta hacia atras..?\n");
    delay(6);
    inputcontinue(&n);
}

void Story_9(Player *player){
    int n;
    printf("\nHaciendo caso a las palabras del mercader, decides intentar escabullirte para evitar la mirada del dragon.\n");
    delay(8);
    printf("\nVes una barricada, fina pero con una tela negra que puede servirte para tapar tu camino.\n");
    delay(7);
    printf("\nSigues lentamente por la barricada, hasta la mitad del piso.\n");
    delay(6);
    printf("\nEl dragon no parece sospechar nada, y ya estas a medio camino de la escalera.\n");
    delay(8);
    printf("\nPero la continuacion esta.. completamente al descubierto. Y no tienes nada con que camuflarte.\n");
    delay(8);
    printf("\nDecides caminar despacio y en cuclillas con el deseo de no alertarlo.\n");
    delay(8);
    printf("\nIntentas hacerte paso hacia el otro extremo de la habitacion, para llegar a las escaleras.\n");
    delay(7);
    printf("\n                                    |¬¬¬> Te estaba esperando, joven %s <¬¬¬|\n", player->name);
    delay(5);
    printf("\nPero el dragon supo desde un principio que ibas a llegar..\n");
    delay(6);
    printf("\nAunque nunca pensaste que un dragon pudiera hablar de forma tan cordial y correcta.\n");
    delay(6);
    printf("\n            |¬¬¬> Se que lograste derrotar a los guardianes anteriores. Estuve viendo cada paso tuyo desde tu llegada <¬¬¬|\n");
    delay(8);
    printf("\n            |¬¬¬> No necesitas esconderte. Supe que estabas aqui desde el momento en el que pisaste el primer escalon hacia este piso. <¬¬¬|\n");
    delay(8);
    printf("\n                       |¬¬¬> Si has llegado hasta aqui, no es para volver hacia atras verdad? <¬¬¬|\n");
    delay(7);
    printf("\n                |¬¬¬> En el proximo piso se encuentra la recamara de mi maestro, y el final de tu aventura. <¬¬¬|\n");
    delay(8);
    printf("\n                                |¬¬¬> Pero nunca llegaras vivo para apreciarlo. <¬¬¬|\n");
    delay(6);
    printf("\n               |¬¬¬> Nadie osara interrumpir a aquel que gobierna todo el cosmos. Marchate antes de ver tu fin. <¬¬¬| \n");
    delay(6);
    printf("\nEso es suficiente! Decides no escuchar ni una palabra mas, y prepararte para lo peor.\n");
    delay(6);
    printf("\nSi el dragon cree que no seras capaz de cumplir tu destino, pues que lo intente!\n");
    delay(6);
    inputcontinue(&n);
    delay(2);
}

void Story_10(Player *player){
    int n;
    printf("\nLuego de sus ultimas palabras, el dragon comienza a cristalizarse completamente.\n");
    delay(6);
    printf("\nUna semejante bestia legendaria, de tiempos antiguos imposibles de trazar...");
    delay(4);
    printf(" derrotada por tu propia voluntad, ante toda adversidad.\n");
    delay(6);
    printf("\nComo es que ese mismo dragon, tan leal a su maestro, haya aceptado su derrota sin sacrificar su vida?\n");
    delay(8);
    printf("\nSera alguno de los planes del senor de la torre? O ha sido por su propia voluntad?\n");
    delay(6);
    printf("\nSea cual fuera la realidad, su forma fisica ahora no es mas que el de una enorme bestia cristalizada.\n");
    delay(8);
    printf("\nPero sin embargo....\n");
    delay(4);
    printf("\nEl piso.. no, la torre entera comienza a temblar abruptamente!\n");
    delay(7);
    printf("\nEscombros de las paredes rusticas comienzan a caer al fondo de los pisos bajos!\n");
    delay(7);
    printf("\n |=-=-=-=-> * %s. Si, %s. Eres la persona que me han profetizado que vendria. * <-=-=-=-=|\n", player->name, player->name);
    delay(7);
    printf("\n |=-=-=-=-> * Procede cuando estes listo. * <-=-=-=-=|\n\n");
    delay(7);
    for (int i=0; i<3; i++){
        letter('.', 10);
    }
    printf("\nEl edificio ha dejado de moverse.\n");
    delay(6);
    printf("\nAqui es cuando comienza el principio del fin.\n");
    delay(6);
    printf("\nDecides dejar de lado al dragon de cristal, para emprender tu camino.");
    delay(7);
    printf(" Hacia la cima de la torre, donde yace el dios del cosmos.\n");
    delay(6);
    inputcontinue(&n);
    delay(3);
    printf("\nMientras subes las escaleras, piensas que sera de los guardianes.\n");
    delay(6);
    printf("\nSeguiran existiendo sus almas, luego de ser derrotadas?\n");
    delay(6);
    printf("\nO acaso seria posible que el lider no les haya otorgado piedad...\n");
    delay(6);
    printf("\nBien sabes que eso no te afecta de ninguna forma, y esos guardianes no eran precisamente simpaticos\n");
    delay(7);
    printf("\nPero si todos los que fueron traidos por el senor de la torre tuvieron la misma suerte.\n");
    delay(6);
    printf("Entonces, que pasara con...");
    delay(5);
    for (int i=0; i<3; i++){
        letter('.', 10);
        printf("\n");
    }
    printf("\nYa logras pisar el ultimo escalon. Adelante tuyo observas un largo y oscuro pasillo.\n");
    delay(7);
    printf("\nLos candelabros alumbran ligeramente la vasta cantidad de cuadros y pinturas que se encuentra en el.\n");
    delay(7);
    printf("\nY sobre el final del corredor, yace una puerta gigantezca, con un color nunca antes visto. \n");
    delay(6);
    printf("\nTransparente, pero imposible de ver a traves. Y sin embargo, tienes la certeza de que el senor esta monitoreandote.\n");
    delay(6);
    printf("\nTodos, y cada uno de tus pasos hasta el encuentro.\n");
    delay(6);
    for (int i=0; i<3; i++){
        letter('.', 10);
        printf("\n");
    }
    printf("\nY en ese momento de tension y confrontamiento...\n");
    for (int i=0; i<3; i++){
        letter('.', 10);
        printf("\n");
    }
    delay(2);
    printf("\n ...un viejo amigo aparece a tu lado.\n");
    delay(4);
    inputcontinue(&n);
    delay(2);
    printf("\n -Esto es. El final de tu aventura.\n");
    delay(5);
    printf("\n -Ha sido dificil, pero has logrado llegar a pesar de todo.\n");
    delay(6);
    printf("\n -Los guardianes, la mascota del senor. La primera persona en ser capaz de derrotar a un ser invencible..\n");
    delay(7);
    printf("\n -Menos mal que te recomende esquivarlo, no? Jajaja\n");
    delay(6);
    if (player->consumable5==0){
        printf("\n -Aunque veo que has utilizado bien los espejos. No te ha sobrado ninguno.\n");
        delay(7);
    } else {
        printf("\n -Incluso te han sobrado espejos? Eres mucho mas fuerte de lo que te imaginas..");
        delay(7);
    }
    printf("\n -Ya no es necesario pensar en el pasado. Ahora existe una ultima mision que debes completar.\n");
    delay(7);
    printf("\n -Permiteme ayudarte por una ultima vez, %s.\n", player->name);
    delay(6);
    inputcontinue(&n);
    delay(2);
}

void Story_11(){

}

void Part1End(Player *player){
    int n;
    printf("\nLuego de sus ultimas palabras, el dragon comienza a cristalizarse completamente.\n");
    delay(6);
    printf("\nUna semejante bestia legendaria, de tiempos antiguos imposibles de trazar...");
    delay(4);
    printf(" derrotada por tu propia voluntad, ante toda adversidad.\n");
    delay(6);
    printf("\nComo es que ese mismo dragon, tan leal a su maestro, haya aceptado su derrota sin sacrificar su vida?\n");
    delay(8);
    printf("\nSera alguno de los planes del senor de la torre? O ha sido por su propia voluntad?\n");
    delay(6);
    printf("\nSea cual fuera la realidad, su forma fisica ahora no es mas que el de una enorme bestia cristalizada.\n");
    delay(8);
    printf("\nPero sin embargo....\n");
    delay(4);
    printf("\nEl piso.. no, la torre entera comienza a temblar abruptamente!\n");
    delay(7);
    printf("\nEscombros de las paredes rusticas comienzan a caer al fondo de los pisos bajos!\n");
    delay(7);
    printf("\n |=-=-=-=-> * %s. Si, %s. Eres la persona que me han profetizado que vendria. * <-=-=-=-=|\n", player->name, player->name);
    delay(7);
    printf("\n |=-=-=-=-> * Procede cuando estes listo. * <-=-=-=-=|\n\n");
    delay(7);
    for (int i=0; i<3; i++){
        letter('.', 10);
    }
    printf("\nEl edificio ha dejado de moverse.\n");
    delay(6);
    printf("\nAqui es cuando comienza el principio del fin.\n");
    delay(6);
    printf("\nDecides dejar de lado al dragon de cristal, para emprender tu camino.");
    delay(7);
    printf(" Hacia la cima de la torre, donde yace el dios del cosmos.\n");
    delay(6);
    inputcontinue(&n);
    delay(3);
    printf("\nMientras subes las escaleras, piensas que sera de los guardianes.\n");
    delay(6);
    printf("\nSeguiran existiendo sus almas, luego de ser derrotadas?\n");
    delay(6);
    printf("\nO acaso seria posible que su dios no les haya otorgado piedad...\n");
    delay(6);
    printf("\nBien sabes que eso no te afecta de ninguna forma, y esos guardianes no eran precisamente simpaticos\n");
    delay(7);
    printf("\nPero si todos los que fueron traidos por el senor de la torre tuvieron la misma suerte.\n");
    delay(6);
    printf("Entonces, que pasara con...\n");
    delay(5);
    for (int i=0; i<3; i++){
        letter('.', 10);
        printf("\n");
    }
    printf("\nYa logras pisar el ultimo escalon. Adelante tuyo observas un largo y oscuro pasillo.\n");
    delay(7);
    printf("\nLos candelabros alumbran ligeramente la vasta cantidad de cuadros y pinturas que se encuentra en el.\n");
    delay(7);
    printf("\nY sobre el final del corredor, yace una puerta gigantezca, con un color nunca antes visto. \n");
    delay(6);
    printf("\nTransparente, pero imposible de ver a traves. Y sin embargo, tienes la certeza de que el senor esta monitoreandote.\n");
    delay(6);
    printf("\nTodos, y cada uno de tus pasos hasta el encuentro.\n");
    delay(6);
    for (int i=0; i<3; i++){
        letter('.', 10);
        printf("\n");
    }
    printf("\nY en ese momento de tension y confrontamiento...\n");
    for (int i=0; i<3; i++){
        letter('.', 10);
        printf("\n");
    }
    printf("\nTu aventura debera esperar.\n");
    delay(6);
    inputcontinue(&n);
    printf("\nBuenas, que tal! Soy el creador de todo esto hablandote por la consola\n");
    delay(8);
    printf("\nAntes que nada, quiero darte las gracias por llegar hasta aca.\n");
    delay(8);
    printf("\nRealmente me pone super contento que hayas derrotado a todos los guardianes! \n");
    delay(8);
    printf("\nY mas aun, espero que hayas disfrutado de este pequeno experimento que me gusto mucho hacer\n");
    delay(8);
    printf("\nDesgraciadamente, el final de esta aventura no esta terminado.\n");
    delay(8);
    printf("\nSi, es horrible y entiendo la frustracion. Pero quiero que sea un final increible, y no algo monotono y simple que se haga en un par de horas.\n");
    delay(9);
    printf("\nEs por eso que si les gusto esto, les agradezco muchisimo y les prometo que algun dia lo voy a terminar :)\n");
    delay(8);
    printf("\nAsi que, sera un hasta luego. No abandonen la aventura!\n");
    delay(6);
    printf("\nY muchisimas gracias por haber jugado a 'The Heretic!'\n");
    delay(6);
    inputcontinue(&n);
}

#endif //THE_HERETIC_PLOT_H
