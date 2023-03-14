#ifndef THE_HERETIC_FIGHT_H
#define THE_HERETIC_FIGHT_H

int Fight(Player *player, int difficulty);
void GenerateEnemy(Player *player, Enemy *enemy, int difficulty, int *uniqueuse1, int *uniqueuse2); /* Esto determina contra que enemigo peleas */
void COUNTCalculator (Player *player); /* solo para COUNT, en dificultad 3 */
void UpdateStats(Player *player, Enemy *enemy);
void DotCalculator(Player *player, Enemy *enemy);
void refreshPlayerBuffs(Player *player);
void updateEnemyBuffsENDGAME(Enemy *enemy, Player *player); /*solamente recalcula el x2, NO AJUSTA TURNOS */
void refreshEnemyBuffs(Enemy *enemy);
void updatePlayerBuffsENDGAME(Player *player); /* solamente recalcula el x2, NO AJUSTA TURNOS */
void Hate_LoveLuck(Player *player, Enemy *enemy); /* esto tambien aplica el cap del 80%, asi que es importante que vaya al final del turno*/
void SelectAction(Player *player, Enemy *enemy, int *playeraction, int *padineta, int *rebote);
void Battle(Player *player, Enemy *enemy, int difficulty, int playeraction, int *lps, int *les, int *reps_lps, int *reps_les, int *uniqueuse1, int *uniqueuse2, int *rebote);
void printenemyshortinfo(Enemy *enemy);
void printplayercompletemenu(Player *player, int *padineta);
void GuardianGameOver(Player *player);
void FinalBossGameOver(Player *player);
void VictoryMessage(Enemy *enemy);

int Fight(Player *player, int difficulty) { /* Importante, este es el esquema prototipo de pelea basica, para futuro */
    int win = 1, playeraction, lps = 0, reps_lps = 0, les = 0, reps_les = 0, padineta=-1, uniqueuse1, uniqueuse2, rebote=0;
                                                /* 0-Game Over, 2-Win */
                                                /* 'playeraction' es la opcion del menu del jugador. 'lps'=LastPlayerSkill y 'les'=LastEnemySkill. Son para checkear cual fue la ultima habilidad tirada.*/
                                                /* 'reps_lps' y 'reps_les' son la cantidad de veces que van tirando una skill */ /*padineta se vuelve 1 si player.keyitem==2 */
                                                /* 'uniqueuse1 y uniqueuse2 son habilidades de uso unico usadas por algunos enemigos */
    Enemy enemy;                                /* 'rebote' es para los espejitos rebotin del dragon */
    GenerateEnemy(player, &enemy, difficulty, &uniqueuse1, &uniqueuse2);
    playerstats(player);  /* Se generan enemy y player. Se recarga la vida de player */
    refillplayer(player);
    refreshPlayerBuffs(player);
    refreshEnemyBuffs(&enemy);
    Hate_LoveLuck(player, &enemy);
    if (player->keyitem2 == -1){
        player->keyitem2 = 1;
    } else if (player->keyitem2 == 2){
        padineta = 1;
    }

    while (win == 1 && player->COUNT > 0) {
        if (difficulty==3){ COUNTCalculator(player); }
        if (player->COUNT > 0) {
            printf("\n\n\n\n\n\n");
            if (difficulty == 3) {
                printf("\nTurnos restantes antes de que el contador llegue a 0: %d\n", player->COUNT);
            }
            UpdateStats(player, &enemy);
            DotCalculator(player, &enemy);
            if (player->HP > 0 && enemy.HP > 0) {
                if (((lps==6 || lps==26) && reps_lps==1) || ((lps==6 || lps==26) && reps_lps==3)){
                    /*6=levantamuros y *26= detonamuros*/
                } else {
                    SelectAction(player, &enemy, &playeraction, &padineta, &rebote);
                }
                Battle(player, &enemy, difficulty, playeraction, &lps, &les, &reps_lps, &reps_les, &uniqueuse1, &uniqueuse2, &rebote);
            }
            if (player->HP <= 0) {
                if (player->keyitem2 == 1 && player->COUNT>0){
                    win = usetalismanofeve(player);
                } else {
                   win = 0;
                }
            } else if (enemy.HP <= 0) {
                win = 2;
            }
        }
    }
    if (win == 0) {
        if (strcmp(enemy.name, "Aluty")==0){
            FinalBossGameOver(player);
            return 0;
        } else {
            GuardianGameOver(player);
            return 0;
        }
    } else { /* Win */
        VictoryMessage(&enemy);
        inputcontinue(&win);
        return win + 1;
    }
}

