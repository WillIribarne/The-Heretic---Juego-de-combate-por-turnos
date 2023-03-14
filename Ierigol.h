#ifndef THE_HERETIC_IERIGOL_H
#define THE_HERETIC_IERIGOL_H

#include "Player Skills.h"

void Ierigol_01(Player *player);
void Ierigol_02(Player *player);
void Ierigol_03(Player *player);
void Ierigol_04(Player *player);
void Ierigol_05(Player *player);
void Ierigol_06(Player *player);
void Menu_Ierigol_02(Player *player);
void Menu_Ierigol_03(Player *player);
void Menu_Ierigol_04(Player *player);
void Menu_Ierigol_05(Player *player);
void Menu_Ierigol_06(Player *player);
void printnormalskills_01();
void printnormalskills_02();
void printnormalskills_03(Player *player);
void printnormalskills_04(Player *player);
void printspecialskills_01();
void printspecialskills_02();
void printspecialskills_03(Player *player);
void selectskillupgrade_01(Player *player);
void selectskillupgrade_02(Player *player);
void selectskillupgrade_03(Player *player);
void selectskillupgrade_04(Player *player);
void updateplayerskills(Player *player, int totalskills);
int validateskill(Player *player, int skillcode, int i); /*devuelve 1 si no tenes la habilidad ya equipada, 0 si ya la tenes */
void changeskill_01(Player *player); /*Es necesario hacer varias changeskill_0 debido a la aparicion de nuevas habilidades, y capacidad de habilidades aumentada */
void changeskill_02(Player *player);
void changeskill_03(Player *player);
void changeskill_04(Player *player);

void Ierigol_01(Player *player) { /* Hacer la ultima opcion, y llenar los prints de cada skill (primeras 5 normales y 2 especiales al menos) */
    int skillchosen, keyitemchosen, option, skillreplace, n;
    char c;

    printf("\nPrimero antes que nada, pensabas ir asi a liquidar guardianes?\n");
    delay(3);
    printf("Necesitas poderes. Necesitas habilidades nuevas, dignas de un ser divino.\n");
    delay(4);
    printf("\nVamos a empezar asignando nuevas habilidades.\n");
    delay(3);
    printf("Estas van a ser tus armas contra los guardianes, asi que te sugiero que las elijas bien.\n");
    delay(3);
    printf("\nCon tu poder actual, creo que unas 3 habilidades normales y 1 especial estara bien.\n");
    delay(4);
    printf("\nAlgo a tener en cuenta, es que estas habilidades consumen un elemento divino llamado MP.\n");
    delay(4);
    printf("\nSin MP, no vas a ser capaz de usarlas. Por suerte, hay algunas que sirven para recuperar MP.\n");
    delay(5);
    printf("\nLas habilidades especiales suelen consumir mucho MP, pero tambien suelen ser bastante poderosas.\n");
    delay(4);
    printf("\nSolo podes seleccionar una cantidad limitada de habilidades, tanto normales como especiales.\n");
    delay(4);
    printf("\nIgual no te preocupes, si le pifeas a alguna que no te gusto, podes modificarla.\n");
    delay(4);
    printf("Estas listo para elegir? S / N\n");
    scanf("%c", &c);
    fflush(stdin);
    if (c=='N' || c=='n'){
        printf("\n Era una pregunta retorica. Vamos!\n\n");
        delay(2);
    } else if ((c!='S') && (c!='s') && (c!='N') && (c!='n')){
        printf("\nNo te entendi nada, asi que lo tomo como un si.\n\n");
        delay(2);
    }
    for (int i=0; i<3; i++){
        printnormalskills_01();
        if (player->skills[0].skillCode!=0){
            printf("\nEstas son las habilidades que tienes:\n");
            int n=0;
            while (player->skills[n].skillCode!=0){
                printf("  %d-", n+1); printskill(player->skills[n].skillCode);
                n++;
            }
        }
        printf("\nSelecciona usando el numero respectivo\n");
        scanf("%d", &skillchosen);
        fflush(stdin);
        while (skillchosen<1 || skillchosen>5){
            printf("Um, la verdad no te entiendo. Un numero valido porfa\n");
            scanf("%d", &skillchosen);
            fflush(stdin);
        }
        if (player->skills[i].skillCode == 0 && validateskill(player, skillchosen, i)==1){
            player->skills[i].skillCode = skillchosen;
            player->skills[i].cooldown = 0;
            printf("Habilidad aprendida!\n");
            delay(2);
            printf("\n\n\n\n");
        }  else {
            printf("Ya tenes esa habilidad, master (si pusiste una letra, pifiaste)\n");
            delay(2);
            printf("\n\n\n\n");
            i--;
        }
    }
    printf("\n\nAsi quedan, pues.\n\n ");
    printplayernormalskills(player);
    delay(4);

    printf("\nBien, ahora que tenes las 3 habilidades normales, te toca elegir 1 habilidad especial\n");
    printf("Cual queres?\n");
    printf("   1- "); printskill(10);
    printf("   2- "); printskill(11);
    printf("\nSelecciona usando el numero respectivo\n");
    scanf("%d", &skillchosen);
    fflush(stdin);
    while (skillchosen!=1 && skillchosen!=2){
        printf("Um, la verdad no te entiendo. Un numero valido porfa\n");
        scanf("%d", &skillchosen);
        fflush(stdin);
    }
    if (skillchosen==1){
        player->skills[3].skillCode = 10;
    } else {
        player->skills[3].skillCode = 11;
    }
    printf("\nBueno, asi quedan tus habilidades finales.\n");
    printplayerskills(player);
    delay(2);

    printf("\n- Parece que estas listo para pelear! Asi que buena su...\n");
    delay(2);
    printf("\n- CASI ME OLVIDO!\n");
    delay(3);
    printf("\n.. Ves que te muestra 3 anillos; cada uno con una piedra preciosa distinta.\n");
    delay(3);
    printf("\n- Bonitos, verdad? Nadie se resiste a estas bellezas, especialmente cuando estan imbuidas con magia.\n");
    delay(3);
    printf("\n- Lastima que solo puedas elegir uno. El resto desaparecera cuando lo hagas.\n\n");
    delay(3);
    printf("Elige sabiamente esta vez. Cual anillo quieres? No hay reembolsos, asi que ojo.\n");

    for (int i=0; i<3; i++) {
        printf(" %d- ", i+1); printkeyitem(i+1, player);
    }
    printf("Cual queres?\n");
    scanf("%d", &keyitemchosen);
    fflush(stdin);
    while (keyitemchosen!=1 && keyitemchosen!=2 && keyitemchosen!=3){
        printf("... es 1, 2 o 3. No es tan dificil, creo.\n");
        scanf("%d", &keyitemchosen);
        fflush(stdin);
    }
    if (keyitemchosen==1){
        player->keyitem1 = 1;
    } else if (keyitemchosen==2){
        player->keyitem1 = 2;
    } else {
        player->keyitem1 = 3;
    }
    delay(1);
    printf("\nBueno, creo que esto va a bastar por ahora.\n");
    printf("\n\n\n\n");
    while (option!=4){
        printf("Algo mas que quieras hacer?\n");
        printf("    1- Modificar Habilidades\n");
        printf("    2- Acerca del Primer Guardian\n");
        printf("    3- Hablar\n");
        printf("    4- Salir\n");
        printf("Ingrese opcion\n");
        scanf("%d", &option);
        fflush(stdin);
        while (option<1 || option>4){
            printf("Ingrese opcion:\n");
            scanf("%d", &option);
            fflush(stdin);
        }
        if (option==1){
            changeskill_01(player);
        } else if (option==2){
            printf("\n- Eh? La verdad, no creo poder decirte mucho de el. Personalmente no conozco a los guardianes.\n");
            delay(3);
            printf("\n- Sin embargo, muchas almas me han contado sobre sus combates contra ellos.\n");
            delay(3);
            printf("\n- Creo que puedo contarte algunas cosas sobre sus estilos de combate.\n");
            delay(3);
            printf("\n-Veamos.. tengo entendido que el Primer Guardian..\n");
            delay(3);
            printf("\n->>Suele mirar anime cuando tiene bastante vitalidad, y lo vuelve un poco extrano...\n");
            delay(3);
            printf("->>Cuando se encuentra en peligro, puede sanar sus heridas\n");
            delay(3);
            printf("->>Ah, suele golpear mas cuando no esta en peligro, aunque a veces ataca igual! No suele ser tan predecible, a decir verdad.\n");
            delay(2);
            inputcontinue(&n);

        } else if (option==3){
            printf("\n -Ah, que gentil. He de decir que a veces uno se aburre en este lugar.\n");
            delay(3);
            printf("\n -Eres el primer humano que logra entrar a la torre. Pero las almas pasan por aqui a menudo.\n");
            delay(3);
            printf("\n -Carecen de forma fisica, lo que les impide acceder al ultimo piso de la torre.\n");
            delay(3);
            printf("\n -Los guardianes tienden a entrenar mucho contra ellas, por lo que harias bien en tener cuidado.\n");
            delay(3);
            printf("\n -Yo.. no soy un buen combatiente. Y a decir verdad, no logro recordar nada sobre mi.\n");
            delay(3);
            printf("\n -Tengo la confianza de que cumpliendo mi proposito, pueda recuperar mi conocimiento.\n");
            delay(3);
            printf("\n -Por lo que confio plenamente en ti! Eh... extrana persona!\n");
            delay(2);
            inputcontinue(&n);
        } else if (option==4) {
            printf("\nEstas Segur@? S/N\n");
            scanf("%c", &c);
            fflush(stdin);
            if (c=='s' || c=='S'){
                printf("\nEspero que nos volvamos a ver. Trata de que no te maten, si?\n");
                delay(4);
            } else {
                option = 0;
            }
        }
        printf("\n\n\n\n");
    }
}

void Ierigol_02(Player *player) {
    int skillchosen, organizeskill;
    printf("\n -Te tengo una buena noticia. Bueno, en realidad 2, pero ire por partes.\n");
    delay(4);
    printf("\n -Tu poder parece haber aumentado, por lo que eres capaz de aprender una nueva habilidad normal.\n");
    delay(4);
    printf("\n -Ahora puedes llevar 4 habilidades normales en combate. Genial, no?\n");
    delay(4);
    printf("\n -Tambien tengo un par de habilidades nuevas para que elijas.\n");
    delay(4);
    printf("\n -Elige tu cuarta habilidad normal. Recuerda que puedes cambiarlas.\n");
    delay(4);
    printnormalskills_02();
    printf("\nnota: las habilidades con |*| son nuevas.\n");
    scanf("%d", &skillchosen);
    fflush(stdin);
    while ((skillchosen<1 || skillchosen>7) || (validateskill(player, skillchosen, 7))==0){
        printf("Ingrese habilidad valida (no repetida)\n");
        scanf("%d", &skillchosen);
        fflush(stdin);
    }
    organizeskill = player->skills[3].skillCode;
    player->skills[3].skillCode = skillchosen;
    player->skills[4].skillCode = organizeskill;

    delay(1);
    printf(" -Perfecto, ahora la segunda noticia!\n");
    delay(3);
    printf("\n -Consegui un par de bebidas que te fortaleceran en las peleas.\n");
    delay(4);
    printf("\n -Sin embargo, a diferencia del anillo que te di, estos son objetos consumibles.\n");
    delay(4);
    printf("\n -Una vez que lo consumas, desaparecera. Eh, se que es medio estupido decirlo, pero queria ser claro.\n");
    delay(5);
    printf("\n -En fin, aqui tienes\n");
    delay(3);
    player->consumable1 = 1;
    printf("\n---------------------Has conseguido una Manaos!---------------------\n");
    player->consumable2 = 1;
    printf("\n---------------------Has conseguido un Fernet Branca!---------------------\n");
    delay(4);
    printf("\n -La Manaos restaura tu vida en un 30%%.\n");
    delay(3);
    printf("\n -El Fernet Branca aumenta tu ataque en 30%% por 3 turnos.\n");
    delay(3);
    printf("\n -Estos objetos se utilizan en medio de un combate.\n");
    delay(3);
    printf("\n -Lo mejor de todo, es que no pierdes el turno al usarlos (a diferencia de las habilidades).\n");
    delay(4);
    printf("\n -Usalos solo cuando los necesites! No creo conseguir muchos mas..\n");
    delay(4);
    Menu_Ierigol_02(player);
}

