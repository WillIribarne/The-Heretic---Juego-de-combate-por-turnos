#ifndef THE_HERETIC_PLAYER_H
#define THE_HERETIC_PLAYER_H

typedef struct{
    int skillCode;
    unsigned int cooldown;
}Skill;

typedef struct{
    int HPMax, MPMax, MP, HP, basespeed, basecritchance, basedodge, speed, critchance, dodge, atkbuff, defbuff, spdbuff, atkdebuff, defdebuff, spddebuff, critchancebuff, critchancedebuff, dodgebuff, dodgedebuff, dot, hot; /* solo valores */
    float atk, def, reflect;
    unsigned int COUNT, turnsatkbuff, turnsdefbuff, turnsspdbuff, turnsatkdebuff, turnsdefdebuff, turnsspddebuff, turnsreflect, turnsdot, turnshot, turnscritchancebuff, turnscritchancedebuff, turnsdodgebuff, turnsdodgedebuff, consumable1, consumable2, consumable3, consumable4, consumable5, keyitem1, keyitem2, keyitem3, statupgrade1, statupgrade2, statupgrade3, statupgrade4; /* solo numero de turnos o cantidades */
    char name[20], type[10], skillupgrade[13]; /*Skill upgrade es 0->Skill 1, 1->Skill 2, y asi. */
    Skill skills[7];
}Player;

void playerstats(Player *player);
void clearplayeritems(Player *player);
void clearplayerskills(Player *player);
void clearskillupgrades(Player *player);
void clearstatupgrades(Player *player);
void refillplayer(Player *player);
void showplayercooldowns(Player *player);
void printitems(Player *player);
void printallitemsQuantity(Player *player);
void printkeyitem(int keyitem, Player *player);
void printkeyitems(Player *player);
void consumeitem(Player *player, int consume, int *rebote);

void playerstats(Player *player){ /* faltan meter los items y mejoras restantes */ /* se usa ANTES DE CADA PELEA */
    player->HPMax = 300;
    player->MPMax = 10;
    player->basespeed = 30;
    player->basecritchance = 5;
    player->basedodge = 5;
    player->atk = 0;
    player->atkbuff = 0;
    player->atkdebuff = 0;
    player->turnsatkbuff = 0;
    player->turnsatkdebuff = 0;
    player->def = 0;
    player->defbuff = 0;
    player->defdebuff = 0;
    player->turnsdefbuff = 0;
    player->turnsdefdebuff = 0;
    player->speed = 0;
    player->spdbuff = 0;
    player->spddebuff = 0;
    player->turnsspdbuff = 0;
    player->turnsspddebuff = 0;
    player->critchance = 0;
    player->critchancebuff = 0;
    player->critchancedebuff = 0;
    player->turnscritchancebuff = 0;
    player->turnscritchancedebuff = 0;
    player->dodge = 0;
    player->dodgebuff = 0;
    player->dodgedebuff = 0;
    player->turnsdodgebuff = 0;
    player->turnsdodgedebuff = 0;
    player->reflect = 0;
    player->turnsreflect = 0;
    player->dot = 0;
    player->turnsdot = 0;
    player->hot = 0;
    player->turnshot = 0;
    player->COUNT = 9999;

    for (int i=0; i<7; i++){
        if (player->skills[i].skillCode!=0){
            player->skills[i].cooldown = 0;
        }
    }

    if (player->keyitem1==1){
        player->basespeed = 40;
    } else if (player->keyitem1==2){
        player->basecritchance = player->basecritchance + 10;
    } else if (player->keyitem1==3){
        player->basedodge = player->basedodge + 8;
    }
    if (player->statupgrade1>0){
        player->HPMax = player->HPMax + (75 * player->statupgrade1);
    }
    if (player->statupgrade2>0){
        player->MPMax = player->MPMax + (5 * player->statupgrade2);
    }
    if (player->statupgrade3>0){
        player->basecritchance = player->basecritchance + (8 * player->statupgrade3);
    }
    if (player->statupgrade4>0){
        player->basedodge = player->basedodge + (8 * player->statupgrade4);
    }
}