void GenerateEnemy(Player *player, Enemy *enemy, int difficulty, int *uniqueuse1, int *uniqueuse2){
    if (player->skills[4].skillCode==0){
        EduStats(enemy);
        if (difficulty==3){
            player->COUNT = 16;
        }
    } else if (player->statupgrade1==0 && player->statupgrade2==0 && player->statupgrade3==0 && player->statupgrade4==0){
        GabotStats(enemy);
        if (difficulty==3){
            player->COUNT = 26;
        }
        if (difficulty!=1){
            *uniqueuse1 = 1;
        }
    } else if (player->skills[5].skillCode==0){
        ToxStats(enemy);
        if (difficulty==3){
            player->COUNT = 19;
        }
    } else if ((player->statupgrade1 + player->statupgrade2 + player->statupgrade3 + player->statupgrade4)<4){
        KStats(enemy);
        if (difficulty==3){
            player->COUNT = 26;
        }
        if (difficulty!=1){
            *uniqueuse1 = 1;
        }
    } else if (player->keyitem3==0){
        DragonStats(enemy);
        if (difficulty==3){
            player->COUNT = 25;
        }
    } else {
        AlutyStats(enemy);
        if (difficulty==3){
            player->COUNT = 31;
        }
    }
}

void COUNTCalculator(Player *player){
        player->COUNT = player->COUNT - 1;
        if (player->COUNT == 0) {
            player->HP = 0;
        }
}

void UpdateStats(Player *player, Enemy *enemy){
    player->atk = player->atkbuff - player->atkdebuff;
    player->def = player->defbuff - player->defdebuff;
    player->speed = player->basespeed + player->spdbuff - player->spddebuff;
    player->critchance = player->basecritchance + player->critchancebuff - player->critchancedebuff;
    player->dodge = player->basedodge + player->dodgebuff - player->dodgedebuff;

    enemy->atk = enemy->atkbuff - enemy->atkdebuff;
    enemy->def = enemy->defbuff - enemy->defdebuff;
    enemy->speed = enemy->basespeed + enemy->spdbuff - enemy->spddebuff;
    enemy->critchance = enemy->basecritchance + enemy->critchancebuff - enemy->critchancedebuff;
    enemy->dodge = enemy->basedodge + enemy->dodgebuff - enemy->dodgedebuff;

    if (player->MP < 0){
        player->MP = 0;
    }
    Hate_LoveLuck(player, enemy);
}

