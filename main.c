#include <stdio.h>
#include <string.h>
#include "Time delay.h"
#include "Menues.h"
#include "Plot.h"
#include "Player.h"
#include "Game Structure.h"

int main() {
    int play;
    char LoadFile[4], Load; /* Load: segun el numero, carga un sitio u otro. Ver word. */
    FILE *p, *l;

    Player player;

    play = StartUp_Menu();
    if (play==4){
        l = fopen("Location.txt", "rt");
        if (ferror(l)){
            printf("Error al cargar el archivo. Vuelva a abrir el juego\n");
        } else {
            fseek(l, 0, SEEK_SET);
            fgets(LoadFile, 5, l); /* esto no funciona. */
            if (strcmp(LoadFile, "EDU1")==0){
                Load = 1;
                play = 1;
            } else if (strcmp(LoadFile, "EDU2")==0){
                Load = 1;
                play = 2;
            } else if (strcmp(LoadFile, "GAB1")==0){
                Load = 2;
                play = 1;
            } else if (strcmp(LoadFile, "GAB2")==0){
                Load = 2;
                play = 2;
            } else if (strcmp(LoadFile, "TOX1")==0){
                Load = 3;
                play = 1;
            } else if (strcmp(LoadFile, "TOX2")==0){
                Load = 3;
                play = 2;
            } else if (strcmp(LoadFile, "KIM1")==0){
                Load = 4;
                play = 1;
            } else if (strcmp(LoadFile, "KIM2")==0){
                Load = 4;
                play = 2;
            } else if (strcmp(LoadFile, "DRA1")==0){
                Load = 5;
                play = 1;
            } else if (strcmp(LoadFile, "DRA2")==0){
                Load = 5;
                play = 2;
            } else if (strcmp(LoadFile, "LAU1")==0){
                Load = 6;
                play = 1;
            } else if (strcmp(LoadFile, "LAU2")==0) {
                Load = 6;
                play = 2;
            }
            printf("Se han cargado los datos\n");
            delay(2);
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
            fread(&player, sizeof(Player), 1, p);/* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;

            case 2:p = fopen("Playerstate.dat", "rb");
            fread(&player, sizeof(Player), 1, p);/* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;

            case 3:p = fopen("Playerstate.dat", "rb");
            fread(&player, sizeof(Player), 1, p);/* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;

            case 4:p = fopen("Playerstate.dat", "rb");
            fread(&player, sizeof(Player), 1, p);/* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;

            case 5:p = fopen("Playerstate.dat", "rb");
            fread(&player, sizeof(Player), 1, p);/* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;

            case 6:p = fopen("Playerstate.dat", "rb");
            fread(&player, sizeof(Player), 1, p);/* aca hay que hacer la copia del archivo playerstate a &player */
            fclose(p);
            Game(&player, Load, play);/* y aca la continuacion del juego desde dicho punto */
            break;
        }
    }

    return 0;
}