void Ierigol_03(Player *player){
    int skillchosen1, skillchosen2, n=1;
    char c;
    printf("\n -He logrado un descubrimiento a base de los guardianes derrotados.\n");
    delay(4);
    printf("\n -Seguramente no te hayas dado cuenta, pero cuando los guardianes desaparecen, sueltan una esencia magica que permanece dando vueltas dentro de la torre.\n");
    delay(5);
    printf("\n -No voy a mentirte, es bastante escurridiza. La esencia de EDU llego hasta un barandal del 5to piso y casi me caigo desde ahi arriba. Que miedo..\n");
    delay(4);
    printf("\n -Pero creeme que te va a gustar.\n");
    delay(4);
    printf("\n >>>>>>>>>>Ahora puedes mejorar tus habilidades normales existentes a versiones mejoradas!<<<<<<<<<<\n");
    delay(4);
    printf("\n -Esto permitira que tus habilidades normales mejoren a una version mucho mas potente.\n");
    delay(4);
    printf("\n -Tienes 2 mejoras posibles. Cuando consiga mas esencias, podre mejorarte aun mas habilidades.\n");
    delay(4);
    inputcontinue(&n);
    selectskillupgrade_01(player);
    printf("\n -Magnifico! Acuerdate de cambiar tus habilidades si mejoraste alguna que no tienes!\n");
    delay(4);
    printf("\n -Pero antes, dejame darte otra mejora importante.\n");
    delay(4);
    printf("\n -Puedes mejorar tus HP maximos, MP maximos, chance critica o evasion. 2 veces.\n");
    delay(4);
    printf("\n -Esto tambien es producto de la esencia de los guardianes. Pero con una gran ventaja..\n");
    delay(4);
    printf("\n -Que cual es? Estas mejoras SE PUEDEN REPETIR\n");
    delay(4);
    printf("\n -Puedes subirte muchos HP para convertirte en un ser indestructible, o tanto MP para golpear sin parar!\n");
    delay(4);
    printf("\n -O puedes incluso ir a pura chance con la evasion o criticos!\n");
    delay(4);
    printf("\n -O combinarlos para poder afrontar diversas situaciones. Siendo franco, es tu decision.\n");
    delay(4);
    printf("\n -A diferencia de las habilidades mejoradas, estas no se pueden deshacer. Una vez hechas, seran permanentes. Asi que elige con cuidado\n");
    delay(4);
    printf("\n -Esto, junto con las habilidades, haran una gran diferencia a la hora de pelear. Es imperativo que tomes tu tiempo y te prepares bien.\n");
    delay(4);
    while (n){
        printf("\n\n -Selecciona la primer mejora:\n");
        printf("1- +75 HP Maximos (Actual: %d)\n", player->HPMax);
        printf("2- +5 MP Maximos (Actual: %d)\n", player->MPMax);
        printf("3- +8%% Chance Critica (Actual %d%%)\n", player->basecritchance);
        printf("4- +8%% Evasion (Actual %d%%)\n", player->basedodge);
        scanf("%d", &skillchosen1);
        fflush(stdin);
        while (skillchosen1 < 1 || skillchosen1 >4){
            printf(".. Del 1 al 4\n");
            scanf("%d", &skillchosen1);
            fflush(stdin);
        }
        printf("\n -Selecciona la segunda mejora:\n");
        scanf("%d", &skillchosen2);
        fflush(stdin);
        while (skillchosen2 < 1 || skillchosen2 >4){
            printf(".. Del 1 al 4\n");
            scanf("%d", &skillchosen2);
            fflush(stdin);
        }
        printf("\nHas elegido las mejoras %d y %d\n", skillchosen1, skillchosen2);
        delay(4);
        printf("\nEsta decision no puede volverse a hacer. Estas completamente segur@ de tu eleccion? S/N\n");
        scanf("%c", &c);
        fflush(stdin);
        while (c!='S' && c!='s' && c!='N' && c!='n'){
            printf("Eh.. S/N ?\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='S' || c=='s'){
            n=0;
            if (skillchosen1==1){
                player->statupgrade1 = player->statupgrade1 + 1;
            } else if (skillchosen1==2){
                player->statupgrade2 = player->statupgrade2 + 1;
            } else if (skillchosen1==3){
                player->statupgrade3 = player->statupgrade3 + 1;
            } else {
                player->statupgrade4 = player->statupgrade4 + 1;
            }
            if (skillchosen2==1){
                player->statupgrade1 = player->statupgrade1 + 1;
            } else if (skillchosen2==2){
                player->statupgrade2 = player->statupgrade2 + 1;
            } else if (skillchosen2==3){
                player->statupgrade3 = player->statupgrade3 + 1;
            } else {
                player->statupgrade4 = player->statupgrade4 + 1;
            }
        } else {
            printf("Esta bien, vamos de nuevo.\n");
            delay(2);
        }
    }
    printf("\n -Perfecto. Creo que ahora si tendras una chance contra los proximos guardianes!\n");
    delay(4);
    printf("\n -Eh, no que no la tuvieras de antes, claro...\n");
    delay(3);
    printf("\n -Dejame darte una cosa mas.\n");
    delay(4);
    printf("\n---------------------Has conseguido tres (3) Baggio Multifruta!---------------------\n");
    delay(4);
    player->consumable4 = player->consumable4 + 3;
    printf("\n -Este (delicioso?) jugo te quitara todas las debilitaciones y purificara tu espiritu.\n");
    delay(4);
    printf("\n -Creo que sera de especial ayuda en tu proximo combate.\n");
    delay(4);
    Menu_Ierigol_03(player);
}

void Ierigol_04(Player *player){
    int skillchosen1, organizeskill, keyitemchosen, n=1;
    char c;

    printf("\n -Ire directo al grano, ya puedes extender tu numero de habilidades al maximo.\n");
    delay(4);
    printf("\n -Actualmente tenes.. 4 habilidades normales y 1 especial, verdad?.\n");
    delay(4);
    printf("\n -Bueno, ahora sos capaz de tener 5 habilidades normales y 2 especiales!\n");
    delay(4);
    printf("\n -Hay un par de habilidades nuevas, tanto normales como especiales, de las que puedes elegir (ademas de las antiguas, claro).\n");
    delay(6);
    printf("\n -Recorda que siempre podes modificar tus habilidades cuando estes conmigo.\n");
    delay(6);
    printf("\n -List@ para elegir?\n");
    delay(3);
    inputcontinue(&n);
    printf("\n -Estas son todas las habilidades normales disponibles:\n");
    delay(3);
    printnormalskills_04(player);
    printf("\n (Nota: las habilidades 8 y 9 son nuevas.) \n");
    printf("\n (Nota 2: La habilidad 8 es una habilidad pasiva. No puede usarse, pero su efecto perdura por todo el combate.) \n");
    delay(6);
    printf("\n -Elegi la habilidad que desees aprender con el numero respectivo.\n");
    scanf("%d", &skillchosen1);
    fflush(stdin);
    while ((skillchosen1<1 || skillchosen1>9) || (validateskill(player, skillchosen1, 7))==0){
        printf("Ingrese habilidad valida (no repetida)\n");
        scanf("%d", &skillchosen1);
        fflush(stdin);
    }
    organizeskill = player->skills[4].skillCode;
    player->skills[4].skillCode = skillchosen1;
    player->skills[5].skillCode = organizeskill;
    printf("\n -Perfecto! La habilidad fue aprendida con exito.\n");
    delay(4);
    printf("\n -Ahora debes elegir tu segunda habilidad especial.\n");
    delay(4);
    printf("\n -A continuacion te mostrare todas las disponibles:\n");
    delay(3);
    printspecialskills_02();
    printf("\n (Nota: las habilidades 3 y 4 son nuevas) \n");
    printf("\n -Elegi la habilidad especial que quieras aprender.\n");
    scanf("%d", &skillchosen1);
    fflush(stdin);
    while ((skillchosen1<1 || skillchosen1>4) || (validateskill(player, skillchosen1, 7))==0){
        printf("Ingrese habilidad valida (no repetida)\n");
        scanf("%d", &skillchosen1);
        fflush(stdin);
    }
    player->skills[6].skillCode = skillchosen1+9;
    printf("\n -Asi se hara. Ahora tienes las 7 habilidades totales. \n");
    delay(4);
    printf("\n -Con respecto a las mejoras de habilidades, las habilidades normales nuevas aun no pueden ser mejoradas.\n");
    delay(4);
    printf("\n -Necesito la esencia de un guardian mas. Y con ella podre mejorar mas habilidades.\n");
    delay(4);
    printf("\n -Igual, recuerda que puedes resetear las mejoras actuales de tus habilidades para mejorar otras.\n");
    delay(4);
    printf("\n -Sigh.. esto es agotador.\n");
    delay(4);
    printf("\n -Creeme que lo hago parecer muy facil, pero todo este trabajo de hacerte mas fuerte requiere mucha energia.\n");
    delay(6);
    printf("\n -En fin, dejame darte algo mas antes de que continues tu camino.\n");
    delay(4);
    printf("\n -He logrado fabricar 2 piezas de artesania nuevas. Similares a los anillos que te he dado, estos objetos son unicos y solo podras elegir uno.\n");
    delay(6);
    printf("\n1- Talisman de Eve: Permite resistir la muerte y revivir con 20%% de tus HPMax, pero solo una vez por combate.\n");
    printf("2- La Padineta: Cancela el turno del rival, hace un poco de dano y reduce su defensa un 50%% por 2 turnos. Usarla no termina tu turno, pero tiene solamente 1 uso por pelea.\n");
    delay(5);
    printf("\n -Elije con sabiduria. El objeto que no elijas desaparecera para toda la eternidad.\n");
    scanf("%d", &keyitemchosen);
    fflush(stdin);
    while (keyitemchosen!=1 && keyitemchosen!=2){
        printf("... es 1 o 2. No es tan dificil, creo.\n");
        scanf("%d", &keyitemchosen);
        fflush(stdin);
    }
    if (keyitemchosen==1){
        player->keyitem2 = 1;
    } else if (keyitemchosen==2){
        player->keyitem2 = 2;
    }
    printf("\n -Como desees. Espero que tu eleccion te sea de gran ayuda.\n");
    delay(4);
    printf("\n -Ah, toma esto.\n");
    delay(4);
    player->consumable1 = player->consumable1 + 1;
    player->consumable3 = player->consumable3 + 2;
    printf("\n---------------------Has conseguido una Manaos!---------------------\n");
    delay(2);
    printf("\n---------------------Has conseguido dos (2) Cafes con Leche!---------------------\n");
    delay(4);
    printf("\nEl cafe con leche aumenta tu Reflejo por 3 turnos. Usalo para hacer que el rival se haga dano a si mismo.\n");
    delay(5);
    printf("\n -Lo siento, creo que mejor necesito estar solo un rato.\n");
    delay(4);
    Menu_Ierigol_04(player);
}

void Ierigol_05(Player *player){
    int skillchosen1, skillchosen2, n=1;
    char c;
    printf("\n -Me estas jodiendo?! El dragon te va a aniquilar!\n");
    delay(6);
    printf("\n -Um.. creo que es culpa mia. Me fui un rato cuando sabia que ibas a necesitar mi ayuda.\n");
    delay(7);
    printf("\n -Lo siento mucho, de verdad.\n");
    delay(5);
    printf("\n -Yo.. cada vez que utilizo mis poderes para ayudarte, siento como un vacio dentro mio que crece.\n");
    delay(7);
    printf("\n -Es como si estuvieras drenando toda mi energia, hasta que ya no queda mas nada...\n");
    delay(6);
    printf("\n -Pero no es tu culpa! No quiero que dejes de perseguir tu objetivo jamas.\n");
    delay(6);
    printf("\n -Mientras yo siga aqui, voy a hacer todo lo posible por ayudarte!\n");
    delay(6);
    printf("\n -Comenzando por sugerir que esquives al dragon...\n");
    delay(6);
    printf("\n -Se que crees que debes luchar contra todos los protectores del senor, pero creeme cuando te digo que ahora debes parar.\n");
    delay(8);
    printf("\n -La mascota del senor no es un rival como los anteriores. Nadie que lo haya visto ha vivido para contarlo.\n");
    delay(8);
    printf("\n -..Sin embargo, debemos esperar lo peor. Dejame elevar tus poderes aun mas, para el peor de los casos.\n");
    delay(3);
    inputcontinue(&n);
    printf("\n       |>>>>>>>>>>>> Ahora puedes mejorar 2 habilidades normales mas! <<<<<<<<<<<<|\n");
    delay(5);
    selectskillupgrade_02(player);
    printf("\n -Ah, perfecto! Fue mas rapido de lo que esperaba.\n");
    delay(5);
    printf("\n -Aumentar la cantidad de habilidades mejoradas hace que sean mas poderosas, pero usualmente hacen que cuesten mas MP.\n");
    delay(6);
    printf("\n -Y es por eso que estuve ausente bastante tiempo.\n");
    delay(5);
    printf("\n -He logrado encontrar la forma de aumentar tu poder innato aun mas.\n");
    delay(5);
    printf("\n -Puedes volver a mejorar tus HP maximos, MP maximos, chance critica o evasion. 2 veces.\n");
    delay(6);
    printf("\n -Tengo que remarcar que esta sera la ultima vez que podre mejorar esto. Tenelo en consideracion.\n");
    delay(6);
    printf("\n -Y recorda que una vez hechas las opciones, no podras volver atras.\n");
    delay(5);
    printf("\n -Vamos a ello?\n");
    delay(4);
    while (n){
        printf("\n\n -Selecciona la primer mejora:\n");
        printf("1- +75 HP Maximos (Actual: %d)\n", player->HPMax);
        printf("2- +5 MP Maximos (Actual: %d)\n", player->MPMax);
        printf("3- +8%% Chance Critica (Actual %d%%)\n", player->basecritchance);
        printf("4- +8%% Evasion (Actual %d%%)\n", player->basedodge);

        scanf("%d", &skillchosen1);
        fflush(stdin);
        while (skillchosen1 < 1 || skillchosen1 >4){
            printf(".. Del 1 al 4\n");
            scanf("%d", &skillchosen1);
            fflush(stdin);
        }
        printf("\n -Selecciona la segunda mejora:\n");
        scanf("%d", &skillchosen2);
        fflush(stdin);
        while (skillchosen2 < 1 || skillchosen2 >4){
            printf(".. Del 1 al 4\n");
            scanf("%d", &skillchosen2);
            fflush(stdin);
        }
        printf("\nHas elegido las mejoras %d y %d\n", skillchosen1, skillchosen2);
        delay(4);
        printf("\nEsta decision no puede volverse a hacer. Estas completamente segur@ de tu eleccion? S/N\n");
        scanf("%c", &c);
        fflush(stdin);
        while (c!='S' && c!='s' && c!='N' && c!='n'){
            printf("Eh.. S/N ?\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='S' || c=='s'){
            n=0;
            if (skillchosen1==1){
                player->statupgrade1 = player->statupgrade1 + 1;
            } else if (skillchosen1==2){
                player->statupgrade2 = player->statupgrade2 + 1;
            } else if (skillchosen1==3){
                player->statupgrade3 = player->statupgrade3 + 1;
            } else {
                player->statupgrade4 = player->statupgrade4 + 1;
            }
            if (skillchosen2==1){
                player->statupgrade1 = player->statupgrade1 + 1;
            } else if (skillchosen2==2){
                player->statupgrade2 = player->statupgrade2 + 1;
            } else if (skillchosen2==3){
                player->statupgrade3 = player->statupgrade3 + 1;
            } else {
                player->statupgrade4 = player->statupgrade4 + 1;
            }
            playerstats(player);
        } else {
            printf("Esta bien, vamos de nuevo.\n");
            delay(2);
        }
    }
    printf("\n -Que asi sea, %s.\n", player->name);
    delay(5);
    printf("\n -Ugh, que mareo me da esto. Sigo sin acostumbrarme.\n");
    delay(5);
    printf("\n -Creo que esto es todo lo que puedo hacer por ti.\n");
    delay(5);
    printf("\n -Sin embargo, dudo que sea suficiente para lograr pasar por el dragon.\n");
    delay(6);
    printf("\n -Se que estoy siendo muy insistente, pero debes evitar entrar en contacto con el.\n");
    delay(5);
    printf("\n -En el peor de los casos, creo que sera mejor que tengas esto.\n");
    delay(5);
    printf("\n ---------------------Has conseguido 3 (tres) Espejitos Rebotin!---------------------\n");
    delay(5);
    player->consumable5 = player->consumable5 + 3;
    printf("\n -Estos espejos estan imbuidos con una magia arcana que permite reflejar los poderes del dragon.\n");
    delay(6);
    printf("\n -Si el dragon te ataca, sera tu mejor defensa contra el.\n");
    delay(6);
    printf("\n -Son los unicos 3 que existen en el universo. Y nunca nadie habia utilizado uno contra la mascota del senor.\n");
    delay(6);
    printf("\n -Diablos, no tengo la certeza ni de que funcionen. Y es por eso que te pido que hagas todo lo posible por evitar que te encuentre.\n");
    delay(7);
    Menu_Ierigol_05(player);


}

void Ierigol_06(Player *player){
    int skillchosen1, skillchosen2, n=1;
    char c;
    printf("\nDefinitivamente eres poderoso. Pero que si te dijera que puedo incrementar tus poderes aun mas?\n");
    delay(6);
    printf("\nLuego de encontrar el alma del dragon, he sido capaz de implementar su uso en ti.\n");
    delay(6);
    printf("\nLogrando que puedas mejorar una de tus habilidades especiales.\n");
    delay(6);
    printf("\nEstas, son increiblemente fuertes. Depende de ti como las uses, por supuesto.\n");
    selectskillupgrade_04(player);
    printf("\nBueno, perfecto. Espero que puedas utilizar su potencial.\n");
    delay(6);
    printf("\nHay otra cosa que tambien quiero darte\n");
    delay(6);
    printf("\nVeras, mientras subias las escaleras hasta llegar hasta aqui, logre crear algo nuevo.\n");
    delay(5);
    printf("\nLogre conseguir unas escamas cristalizadas del dragon. Puedo sintetizarlas en un santiamen para crear un amuleto, pero necesito que me digas cual.\n");
    delay(8);
    while(n){
        printf("\nQue amuleto decides fabricar?\n");
        delay(3);
        printf("\n1-Amuleto de la Patagonia: Parece que es un indicador de que eres Dueno de la Patagonia... Que efecto tendra?\n");
        printf("\n2-Amuleto del Caos Absoluto: Se duplican todos los aumentos y disminuciones de: ataque, velocidad, critico, evasion. Propios y enemigos.\n");
        delay(6);
        printf("\nSelecciona el que deseas. Recuerda que esto no podra cambiarse a futuro.\n");
        delay(6);
        scanf("%d", &skillchosen1);
        fflush(stdin);
        while (skillchosen1!=1 && skillchosen1!=2){
            printf("Ingresa una opcion valida\n");
            scanf("%d", &skillchosen1);
            fflush(stdin);
        }
        printf("\nEsta decision no puede volverse a hacer. Estas completamente segur@ de tu eleccion? S/N\n");
        scanf("%c", &c);
        fflush(stdin);
        while (c!='S' && c!='s' && c!='N' && c!='n'){
            printf("Eh.. S/N ?\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='S' || c=='s'){
            n=0;
            if (skillchosen1==1){
                player->keyitem3 = 1;
            } else {
                player->keyitem3 = 2;
            }
        } else if (c=='N' || c=='n'){
            printf("\nEsta bien, vuelve a elegir.\n");
            delay(3);
        }
    }
    printf("\nAsi lo hare. Lo tendre listo para dartelo cuando decidas emprender tu camino.\n");
    delay(6);
    Menu_Ierigol_06(player);
}

void Menu_Ierigol_02(Player *player){
    int option, n;
    char c;
    playerstats(player);
    while (option!=6){
        printf("\n\n\n\n");
        printf("    1- Ver Habilidades y Objetos\n");
        printf("    2- Modificar Habilidades\n");
        printf("    3- Acerca del Segundo Guardian\n");
        printf("    4- Tips de combate\n");
        printf("    5- Hablar\n");
        printf("    6- Salir\n");
        printf("Ingrese opcion\n");
        scanf("%d", &option);
        fflush(stdin);
        while (option<1 || option>6){
            printf("Ingrese opcion valida:\n");
            scanf("%d", &option);
            fflush(stdin);
        }
        if (option==1){
            printf("\nTus habilidades:\n");
            printplayerskills(player);
            printf("\nTus objetos:\n");
            printallitemsQuantity(player);
            printf("\nTus objetos clave:\n");
            printkeyitems(player);
            inputcontinue(&n);
        } else if (option==2){
            changeskill_02(player);
        } else if (option==3){
            printf("\n -Del Segundo Guardian? En principio, ya viste la casita que hay alli, no?\n");
            delay(4);
            printf("\n -Ese es su lugar de descanso. O tal vez sea su puesto de vigilancia.\n");
            delay(4);
            printf("\n -Te sugiero que no te asomes, por tu bien. Aunque probablemente te vaya a buscar si vas hacia el siguiente piso.\n");
            delay(4);
            printf("\n -Respecto su forma de combatir, he escuchado que...\n");
            delay(4);
            printf("\n-->Es capaz de imprimir armas de fuego en combate, y son extremadamente letales cuando las usa. Te recomiendo tener algo con que defenderte.\n");
            delay(4);
            printf("-->Es moderadamente veloz. Si no eres tan rapido, probablemente tenga la primera accion.\n");
            delay(4);
            printf("-->No te confies al bajar sus HP a 0. Se rumorea que tiene un sistema para emergencias..\n");
            delay(4);
            inputcontinue(&n);
        } else if (option==4){
            printf("\n -Hm? Las peleas no son tan simples como golpear mas fuerte que tu rival.\n");
            delay(4);
            printf("\n -Existen ciertos factores que son de vital importancia al momento de combatir.\n");
            delay(5);
            printf("\n -Por ejemplo: quien tendra el primer golpe? Eso siempre es definido por la VELOCIDAD.\n");
            delay(6);
            printf("\nSi tu oponente es mas VELOZ que tu, su accion ira antes que la tuya. Sin embargo, hay ataques que pueden alterar este orden, como Patagonia Strike!.\n");
            delay(5);
            printf("\n -Has visto algo llamado ATAQUE y DEFENSA? Creo que lo marcan con un %%\n");
            delay(4);
            printf("\nEl ataque influira en tu capacidad para infligir dano, y la defensa para reducirlo. Preocupate si esta negativo!\n");
            delay(5);
            printf("\n -Los golpes nunca son constantes. La mayoria pueden llegar a causar golpes criticos, o bien tal vez fallar.\n");
            delay(4);
            printf("\n       (nota IMPORTANTE: la evasion maxima y chance critica nunca pueden superar el 80%%)\n");
            delay(5);
            printf("\n -Por ultimo, tambien es posible reflejar dano de vuelta! Aunque eso es algo mas avanzado, heh.\n");
            delay(4);
            inputcontinue(&n);
        } else if (option==5){
            printf("\n -Te has preguntado por que los guardianes no hablan?\n");
            delay(4);
            printf("\n -No son personas. Son meramente almas 'rescatadas' por el senor.\n");
            delay(3);
            printf("\n -No se si podria llamarse rescatadas. Mas bien condenadas.\n");
            delay(4);
            printf("\n -Condenadas a ser protectores del senor de la torre hasta su muerte.\n");
            delay(4);
            printf("\n -Su unica voluntad es poner su vida en riesgo para impedir que nadie llegue al piso mas alto.\n");
            delay(4);
            printf("\n -Es por eso que no sentiran empatia, y tampoco debes sentirla tu hacia ellos.\n");
            delay(3);
            inputcontinue(&n);
        } else if (option==6){
            printf("\nEstas Segur@? S/N\n");
            scanf("%c", &c);
            fflush(stdin);
            if (c=='s' || c=='S'){
                printf("\n -Esta bien, cuidate. Nos vemos arriba!\n");
                delay(4);
            } else {
                option = 0;
            }
        }
    }
}

void Menu_Ierigol_03(Player *player){
    int option, n;
    char c;
    playerstats(player);
    while (option!=7){
        printf("\n\n\n\n");
        printf("Algo mas que quieras hacer?\n");
        printf("    1- Ver Habilidades y Objetos\n");
        printf("    2- Modificar Habilidades\n");
        printf("    3- Resetear Mejoras de Habilidades\n");
        printf("    4- Acerca del Tercer Guardian\n");
        printf("    5- Tips de combate\n");
        printf("    6- Hablar\n");
        printf("    7- Salir\n");
        printf("Ingrese opcion\n");
        scanf("%d", &option);
        fflush(stdin);
        while (option<1 || option>7){
            printf("Ingrese opcion valida:\n");
            scanf("%d", &option);
            fflush(stdin);
        } if (option==1){
            printf("\nTus habilidades\n");
            printplayerskills(player);
            printf("\nTus objetos:\n");
            printallitemsQuantity(player);
            printf("\nTus objetos clave:\n");
            printkeyitems(player);
            inputcontinue(&n);
        } else if (option==2){
            changeskill_03(player);
        } else if (option==3){
            printf("\nQuieres resetear todas las mejoras de habilidades, y volverlas a asignar? S/N\n");
            scanf("%c", &c);
            fflush(stdin);
            while (c!='S' && c!='s' && c!='N' && c!='n'){
                printf("Eh.. S/N ?\n");
                scanf("%c", &c);
                fflush(stdin);
            }
            if (c=='S' || c=='s') {
                clearskillupgrades(player);
                printf("Esta bien, vuelve a elegir que habilidades mejorar!\n");
                delay(3);
                selectskillupgrade_01(player);
                updateplayerskills(player, 5);
            }
        } else if (option==4){
            printf("\n -Bueno veras... a partir de ahora los guardianes seran mas dificiles.\n");
            delay(4);
            printf("\n -No solamente tienen mayor vitalidad, tambien poseen mas habilidades.\n");
            delay(4);
            printf("\n -A decir verdad, las mejoras van a ser esenciales para tu victoria.\n");
            delay(4);
            printf("\n -El Tercer Guardian es conocido por muchos, como la criatura mas rapida del universo.\n");
            delay(5);
            printf("\n -Un arma biologica surgida de la malicia humana misma. Capaz de destruir todo lo que toque.\n");
            delay(5);
            printf("\n -No posee una forma solida, ni liquida o gaseosa. Es algo que alterna entre las 3. Un especimen fisico desconocido.\n");
            delay(5);
            printf("\n -Gracias a esto es que le permite moverse de forma impredecible y rapidisima.\n");
            delay(5);
            printf("\n -Por ende, dejame decirte algunas cosas clave sobre el.\n");
            delay(4);
            printf("\n-->Olvidate de tener la primer accion. El siempre sera mas rapido que tu, sin importar lo que hagas. \n");
            delay(4);
            printf("\n-->Tiene solo un ataque directo, pero escala con su velocidad. Disminuir su velocidad reducira el dano. \n");
            delay(4);
            printf("\n-->Es absurdo tratar de esquivar sus ataques. Lo mejor es una buena defensa firme.\n");
            delay(4);
            printf("\n-->Tiene mucha evasion, asi que espera que pueda esquivar tus ataques. Si ves que no te ataca, muy probablemente estara planeando algo.\n");
            delay(4);
            printf("\n-->Recuerda usar los Baggio Multifruta. Su veneno puede ser activado a voluntad, y puede resultar en una catastrofe..\n");
            delay(4);
        } else if (option==5){
            printf("\n -Ya te conte sobre algunos, verdad?\n");
            delay(4);
            printf("\n -Bueno, por si las dudas, aqui dejo un resumen de lo anterior:\n");
            delay(4);
            printf("\n-->Ataque: aumenta el dano de tus ataques.\n");
            printf("\n-->Defensa: reduce el dano recibido por los ataques enemigos.\n");
            printf("\n-->Evasion y critico: chance de esquivar golpes, o de infligir golpes criticos. (Maximo: 80%% de chance)\n");
            printf("\n-->Velocidad: define quien ira primero en un turno. \n");
            delay(7);
            printf("\n -Ahora te explicare sobre algo diferente: DANO POR TURNOS, CURACION POR TURNOS y REFLEJO\n");
            delay(5);
            printf("\n ->El DANO POR TURNOS te inflige cierta cantidad de dano durante una cantidad de turnos. Siempre se aplica luego de que ambos jugadores usen sus turnos.\n");
            delay(6);
            printf("\n ->CURACION POR TURNOS funciona exactamente igual que el DANO POR TURNOS, pero en vez de infligir dano, te cura.\n");
            delay(5);
            printf("\n ->Usualmente veas DANO POR TURNOS de enemigos que usen ataques toxicos o venenosos, fuego, etc..\n");
            delay(5);
            printf("\n ->Algo importante de los danos por turnos, es que usarlos muchas veces seguidas disminuye su efectividad, por lo que recomiendo usarlo de forma espaciada.\n");
            delay(6);
            printf("\n ->REFLEJO permite reflejar dano recibido por el enemigo, de vuelta al rival. Es un %% del dano maximo que pueda causar un ataque.\n");
            delay(5);
            printf("\n ->Por ejemplo, si tienes 25%% REFLEJO y recibes un golpe de 40HP, el atacante recibira 10HP de dano debido a tu REFLEJO.\n");
            delay(5);
            printf("\n ->Lo mejor del REFLEJO, es que si tienes defensa, es mucho mas efectivo!\n");
            delay(5);
            printf("\n ->Supongamos que recibes el mismo golpe de 40HP, pero tienes 50%% DEFENSA. Recibiras 20HP de dano, pero tu rival sufrira 10HP de todos modos!\n");
            delay(6);
            printf("\n ->Esto ocurre debido a que el REFLEJO funciona antes de la DEFENSA. Toma nota de eso!\n");
            delay(5);
            printf("\nEspero que se haya entendido bien, porque no lo volvere a explicar en detalle mas adelante.\n");
            delay(4);
            inputcontinue(&n);
        } else if (option==6){
            printf("\n -Hey! Sabias que estoy empezando a recordar algunas cosas?\n");
            delay(4);
            printf("\n -Estoy muerto! O.. eso creo, porque si no nunca hubiese podido entrar en la torre.\n");
            delay(4);
            printf("\n -Llegue a la conclusion de que fui invocado por el senor de la torre.\n");
            delay(4);
            printf("\n -De la misma forma que todos los Guardianes.\n");
            delay(4);
            printf("\n -Pero tranquil@, yo no voy a luchar contigo. Pero es extrano que sea el unico aqui que sea diferente a ellos...\n");
            delay(4);
            printf("\n -Antes creia que ayudarte era mi proposito, pero ahora no se bien que pensar.\n");
            delay(4);
            printf("\n -Si fui invocado por el senor de la Torre, entonces por que estoy ayudandote, en lugar de ser un guardian?\n");
            delay(4);
            printf("\n -Sinceramente me vuela el bocho. Pero en el fondo siento que estoy haciendo lo correcto.\n");
            delay(4);
        } else if (option==7){
            printf("\nEstas Segur@? S/N\n");
            scanf("%c", &c);
            fflush(stdin);
            if (c=='s' || c=='S'){
                printf("\n -Ten mucho cuidado, y derrota al Tercer Guardian!\n");
                delay(4);
            } else {
                option = 0;
            }
        }
    }
}

void Menu_Ierigol_04(Player *player){
    int option, n;
    char c;
    playerstats(player);
    while (option!=7){
        printf("\n\n\n\n");
        printf("Algo mas que quieras hacer?\n");
        printf("    1- Ver Habilidades y Objetos\n");
        printf("    2- Modificar Habilidades\n");
        printf("    3- Resetear Mejoras de Habilidades\n");
        printf("    4- Acerca del Cuarto Guardian\n");
        printf("    5- Tips de combate\n");
        printf("    6- Hablar\n");
        printf("    7- Salir\n");
        printf("Ingrese opcion\n");
        scanf("%d", &option);
        fflush(stdin);
        while (option<1 || option>7){
            printf("Ingrese opcion valida:\n");
            scanf("%d", &option);
            fflush(stdin);
        } if (option==1){
            printf("\nTus habilidades\n");
            printplayerskills(player);
            printf("\nTus objetos:\n");
            printallitemsQuantity(player);
            printf("\nTus objetos clave:\n");
            printkeyitems(player);
            inputcontinue(&n);
        } else if (option==2){
            changeskill_04(player);
        } else if (option==3){
            printf("\nQuieres resetear todas las mejoras de habilidades, y volverlas a asignar? S/N\n");
            scanf("%c", &c);
            fflush(stdin);
            while (c!='S' && c!='s' && c!='N' && c!='n'){
                printf("Eh.. S/N ?\n");
                scanf("%c", &c);
                fflush(stdin);
            }
            if (c=='S' || c=='s') {
                clearskillupgrades(player);
                printf("Esta bien, vuelve a elegir que habilidades mejorar!\n");
                delay(3);
                selectskillupgrade_01(player);
                updateplayerskills(player, 7);
            }
        } else if (option==4){
            printf("\n--->Es lento, pero muy duro. Puede cargar un ataque que inflige dano devastador.\n");
            delay(4);
            printf("\n--->Puede quitarte MP con sus ataques, asi que ten en cuenta de tener suficientes.\n");
            delay(4);
            printf("\n--->Tiene la capacidad de recuperar HP, pero eso lo deja vulnerable al mismo tiempo.\n");
            delay(4);
            printf("\n--->Dicen que lucha injustamente. Si te ataca multiples veces en un turno, tener evasion te podra servir..\n");
            delay(4);
            printf("\n -Lo siento, necesito estar solo un rato.\n");
            delay(4);
        } else if (option==5){
            printf("\n -A decir verdad, creo que ya sabes todo lo necesario.\n");
            delay(4);
            printf("\n -El resumen de lo que te he dicho anteriormente:\n");
            delay(4);
            printf("\n-->Ataque: aumenta el dano de tus ataques.\n");
            printf("\n-->Defensa: reduce el dano recibido por los ataques enemigos.\n");
            printf("\n-->Evasion y critico: chance de esquivar golpes, o de infligir golpes criticos. (Maximo: 80%% de chance)\n");
            printf("\n-->Velocidad: define quien ira primero en un turno. \n");
            printf("\n-->Reflejo: devuelve parte del dano recibido al atacante.\n");
            printf("\n-->Dano/curacion por turnos: recibe dano/curacion al finalizar ambas acciones de los combatientes.\n");
            delay(5);
            printf("\n       |<->| Pro Tip #1: Usar aumentos/disminuciones de estadisticas y/o danos/curaciones cuando el objetivo ya tiene uno, reduce muchisimo su efectividad.\n");
            printf("                           Lo mejor es esperar a que pase el efecto, antes de volver a aplicarlas.\n");

            delay(5);
            inputcontinue(&n);
        } else if (option==6){
            delay(2);
            printf("\n ...Parece que no tiene ganas de hablar. Se lo ve desolado y angustiado..\n");
            delay(4);
        } else if (option==7){
            printf("\nEstas Segur@? S/N\n");
            scanf("%c", &c);
            fflush(stdin);
            if (c=='s' || c=='S'){
                delay(1);
                printf("\n...\n");
                delay(2);
                printf("\n   ..Se ha desaparecido sin dejar rastro...\n");
                delay(4);
            } else {
                option = 0;
            }
        }
    }
}

void Menu_Ierigol_05(Player *player){
    int option, n;
    char c;
    playerstats(player);
    while (option!=7){
        printf("\n\n\n\n");
        printf("Algo mas que quieras hacer?\n");
        printf("    1- Ver Habilidades y Objetos\n");
        printf("    2- Modificar Habilidades\n");
        printf("    3- Resetear Mejoras de Habilidades\n");
        printf("    4- Acerca del Sexto Guardian\n");
        printf("    5- Tips de combate\n");
        printf("    6- Hablar\n");
        printf("    7- Salir\n");
        printf("Ingrese opcion\n");
        scanf("%d", &option);
        fflush(stdin);
        while (option<1 || option>7){
            printf("Ingrese opcion valida:\n");
            scanf("%d", &option);
            fflush(stdin);
        } if (option==1){
            printf("\nTus habilidades\n");
            printplayerskills(player);
            printf("\nTus objetos:\n");
            printallitemsQuantity(player);
            printf("\nTus objetos clave:\n");
            printkeyitems(player);
            inputcontinue(&n);
        } else if (option==2){
            changeskill_04(player);
        } else if (option==3){
            printf("\nQuieres resetear todas las mejoras de habilidades, y volverlas a asignar? S/N\n");
            scanf("%c", &c);
            fflush(stdin);
            while (c!='S' && c!='s' && c!='N' && c!='n'){
                printf("Eh.. S/N ?\n");
                scanf("%c", &c);
                fflush(stdin);
            }
            if (c=='S' || c=='s') {
                clearskillupgrades(player);
                printf("Esta bien, vuelve a elegir que habilidades mejorar!\n");
                delay(3);
                selectskillupgrade_03(player);
                updateplayerskills(player, 7);
            }
        } else if (option==4){
            printf("\n -Veras, La mascota del Senor tambien es el Sexto Guardian.\n");
            delay(6);
            printf("\n -La gran diferencia con los anteriores, es que este no fue invocado como protector por el senor mismo.\n");
            delay(6);
            printf("\n -Es mas, la mascota es hasta mas antigua que el senor mismo.\n");
            delay(6);
            printf("\n -Ha sido sirviente leal de varios maestros anteriores, uno por uno, hasta llegar al actual maestro.\n");
            delay(7);
            printf("\n -Sus poderes son tan ancestrales como la creacion del universo. Y jamas en la historia tuvo lugar un enfrentamiento en el que haya sido derrotado.\n");
            delay(8);
            printf("\n -Sin embargo, muchos lo han intentado. Y de esas experiencias, logre recolectar la siguiente informacion:\n");
            delay(6);
            printf("\n--->Utiliza alientos de distintos elementos, cada uno con un efecto diferente. Los utiliza de forma intercalada, ya que necesita tiempo para recuperar su aliento.\n");
            delay(7);
            printf("\n--->Se rumorea que es invencible, dados sus HP abismales.\n");
            delay(6);
            printf("\n--->Una vez que debilita lo suficiente a su presa, el dragon la devora completamente. Es una ejecucion atroz, y no hay escape de ella.\n");
            delay(7);
            printf("\n -Recuerdas los espejitos rebotin que te di?\n");
            delay(5);
            printf("\n -Si tienes que luchar, usalos. Y lo digo en serio. Porque no te serviran para nada mas en tu aventura.\n");
            delay(7);

        } else if (option==5){
            printf("\n -A decir verdad, creo que ya sabes todo lo necesario.\n");
            delay(4);
            printf("\n -El resumen de lo que te he dicho anteriormente:\n");
            delay(4);
            printf("\n-->Ataque: aumenta el dano de tus ataques.\n");
            printf("\n-->Defensa: reduce el dano recibido por los ataques enemigos.\n");
            printf("\n-->Evasion y critico: chance de esquivar golpes, o de infligir golpes criticos. (Maximo: 80%% de chance)\n");
            printf("\n-->Velocidad: define quien ira primero en un turno. \n");
            printf("\n-->Reflejo: devuelve parte del dano recibido al atacante.\n");
            printf("\n-->Dano/curacion por turnos: recibe dano/curacion al finalizar ambas acciones de los combatientes.\n");
            delay(5);
            printf("\n       |<->| Pro Tip #1: Usar aumentos/disminuciones de estadisticas y/o danos/curaciones cuando el objetivo ya tiene uno, reduce muchisimo su efectividad.\n");
            printf("                           Lo mejor es esperar a que pase el efecto, antes de volver a aplicarlas.\n");

            delay(5);
            inputcontinue(&n);
        } else if (option==6){
            delay(2);
            printf("\n -Che %s, creo que tengo algo que decirte.\n", player->name);
            delay(6);
            printf("\n -Mi memoria ha vuelto, casi por completo. Y descubri cosas acerca de mi vida.\n");
            delay(6);
            printf("\n -Antes de morir, era un mercader ambulante que ofrecia viveres, herramientas y materiales.\n");
            delay(7);
            printf("\n -Mis clientes solian ser personas en busca de un nuevo hogar. Y ellos mismos querian fabricarlos.\n");
            delay(7);
            printf("\n -Yo les daba las herramientas que necesitaran, y luego me pagaban. Muchas veces incluso los ayudaba con la construccion.\n");
            delay(7);
            printf("\n -No me pagaban siempre con dinero. A veces me daban comida, o me invitaban a sus novedosos hogares.\n");
            delay(7);
            printf("\n -La verdad es que era un trabajo humilde, aunque arduo y extenuante. A veces no dormia por varios dias con tal de ayudar con algun proyecto.\n");
            delay(8);
            printf("\n -Pero he conocido gente fabulosa y que me ha tratado como de la familia.\n");
            delay(7);
            printf("\n -Y gracias a eso, me he dado cuenta que mi verdadera meta en la vida es ayudar a los demas.\n");
            delay(8);
            printf("\n -...Te comente que toda mi energia la utilizo en ayudarte, y es algo que me deja hecho pure.\n");
            delay(7);
            printf("\n -Pues.. si bien es verdad, no quiero que sientas que me estas utilizando o algo asi.\n");
            delay(8);
            printf("\n -Fui traido a esta torre con un proposito. Y se que yo soy el unico capaz de cumplirlo.\n");
            delay(8);
            printf("\n -Si no por que traerme justamente a mi, entre todos los mercaderes del universo?\n");
            delay(8);
            printf("\n -La realidad es que, quiero agradecerte por permitirme ayudarte.\n");
            delay(8);
            printf("\n -Parece que es algo que he estado destinado a hacer, como tu de escalar hasta la cima de la torre.\n");
            delay(6);
            printf("\n -Y prometo seguirte hasta el final!\n");
            delay(6);
            inputcontinue(&n);

        } else if (option==7){
            printf("\nEstas Segur@? S/N\n");
            scanf("%c", &c);
            fflush(stdin);
            if (c=='s' || c=='S'){
                delay(1);
                printf("\n...\n");
                delay(2);
                printf("\n -Bueno, aqui nos despedimos, %s.\n", player->name);
                delay(4);
                printf("\n -Es algo triste.. la despedida. He visto como has derrotado a cada guardian, cada golpe, cada esquive.\n");
                delay(6);
                printf("\n -Ha sido divertido ayudarte hasta aqui!\n");
                delay(6);
                printf("\n -Pero es momento de que vayas adelante y continues con tu destino.\n");
                delay(6);
                printf("\n -Mi momento ha llegado, y debo marcharme. \n");
                delay(6);
                printf("\n -Por favor, trata de evitar al dragon a toda costa.\n");
                delay(6);
                printf("\n -Quiero pasar mis ultimos segundos aqui para verte llegar hasta el final de la torre!\n");
                delay(6);
                printf("\n    ....Y con esas palabras, el cuerpo del mercader desaparece. Sera.. para siempre esta vez?\n");
                delay(8);
            } else {
                option = 0;
            }
        }
    }
}

void Menu_Ierigol_06(Player *player) {
    int option, n;
    char c;
    playerstats(player);
    while (option != 7) {
        printf("\n\n\n\n");
        printf("Algo mas que quieras hacer?\n");
        printf("    1- Ver Habilidades y Objetos\n");
        printf("    2- Modificar Habilidades\n");
        printf("    3- Resetear Mejoras de Habilidades\n");
        printf("    4- Acerca del senor de la torre\n");
        printf("    5- Tips de combate\n");
        printf("    6- Hablar\n");
        printf("    7- Salir\n");
        printf("Ingrese opcion\n");
        scanf("%d", &option);
        fflush(stdin);
        while (option < 1 || option > 7) {
            printf("Ingrese opcion valida:\n");
            scanf("%d", &option);
            fflush(stdin);
        }
        if (option==1){
            printf("\nTus habilidades\n");
            printplayerskills(player);
            printf("\nTus objetos:\n");
            printallitemsQuantity(player);
            printf("\nTus objetos clave:\n");
            printkeyitems(player);
            inputcontinue(&n);
        } else if (option==2){
            changeskill_04(player);
        } else if (option==3){
            printf("\nQuieres resetear todas las mejoras de habilidades, y volverlas a asignar? S/N\n");
            scanf("%c", &c);
            fflush(stdin);
            while (c!='S' && c!='s' && c!='N' && c!='n'){
                printf("Eh.. S/N ?\n");
                scanf("%c", &c);
                fflush(stdin);
            }
            if (c=='S' || c=='s') {
                clearskillupgrades(player);
                printf("Esta bien, vuelve a elegir que habilidades mejorar!\n");
                delay(3);
                selectskillupgrade_03(player);
                printf("\nYa estan las habilidades normales. Ahora quedan las especiales.\n");
                delay(6);
                selectskillupgrade_04(player);
                updateplayerskills(player, 7);
            }
        } else if (option==4){
            printf("\n -Ah... efectivamente %s. Ponte comodo, que hay mucho que debes saber.\n", player->name);
            delay(6);
            printf("\n -El senor de la torre. ");
            delay(4);
            printf("Emperador del universo. ");
            delay(3);
            printf("Dios del cosmos. \n");
            delay(3);
            printf("\n -Son muchos los nombres que se le han atribuido a lo largo de los tiempos.\n");
            delay(7);
            printf("\n -Nunca nadie lo ha conocido en persona. Nadie sabe que es, si es que es un ente viviente.\n");
            delay(8);
            printf("\n -La historia de esta torre, se remonta nada mas que al inicio de todo lo que conocemos.\n");
            delay(8);
            printf("\n -O al menos eso es lo que cuentan.\n");
            delay(6);
            printf("\n -Se rumorea que este es el lugar donde todo se crea. La raza humana, el mar, las montanas.\n");
            delay(7);
            printf("\n -Asi como tambien todo lo creado se destruye. Lo alguna vez creado, regresa a su forma vacia.\n");
            delay(8);
            letter('.', 10);
            letter('.', 10);
            letter('.', 10);
            printf("\n -Sin embargo, hay algo que debes saber...\n");
            delay(8);
            printf("\n -Yo.. no se como explicarlo. Pero algo no anda bien.\n");
            delay(6);
            printf("\n -Yo he sido traido aqui por su propia voluntad. El uso sus poderes para lograrlo, al igual que los demas guardianes\n");
            delay(8);
            printf("\n -Gracias a ello, parte de su energia la siento en mi interior. Y siento que de algun modo puedo ver a traves de el.\n");
            delay(6);
            printf("\n -%s. Debes detenerlo.\n", player->name);
            delay(6);
            printf("\n -El senor de la torre.. planea destruir el universo.\n");
            delay(7);
            printf("\n -Y no solo el universo. Cualquier posibilidad de regreso a la actualidad.\n");
            delay(7);
            printf("\n -Es por esa razon que invoco a los guardianes. Es por esa misma razon que decidio eliminar mi memoria al traerme aqui.\n");
            delay(8);
            printf("\n -Paradojicamente, tambien me asigno la tarea de ayudarte.\n");
            delay(6);
            printf("\n -Puedo pensar que debe haber un motivo por el cual ha decidido que seas tu el elegido.\n");
            delay(7);
            printf("\n -Y que, de alguna forma, tu eres una pieza valiosa en su plan.\n");
            delay(8);
            printf("\n -Como somos todos nosotros en esta desgraciada torre.\n");
            delay(7);
            printf("\n -Debi saberlo desde un principio... y habertelo advertido.\n");
            delay(6);
            printf("\n -Es por eso que hare todo lo posible para ayudarte a salvar al universo.\n");
            delay(6);
            printf("\n -Aunque sea lo ultimo que haga.\n");
            delay(4);
            inputcontinue(&n);
            delay(2);
            printf("\n -Sobre lo que pueda llegar a hacer en caso de un combate...\n");
            delay(5);
            printf("\n -Me temo que no hay nada que pueda decirte.\n");
            delay(6);
            printf("\n -No conozco sus poderes. Mucho menos lo que es capaz de hacer.\n");
            delay(6);
            printf("\n -Pero si hay algo que puedo aconsejarte que hagas, es que observes con cuidado.\n");
            delay(6);
            printf("\n -El dios del cosmos es capaz de manipularlo todo. Incluso tus poderes, si fuese necesario.\n");
            delay(7);
            printf("\n -Aun asi, si hay alguien a quien debe temer, ese eres tu.\n");
            delay(6);
            printf("\n -El no conoce lo fuerte que te has vuelto. Incluso si debilita tus poderes, te subestimara, y esa sera tu ventaja.\n");
            delay(6);
            printf("\n -Analizalo bien. Toma buenas decisiones. Y no permitas que destruya el universo.\n");
            delay(6);
            printf("\n -Nadie lo sabe, pero todos cuentan contigo.\n");
            delay(6);

        } else if (option==5){
            printf("\n -Um.. despues de derrotar a cada guardian en tu camino..?\n");
            delay(7);
            printf("\n -Bueno, quien soy yo para juzgar.\n");
            delay(4);
            printf("\n -El resumen de lo que te he dicho anteriormente:\n");
            delay(4);
            printf("\n-->Ataque: aumenta el dano de tus ataques.\n");
            printf("\n-->Defensa: reduce el dano recibido por los ataques enemigos.\n");
            printf("\n-->Evasion y critico: chance de esquivar golpes, o de infligir golpes criticos. (Maximo: 80%% de chance)\n");
            printf("\n-->Velocidad: define quien ira primero en un turno. \n");
            printf("\n-->Reflejo: devuelve parte del dano recibido al atacante.\n");
            printf("\n-->Dano/curacion por turnos: recibe dano/curacion al finalizar ambas acciones de los combatientes.\n");
            delay(5);
            printf("\n       |<->| Pro Tip #1: Usar aumentos/disminuciones de estadisticas y/o danos/curaciones cuando el objetivo ya tiene uno, reduce muchisimo su efectividad.\n");
            printf("                           Lo mejor es esperar a que pase el efecto, antes de volver a aplicarlas.\n");
            printf("\n       |<->| Pro Tip #2: Si no tenes el amuleto de la patagonia, subite la defensa que te van a golpear fuerte.");
        } else if (option==6){
            printf("\n -Creo que esto es todo, no?\n");
            delay(5);
            printf("\n -Me hubiese gustado que fuese de otro modo, sinceramente...\n");
            delay(6);
            printf("\n -Recuerdas la leyenda por la cual viniste hasta aqui?\n");
            delay(6);
            printf("\n  'Quien logre llegar a la cuspide podra pedir un deseo al dios de la creacion'  \n\n");
            delay(6);
            printf("\n -Quien diria que ese mismo dios de la creacion, seria a su vez el de la eliminacion del universo?\n");
            delay(7);
            printf("\n -Parece que te hicieron un pequeno chiste y ahora tenes que luchar por todos.\n");
            delay(6);
            printf("\n -En fin, ha sido una aventura enorme! Llegar hasta aqui, derrotar a los guardianes.\n");
            delay(6);
            printf("\n -Desde el momento en el que pisaste la torre, senti que habia algo especial en vos.\n");
            delay(6);
            printf("\n -Y la verdad que le atine bastante bien!\n");
            delay(6);
        } else if (option==7){
            printf("\nEstas Segur@? S/N\n");
            scanf("%c", &c);
            fflush(stdin);
            if (c=='s' || c=='S'){
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);
                printf("\n\n");
                delay(6);

            } else {
                option = 0;
            }
        }
    }
}


int validateskill(Player *player, int skillcode, int i){
    for (int n=0; n<i; n++){
        if (player->skills[n].skillCode == skillcode){
            return 0;
        }
    }
    return 1;
}

void printnormalskills_01(){
    printf("   1- "); printskill(1);
    printf("   2- "); printskill(2);
    printf("   3- "); printskill(3);
    printf("   4- "); printskill(4);
    printf("   5- "); printskill(5);
}
void printnormalskills_02(){
    printf("   1- "); printskill(1);
    printf("   2- "); printskill(2);
    printf("   3- "); printskill(3);
    printf("   4- "); printskill(4);
    printf("   5- "); printskill(5);
    printf("|*|6- "); printskill(6);
    printf("|*|7- "); printskill(7);
}

void printnormalskills_03(Player *player){
    for (int i=1; i<8; i++){
        if (player->skillupgrade[i-1]=='s'){
            printf("   (Mejorada) %d- ", i); printskill((i+20));
        } else {
            printf("   %d- ", i); printskill(i);
        }
    }
}

void printnormalskills_04(Player *player){
    for (int i=1; i<10; i++){
        if (player->skillupgrade[i-1]=='s'){
            printf("   (Mejorada) %d- ", i); printskill((i+20));
        } else {
            printf("   %d- ", i); printskill(i);
        }
    }
}

void printspecialskills_01(){
    printf("   1- "); printskill(10);
    printf("   2- "); printskill(11);
}

void printspecialskills_02(){
    printf("   1- "); printskill(10);
    printf("   2- "); printskill(11);
    printf("   3- "); printskill(12);
    printf("   4- "); printskill(13);
}

void printspecialskills_03(Player *player){
    for (int i=10; i<14; i++){
        if (player->skillupgrade[i-1]=='s'){
            printf("  (Mejorada) %d- ", i-9); printskill((i+4));
        } else {
            printf("   %d- ", i-9); printskill(i);
        }
    }
}

void selectskillupgrade_01(Player *player){
    int n=1, skillchosen1, skillchosen2;
    char c;

    printf("\n -A continuacion se mostraran todas las habilidades normales disponibles hasta el momento.\n\n");
    printf("   1- "); printskill(1);
    printf("   2- "); printskill(2);
    printf("   3- "); printskill(3);
    printf("   4- "); printskill(4);
    printf("   5- "); printskill(5);
    printf("   6- "); printskill(6);
    printf("   7- "); printskill(7);
    delay(4);
    printf("\n -Y ahora, las habilidades mejoradas.\n\n");
    delay(4);
    printf("   1- "); printskill(21);
    printf("   2- "); printskill(22);
    printf("   3- "); printskill(23);
    printf("   4- "); printskill(24);
    printf("   5- "); printskill(25);
    printf("   6- "); printskill(26);
    printf("   7- "); printskill(27);
    printf("\n -Cada habilidad tiene su numero respectivo. Por ejemplo, 1- es Ataque Directo, y se transformara en 1- Ataque Celestial.\n");
    delay(7);
    printf("\n -Recuerda que solamente puedes mejorar 2 habilidades, y deben ser diferentes habilidades.\n");
    delay(4);

    while (n){
        printf("\n -Selecciona la primer habilidad para mejorar.\n");
        scanf("%d", &skillchosen1);
        fflush(stdin);
        while (skillchosen1 < 1 || skillchosen1 >7){
            printf("Selecciona una habilidad valida\n");
            scanf("%d", &skillchosen1);
            fflush(stdin);
        }
        printf("\n -Muy bien. Ahora elige la segunda habilidad para mejorar.\n");
        scanf("%d", &skillchosen2);
        fflush(stdin);
        while (skillchosen2 < 1 || skillchosen2 >7 || skillchosen2 == skillchosen1){
            printf("Selecciona una habilidad valida\n");
            scanf("%d", &skillchosen2);
            fflush(stdin);
        }
        printf("\n -Perfecto. Las habilidades seleccionadas fueron:\n");
        printf("   %d- ", skillchosen1); printskill(skillchosen1);
        printf("   %d- ", skillchosen2); printskill(skillchosen2);
        printf("\n -Estas habilidades se mejoraran (respectivamente) a:\n");
        printf("   %d- ", skillchosen1); printskill(skillchosen1+20);
        printf("   %d- ", skillchosen2); printskill(skillchosen2+20);
        printf("\n -Estas segur@ de tu decision?  S/N\n");
        scanf("%c", &c);
        fflush(stdin);
        while (c!='S' && c!='s' && c!='N' && c!='n'){
            printf("Eh.. S/N ?\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='S' || c=='s'){
            n=0;
            player->skillupgrade[skillchosen1-1] = 's';
            player->skillupgrade[skillchosen2-1] = 's';
            for (int i=0; i<5; i++){
                if (player->skills[i].skillCode == skillchosen1 || player->skills[i].skillCode == skillchosen2){
                    player->skills[i].skillCode = player->skills[i].skillCode + 20;
                }
            }
        } else {
            printf("Bueno, vamos a elegir de nuevo entonces.\n");
            delay(3);
        }
    }
}

void selectskillupgrade_02(Player *player){
    int n=1, skillchosen1, skillchosen2;
    char c;

    printf("\n -A continuacion se mostraran todas las habilidades normales disponibles hasta el momento (observaras que ya hay algunas que tienes previamente mejoradas).\n\n");
    delay(4);
    for (int i=0; i<9; i++){
        if (player->skillupgrade[i] == 's'){
            printf("   %d-", i+1); printskill(i+21);
        } else {
            printf("   %d-", i+1); printskill(i+1);
        }
    }
    delay(5);
    printf("\n -Y ahora, todas las habilidades mejoradas.\n\n");
    delay(3);
    printf("   1- "); printskill(21);
    printf("   2- "); printskill(22);
    printf("   3- "); printskill(23);
    printf("   4- "); printskill(24);
    printf("   5- "); printskill(25);
    printf("   6- "); printskill(26);
    printf("   7- "); printskill(27);
    printf("   8- "); printskill(28);
    printf("   9- "); printskill(29);
    printf("\n -Cada habilidad tiene su numero respectivo. Por ejemplo, 1- es Ataque Directo, y se transformara en 1- Ataque Celestial.\n");
    delay(7);
    printf("\n -Recuerda que solamente puedes tener un total de 4 habilidades mejoradas, y deben ser diferentes habilidades.\n");
    delay(4);
    printf("\n -Como ya tienes 2 habilidades, debes elegir la tercera y la cuarta habilidad.\n");
    delay(5);

    while (n){
        printf("\n -Elige la tercer habilidad para mejorar.\n");
        scanf("%d", &skillchosen1);
        fflush(stdin);
        while (skillchosen1 < 1 || skillchosen1 > 9 || player->skillupgrade[skillchosen1-1] == 's'){
            printf("Selecciona una habilidad valida sin mejorar\n");
            scanf("%d", &skillchosen1);
            fflush(stdin);
        }
        printf("\n -Muy bien. Ahora elige la cuarta habilidad para mejorar.\n");
        scanf("%d", &skillchosen2);
        fflush(stdin);
        while (skillchosen1 < 1 || skillchosen1 > 9 || player->skillupgrade[skillchosen1-1] == 's' || skillchosen2 == skillchosen1){
            printf("Selecciona una habilidad valida sin mejorar\n");
            scanf("%d", &skillchosen2);
            fflush(stdin);
        }
        printf("\n -Perfecto. Las habilidades seleccionadas fueron:\n");
        printf("   %d- ", skillchosen1); printskill(skillchosen1);
        printf("   %d- ", skillchosen2); printskill(skillchosen2);
        printf("\n -Estas habilidades se mejoraran (respectivamente) a:\n");
        printf("   %d- ", skillchosen1); printskill(skillchosen1+20);
        printf("   %d- ", skillchosen2); printskill(skillchosen2+20);
        printf("\n -Estas segur@ de tu decision?  S/N\n");
        scanf("%c", &c);
        fflush(stdin);
        while (c!='S' && c!='s' && c!='N' && c!='n'){
            printf("Eh.. S/N ?\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='S' || c=='s'){
            n=0;
            player->skillupgrade[skillchosen1-1] = 's';
            player->skillupgrade[skillchosen2-1] = 's';
            for (int i=0; i<7; i++){
                if (player->skills[i].skillCode == skillchosen1 || player->skills[i].skillCode == skillchosen2){
                    player->skills[i].skillCode = player->skills[i].skillCode + 20;
                }
            }
        } else {
            printf("Bueno, vamos a elegir de nuevo entonces.\n");
            delay(3);
        }
    }
}

void selectskillupgrade_03(Player *player){
    int n=1, skillchosen1, skillchosen2, skillchosen3, skillchosen4;
    char c;

    printf("\n -A continuacion se mostraran todas las habilidades normales disponibles hasta el momento (observaras que ya hay algunas que tienes previamente mejoradas).\n\n");
    for (int i=0; i<9; i++){
        if (player->skillupgrade[i] == 's'){
            printf("   %d-", i+1); printskill(i+21);
        } else {
            printf("   %d-", i+1); printskill(i+1);
        }
    }
    delay(6);
    printf("\n -Y ahora, todas las habilidades mejoradas.\n\n");
    delay(4);
    printf("   1- "); printskill(21);
    printf("   2- "); printskill(22);
    printf("   3- "); printskill(23);
    printf("   4- "); printskill(24);
    printf("   5- "); printskill(25);
    printf("   6- "); printskill(26);
    printf("   7- "); printskill(27);
    printf("   8- "); printskill(28);
    printf("   9- "); printskill(29);
    delay(6);
    printf("\n -Cada habilidad tiene su numero respectivo. Por ejemplo, 1- es Ataque Directo, y se transformara en 1- Ataque Celestial.\n");
    delay(7);
    printf("\n -Recuerda que solamente puedes tener un total de 4 habilidades mejoradas, y deben ser diferentes habilidades.\n");
    delay(4);
    printf("\n -Debes elegir 4 habilidades diferentes, ingresando el numero de la habilidad respectiva.\n");
    delay(5);

    while (n){
        printf("\n -Elige la primer habilidad para mejorar.\n");
        scanf("%d", &skillchosen1);
        fflush(stdin);
        while (skillchosen1 < 1 || skillchosen1 > 9){
            printf("Selecciona una habilidad valida sin mejorar\n");
            scanf("%d", &skillchosen1);
            fflush(stdin);
        }
        printf("\n -Ahora elige la segunda habilidad para mejorar.\n");
        scanf("%d", &skillchosen2);
        fflush(stdin);
        while (skillchosen2 < 1 || skillchosen2 > 9 || skillchosen2 == skillchosen1){
            printf("Selecciona una habilidad valida sin mejorar\n");
            scanf("%d", &skillchosen2);
            fflush(stdin);
        }
        printf("\n -Elige la tercer habilidad para mejorar.\n");
        scanf("%d", &skillchosen3);
        fflush(stdin);
        while (skillchosen3 < 1 || skillchosen3 > 9 || skillchosen3 == skillchosen2 || skillchosen3 == skillchosen1){
            printf("Selecciona una habilidad valida sin mejorar\n");
            scanf("%d", &skillchosen3);
            fflush(stdin);
        }
        printf("\n -Ahora elige la ultima habilidad para mejorar.\n");
        scanf("%d", &skillchosen4);
        fflush(stdin);
        while (skillchosen4 < 1 || skillchosen4 > 9 || skillchosen4 == skillchosen3 || skillchosen4 == skillchosen2 || skillchosen4 == skillchosen1){
            printf("Selecciona una habilidad valida sin mejorar\n");
            scanf("%d", &skillchosen4);
            fflush(stdin);
        }
        printf("\n -Perfecto. Las habilidades seleccionadas fueron:\n");
        printf("   %d- ", skillchosen1); printskill(skillchosen1);
        printf("   %d- ", skillchosen2); printskill(skillchosen2);
        printf("   %d- ", skillchosen3); printskill(skillchosen3);
        printf("   %d- ", skillchosen4); printskill(skillchosen4);
        printf("\n -Estas habilidades se mejoraran (respectivamente) a:\n");
        printf("   %d- ", skillchosen1); printskill(skillchosen1+20);
        printf("   %d- ", skillchosen2); printskill(skillchosen2+20);
        printf("   %d- ", skillchosen3); printskill(skillchosen3+20);
        printf("   %d- ", skillchosen4); printskill(skillchosen4+20);
        printf("\n -Estas segur@ de tu decision?  S/N\n");
        scanf("%c", &c);
        fflush(stdin);
        while (c!='S' && c!='s' && c!='N' && c!='n'){
            printf("Eh.. S/N ?\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='S' || c=='s'){
            n=0;
            player->skillupgrade[skillchosen1-1] = 's';
            player->skillupgrade[skillchosen2-1] = 's';
            player->skillupgrade[skillchosen3-1] = 's';
            player->skillupgrade[skillchosen4-1] = 's';
            for (int i=0; i<7; i++){
                if (player->skills[i].skillCode == skillchosen1 || player->skills[i].skillCode == skillchosen2 || player->skills[i].skillCode == skillchosen3 || player->skills[i].skillCode == skillchosen4){
                    player->skills[i].skillCode = player->skills[i].skillCode + 20;
                }
            }
        } else {
            printf("Bueno, vamos a elegir de nuevo entonces.\n");
            delay(3);
        }
    }
}

void selectskillupgrade_04(Player *player){
    int n=1, skillchosen1, skillchosen2, skillchosen3, skillchosen4;
    char c;

    while (n){
        printf("\nA continuacion se mostraran todas las habilidades especiales actuales.\n");
        printspecialskills_02();
        printf("\nY ahora, podras elegir mejorar una de las anteriores, a una de estas.\n");
        printf("   1- "); printskill(14);
        printf("   2- "); printskill(15);
        printf("   3- "); printskill(16);
        printf("   4- "); printskill(17);

        printf("\n -Cada habilidad tiene su numero respectivo. Por ejemplo, 1- es Macaco Blaster, y se transformara en 1- Macaco Ragnarok.\n");
        delay(7);
        printf("\n -Debido a su inmenso poder y potencial de uso, solo puedes elegir una. Pero si te arrepientes, puedes cambiarla despues.");
        delay(7);
        printf("\nEntonces, cual eliges?\n");
        scanf("%d", &skillchosen1);
        fflush(stdin);
        while(skillchosen1!=1 && skillchosen1!=2 && skillchosen1!=3 && skillchosen1!=4){
            printf("\nElegi una habilidad valida\n");
            scanf("%d", &skillchosen1);
        }
        printf("\n -Perfecto. La habilidad seleccionada fue:\n");
        printf("   %d- ", skillchosen1); printskill(skillchosen1+13);
        printf("\n -Estas segur@ de tu decision?  S/N\n");
        scanf("%c", &c);
        fflush(stdin);
        while (c!='S' && c!='s' && c!='N' && c!='n'){
            printf("Eh.. S/N ?\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='S' || c=='s'){
            n=0;
            player->skillupgrade[skillchosen1+13] = 's';
            for (int i=5; i<7; i++){
                if (player->skills[i].skillCode == skillchosen1+9){
                    player->skills[i].skillCode = player->skills[i].skillCode + 4;
                    return;
                }
            }
        } else {
            printf("Bueno, vamos a elegir de nuevo entonces.\n");
            delay(3);
        }
    }
}

void updateplayerskills(Player *player, int totalskills){

    for (int i=0; i<totalskills; i++){
        if (player->skills[i].skillCode <= 13 && player->skills[i].skillCode >= 10){
            if (player->skillupgrade[player->skills[i].skillCode-1]=='s'){
                player->skills[i].skillCode = player->skills[i].skillCode + 4;
            }
        } else if (player->skills[i].skillCode <= 17 && player->skills[i].skillCode >= 14){
            if (player->skillupgrade[player->skills[i].skillCode-5]== 'n'){
                player->skills[i].skillCode = player->skills[i].skillCode - 4;
            }
        } else if (player->skills[i].skillCode < 10){
            if (player->skillupgrade[player->skills[i].skillCode-1]== 's'){
                player->skills[i].skillCode = player->skills[i].skillCode + 20;
            }
        } else if (player->skills[i].skillCode > 20){
            if (player->skillupgrade[player->skills[i].skillCode-21]== 'n'){
                player->skills[i].skillCode = player->skills[i].skillCode - 20;
            }
        }
    }
}

void changeskill_01(Player *player){ /* esta funcion es reciclable para los demas Ierigol(), solamente hay que cambiar unos valores y listo */
    int skillchosen, skillreplace, n;
    printf("\nQue habilidad deseas cambiar?\n\n");
    printplayerskills(player);
    scanf("%d", &skillchosen);
    fflush(stdin);
    while (skillchosen<1 || skillchosen>4){ /* cambiar esto para que de justo con las habilidades */
        printf("Ingresa una habilidad valida\n");
        scanf("%d", &skillchosen);
        fflush(stdin);
    }
    printf("\nPor cual habilidad?\n");
    if (player->skills[skillchosen-1].skillCode>9 && player->skills[skillchosen-1].skillCode<14){
        printspecialskills_01();
        scanf("%d", &skillreplace);
        fflush(stdin);
        n=3;
        while (skillreplace<1 || skillreplace>2){ /* cambiar esto para que de justo con las habilidades (especiales) */
            printf("Ingrese habilidad valida\n");
            scanf("%d", &skillreplace);
            fflush(stdin);
        }
        skillreplace = skillreplace + 9; /* cambiar esto para que de justo con las habilidades */
    } else {
        printnormalskills_01();
        scanf("%d", &skillreplace);
        fflush(stdin);
        n=3;
        while (skillreplace<1 || skillreplace>5){
            printf("Ingrese habilidad valida\n");
            scanf("%d", &skillreplace);
            fflush(stdin);
        }
    }
    if (validateskill(player, skillreplace, n)==0 || player->skills[skillchosen-1].skillCode == skillreplace){
        printf("Ya tenes esa habilidad!\n");
        delay(2);
    } else {
        player->skills[skillchosen-1].skillCode = skillreplace;
        player->skills[skillchosen-1].cooldown = 0;
        printf("Habilidad cambiada con exito!\n");
        delay(2);
    }
}

void changeskill_02(Player *player){ /* esta funcion es reciclable para los demas Ierigol(), solamente hay que cambiar unos valores y listo */
    int skillchosen, skillreplace;
    printf("\nQue habilidad deseas cambiar?\n\n");
    printplayerskills(player);
    scanf("%d", &skillchosen);
    fflush(stdin);
    while (skillchosen<1 || skillchosen>5){ /* cambiar esto para que de justo con las habilidades */
        printf("Ingresa una habilidad valida\n");
        scanf("%d", &skillchosen);
        fflush(stdin);
    }
    printf("\nPor cual habilidad?\n");
    if (player->skills[skillchosen-1].skillCode>9 && player->skills[skillchosen-1].skillCode<14){
        printspecialskills_01(); /* cambiar funcion por la adecuada */
        scanf("%d", &skillreplace);
        fflush(stdin);
        while (skillreplace<1 || skillreplace>2){ /* cambiar esto para que de justo con las habilidades (especiales) */
            printf("Ingrese habilidad valida\n");
            scanf("%d", &skillreplace);
            fflush(stdin);
        }
        skillreplace = skillreplace + 9; /* cambiar esto para que de justo con las habilidades */
    } else {
        printnormalskills_02(); /* cambiar funcion por la adecuada */
        scanf("%d", &skillreplace);
        fflush(stdin);    /*------> cantidad de habilidades del jugador -1 */
        while (skillreplace<1 || skillreplace>7){ /* cambiar esto para que de justo con las habilidades (normales) */
            printf("Ingrese habilidad valida\n");
            scanf("%d", &skillreplace);
            fflush(stdin);
        }
    }
    if (validateskill(player, skillreplace, 7)==0 || player->skills[skillchosen-1].skillCode == skillreplace){
        printf("Ya tenes esa habilidad!\n");
        delay(2);
    } else {
        player->skills[skillchosen-1].skillCode = skillreplace;
        player->skills[skillchosen-1].cooldown = 0;
        printf("Habilidad cambiada con exito!\n");
        delay(2);
    }
}

void changeskill_03(Player *player){
    int skillchosen, skillreplace;
    printf("\nQue habilidad deseas cambiar?\n\n");
    printplayerskills(player);
    scanf("%d", &skillchosen);
    fflush(stdin);
    while (skillchosen<1 || skillchosen>5){ /* cambiar esto para que de justo con las habilidades */
        printf("Ingresa una habilidad valida\n");
        scanf("%d", &skillchosen);
        fflush(stdin);
    }
    printf("\nPor cual habilidad?\n");
    if (player->skills[skillchosen-1].skillCode>9 && player->skills[skillchosen-1].skillCode<14){
        printspecialskills_01(); /* cambiar funcion por la adecuada */
        scanf("%d", &skillreplace);
        fflush(stdin);
        while (skillreplace<1 || skillreplace>2){ /* cambiar esto para que de justo con las habilidades (especiales) */
            printf("Ingrese habilidad valida\n");
            scanf("%d", &skillreplace);
            fflush(stdin);
        }
        skillreplace = skillreplace + 9; /* cambiar esto para que de justo con las habilidades */ /*CAMBIAR CUANDO TENGAN QUE HACERSE + HABILIDADES ESPECIALES Y ESPECIALES MEJORADAS */
    } else {
        printnormalskills_03(player); /* cambiar funcion por la adecuada */
        scanf("%d", &skillreplace);
        fflush(stdin);
        while (skillreplace<1 || skillreplace>7){ /* cambiar esto para que de justo con las habilidades (normales) */
            printf("Ingrese habilidad valida\n");
            scanf("%d", &skillreplace);
            fflush(stdin);
        }
    }
    if (validateskill(player, skillreplace, 7)==0 || player->skills[skillchosen-1].skillCode == skillreplace || validateskill(player, skillreplace+20, 7)==0){
        printf("Ya tenes esa habilidad!\n");
        delay(2);
    } else {
        if (player->skillupgrade[skillreplace-1] == 's'){
            player->skills[skillchosen-1].skillCode = skillreplace + 20;
        } else {
            player->skills[skillchosen-1].skillCode = skillreplace;
        }
        player->skills[skillchosen-1].cooldown = 0;
        printf("Habilidad cambiada con exito!\n");
        delay(2);
    }
}

void changeskill_04(Player *player){
    int skillchosen, skillreplace;
    printf("\nQue habilidad deseas cambiar?\n\n");
    printplayerskills(player);
    scanf("%d", &skillchosen);
    fflush(stdin);
    while (skillchosen<1 || skillchosen>7){ /* cambiar esto para que de justo con las habilidades */
        printf("Ingresa una habilidad valida\n");
        scanf("%d", &skillchosen);
        fflush(stdin);
    }
    printf("\nPor cual habilidad?\n");
    if (player->skills[skillchosen-1].skillCode>9 && player->skills[skillchosen-1].skillCode<14){
        printspecialskills_03(player); /* cambiar funcion por la adecuada */
        scanf("%d", &skillreplace);
        fflush(stdin);
        while (skillreplace<1 || skillreplace>4){ /* cambiar esto para que de justo con las habilidades (especiales) */
            printf("Ingrese habilidad valida\n");
            scanf("%d", &skillreplace);
            fflush(stdin);
        }
        if (player->skillupgrade[skillreplace+9]== 's'){
            skillreplace = skillreplace + 13;
        } else {
            skillreplace = skillreplace + 9; /* cambiar esto para que de justo con las habilidades */ /*CAMBIAR CUANDO TENGAN QUE HACERSE + HABILIDADES ESPECIALES Y ESPECIALES MEJORADAS*/
        }
    } else {
        printnormalskills_04(player); /* cambiar funcion por la adecuada */
        scanf("%d", &skillreplace);
        fflush(stdin);
        while (skillreplace<1 || skillreplace>9){ /* cambiar esto para que de justo con las habilidades (normales) */
            printf("Ingrese habilidad valida\n");
            scanf("%d", &skillreplace);
            fflush(stdin);
        }
    }
    if (validateskill(player, skillreplace, 7)==0 || player->skills[skillchosen-1].skillCode == skillreplace || validateskill(player, skillreplace+20, 7)==0){
        printf("Ya tenes esa habilidad!\n");
        delay(2);
    } else {
        if (player->skillupgrade[skillreplace-1] == 's'){
            player->skills[skillchosen-1].skillCode = skillreplace + 20;
        } else {
            player->skills[skillchosen-1].skillCode = skillreplace;
        }
        player->skills[skillchosen-1].cooldown = 0;
        printf("Habilidad cambiada con exito!\n");
        delay(2);
    }
}

#endif //THE_HERETIC_IERIGOL_H