void DotCalculator(Player *player, Enemy *enemy){
    if (player->dot > 0) {
        player->HP = player->HP - player->dot;
        if (player->turnsdot == 1){
            printf("\n ||->>>>  Has recibido %d de dano periodico! El efecto termino.", player->dot);
        } else {
            printf("\n ||->>>>  Has recibido %d de dano periodico! Quedan %d turnos", player->dot, player->turnsdot - 1);
        }
    }
    if (player->hot > 0) {
        player->HP = player->HP + player->hot;
        if (player->HP > player->HPMax) {
            player->HP = player->HPMax;
        }
        if (player->turnshot == 1){
            printf("\n ||->>>>  Te has curado %d de vida periodicamente! El efecto termino.\n", player->hot);
        } else {
            printf("\n ||->>>>  Te has curado %d de vida periodicamente! Quedan %d turnos\n", player->hot, player->turnshot - 1);
        }
    }

    if (enemy->dot > 0) {
        enemy->HP = enemy->HP - enemy->dot;
        if (strcmp(enemy->name, "Aluty")==0){
            if (enemy->turnsdot == 1){
                printf("\n ||->>>>  El Dios del Cosmos, %s, ha recibido %d de dano periodico! El efecto termino.\n", enemy->name, enemy->dot);
            } else {
                printf("\n ||->>>>  El Dios del Cosmos, %s, ha recibido %d de dano periodico! Quedan %d turnos\n", enemy->name, enemy->dot, enemy->turnsdot - 1);
            }
        } else {
            if (enemy->turnsdot == 1){
                printf("\n ||->>>>  El Guardian, %s, ha recibido %d de dano periodico! El efecto termino.\n", enemy->name, enemy->dot);
            } else {
                printf("\n ||->>>>  El Guardian, %s, ha recibido %d de dano periodico! Quedan %d turnos\n", enemy->name, enemy->dot, enemy->turnsdot - 1);
            }
        }
    }
    if (enemy->hot > 0) {
        enemy->HP = enemy->HP + enemy->hot;
        if (enemy->HP > enemy->HPMax) {
            enemy->HP = enemy->HPMax;
        }
        if (strcmp(enemy->name, "Aluty")==0){
            if (enemy->turnshot == 1){
                printf("\n ||->>>>  El dios del cosmos, %s, ha recuperado %d de HP periodicamente! El efecto termino.\n", enemy->name, enemy->hot);
            } else {
                printf("\n ||->>>>  El dios del cosmos, %s, ha recuperado %d de HP periodicamente! Quedan %d turnos\n", enemy->name, enemy->hot, enemy->turnshot - 1);
            }
        } else {
            if (enemy->turnshot == 1){
                printf("\n ||->>>>  El guardian, %s, se ha curado %d de HP periodicamente! El efecto termino.\n", enemy->name, enemy->hot);
            } else {
                printf("\n ||->>>>  El guardian, %s, se ha curado %d de HP periodicamente! Quedan %d turnos\n", enemy->name, enemy->hot, enemy->turnshot - 1);
            }
        }

    }

    if (player->turnsdot>0){
        player->turnsdot--;
        if (player->turnsdot==0){
            player->dot = 0;
        }
    }
    if (player->turnshot>0){
        player->turnshot--;
        if (player->turnshot==0){
            player->hot = 0;
        }
    }
    if (enemy->turnsdot>0){
        enemy->turnsdot--;
        if (enemy->turnsdot==0){
            enemy->dot = 0;
        }
    }
    if (enemy->turnshot>0){
        enemy->turnshot--;
        if (enemy->turnshot==0){
            enemy->hot = 0;
        }
    }
}

void refreshPlayerBuffs(Player *player){ /* baja el contador de turnos de cada buff/debuff/dot/cds en 1. atk, def, speed, crit, dodge, reflect, dot, cooldown.*/
        int i=0;                                         /*SIEMPRE SE EJECUTA AL PRINCIPIO DE CADA TURNO. por ende, hacer que las habilidades tengan +1 de turno*/
                                                                 /*Ejemplo: aliento de fuego: dot por 3 turnos. Que sean 4 turnos (3, 2, 1. Porque el 0 no cuenta) */
    if (player->turnsatkbuff>0){                                         /*Ejemplo 2: Buff 50% prox turno. Que sean 2 turnos (1). */
        player->turnsatkbuff--;
        if (player->turnsatkbuff==0){
            player->atkbuff = 0;
        }
    }
    if (player->turnsatkdebuff>0){
        player->turnsatkdebuff--;
        if (player->turnsatkdebuff==0){
            player->atkdebuff = 0;
        }
    }
    if (player->turnsdefbuff>0){
        player->turnsdefbuff--;
        if (player->turnsdefbuff==0){
            player->defbuff = 0;
        }
    }
    if (player->turnsdefdebuff>0){
        player->turnsdefdebuff--;
        if (player->turnsdefdebuff==0){
            player->defdebuff = 0;
        }
    }
    if (player->turnsspdbuff>0){
        player->turnsspdbuff--;
        if (player->turnsspdbuff==0){
            player->spdbuff = 0;
        }
    }
    if (player->turnsspddebuff>0){
        player->turnsspddebuff--;
        if (player->turnsspddebuff==0){
            player->spddebuff = 0;
        }
    }
    if (player->turnscritchancebuff>0){
        player->turnscritchancebuff--;
        if (player->turnscritchancebuff==0){
            player->critchancebuff = 0;
        }
    }
    if (player->turnscritchancedebuff>0){
        player->turnscritchancedebuff--;
        if (player->turnscritchancedebuff==0){
            player->critchancedebuff = 0;
        }
    }
    if (player->turnsdodgebuff>0){
        player->turnsdodgebuff--;
        if (player->turnsdodgebuff==0){
            player->dodgebuff = 0;
        }
    }
    if (player->turnsdodgedebuff>0){
        player->turnsdodgedebuff--;
        if (player->turnsdodgedebuff==0){
            player->dodgedebuff = 0;
        }
    }
    if (player->turnsreflect>0){
        player->turnsreflect--;
        if (player->turnsreflect==0){
            player->reflect = 0;
        }
    }

    player->atk = player->atkbuff - player->atkdebuff;
    player->def = player->defbuff - player->defdebuff;
    player->speed = player->basespeed + player->spdbuff - player->spddebuff;
    player->critchance = player->basecritchance + player->critchancebuff - player->critchancedebuff;
    player->dodge = player->basedodge + player->dodgebuff - player->dodgedebuff;

    while (player->skills[i].skillCode!=0){
        if (player->skills[i].cooldown>0){
            player->skills[i].cooldown--;
        }
        i = i+1;
    }
}