void clearplayeritems(Player *player){
    player->consumable1 = 0;
    player->consumable2 = 0;
    player->consumable3 = 0;
    player->consumable4 = 0;
    player->consumable5 = 0;
    player->keyitem1 = 0;
    player->keyitem2 = 0;
    player->keyitem3 = 0;
}

void clearplayerskills(Player *player){
    for (int i=0; i<7; i++){
        player->skills[i].skillCode = 0;
        player->skills[i].cooldown = 0;
    }
}

void clearskillupgrades(Player *player){
    for (int i=0; i < 13; i++){
        player->skillupgrade[i] = 'n';
    }
}

void clearstatupgrades(Player *player){
    player->statupgrade1 = 0;
    player->statupgrade2 = 0;
    player->statupgrade3 = 0;
    player->statupgrade4 = 0;
}

void refillplayer(Player *player){
    player->HP = player->HPMax;
    player->MP = player->MPMax;
}

void showplayercooldowns(Player *player){
    int i=0;
    while (player->skills[i].skillCode!=0 && i<7){
        if (player->skills[i].cooldown>0){
            printf("(Habilidad %d en enfriamiento: %d turno/s)\n", i+1, player->skills[i].cooldown);
        }
        i = i+1;
    }
}

void printitems(Player *player){
    int n=0;

    if (player->consumable1>0){
        printf("1-Manaos (%d) = Cura 30%% de los HP Maximos\n", player->consumable1);
    }
    if (player->consumable2>0){
        printf("2-Fernet Branca (%d) = Aumenta tu ataque en 30%% por 3 turnos\n", player->consumable2);
    }
    if (player->consumable3>0){
        printf("3-Cafe con Leche (%d) = Aumenta tu reflejo en 50%% por 3 turnos (25%% por 1 turno si ya tienes un efecto de reflejo)\n", player->consumable3);
    }
    if (player->consumable4>0){
        printf("4-Baggio Multifruta (%d) = Cura todas las disminuciones de parametros y danos continuos del jugador\n", player->consumable4);
    }
    if (player->consumable5>0){
        printf("5-Espejito Rebotin (%d) = Refleja ataques elementales de bestias gigantescas.\n", player->consumable5);
    }
}

void printallitemsQuantity(Player *player){
    if (player->consumable1>0){
        printf("Manaos (%d) = Cura 30%% de los HP Maximos\n", player->consumable1);
    }
    if (player->consumable2>0){
        printf("Fernet Branca (%d) = Aumenta tu ataque en 30%% por 3 turnos\n", player->consumable2);
    }
    if (player->consumable3>0){
        printf("Cafe con Leche (%d) = Aumenta tu reflejo en 50%% por 3 turnos\n", player->consumable3);
    }
    if (player->consumable4>0){
        printf("Baggio Multifruta (%d) = Cura todas las disminuciones de parametros y danos continuos del jugador\n", player->consumable4);
    }
    if (player->consumable5>0){
        printf("Espejito Rebotin (%d) = Refleja ataques elementales de bestias gigantescas.\n", player->consumable5);
    }
}

void printkeyitem(int keyitem, Player *player){
    switch(keyitem){
        case 1: printf("Zafiro: Aumenta tu velocidad en 10 permanentemente. (Actual: %d)\n", player->basespeed);
            break;
        case 2: printf("Rubi: Aumenta tu chance critica en 10%% permanentemente.\n");
            break;
        case 3: printf("Esmeralda: Aumenta tu evasion en 8%% permanentemente.\n");
            break;
    }
}

