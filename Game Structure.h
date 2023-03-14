#ifndef THE_HERETIC_GAME_STRUCTURE_H
#define THE_HERETIC_GAME_STRUCTURE_H

#include "Player.h"
#include "Plot.h"
#include "Tutorial Fight.h"
#include "Ierigol.h"
#include "Fight.h"
#include "Enemies.h"
#include "Player Skills.h"

void Game(Player *player, int Load, int difficulty);

void Game(Player *player, int Load, int difficulty) { /*difficulty: 1=Facil, 2=Dificil, 3=Willy */
    int resume, n, skip;
    char c;
    FILE *p, *l;
    if (Load == 0) { /* Por cada Load, se ejecuta una rama distinta del juego. Load=0 es el juego completo */

        playerstats(player);
        clearplayeritems(player);
        clearplayerskills(player);
        clearskillupgrades(player);
        clearstatupgrades(player);

        Story_0(player);
        printf("Deseas hacer el combate tutorial introductorio? Es completamente opcional. S/N\n");
        scanf("%c", &c);
        fflush(stdin);
        while ((c != 'S') && (c != 's') && (c != 'N') && (c != 'n')) {
            printf("Ingresa S (si) o N (no)\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c == 'S' || c == 's') {
            delay(1);
            refillplayer(player);
            Tutorial(player);
            delay(4);
        } else {
            printf("\nComo desees. Es tu eleccion.\n");
            delay(2);
        }
        skip = skipstory(&skip);
        if (skip==0){
            Story_01();
        }
        Ierigol_01(player);
        skip = skipstory(&skip);
        if (skip==0){
            Story_1();
        }
        resume = Fight(player, difficulty);
        if (resume==2){ /*resume es 'win' de la pelea. Fight devuelve 2 si ganaste, 0 si perdes. */
            if (difficulty!=3){                 /* aca se guardan los archivos */
                printf("\nGuardando partida...\n");
                delay(3);
                if (difficulty==1){
                    char str[] = "EDU1";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                } else {
                    char str[] = "EDU2";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                }
                printf("\nListo!");
                inputcontinue(&n);
                delay(1);
            }
            skip = skipstory(&skip);
            if (skip==0){
                Story_2();
            }
            Ierigol_02(player);
            skip = skipstory(&skip);
            if (skip==0){
                Story_3();
            }
            resume = Fight(player, difficulty);
            if (resume==2){ /*resume es 'win' de la pelea. Fight devuelve 2 si ganaste, 0 si perdes. */
            if (difficulty!=3){                 /* aca se guardan los archivos */
                printf("\nGuardando partida...\n");
                delay(3);
                if (difficulty==1){
                    char str[] = "GAB1";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                } else {
                    char str[] = "GAB2";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                }
                printf("\nListo!");
                inputcontinue(&n);
                delay(1);
            }
            skip = skipstory(&skip);
            if (skip==0){
                Story_4();
            }
            Ierigol_03(player);
            skip = skipstory(&skip);
            if (skip==0){
                Story_5();
            }
            resume = Fight(player, difficulty);
            if (resume==2) { /*resume es 'win' de la pelea. Fight devuelve 2 si ganaste, 0 si perdes. */
                if (difficulty != 3) {                 /* aca se guardan los archivos */
                    printf("\nGuardando partida...\n");
                    delay(3);
                    if (difficulty == 1) {
                        char str[] = "TOX1";
                        p = fopen("PlayerState.dat", "wb");
                        l = fopen("Location.txt", "wt");
                        fwrite(player, sizeof(Player), 1, p);
                        fwrite(str, 1, sizeof(str), l);
                        fclose(l);
                        fclose(p);
                    } else {
                        char str[] = "TOX2";
                        p = fopen("PlayerState.dat", "wb");
                        l = fopen("Location.txt", "wt");
                        fwrite(player, sizeof(Player), 1, p);
                        fwrite(str, 1, sizeof(str), l);
                        fclose(l);
                        fclose(p);
                    }
                    printf("\nListo!");
                    inputcontinue(&n);
                    delay(1);
                }
                skip = skipstory(&skip);
                if (skip==0){
                    Story_6();
                }
                Ierigol_04(player);
                skip = skipstory(&skip);
                if (skip==0){
                    Story_7();
                }
                resume = Fight(player, difficulty);
                if (resume == 2) {
                    if (difficulty != 3) {                 /* aca se guardan los archivos */
                        printf("\nGuardando partida...\n");
                        delay(3);
                        if (difficulty == 1) {
                            char str[] = "KIM1";
                            p = fopen("PlayerState.dat", "wb");
                            l = fopen("Location.txt", "wt");
                            fwrite(player, sizeof(Player), 1, p);
                            fwrite(str, 1, sizeof(str), l);
                            fclose(l);
                            fclose(p);
                        } else {
                            char str[] = "KIM2";
                            p = fopen("PlayerState.dat", "wb");
                            l = fopen("Location.txt", "wt");
                            fwrite(player, sizeof(Player), 1, p);
                            fwrite(str, 1, sizeof(str), l);
                            fclose(l);
                            fclose(p);
                        }
                        printf("\nListo!");
                        inputcontinue(&n);
                        delay(1);
                    }
                    skip = skipstory(&skip);
                    if (skip==0){
                        Story_8();
                    }
                    Ierigol_05(player);
                    skip = skipstory(&skip);
                    if (skip==0){
                        Story_9(player);
                    }
                    resume = Fight(player, difficulty);
                    if (resume==2){
                if (difficulty!=3){                 /* aca se guardan los archivos */
                printf("\nGuardando partida...\n");
                delay(3);
                if (difficulty==1){
                    char str[] = "DRA1";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                } else {
                    char str[] = "DRA2";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                }
                printf("\nListo!");
                inputcontinue(&n);
                delay(1);
            }
                /* Part1End(player); */
                skip = skipstory(&skip);
                if (skip==0){
                    Story_10(player);
                }
                Ierigol_06(player);
                skip = skipstory(&skip);
                if (skip==0){
                    Story_11();
                }
                resume = Fight(player, difficulty);
            }
                }
            }
            }
        }
    } else if (Load == 1){
        skip = skipstory(&skip);
        if (skip==0){
            Story_2();
        }
        Ierigol_02(player);
        skip = skipstory(&skip);
        if (skip==0){
            Story_3();
        }
        resume = Fight(player, difficulty);
        if (resume==2){ /*resume es 'win' de la pelea. Fight devuelve 2 si ganaste, 0 si perdes. */
            if (difficulty!=3){                 /* aca se guardan los archivos */
                printf("\nGuardando partida...\n");
                delay(3);
                if (difficulty==1){
                    char str[] = "GAB1";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                } else {
                    char str[] = "GAB2";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                }
                printf("\nListo!");
                inputcontinue(&n);
                delay(1);
            }
            skip = skipstory(&skip);
            if (skip==0){
                Story_4();
            }
            Ierigol_03(player);
            skip = skipstory(&skip);
            if (skip==0){
                Story_5();
            }
            resume = Fight(player, difficulty);
            if (resume==2) { /*resume es 'win' de la pelea. Fight devuelve 2 si ganaste, 0 si perdes. */
                if (difficulty != 3) {                 /* aca se guardan los archivos */
                    printf("\nGuardando partida...\n");
                    delay(3);
                    if (difficulty == 1) {
                        char str[] = "TOX1";
                        p = fopen("PlayerState.dat", "wb");
                        l = fopen("Location.txt", "wt");
                        fwrite(player, sizeof(Player), 1, p);
                        fwrite(str, 1, sizeof(str), l);
                        fclose(l);
                        fclose(p);
                    } else {
                        char str[] = "TOX2";
                        p = fopen("PlayerState.dat", "wb");
                        l = fopen("Location.txt", "wt");
                        fwrite(player, sizeof(Player), 1, p);
                        fwrite(str, 1, sizeof(str), l);
                        fclose(l);
                        fclose(p);
                    }
                    printf("\nListo!");
                    inputcontinue(&n);
                    delay(1);
                }
                skip = skipstory(&skip);
                if (skip==0){
                    Story_6();
                }
                Ierigol_04(player);
                skip = skipstory(&skip);
                if (skip==0){
                    Story_7();
                }
                resume = Fight(player, difficulty);
                if (resume == 2) {
                    if (difficulty != 3) {                 /* aca se guardan los archivos */
                        printf("\nGuardando partida...\n");
                        delay(3);
                        if (difficulty == 1) {
                            char str[] = "KIM1";
                            p = fopen("PlayerState.dat", "wb");
                            l = fopen("Location.txt", "wt");
                            fwrite(player, sizeof(Player), 1, p);
                            fwrite(str, 1, sizeof(str), l);
                            fclose(l);
                            fclose(p);
                        } else {
                            char str[] = "KIM2";
                            p = fopen("PlayerState.dat", "wb");
                            l = fopen("Location.txt", "wt");
                            fwrite(player, sizeof(Player), 1, p);
                            fwrite(str, 1, sizeof(str), l);
                            fclose(l);
                            fclose(p);
                        }
                        printf("\nListo!");
                        inputcontinue(&n);
                        delay(1);
                    }
                    skip = skipstory(&skip);
                    if (skip==0){
                        Story_8();
                    }
                    Ierigol_05(player);
                    skip = skipstory(&skip);
                    if (skip==0){
                        Story_9(player);
                    }
                    resume = Fight(player, difficulty);
                    if (resume==2){
                if (difficulty!=3){                 /* aca se guardan los archivos */
                printf("\nGuardando partida...\n");
                delay(3);
                if (difficulty==1){
                    char str[] = "DRA1";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                } else {
                    char str[] = "DRA2";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                }
                printf("\nListo!");
                inputcontinue(&n);
                delay(1);
            }
               /* Part1End(player); */
               skip = skipstory(&skip);
                if (skip==0){
                    Story_10(player);
                }
                Ierigol_06(player);
                skip = skipstory(&skip);
                if (skip==0){
                    Story_11();
                }
                resume = Fight(player, difficulty);
            }
                }
            }
        }
    } else if (Load == 2){
        skip = skipstory(&skip);
        if (skip==0){
            Story_4();
        }
        Ierigol_03(player);
        skip = skipstory(&skip);
        if (skip==0){
            Story_5();
        }
        resume = Fight(player, difficulty);
        if (resume==2) { /*resume es 'win' de la pelea. Fight devuelve 2 si ganaste, 0 si perdes. */
            if (difficulty != 3) {                 /* aca se guardan los archivos */
                printf("\nGuardando partida...\n");
                delay(3);
                if (difficulty == 1) {
                    char str[] = "TOX1";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                } else {
                    char str[] = "TOX2";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                }
                printf("\nListo!");
                inputcontinue(&n);
                delay(1);
            }
            skip = skipstory(&skip);
            if (skip==0){
                Story_6();
            }
            Ierigol_04(player);
            skip = skipstory(&skip);
            if (skip==0){
                Story_7();
            }
            resume = Fight(player, difficulty);
            if (resume == 2) {
                if (difficulty != 3) {                 /* aca se guardan los archivos */
                    printf("\nGuardando partida...\n");
                    delay(3);
                    if (difficulty == 1) {
                        char str[] = "KIM1";
                        p = fopen("PlayerState.dat", "wb");
                        l = fopen("Location.txt", "wt");
                        fwrite(player, sizeof(Player), 1, p);
                        fwrite(str, 1, sizeof(str), l);
                        fclose(l);
                        fclose(p);
                    } else {
                        char str[] = "KIM2";
                        p = fopen("PlayerState.dat", "wb");
                        l = fopen("Location.txt", "wt");
                        fwrite(player, sizeof(Player), 1, p);
                        fwrite(str, 1, sizeof(str), l);
                        fclose(l);
                        fclose(p);
                    }
                    printf("\nListo!");
                    inputcontinue(&n);
                    delay(1);
                }
                skip = skipstory(&skip);
                if (skip==0){
                    Story_8();
                }
                Ierigol_05(player);
                skip = skipstory(&skip);
                if (skip==0){
                    Story_9(player);
                }
                resume = Fight(player, difficulty);
                if (resume==2){
                if (difficulty!=3){                 /* aca se guardan los archivos */
                printf("\nGuardando partida...\n");
                delay(3);
                if (difficulty==1){
                    char str[] = "DRA1";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                } else {
                    char str[] = "DRA2";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                }
                printf("\nListo!");
                inputcontinue(&n);
                delay(1);
            }
                /* Part1End(player); */
                skip = skipstory(&skip);
                if (skip==0){
                    Story_10(player);
                }
                Ierigol_06(player);
                skip = skipstory(&skip);
                if (skip==0){
                    Story_11();
                }
                resume = Fight(player, difficulty);
            }
            }
        }
    } else if (Load == 3){
        skip = skipstory(&skip);
            if (skip==0){
                Story_6();
            }
            Ierigol_04(player);
            skip = skipstory(&skip);
            if (skip==0){
                Story_7();
            }
            resume = Fight(player, difficulty);
            if (resume==2) {
                if (difficulty != 3) {                 /* aca se guardan los archivos */
                    printf("\nGuardando partida...\n");
                    delay(3);
                    if (difficulty == 1) {
                        char str[] = "KIM1";
                        p = fopen("PlayerState.dat", "wb");
                        l = fopen("Location.txt", "wt");
                        fwrite(player, sizeof(Player), 1, p);
                        fwrite(str, 1, sizeof(str), l);
                        fclose(l);
                        fclose(p);
                    } else {
                        char str[] = "KIM2";
                        p = fopen("PlayerState.dat", "wb");
                        l = fopen("Location.txt", "wt");
                        fwrite(player, sizeof(Player), 1, p);
                        fwrite(str, 1, sizeof(str), l);
                        fclose(l);
                        fclose(p);
                    }
                    printf("\nListo!");
                    inputcontinue(&n);
                    delay(1);
                }
                skip = skipstory(&skip);
                if (skip==0){
                    Story_8();
                }
                Ierigol_05(player);
                skip = skipstory(&skip);
                if (skip==0){
                    Story_9(player);
                }
                resume = Fight(player, difficulty);
                if (resume==2){
                if (difficulty!=3){                 /* aca se guardan los archivos */
                printf("\nGuardando partida...\n");
                delay(3);
                if (difficulty==1){
                    char str[] = "DRA1";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                } else {
                    char str[] = "DRA2";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                }
                printf("\nListo!");
                inputcontinue(&n);
                delay(1);
            }
                /* Part1End(player); */
                skip = skipstory(&skip);
                if (skip==0){
                    Story_10(player);
                }
                Ierigol_06(player);
                skip = skipstory(&skip);
                if (skip==0){
                    Story_11();
                }
                resume = Fight(player, difficulty);
            }
            }
    } else if (Load == 4){
        skip = skipstory(&skip);
            if (skip==0){
                Story_8();
            }
            Ierigol_05(player);
            skip = skipstory(&skip);
            if (skip==0){
                Story_9(player);
            }
            resume = Fight(player, difficulty);
            if (resume==2){
                if (difficulty!=3){                 /* aca se guardan los archivos */
                printf("\nGuardando partida...\n");
                delay(3);
                if (difficulty==1){
                    char str[] = "DRA1";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                } else {
                    char str[] = "DRA2";
                    p = fopen("PlayerState.dat", "wb");
                    l = fopen("Location.txt", "wt");
                    fwrite(player, sizeof(Player), 1, p);
                    fwrite(str, 1, sizeof(str), l);
                    fclose(l);
                    fclose(p);
                }
                printf("\nListo!");
                inputcontinue(&n);
                delay(1);
            }
                /* Part1End(player); */
                skip = skipstory(&skip);
                if (skip==0){
                    Story_10(player);
                }
                Ierigol_06(player);
                skip = skipstory(&skip);
                if (skip==0){
                    Story_11();
                }
                resume = Fight(player, difficulty);
            }
    } else if (Load == 5){
         /* Part1End(player); */
        skip = skipstory(&skip);
        if (skip==0){
            Story_10(player);
        }
        Ierigol_06(player);
        skip = skipstory(&skip);
        if (skip==0){
            Story_11();
        }
        resume = Fight(player, difficulty);
    } else {

    }
}
#endif //THE_HERETIC_GAME_STRUCTURE_H