void updateEnemyBuffsENDGAME(Enemy *enemy, Player *player){
    if (player->keyitem3==2){
        enemy->atk = (enemy->atkbuff * 2) - (enemy->atkdebuff * 2);
        enemy->speed = enemy->basespeed + (enemy->spdbuff * 2) - (enemy->spddebuff * 2);
        enemy->critchance = enemy->basecritchance + (enemy->critchancebuff * 2) - (enemy->critchancedebuff * 2);
        enemy->dodge = enemy->basedodge + (enemy->dodgebuff * 2) - (enemy->dodgedebuff * 2);
    }
}

void refreshEnemyBuffs(Enemy *enemy){
    if (enemy->turnsatkbuff>0){
        enemy->turnsatkbuff--;
        if (enemy->turnsatkbuff==0){
            enemy->atkbuff = 0;
        }
    }
    if (enemy->turnsatkdebuff>0){
        enemy->turnsatkdebuff--;
        if (enemy->turnsatkdebuff==0){
            enemy->atkdebuff = 0;
        }
    }
    if (enemy->turnsdefbuff>0){
        enemy->turnsdefbuff--;
        if (enemy->turnsdefbuff==0){
            enemy->defbuff = 0;
        }
    }
    if (enemy->turnsdefdebuff>0){
        enemy->turnsdefdebuff--;
        if (enemy->turnsdefdebuff==0){
            enemy->defdebuff = 0;
        }
    }
    if (enemy->turnsspdbuff>0){
        enemy->turnsspdbuff--;
        if (enemy->turnsspdbuff==0){
            enemy->spdbuff = 0;
        }
    }
    if (enemy->turnsspddebuff>0){
        enemy->turnsspddebuff--;
        if (enemy->turnsspddebuff==0){
            enemy->spddebuff = 0;
        }
    }
    if (enemy->turnscritchancebuff>0){
        enemy->turnscritchancebuff--;
        if (enemy->turnscritchancebuff==0){
            enemy->critchancebuff = 0;
        }
    }
    if (enemy->turnscritchancedebuff>0){
        enemy->turnscritchancedebuff--;
        if (enemy->turnscritchancedebuff==0){
            enemy->critchancedebuff = 0;
        }
    }
    if (enemy->turnsdodgebuff>0){
        enemy->turnsdodgebuff--;
        if (enemy->turnsdodgebuff==0){
            enemy->dodgebuff = 0;
        }
    }
    if (enemy->turnsdodgedebuff>0){
        enemy->turnsdodgedebuff--;
        if (enemy->turnsdodgedebuff==0){
            enemy->dodgedebuff = 0;
        }
    }
    if (enemy->turnsreflect>0){
        enemy->turnsreflect--;
        if (enemy->turnsreflect==0){
            enemy->reflect = 0;
        }
    }

    enemy->atk = enemy->atkbuff - enemy->atkdebuff;
    enemy->def = enemy->defbuff - enemy->defdebuff;
    enemy->speed = enemy->basespeed + enemy->spdbuff - enemy->spddebuff;
    enemy->critchance = enemy->basecritchance + enemy->critchancebuff - enemy->critchancedebuff;
    enemy->dodge = enemy->basedodge + enemy->dodgebuff - enemy->dodgedebuff;
}