void printkeyitems(Player *player){
    if (player->keyitem1==1){
        printf("Zafiro: Aumenta tu velocidad en 10 permanentemente. (Actual: %d)\n", player->basespeed);
    } else if (player->keyitem1==2){
        printf("Rubi: Aumenta tu chance critica en 10%% permanentemente. (Actual: %d%%)\n", player->basecritchance);
    } else {
        printf("Esmeralda: Aumenta tu evasion en 8%% permanentemente. (Actual: %d%%)\n", player->basedodge);
    }

    if (player->keyitem2==1){
        printf("Talisman de Eve: Permite resistir la muerte y revivir con 20%% de tus HPMax, pero solo una vez por combate.\n");
    } else if (player->keyitem2==2){
        printf("La Padineta: Cancela el turno del rival, hace un poco de dano y reduce su defensa un 50%% por 2 turnos. Usarla no termina tu turno, pero tiene solamente 1 uso por pelea.\n");
    }

    if (player->keyitem3==1){
        printf("Amuleto de la Patagonia: Parece que es un indicador de que eres Dueno de la Patagonia... Que efecto tendrá?\n");
    } else if (player->keyitem3==2){
        printf("Amuleto del Caos Absoluto: Todos los aumentos y reducciones de: ataque, velocidad, criticos y evasion, se duplican. \n");
    }
}

void consumeitem(Player *player, int consume, int *rebote){
    if (consume==1){
        player->HP = player->HP + ((player->HPMax * 3) / 10);
        if (player->HP > player->HPMax){
            player->HP = player->HPMax;
        }
        player->consumable1 = player->consumable1 - 1;

        printf("Te has tomado una Manaos. Has recuperado HP!\n");
        delay(3);
    }
    if (consume==2){
        player->atkbuff = 30;
        player->turnsatkbuff = 3;

        player->consumable2 = player->consumable2 - 1;

        printf("Te has tomado un Fernet Branca (sin.. coca?!). Tu ataque ha aumentado por 3 turnos!\n");
        delay(3);
    }
    if (consume==3){
        if (player->reflect == 0){
            player->reflect = 50;
            player->turnsreflect = 3;
        } else {
            player->reflect = player->reflect + 25;
        }


        player->consumable3 = player->consumable3 - 1;

        printf("Te has tomado un cafe con leche! Afilas tus reflejos en un 50%% por 3 turnos!\n");
        delay(3);
    }
    if (consume==4){
        player->atkdebuff = 0;
        player->turnsatkdebuff = 0;
        player->defdebuff = 0;
        player->turnsdefdebuff = 0;
        player->spddebuff = 0;
        player->turnsspddebuff = 0;
        player->critchancedebuff = 0;
        player->turnscritchancedebuff = 0;
        player->dodgedebuff = 0;
        player->turnsdodgedebuff = 0;
        player->dot = 0;
        player->turnsdot = 0;

        player->consumable4 = player->consumable4 - 1;

        printf("Te has tomado un juguito Baggio Multifruta. Tus debilitaciones se han eliminado!\n");
        delay(3);
    }
    if (consume==5){ /*Las mecanicas de rebote se ejecutan en los ataques de Faffy */
        *rebote = 1;
        player->consumable5 = player->consumable5 - 1;

        printf("Usaste un espejito rebotin! Esperemos que funcione..\n");
        delay(3);
    }

    player->atk = player->atkbuff - player->atkdebuff;
    player->def = player->defbuff - player->defdebuff;
    player->speed = player->basespeed + player->spdbuff - player->spddebuff;
    player->critchance = player->basecritchance + player->critchancebuff - player->critchancedebuff;
    player->dodge = player->basedodge + player->dodgebuff - player->dodgedebuff;
}

/* consumables son 1-Manaos  2-Fernecito  3-Cafe con leche  4-Baggio Multifruta  5-Espejito Rebotin*/
/* keyitems son 1-Zafiro | 2-Rubi | 3-Esmeralda |°|°| 4-Talisman de Eve | 5-Padineta |°|°| 6-Amuleto de la Patagonia | 7-Amuleto del reino del reves */

#endif //THE_HERETIC_PLAYER_H
