#ifndef THE_HERETIC_MENUES_H
#define THE_HERETIC_MENUES_H

int StartUp_Menu();
void Print_GameName();
void Print_Options();
int Select_OptionMenu();
int Execute_Option(int option, int *info);
void StartStory(int *play);
void Continue(int *load);
void DeleteData();
void Info();
void Credits();
void GameStart();

int StartUp_Menu(){
    int option, info=0, play=0; /* play: 1- Easy, 2-Hard, 3- Will, 4-Continue*/
    Print_GameName();
    while ((play<1 || play>4) && play!=-1) {
        Print_Options();
        option = Select_OptionMenu();
        play = Execute_Option(option, &info);
    }
    return play;
}

void Print_GameName(){
    printf("  _______   _                   _    _                         _      _       \n");
    printf(" |__   __| | |                 | |  | |                       | |    (_)      \n");
    printf("    | |    | |___     ___      | |__| |    ___   _ __    ___  | |_    _   ___ \n");
    printf("    | |    | '_  |  / _ |      |  __  |  / _ |  | '__| / _ |  | __|  | | / __|\n");
    printf("    | |    | | | |  | __/      | |  | |  | __/  | |    |___/  | |__  | | |(__ \n");
    printf("    |_|    |_| |_|  |___|      |_|  |_|  |___|  |_|    |___|  |____| |_| |___|\n");
}

void Print_Options(){
    printf("\n               1- Comenzar Historia\n");
    printf("               2- Continuar\n");
    printf("               3- Borrar Datos\n");
    printf("               4- Informacion y ayuda\n");
    printf("               5- Creditos\n");
    printf("               6- Salir\n");
}

int Select_OptionMenu(){
    int option;
    printf("               Ingrese opcion deseada:\n ");
    scanf("%d", &option);
    fflush(stdin);
    while (option>6 || option<1){
        printf("Eh, una opcion valida..\n");
        scanf("%d", &option);
        fflush(stdin);
    }
    return option;
}

int Execute_Option(int option, int *info){
    int play=0, load=0;
    char c;
    while (1){
        switch (option){
        case 1:
            if (*info==0){
                printf("\nSugiero que antes de empezar, mires la Informacion y Ayuda.\n");
                printf("Deseas ver la Informacion y Ayuda?  S/N\n");
                scanf("%c", &c);
                fflush(stdin);
                while ((c!='S') && (c!='s') && (c!='N') && (c!='n')){
                    printf("S para si, N para no.\n");
                    scanf("%c", &c);
                    fflush(stdin);
                }
                if ((c=='S') || (c=='s')){
                    Info();
                    *info=1;
                } else{
                    *info=1;
                }
            }
        StartStory(&play); /* 1-East, 2-Hard, 3-Will */
        return play;
        case 2: Continue(&load);/* 4-Load */
        return load;
        case 3: DeleteData();
        return 0;
        case 4: Info();
        *info=1;
        return 0;
        case 5: Credits();
        return 0;
        case 6: return -1;
        }
    }
}