void updatePlayerBuffsENDGAME(Player *player){
    if (player->keyitem3==2){
        player->atk = (player->atkbuff * 2) - (player->atkdebuff * 2);
        player->speed = player->basespeed + (player->spdbuff * 2) - (player->spddebuff * 2);
        player->critchance = player->basecritchance + (player->critchancebuff * 2) - (player->critchancedebuff * 2);
        player->dodge = player->basedodge + (player->dodgebuff * 2) - (player->dodgedebuff * 2);
    }
}

void Hate_LoveLuck(Player *player, Enemy *enemy){
    if (validateskill(player, 8, 7)==0){
        player->critchance = 0;
        enemy->critchance = 0;
        player->dodge = 0;
        enemy->dodge = 0;
    }
    if (validateskill(player, 28, 7)==0){
        player->critchance = player->critchance * 1.75;
        if (player->critchance>80){
            player->critchance = 80;
        }
        enemy->critchance = enemy->critchance * 2;
        if (enemy->critchance>80){
            enemy->critchance = 80;
        }
        player->dodge = player->dodge * 1.75;
        if (player->dodge>80){
            player->dodge = 80;
        }
    }
}

void SelectAction(Player *player, Enemy *enemy, int *playeraction, int *padineta, int *rebote){ /* para las proximas peleas, acordarse de los items */
    int MPCost, playeritem;

    printf("\n\n");
    if (player->HP == 1){
        printf("\nTuviste bastante suerte no? Te queda 1 HP\n");
    } else if ((player->HP < ((player->HPMax * 10) / 100))){
        printf("\nEstado Critico!\n");
    } else if (player->HP < ((player->HPMax * 30) / 100)){
        printf("\nCuidado! Tienes poca vida\n");
    }
    printenemyshortinfo(enemy);
    printf("Que deseas hacer, %s?  ", player->name);
    printf("HP: %d / %d   ||   MP: %d / %d\n\n", player->HP, player->HPMax, player->MP, player->MPMax);
    printplayercompletemenu(player, padineta);
    scanf("%d", playeraction);
    fflush(stdin);

    while (((player->skills[*playeraction - 1].skillCode == 0 || player->skills[*playeraction - 1].skillCode == 8 || player->skills[*playeraction - 1].skillCode == 28) && *playeraction != 0) || (*playeraction<0 || *playeraction>9) || (*playeraction==9 && *padineta<=0) || ((*playeraction==8) && (player->consumable1==0 && player->consumable2==0 && player->consumable3==0 && player->consumable4==0 && player->consumable5==0)) || (player->skills[*playeraction - 1].cooldown > 0 && (*playeraction>0 && *playeraction<8))){
        if (player->skills[*playeraction - 1].cooldown > 0 && (*playeraction>0 && *playeraction<8)){
            printf("Esa habilidad esta en enfriamiento\n");
        }
        printf("Ingresa una accion valida.\n");
        scanf("%d", playeraction);
        fflush(stdin);
    }

    if (*playeraction==8 && (player->consumable1>0 || player->consumable2>0 || player->consumable3>0 || player->consumable4>0 || player->consumable5>0)){
        printitems(player);
        printf("0-Volver atras\n");
        printf("Elija objeto\n");
        scanf("%d", &playeritem);
        fflush(stdin);
        while (playeritem<0 || playeritem>5 || (playeritem==1 && player->consumable1==0) || (playeritem==2 && player->consumable2==0) || (playeritem==3 && player->consumable3==0) || (playeritem==4 && player->consumable4==0) || (playeritem==5 && player->consumable5==0)){
            printf("Ingresa una accion valida\n");
            scanf("%d", &playeritem);
            fflush(stdin);
        }
        if (playeritem>0 && playeritem<6){
            consumeitem(player, playeritem, rebote);
            updateEnemyBuffsENDGAME(enemy, player);
            updatePlayerBuffsENDGAME(player);
            UpdateStats(player, enemy);
            SelectAction(player, enemy, playeraction, padineta, rebote);
        } else {
            SelectAction(player, enemy, playeraction, padineta, rebote);
        }
    }
    if (*playeraction!=0){
        MPCost = checkMPcosts(player, player->skills[*playeraction - 1].skillCode);
        while (MPCost!=1){
            printf("\nNo tenes MP para usar esa habilidad.\n");
            printf("\nElegi una nueva accion\n");
            scanf("%d", playeraction);
            fflush(stdin);
            while (player->skills[*playeraction - 1].skillCode == 0 && *playeraction != 0){
                printf("Ingresa una accion valida\n");
                scanf("%d", playeraction);
                fflush(stdin);
            }
            MPCost = checkMPcosts(player, player->skills[*playeraction - 1].skillCode);
        }
    }
    if (*playeraction==9){
        *padineta = 0;
    }
}

