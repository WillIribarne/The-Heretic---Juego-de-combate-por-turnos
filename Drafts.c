
/* Archivos prueba creado y borrado
FILE *f
f = fopen("Edu.txt", "rt");
if (f==NULL){
        f = fopen("Edu.txt", "wt");
        printf("Se creo el archivo Edu\n");
    } else {
        printf("Edu ya existe\n");
    }
fclose(f);

if (remove("Edu.txt")==0){
        printf("Se borro el archivo\n");
    } else {
        printf("No se pudo borrar el archivo\n");
    }
*/

    printf("  _______   _                   _    _                         _      _       \n");
    printf(" |__   __| | |                 | |  | |                       | |    (_)      \n");
    printf("    | |    | |___     ___      | |__| |    ___   _ __    ___  | |_    _   ___ \n");
    printf("    | |    | '_  |  / _ |      |  __  |  / _ |  | '__| / _ |  | __|  | | / __|\n");
    printf("    | |    | | | |  | __/      | |  | |  | __/  | |    |___/  | |__  | | |(__ \n");
    printf("    |_|    |_| |_|  |___|      |_|  |_|  |___|  |_|    |___|  |____| |_| |___|\n");


    p = fopen("PlayerState.dat", "wb");
    l = fopen("Location.txt", "wt");
    fwrite(&player, sizeof(player), 1, p);
    fputs("EDU", l);
    fclose(l);
    fclose(p);

    if (play==4){
        p = fopen("PlayerState.dat", "rb");
        l = fopen("Location.txt", "rt");
        if (ferror(p) || ferror(l)){
            printf("Error al cargar el archivo. Vuelva a abrir el juego\n");
        } else {
            fseek(l, 0, SEEK_SET);
            strcpy(LoadFile, fgets(LoadFile, 4, l));
            if (strcmp(LoadFile, "EDU")==0){
                printf("Se han cargado los datos\n");
                Load = 1;
            } else if (strcmp(LoadFile, "GAB")==0){
                printf("Se han cargado los datos\n");
                Load = 2;
            } else if (strcmp(LoadFile, "TOX")==0){
                printf("Se han cargado los datos\n");
                Load = 3;
            } else if (strcmp(LoadFile, "KIM")==0){
                printf("Se han cargado los datos\n");
                Load = 4;
            } else if (strcmp(LoadFile, "DRA")==0){
                printf("Se han cargado los datos\n");
                Load = 5;
            } else if (strcmp(LoadFile, "LAU")==0){
                printf("Se han cargado los datos\n");
                Load = 6;
            }
        }
    }

    printf("Que habilidad deseas cambiar?\n");
            printplayerskills(player);
            scanf("%d", &skillchosen);
            fflush(stdin);
            while (skillchosen<1 || skillchosen>4){
                printf("Ingresa una habilidad valida\n");
                scanf("%d", &skillchosen);
                fflush(stdin);
            }
            if (player->skills[skillchosen-1].skillCode>=9 && player->skills[skillchosen-1].skillCode<=13){
                printf("Selecciona la habilidad especial que deseas\n");
                printspecialskills_01();
                scanf("%d", &skillreplace);
                fflush(stdin);
                while (skillreplace!=1 && skillreplace!=2){
                    printf("Ingresa una habilidad valida\n");
                    scanf("%d", &skillreplace);
                    fflush(stdin);
                }
                player->skills[skillchosen-1].skillCode = skillreplace;
            } else if (player->skills[skillchosen-1].skillCode<=9 || player->skills[skillchosen-1].skillCode>=13){
                printf("Selecciona la habilidad que deseas\n");
                printnormalskills_01();
                scanf("%d", &skillreplace);
                fflush(stdin);
                while (skillreplace!=1 && skillreplace!=2){
                    printf("Ingresa una habilidad valida\n");
                    scanf("%d", &skillreplace);
                    fflush(stdin);
                }

            }

int GenerateRandomChance();

int GenerateRandomChance();
    int i, random = 1, RNG, a[100000], contador=0;

    for (i=0; i<100000; i++){
       srand(time(0) * random);
       random = rand();
       srand(random);
       RNG = rand() % 100 + 1;
       printf("%d\n", RNG);
        a[i] = RNG;
        if(RNG>50){
            contador = contador + 1;
        }
    }

    printf("\nCantidad de numeros mayores a cincuenta: %d", contador);
    return 0;
}

    int play;
    char LoadFile[4], Load; /* Load: segun el numero, carga un sitio u otro. Ver word. */
    FILE *p, *l;

    Player player;

    //p = fopen("PlayerState.dat", "wb"); /* estas 6 lineas estan para testear los archivos. Borrar despues */
    //l = fopen("Location.txt", "wt");
    //fwrite(&player, sizeof(player), 1, p);
    //fputs("EDU", l);
    //fclose(l);
    //fclose(p);

    play = StartUp_Menu();
    if (play==4){
        l = fopen("Location.txt", "rt");
        if (ferror(l)){
            printf("Error al cargar el archivo. Vuelva a abrir el juego\n");
        } else {
            fseek(l, 0, SEEK_SET);
            strcpy(LoadFile, fgets(LoadFile, 4, l)); /* esto no funciona. */
            if (strcmp(LoadFile, "EDU")==0){
                printf("Se han cargado los datos\n");
                Load = 1;
            } else if (strcmp(LoadFile, "GAB")==0){
                printf("Se han cargado los datos\n");
                Load = 2;
            } else if (strcmp(LoadFile, "TOX")==0){
                printf("Se han cargado los datos\n");
                Load = 3;
            } else if (strcmp(LoadFile, "KIM")==0){
                printf("Se han cargado los datos\n");
                Load = 4;
            } else if (strcmp(LoadFile, "DRA")==0){
                printf("Se han cargado los datos\n");
                Load = 5;
            } else if (strcmp(LoadFile, "LAU")==0){
                printf("Se han cargado los datos\n");
                Load = 6;
            }
        }
        fclose(l);
    } else if (play!=-1) {
        Load = 0;
        GameStart();
    }

    if (play!=-1){
        switch(Load){
            case 0: Game(&player, Load, play);
            break;

            case 1: p = fopen("Playerstate.dat", "rb");
            /* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;

            case 2:p = fopen("Playerstate.dat", "rb");
            /* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;

            case 3:p = fopen("Playerstate.dat", "rb");
            /* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;

            case 4:p = fopen("Playerstate.dat", "rb");
            /* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;

            case 5:p = fopen("Playerstate.dat", "rb");
            /* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;

            case 6:p = fopen("Playerstate.dat", "rb");
            /* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;
        }
    }