void StartStory(int *play){
    char c;
    printf("\n                     Elija la Dificultad\n\n");
    printf("       (1) Facil: Los enemigos hacen dano normal y tienen pocas habilidades\n");
    printf("   (2) Dificil: Los enemigos infligen mas dano y tienen acceso a nuevas habilidades\n");
    printf("(3) Willy: Cada pelea tiene un contador de turnos. Si llega a 0, pierdes. No es posible continuar. Mismos enemigos que en Dificil\n");
    scanf("%d", play);
    fflush(stdin);
    while (*play!=1 && *play!=2 && *play!=3){
        printf("Ingrese una opcion valida");
        scanf("%d", play);
        fflush(stdin);
    }
    if (*play==1){
        printf("Elegiste la dificultad Facil (hmm...)\n Estas Segur@? S/N\n");
        scanf("%c", &c);
        while ((c!='S') && (c!='s') && (c!='N') && (c!='n')){
            printf("Ingresa S (si) o N (no)\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='n' || c=='N'){
            *play=0;
        }
    } else if (*play==2){
        printf("Elegiste la dificultad Dificil. Estas segur@? S/N\n");
        scanf("%c", &c);
        while ((c!='S') && (c!='s') && (c!='N') && (c!='n')){
            printf("Ingresa S (si) o N (no)\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='n' || c=='N'){
            *play=0;
        }
    } else if (*play==3){
        printf("Elegiste la dificultad Willy (que valiente!). Estas segur@? S/N\n");
        scanf("%c", &c);
        while ((c!='S') && (c!='s') && (c!='N') && (c!='n')){
            printf("Ingresa S (si) o N (no)\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='n' || c=='N'){
            *play=0;
        }
    }
}

void Continue(int *load){
    char c;
    FILE *p, *l;
    p = fopen("Playerstate.dat", "rb");
    l = fopen("Location.txt", "rt");

    if (p==NULL || l==NULL){
        printf("\nNo tienes ningun archivo guardado\n");
        *load=0;
    } else {
        printf("Deseas continuar desde el ultimo guardado? S/N\n");
        scanf("%c", &c);
        fflush(stdin);
        while ((c!='S') && (c!='s') && (c!='N') && (c!='n')){
            printf("Ingresa S (si) o N (no)\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='s' || c=='S'){
            *load=4;
        } else {
            *load=0;
        }
    }
    fclose(p);
    fclose(l);
}

void DeleteData(){
    FILE *p, *l;
    char c;
    p = fopen("PlayerState.dat", "rb");
    l = fopen("Location.txt", "rt");
    if (p==NULL && l==NULL){
        printf("\nNo hay datos para borrar.\n");
    } else {
        printf("Seguro que deseas borrar los datos? S/N\n");
        scanf("%c", &c);
        fflush(stdin);
        while (c!='S' && c!='s' && c!='N' && c!='n'){
            printf("Ingrese S/N\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='s' || c=='S'){
            fclose(p);
            fclose(l);
            remove("PlayerState.dat");
            remove("Location.txt");
            printf("\nSe han borrado los datos preexistentes.\n");
        } else if (c=='n' || c=='N'){
            fclose(p);
            fclose(l);
        }
    }
}

void Info(){
    printf("\nBienvenido a la informacion del jugador/a!\n");
    printf("\nComo probablemente sepas, este juego lo hizo una persona sola que empezo a programar hace relativamente poco.\n");
    printf("Es un juego de combate por turnos (como un pokemon), con historia, personajes y habilidades unicas.\n");
    printf("A medida que se avanza, el juego se hara mas complicado, pero el jugador tendra mas herramientas para fortalecerse.\n");
    printf("A continuacion voy a mencionar algunas cosas importantes a tener en cuenta antes de empezar.\n");
    printf("\n>> Lo mas importante a tener en cuenta, es que muy probablemente encuentres bugs/errores. Algunos probablemente destruyan el juego, haciendo que tengas que reiniciarlo.\n");
    printf("  Es por esa razon que encarecidamente sugiero que SOLAMENTE ingresen opciones/informacion cuando el juego les diga o se los permita.\n");
    printf("  Si ingresan texto, por ejemplo, mientras se reproduce un fragmento de la historia, seguramente pasen anormalidades.\n");
    printf("\n>> Esto va ligado de otra cosa importante: cuando ingresen una opcion, ingresen SOLO el numero/letra pedido\n");
    printf("  Por ejemplo, cuando el juego les dice S/N, es tipear 's' o 'n' y apretar enter. Es probable que si escriben una palabra como 'no', tambien ocurran anormalidades\n");
    printf("  En los menues donde se tienen, por ejemplo, 1- 2- 3- 4-..., tipear el numero de la opcion que se quiera ejecutar.\n");
    printf("\n>> Tercero, y que me entristece bastante, es que este juego no posee sonido ni ilustraciones/animaciones. Desgraciadamente, no es algo que pueda hacer con la terminal de Windows.\n");
    printf("  Mi recomendacion es que elijan una buena musica de su gusto personal, para acompanar la experiencia del juego.\n");
    printf("\n>> Notaran que no hay tildes en las palabras, ni tampoco caracteres especiales o caracteristicos del idioma espanol.\n");
    printf("  Eso se debe a que la terminal de Windows tampoco reconoce las tildes ni la letra 'enie'. Si las usase, se verian de esta manera: ñ ");
    printf("  (no se rian, redactar mal adrede es bastante mas complicado de lo que parece)\n");
    printf("\n>> El juego, despues de cada combate exitoso, tiene una funcion de guardado. Este permite que sea posible continuar la partida desde dicho punto, siempre que no se borren los archivos generados.\n");
    printf("  (nota: la funcion de guardado no aplica en la ultima dificultad)\n");

    printf("\nEso es todo, creo. Espero que puedan disfrutar el juego!\n");
    printf("\n - Atte: El developer.\n");
}

void Credits(){
    printf("\nEh.. por ahora no esta terminado hehe. Volve despues cuando avance mas.\n");
};

void GameStart(){
    printf("Muy bien. La aventura comenzara en breve. Suerte!\n\n\n\n\n\n");
    delay(5);
}


#endif //THE_HERETIC_MENUES_H