void Battle(Player *player, Enemy *enemy, int difficulty, int playeraction, int *lps, int *les, int *reps_lps, int *reps_les, int *uniqueuse1, int *uniqueuse2, int *rebote) {
    if ((player->speed >= enemy->speed && ((player->skills[playeraction - 1].skillCode != 11) && (player->skills[playeraction - 1].skillCode != 15))) || playeraction == 9 || player->skills[playeraction - 1].skillCode == 13 || player->skills[playeraction - 1].skillCode == 17) { /* Primero player, Segundo Enemy. Si usa Patagonia Strike, no. */
        if (playeraction == 9) {
            usepadineta(player, enemy, les);
            updateEnemyBuffsENDGAME(enemy, player);
            updatePlayerBuffsENDGAME(player);
            *lps = 18;
            *reps_lps = *reps_lps + 1;
            updateEnemyBuffsENDGAME(enemy, player);
            updatePlayerBuffsENDGAME(player);
            UpdateStats(player, enemy);
        } else {
            if (*lps == player->skills[playeraction - 1].skillCode) {
                *reps_lps = *reps_lps + 1;
            } else {
                *lps = player->skills[playeraction - 1].skillCode;
                *reps_lps = 1;
            }
            Player_Action(player, enemy, player->skills[playeraction - 1].skillCode, lps, les, reps_lps, reps_les);
            UpdateStats(player, enemy);
            refreshPlayerBuffs(player);
            updateEnemyBuffsENDGAME(enemy, player);
            updatePlayerBuffsENDGAME(player);
            Hate_LoveLuck(player, enemy);
            if (enemy->HP > 0) {
                if (*les==19){
                    *les=0;
                    printf("\nEl enemigo ha perdido su turno, producto del fuerte Padinetazo en la cabeza!\n");
                    delay(4);
                } else {
                    Enemy_Action(player, enemy, difficulty, player->skills[playeraction - 1].skillCode, lps, les, reps_lps, reps_les, uniqueuse1, uniqueuse2, rebote);
                }
                UpdateStats(player, enemy);
                refreshEnemyBuffs(enemy);
                updateEnemyBuffsENDGAME(enemy, player);
                updatePlayerBuffsENDGAME(player);
                Hate_LoveLuck(player, enemy);
            }
        }
    } else {/* Primero Enemy, Segundo Player */
        if (*les==19){
            *les=0;
            printf("\nEl enemigo ha perdido su turno, producto del fuerte Padinetazo en la cabeza!\n");
        } else {
            Enemy_Action(player, enemy, difficulty, player->skills[playeraction - 1].skillCode, lps, les, reps_lps, reps_les, uniqueuse1, uniqueuse2, rebote);
        }
        UpdateStats(player, enemy);
        refreshEnemyBuffs(enemy);
        updateEnemyBuffsENDGAME(enemy, player);
        updatePlayerBuffsENDGAME(player);
        Hate_LoveLuck(player, enemy);
        if (playeraction != 0 && player->HP > 0) {
            if (*lps == player->skills[playeraction - 1].skillCode) {
                *reps_lps = *reps_lps + 1;
            } else {
                *lps = player->skills[playeraction - 1].skillCode;
                *reps_lps = 1;
            }
            Player_Action(player, enemy, player->skills[playeraction - 1].skillCode, lps, les, reps_lps, reps_les);
            UpdateStats(player, enemy);
            refreshPlayerBuffs(player);
            updateEnemyBuffsENDGAME(enemy, player);
            updatePlayerBuffsENDGAME(player);
            Hate_LoveLuck(player, enemy);
        }
    }
    if (*rebote == 1){
        *rebote = 0;
    }
}

