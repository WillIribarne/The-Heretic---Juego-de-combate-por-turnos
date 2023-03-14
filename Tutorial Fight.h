#ifndef THE_HERETIC_TUTORIAL_FIGHT_H
#define THE_HERETIC_TUTORIAL_FIGHT_H

typedef struct{
    int HPMax, HP;
}tutorial;

void Tutorial(Player *player);

void Tutorial(Player *player){
    int n;
    printf("\n\n\n\n\n\n");
    printf("\nGuiad@ por tu instinto divino y una simple barcaza de madera, no tardaras mucho en divisar la torre. \n");
    delay(4);
    printf("\nPero es claro que los peligros estan siempre presentes..\n");
    delay(3);
    printf("\nEl fantasma de un pirata salta desde las profundidades del oceano hacia tu bote.\n");
    delay(5);
    printf("\nParece que no es posible razonar con el. Habra que darle una leccion!\n");
    delay(4);

    printf("         (pulse 1 para continuar)\n");
    scanf("%d", &n);
    fflush(stdin);
    while (n!=1){
        printf("Pulse 1 para continuar\n");
        scanf("%d", &n);
        fflush(stdin);
    }
    tutorial tutorialmob;
    tutorialmob.HPMax = 40;
    tutorialmob.HP = 40;

    delay(1);
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("En este combate aprenderas como se ve y realiza una pelea.\n");
    delay(4);
    printf("Tu objetivo es llevar los HP (Health Points o vida) del enemigo a 0 usando tus habilidades.\n");
    delay(5);
    printf("Abajo veras un menu de opciones que puedes realizar, y la vitalidad de tu enemigo.\n\n\n");
    delay(4);
    printf("                                                                                Pirata Fantasma(HP): %d / %d", tutorialmob.HP, tutorialmob.HPMax);
    printf("\nQue deseas hacer %s?   HP:  300 / 300\n", player->name);
    printf("1- Ataque debilucho: Inflige 10HP de dano al enemigo\n");
    printf("2- Cubrete!: Cubres un 50%% del dano recibido, pero solo puedes usarlo 1 vez.\n");
    delay(2);
    printf("\nNota importante, los numeros de las habilidades de dano son aproximados.\n");
    printf("Por el momento, tienes solo 2 habilidades. Tipea 1 para utilizar 'Ataque Debilucho'!\n");
    scanf("%d", &n);
    fflush(stdin);
    while (n!=1){
        printf("Esto es un tutorial bro, ataca poniendo 1!\n");
        scanf("%d", &n);
        fflush(stdin);
    }
    n=0;

    tutorialmob.HP = tutorialmob.HP - 9;
    player->HP = player->HP - 35;

    printf("\nUsaste Ataque Debilucho! Infligiste 9 HP de dano.\n");
    delay(3);
    printf("\nEl pirata fantasma uso Sable rustico! Recibiste 35 de dano.\n");
    delay(3);
    printf("\n\nParece que golpea mas duro que tu, pero tiene pocos HP. No hay de que preocuparse.\n");
    delay(3);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("                                                                                Pirata Fantasma(HP): %d / %d", tutorialmob.HP, tutorialmob.HPMax);
    printf("\nQue deseas hacer %s?   HP:  265 / 300\n", player->name);
    printf("1- Ataque debilucho: Inflige 10HP de dano al enemigo\n");
    printf("2- Cubrete!: Cubres un 100%% del dano recibido, pero solo puedes usarlo 1 vez.\n");
    printf("\nVuelve a usar 'Ataque Debilucho'!\n");
    scanf("%d", &n);
    fflush(stdin);
    while (n!=1){
        printf("Esto es un tutorial bro, ataca poniendo 1!\n");
        scanf("%d", &n);
        fflush(stdin);
    }
    n=0;

    tutorialmob.HP = tutorialmob.HP - 11;

    printf("\nUsaste Ataque Debilucho! Infligiste 11HP de dano.\n");
    delay(3);
    printf("\nEl pirata uso Cargar Mosquete!\n");
    delay(3);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("Parece que el pirata esta preparado para disparar en el proximo turno.\n\n");
    printf("                                                                                Pirata Fantasma(HP): %d / %d", tutorialmob.HP, tutorialmob.HPMax);
    printf("\nQue deseas hacer %s?   HP:  265 / 300\n", player->name);
    printf("1- Ataque debilucho: Inflige 10HP de dano al enemigo\n");
    printf("2- Cubrete!: Cubres un 100%% del dano recibido, pero solo puedes usarlo 1 vez.\n");
    printf("\nEl pirata disparara en el proximo turno. Usa 'Cubrete!' para anular su ataque!\n");
    scanf("%d", &n);
    fflush(stdin);
    while (n!=2){
        printf("Esto es un tutorial bro, defendete poniendo 2!\n");
        scanf("%d", &n);
        fflush(stdin);
    }
    n=0;

    printf("\n%s se cubrio, anulando el dano del siguiente ataque!\n", player->name);
    delay(3);
    printf("\nEl pirata uso Disparar Mosquete!\n");
    delay(3);
    printf("\n%s se ha cubierto, mitigando todo el dano recibido por Disparar Mosquete!\n", player->name);
    delay(3);

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                                                Pirata Fantasma(HP): %d / %d", tutorialmob.HP, tutorialmob.HPMax);
    printf("\nQue deseas hacer %s?   HP:  265 / 300\n", player->name);
    printf("1- Ataque debilucho: Inflige 10HP de dano al enemigo\n");
    scanf("%d", &n);
    fflush(stdin);
    while (n!=1){
        printf("Esto es un tutorial bro, ataca poniendo 1!\n");
        scanf("%d", &n);
        fflush(stdin);
    }
    n=0;

    tutorialmob.HP = tutorialmob.HP - 12;

    printf("\nUsaste Ataque Debilucho! Infligiste 12 HP de dano.\n");
    delay(3);
    printf("\nEl pirata fantasma uso Cargar Mosquete!\n");
    delay(3);

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("No te preocupes por su mosquete. Eres mas rapido que el pirata, por lo que atacaras antes que el.\n");
    printf("A menos que logre esquivar tu ataque, la pelea ya esta en la bolsa!\n");
    printf("                                                                                Pirata Fantasma(HP): %d / %d", tutorialmob.HP, tutorialmob.HPMax);
    printf("\nQue deseas hacer %s?   HP:  265 / 300\n", player->name);
    printf("1- Ataque debilucho: Inflige 10HP de dano al enemigo\n");
    scanf("%d", &n);
    fflush(stdin);
    while (n!=1){
        printf("Esto es un tutorial bro, ataca poniendo 1!\n");
        scanf("%d", &n);
        fflush(stdin);
    }
    n=0;

    printf("Usaste Ataque Debilucho! Infligiste 8 de dano.\n");
    delay(3);
    printf("\nLos HP del pirata han bajado a 0. Has ganado!\n");
    delay(4);
    printf("\nCon el pirata derrotado, te diriges a tu destino... \n");
}

#endif //THE_HERETIC_TUTORIAL_FIGHT_H