void printenemyshortinfo(Enemy *enemy){
    if (strcmp(enemy->name, "EDU")==0){
        printf("                                                                                 EDU, El Extranjero: %d / %d HP\n", enemy->HP, enemy->HPMax);
        printf("                                                                                 (ataque:/%.0f%%/ | defensa:/%.0f%%/)\n", enemy->atk, enemy->def);
    } else if (strcmp(enemy->name, "Gabot")==0){
        printf("                                                                                 Gabot, La Pesadilla Mecanica: %d / %d HP\n", enemy->HP, enemy->HPMax);
        printf("                                                                                 (ataque:/%.0f%%/ | defensa:/%.0f%%/)\n", enemy->atk, enemy->def);
    } else if (strcmp(enemy->name, "Tox")==0){
        printf("                                                                                 Tox, El Destello Nuclear: %d / %d HP\n", enemy->HP, enemy->HPMax);
        printf("                                                                                 (ataque:/%.0f%%/ | defensa:/%.0f%%/)\n", enemy->atk, enemy->def);
    } else if (strcmp(enemy->name, "K")==0){
        printf("                                                                                 K, El Caballero Carmesi: %d / %d HP\n", enemy->HP, enemy->HPMax);
        printf("                                                                                 (ataque:/%.0f%%/ | defensa:/%.0f%%/)\n", enemy->atk, enemy->def);
    } else if (strcmp(enemy->name, "El dragon")==0){
        printf("                                                                                 La mascota del Senor: %d / %d HP\n", enemy->HP, enemy->HPMax);
        printf("                                                                                 (ataque:/%.0f%%/ | defensa:/%.0f%%/)\n", enemy->atk, enemy->def);
    } else if (strcmp(enemy->name, "Aluty")==0){
        printf("                                                                                 Aluty, Dios del Cosmos: %d / %d HP\n", enemy->HP, enemy->HPMax);
        printf("                                                                                 (ataque:/%.0f%%/ | defensa:/%.0f%%/)\n", enemy->atk, enemy->def);
    }
}

void printplayercompletemenu(Player *player, int *padineta){
    printplayernormalskills(player);
    printplayerspecialskills(player);
    if (player->consumable1>0 || player->consumable2>0 || player->consumable3>0 || player->consumable4>0 || player->consumable5>0){
        printf("8- Objetos\n");
    }
    if (player->keyitem2==2 && (*padineta)>0){
        printf("9- Usar Padineta: Cancela el turno del rival, hace un poco de dano y reduce su defensa un 50%% por 2 turnos. Usarla no termina tu turno. Solo 1 uso por pelea.\n");
    }
    printf("0- Pasar Turno.\n\n");
    showplayercooldowns(player);
    printf("\n                                                                        Nota: los valores numericos (no %%) varian\n\n");
    printf("Tu ataque: /%.0f%%/  |  Tu defensa: /%.0f%%/\n", player->atk, player->def);
    printf("Tu chance de criticos: /%d%%/  |  Tu chance de evasion: /%d%%/\n\n", player->critchance, player->dodge);
}

void GuardianGameOver(Player *player){
    printf("\n\n.");
    delay(1);
    printf("\n.");
    delay(1);
    printf("\n.");
    delay(1);/* Game Over en letras facheras*/
    if (player->COUNT == 0) {
        printf("\n...el contador que marcaba tu tiempo restante, ha llegado a 0.");
    } else {
        printf("\nTus HP han bajado a 0.\n");
    }
    delay(2);
    printf("\nNo puedes.. hacer nada. El guardian es demasiado fuerte.\n");
    delay(5);
    printf("\nTu existencia, %s, comienza a desvanecerse lentamente.\n", player->name);
    delay(4);
    printf("\n.. y asi, la aventura llega a su fin.\n");
    delay(6);
    printf("   ______\n");
    printf("  / ____/ ______   ____ ____   ____     ------  __   __  ____   _____\n");
    printf(" / / __/ /  __ `/ / __ `__  / /___ /   / / / / |  | / / /___/  / ___/\n");
    printf("/ /_/ / /  /_/ / / / / / / / / __/    / /_/ /  |  |/ / / __/  / /    \n");
    printf("|____/ /__/ /_/ /_/ /_/ /_/  |___/   /_____/   |____/  |___/ /_/     \n");
    printf("\n");
    delay(10);
}

void FinalBossGameOver(Player *player){
    printf("\n\n.");
    delay(1);
    printf("\n.");
    delay(1);
    printf("\n.");
}

void VictoryMessage(Enemy *enemy){
    printf("\n\n.");
    delay(1);
    printf("\n.");
    delay(1);
    printf("\n.");
    delay(1);
    if (strcmp(enemy->name, "EDU")==0){
        printf("\nCon el ultimo golpe, el guardian cae al suelo, inconsciente.\n");
        delay(4);
        printf("\nLuego de unos segundos, su diccionario comienza a perder paginas una por una.\n");
        delay(4);
        printf("Antes de perder la ultima pagina, Edu la sostiene de un extremo.\n");
        delay(5);
        printf("Y en un instante, el diccionario se desintegra. Junto con el primer guardian.\n");
        delay(5);
        printf("\nHas derrotado al primer guardian.\n");
        delay(3);
    } else if (strcmp(enemy->name, "Gabot")==0){
        printf("\nEl guardian empieza a soltar chispas, y llamaradas de fuego desde su interior.\n");
        delay(4);
        printf("\nParece que el dano causado ha llegado a un extremo irreparable.\n");
        delay(4);
        printf("\nEn un intento por hacer un ultimo ataque, el guardian entra en cortocircuito, causandole una explosion interna.\n");
        delay(4);
        printf("\nHas derrotado al segundo guardian.\n");
        delay(3);
    } else if (strcmp(enemy->name, "Tox")==0){
        printf("\nEl Guardian se retuerce de dolor, y su apariencia se torna similar a una persona.\n");
        delay(6);
        printf("\nEse ultimo impacto fue suficiente para hacer caer al Amo de la Toxicidad.\n");
        delay(6);
        printf("\nHay un ultimo destello, con el que logra proyectar unas letras en el aire para proyectar un ultimo mensaje.\n");
        delay(6);
        printf("\n            'La oscuridad aguarda en el recinto del proximo guardian'\n");
        delay(6);
        printf("\nSegundos despues, el tercer guardan cae apagado. \n");
        delay(6);
        printf("\nHas derrotado al tercer guardian.\n");
        delay(3);

    } else if (strcmp(enemy->name, "K")==0){
        printf("\nAl asestar el golpe de gracia, notas que el mandoble se empieza a resquebrajar.\n");
        delay(5);
        printf("\nLuego de un breve instante, este se rompe en mil pedazos, liberando a todas las almas encerradas.\n");
        delay(5);
        printf("\nEl caballero yace de rodillas, vencido, inerte. Mueves su casco a un costado, para descubrir una extrana verdad.\n");
        delay(6);
        printf("\nNo hay nadie dentro de la armadura..\n");
        delay(6);
        printf("\nHas derrotado al cuarto guardian.\n");
        delay(3);

    } else if (strcmp(enemy->name, "El dragon")==0){
        printf("\n            |¬¬¬> Ugh.... es suficiente. <¬¬¬|\n");
        delay(5);
        printf("\n            |¬¬¬> Veo el brillo en tu forma de combatir. Tus movimientos e intelecto han sido lo que te han otorgado la merecida victoria. <¬¬¬|\n");
        delay(7);
        printf("\n            |¬¬¬> Creo, que debo admitir mi derrota. <¬¬¬|\n");
        delay(6);
        printf("\n            |¬¬¬> Solamente espero que lo que decidas hacer de aqui en adelante, mantenga el equilibrio del universo. <¬¬¬|\n");
        delay(7);
        printf("\n            |¬¬¬> Lo siento mucho, mi amo... <¬¬¬|\n");
        delay(6);
        printf("\nHas derrotado al sexto guardian.\n");
        delay(3);
    } else if (strcmp(enemy->name, "Aluty")==0){

    }
}

#endif //THE_HERETIC_FIGHT_H
