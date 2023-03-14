#ifndef THE_HERETIC_ENEMIES_H
#define THE_HERETIC_ENEMIES_H

#include "RNG.h"

typedef struct{
    int HPMax, HP, basespeed, basecritchance, basedodge, speed, critchance, dodge, atkbuff, defbuff, spdbuff, atkdebuff, defdebuff, spddebuff, critchancebuff, critchancedebuff, dodgebuff, dodgedebuff, dot, hot; /* solo valores */
    float atk, def, reflect;
    unsigned int turnsatkbuff, turnsdefbuff, turnsspdbuff, turnsatkdebuff, turnsdefdebuff, turnsspddebuff, turnsreflect, turnsdot, turnshot, turnscritchancebuff, turnscritchancedebuff, turnsdodgebuff, turnsdodgedebuff; /* solo numero de turnos o cantidades */
    char name[30], type[10];
}Enemy;


void Enemy_Action(Player *player, Enemy *enemy, int difficulty, int playerskill, int *lps, int *les, int *reps_lps, int *reps_les, int *uniqueuse1, int *uniqueuse2, int *rebote);
void EduStats(Enemy *edu);
void GabotStats(Enemy *gabot);
void ToxStats(Enemy *tox);
void KStats(Enemy *K);
void DragonStats(Enemy *dragon);
void AlutyStats(Enemy *aluty);
void EduAttack_1(Player *player, Enemy *edu, int difficulty, int playerskill, int *les); /* cada ataque enemigo tienen codigo; van desde el -1 hacia abajo */
void EduAttack_2(Enemy *edu, int difficulty, int *les);
void EduAttack_3(Enemy *edu, int *les);
void EduAttack_4(Enemy *edu, int *les);
void GabotAttack_1(Enemy *gabot, int *les);
void GabotAttack_2(Player *player, Enemy *gabot, int difficulty, int *les);
void GabotAttack_3(Player *player, Enemy *gabot, int difficulty, int *lps, int *les);
void GabotAttack_4(Enemy *gabot, int *les, int *uniqueuse1);
void ToxAttack_1(Player *player, Enemy *tox, int difficulty, int *les);
void ToxAttack_2(Enemy *tox, int *les);
void ToxAttack_3(Player *player, Enemy *tox, int *les);
void ToxAttack_4(Player *player, Enemy *tox, int difficulty, int *les);
void ToxAttack_5(Enemy *tox, int *les);
void ToxAttack_6(Enemy *tox, int *les);
void KAttack_1(Enemy *k, int difficulty, int *les);
void KAttack_2(Enemy *k, int *les);
void KAttack_3(Player *player, Enemy *k, int difficulty, int *les);
void KAttack_4(Player *player, Enemy *k, int difficulty, int *les);
void KAttack_5(Enemy *k, int *les);
void KAttack_6(Player *player, Enemy *k, int *les);
void FaffyAttack_1(Player *player, Enemy *faffy, int difficulty, int *les, int *rebote);
void FaffyAttack_2(Player *player, Enemy *faffy, int difficulty, int *les, int *rebote);
void FaffyAttack_3(Player *player, Enemy *faffy, int difficulty, int *les, int *rebote);
void FaffyAttack_4(Player *player, Enemy *faffy, int *les);
void FaffyAttack_5(Player *player, Enemy *faffy, int *les);
void FaffyAttack_6(Enemy *faffy, int *les);
void EduAction_1(Player *player, Enemy *edu, int playerskill, int *les); /* AI para dificultad facil */
void EduAction_2(Player *player, Enemy *edu, int playerskill, int *les); /* AI para dificultad dificil/willy */
void GabotAction_1(Player *player, Enemy *gabot, int *lps, int *les); /* AI para dificultad facil */
void GabotAction_2(Player *player, Enemy *gabot, int *lps, int *les, int *uniqueuse1); /* AI para dificultad dificil/willy */
void ToxAction_1(Player *player, Enemy *tox, int *lps, int *les); /* AI para dificultad facil */
void ToxAction_2(Player *player, Enemy *tox, int *lps, int *les); /* AI para dificultad dificil/willy */
void KAction_1(Player *player, Enemy *enemy, int *lps, int *les); /* AI para dificultad facil */
void KAction_2(Player *player, Enemy *enemy, int *lps, int *les, int *uniqueuse1); /* AI para dificultad dificil/willy */
void DragonAction_1(Player *player, Enemy *enemy, int *lps, int *les, int *rebote); /* AI para dificultad facil */
void DragonAction_2(Player *player, Enemy *enemy, int *lps, int *les, int *rebote); /* AI para dificultad dificil/willy */
void AlutyAction_1(Player *player, Enemy *enemy, int *lps, int *les); /* AI para dificultad facil */
void AlutyAction_2(Player *player, Enemy *enemy, int *lps, int *les); /* AI para dificultad dificil/willy */


void Enemy_Action(Player *player, Enemy *enemy, int difficulty, int playerskill, int *lps, int *les, int *reps_lps, int *reps_les, int *uniqueuse1, int *uniqueuse2, int *rebote){
    if (strcmp(enemy->name, "EDU")==0){
        if (difficulty==1){
            EduAction_1(player, enemy, playerskill, les);
        } else {
            EduAction_2(player, enemy, playerskill, les);
        }
    }
    if (strcmp(enemy->name, "Gabot")==0){
        if (difficulty==1){
            GabotAction_1(player, enemy, lps, les);
        } else {
            GabotAction_2(player, enemy, lps, les, uniqueuse1);
        }
    }
    if (strcmp(enemy->name, "Tox")==0){
        if (difficulty==1){
            ToxAction_1(player, enemy, lps, les);
        } else {
            ToxAction_2(player, enemy, lps, les);
        }
    }
    if (strcmp(enemy->name, "K")==0){
        if (difficulty==1){
            KAction_1(player, enemy, lps, les);
        } else {
            KAction_2(player, enemy, lps, les, uniqueuse1);
        }
    }
    if (strcmp(enemy->name, "El dragon")==0){
        if (difficulty==1){
            DragonAction_1(player, enemy, lps, les, rebote);
        } else {
            DragonAction_2(player, enemy, lps, les, rebote);
        }
    }
    if (strcmp(enemy->name, "Gabot")==0){
        if (difficulty==1){
            AlutyAction_1(player, enemy, lps, les);
        } else {
            AlutyAction_2(player, enemy, lps, les);
        }
    }
}

void EduStats(Enemy *edu){
    strcpy(edu->name, "EDU");
    edu->HPMax = 400;
    edu->HP = edu->HPMax;
    edu->basespeed = 20;
    edu->basecritchance = 5;
    edu->basedodge = 5;
    edu->atk = 0;
    edu->atkbuff = 0;
    edu->atkdebuff = 0;
    edu->turnsatkbuff = 0;
    edu->turnsatkdebuff = 0;
    edu->def = 0;
    edu->defbuff = 0;
    edu->defdebuff = 0;
    edu->turnsdefbuff = 0;
    edu->turnsdefdebuff = 0;
    edu->speed = 0;
    edu->spdbuff = 0;
    edu->spddebuff = 0;
    edu->turnsspdbuff = 0;
    edu->turnsspddebuff = 0;
    edu->critchance = 0;
    edu->critchancebuff = 0;
    edu->critchancedebuff = 0;
    edu->turnscritchancebuff = 0;
    edu->turnscritchancedebuff = 0;
    edu->dodge = 0;
    edu->dodgebuff = 0;
    edu->dodgedebuff = 0;
    edu->turnsdodgebuff = 0;
    edu->turnsdodgedebuff = 0;
    edu->reflect = 0;
    edu->turnsreflect = 0;
    edu->dot = 0;
    edu->turnsdot = 0;
    edu->hot = 0;
    edu->turnshot = 0;
}

void GabotStats(Enemy *gabot){
    strcpy(gabot->name, "Gabot");
    gabot->HPMax = 290;
    gabot->HP = gabot->HPMax;
    gabot->basespeed = 35;
    gabot->basecritchance = 8;
    gabot->basedodge = 14;
    gabot->atk = 0;
    gabot->atkbuff = 0;
    gabot->atkdebuff = 0;
    gabot->turnsatkbuff = 0;
    gabot->turnsatkdebuff = 0;
    gabot->def = 0;
    gabot->defbuff = 0;
    gabot->defdebuff = 0;
    gabot->turnsdefbuff = 0;
    gabot->turnsdefdebuff = 0;
    gabot->speed = 0;
    gabot->spdbuff = 0;
    gabot->spddebuff = 0;
    gabot->turnsspdbuff = 0;
    gabot->turnsspddebuff = 0;
    gabot->critchance = 0;
    gabot->critchancebuff = 0;
    gabot->critchancedebuff = 0;
    gabot->turnscritchancebuff = 0;
    gabot->turnscritchancedebuff = 0;
    gabot->dodge = 0;
    gabot->dodgebuff = 0;
    gabot->dodgedebuff = 0;
    gabot->turnsdodgebuff = 0;
    gabot->turnsdodgedebuff = 0;
    gabot->reflect = 0;
    gabot->turnsreflect = 0;
    gabot->dot = 0;
    gabot->turnsdot = 0;
    gabot->hot = 0;
    gabot->turnshot = 0;
}

void ToxStats(Enemy *tox){
    strcpy(tox->name, "Tox");
    tox->HPMax = 650;
    tox->HP = tox->HPMax;
    tox->basespeed = 80;
    tox->basecritchance = 10;
    tox->basedodge = 25;
    tox->atk = 0;
    tox->atkbuff = 0;
    tox->atkdebuff = 0;
    tox->turnsatkbuff = 0;
    tox->turnsatkdebuff = 0;
    tox->def = 0;
    tox->defbuff = 0;
    tox->defdebuff = 0;
    tox->turnsdefbuff = 0;
    tox->turnsdefdebuff = 0;
    tox->speed = 0;
    tox->spdbuff = 0;
    tox->spddebuff = 0;
    tox->turnsspdbuff = 0;
    tox->turnsspddebuff = 0;
    tox->critchance = 0;
    tox->critchancebuff = 0;
    tox->critchancedebuff = 0;
    tox->turnscritchancebuff = 0;
    tox->turnscritchancedebuff = 0;
    tox->dodge = 0;
    tox->dodgebuff = 0;
    tox->dodgedebuff = 0;
    tox->turnsdodgebuff = 0;
    tox->turnsdodgedebuff = 0;
    tox->reflect = 0;
    tox->turnsreflect = 0;
    tox->dot = 0;
    tox->turnsdot = 0;
    tox->hot = 0;
    tox->turnshot = 0;
}

void KStats(Enemy *K){
    strcpy(K->name, "K");
    K->HPMax = 800;
    K->HP = K->HPMax;
    K->basespeed = 20;
    K->basecritchance = 11;
    K->basedodge = 5;
    K->atk = 0;
    K->atkbuff = 0;
    K->atkdebuff = 0;
    K->turnsatkbuff = 0;
    K->turnsatkdebuff = 0;
    K->def = 0;
    K->defbuff = 0;
    K->defdebuff = 0;
    K->turnsdefbuff = 0;
    K->turnsdefdebuff = 0;
    K->speed = 0;
    K->spdbuff = 0;
    K->spddebuff = 0;
    K->turnsspdbuff = 0;
    K->turnsspddebuff = 0;
    K->critchance = 0;
    K->critchancebuff = 0;
    K->critchancedebuff = 0;
    K->turnscritchancebuff = 0;
    K->turnscritchancedebuff = 0;
    K->dodge = 0;
    K->dodgebuff = 0;
    K->dodgedebuff = 0;
    K->turnsdodgebuff = 0;
    K->turnsdodgedebuff = 0;
    K->reflect = 0;
    K->turnsreflect = 0;
    K->dot = 0;
    K->turnsdot = 0;
    K->hot = 0;
    K->turnshot = 0;
}

void DragonStats(Enemy *dragon){
    strcpy(dragon->name, "El dragon");
    dragon->HPMax = 4500;
    dragon->HP = dragon->HPMax;
    dragon->basespeed = 50;
    dragon->basecritchance = 10;
    dragon->basedodge = 10;
    dragon->atk = 0;
    dragon->atkbuff = 0;
    dragon->atkdebuff = 0;
    dragon->turnsatkbuff = 0;
    dragon->turnsatkdebuff = 0;
    dragon->def = 0;
    dragon->defbuff = 0;
    dragon->defdebuff = 0;
    dragon->turnsdefbuff = 0;
    dragon->turnsdefdebuff = 0;
    dragon->speed = 0;
    dragon->spdbuff = 0;
    dragon->spddebuff = 0;
    dragon->turnsspdbuff = 0;
    dragon->turnsspddebuff = 0;
    dragon->critchance = 0;
    dragon->critchancebuff = 0;
    dragon->critchancedebuff = 0;
    dragon->turnscritchancebuff = 0;
    dragon->turnscritchancedebuff = 0;
    dragon->dodge = 0;
    dragon->dodgebuff = 0;
    dragon->dodgedebuff = 0;
    dragon->turnsdodgebuff = 0;
    dragon->turnsdodgedebuff = 0;
    dragon->reflect = 0;
    dragon->turnsreflect = 0;
    dragon->dot = 0;
    dragon->turnsdot = 0;
    dragon->hot = 0;
    dragon->turnshot = 0;
}

void AlutyStats(Enemy *aluty){
    strcpy(aluty->name, "Aluty");
    aluty->HPMax = 1000;
    aluty->HP = aluty->HPMax;
    aluty->basespeed = 40;
    aluty->basecritchance = 10;
    aluty->basedodge = 10;
    aluty->atk = 0;
    aluty->atkbuff = 0;
    aluty->atkdebuff = 0;
    aluty->turnsatkbuff = 0;
    aluty->turnsatkdebuff = 0;
    aluty->def = 0;
    aluty->defbuff = 0;
    aluty->defdebuff = 0;
    aluty->turnsdefbuff = 0;
    aluty->turnsdefdebuff = 0;
    aluty->speed = 0;
    aluty->spdbuff = 0;
    aluty->spddebuff = 0;
    aluty->turnsspdbuff = 0;
    aluty->turnsspddebuff = 0;
    aluty->critchance = 0;
    aluty->critchancebuff = 0;
    aluty->critchancedebuff = 0;
    aluty->turnscritchancebuff = 0;
    aluty->turnscritchancedebuff = 0;
    aluty->dodge = 0;
    aluty->dodgebuff = 0;
    aluty->dodgedebuff = 0;
    aluty->turnsdodgebuff = 0;
    aluty->turnsdodgedebuff = 0;
    aluty->reflect = 0;
    aluty->turnsreflect = 0;
    aluty->dot = 0;
    aluty->turnsdot = 0;
    aluty->hot = 0;
    aluty->turnshot = 0;
}

void EduAttack_1(Player *player, Enemy *edu, int difficulty, int playerskill, int *les){
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Wea Attack!\n", edu->name);

    DMG = GenerateRandom(17, 23, 1);
    DMGMax = DMG + (DMG * ((edu->atk) / 100));

    if (difficulty==2){
        DMGMax = DMGMax + ((DMGMax * 30) / 100);
    }
    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();
    delay(1);

    if (Dodge <= player->dodge){
        printf("\nEl ataque de %s ha fallado!\n", edu->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= edu->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nUh, el golpe de %s ha sido critico!\n", edu->name);
        delay(3);
    }

    if (playerskill == 3){
        DMGMax = DMGMax + ((DMGMax * 50) / 100);
        printf("\nParece que El Guardian ha usado 'Wea Attack' mientras %s estaba Mimido, haciendo mas dano!\n", player->name);
        delay(4);
    }

    DMGTot = DMGMax - (DMGMax * ((player->def) / 100));

    if (DMGMax > 0){
        player->HP = player->HP - DMGTot;
        printf("\nEl ataque inentendible de %s ha causado %d de dano!\n", edu->name, DMGTot);

        if (player->reflect>0){
            ReflectDMG = (DMGMax * ((player->reflect) / 100));
            edu->HP = edu->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien %s ha recibido %d de dano reflejado por %s!\n", edu->name, ReflectDMG, player->name);
        }
        delay(3);
    }
    *les = -1;
}

void EduAttack_2(Enemy *edu, int difficulty, int *les) {
    int Heal;

    printf("\n%s uso De Guardia!\n", edu->name);
    delay(3);
    Heal = GenerateRandom(15, 23, 1);

    if (difficulty!=1){
        Heal = Heal + ((Heal * 30) / 100);
    }
    edu->HP = edu->HP + Heal;
    if (edu->HP>edu->HPMax){
        edu->HP = edu->HPMax;
    }
    printf("\nEstar de guardia hizo que %s pueda arreglar bugs del sistema. Ha recuperado %d HP!\n", edu->name, Heal);
    delay(3);

    *les = -2;
}

void EduAttack_3(Enemy *edu, int *les){
    int AtkBuff=100, DefDebuff=130;

    printf("\n%s esta Mirando Evangelion!\n", edu->name);
    delay(3);

    if (edu->atkbuff==0){
        edu->atkbuff = AtkBuff;
        edu->turnsatkbuff = 2;
    } else if (edu->atkbuff>0){
        edu->atkbuff = edu->atkbuff + AtkBuff;
    }

    if (edu->defdebuff==0){
        edu->defdebuff = DefDebuff;
        edu->turnsdefdebuff = 2;
    } else if (edu->defdebuff>0){
        edu->defdebuff = edu->defdebuff + DefDebuff;
    }

    printf("\nUh oh, parece que no le gusto el final del anime. Se lo ve peligroso, aunque vulnerable...\n");
    delay(4);
    *les = -3;
}

void EduAttack_4(Enemy *edu, int *les){
    int DefBuff=30;

    printf("\n%s utilizo Entereza Chilena\n", edu->name);
    delay(3);
    if (edu->defbuff==0){
        edu->defbuff = DefBuff;
        edu->turnsdefbuff = 3;
    } else if (edu->defbuff>0){
        edu->defbuff = edu->defbuff + DefBuff;
    }

    printf("\nInvocando al poder de sus ancestros, %s ha aumentado su capacidad defensiva por 2 turnos!\n", edu->name);
    delay(4);

    *les = -4;
}

void GabotAttack_1(Enemy *gabot, int *les){
    printf("\n%s uso Imprimir M4A1!\n", gabot->name);
    delay(2);
    gabot->spddebuff = 35;
    gabot->turnsspddebuff = 2;
    printf("\n%s ha impreso un rifle de asalto 3D! Debera poder dispararla en el proximo turno. A cubierto!\n", gabot->name);
    delay(3);
    *les = -5;
}

void GabotAttack_2(Player *player, Enemy *gabot, int difficulty, int *les){ /* Disparar M4A1: Hace mucho daño. Si el jugador no se sube defensa, pega 33% mas */
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Disparar M4A1!\n", gabot->name);

    if (player->def>0){
        DMG = GenerateRandom(35, 50, 1);
    } else {
        DMG = GenerateRandom(65,80, 1);
    }
    DMGMax = DMG + (DMG * ((gabot->atk) / 100));

    if (difficulty==2){ /* En este caso, se disminuye el daño porque la pelea es mas larga */
        DMGMax = DMGMax - ((DMGMax * 35) / 100);
    }
    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();
    delay(1);

    if (Dodge <= player->dodge){
        printf("\nEl ataque de %s ha fallado!\n", gabot->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= gabot->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nUh, el golpe de %s ha sido critico!\n", gabot->name);
        delay(3);
    }

    DMGTot = DMGMax - (DMGMax * ((player->def) / 100));

    if (DMGMax > 0){
        player->HP = player->HP - DMGTot;
        printf("\nLos disparos de %s arrasan con todo, causandote %d de dano!\n", gabot->name, DMGTot);
        if (player->reflect>0){
            ReflectDMG = (DMGMax * ((player->reflect) / 100));
            gabot->HP = gabot->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien %s ha recibido %d de dano reflejado por %s!\n", gabot->name, ReflectDMG, player->name);
        }
        delay(3);
    }
    *les = -6;
}

void GabotAttack_3(Player *player, Enemy *gabot, int difficulty, int *lps, int *les){ /*Zarpazo letal: Hace daño y tiene chance de disminuir atk del rival */
    int DMG, DMGMax, DMGTot, Dodge, Crit, atkDebuffchance, ReflectDMG;

    printf("\n%s uso Zarpazo Letal!\n", gabot->name);

    DMG = GenerateRandom(18, 23, 1);
    DMGMax = DMG + (DMG * ((gabot->atk) / 100));

    if (difficulty==2){ /* En este caso, se disminuye el daño porque la pelea es mas larga */
        DMGMax = DMGMax - ((DMGMax * 35) / 100);
    }
    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();
    delay(1);

    if (Dodge <= player->dodge){
        printf("\nEl ataque de %s ha fallado!\n", gabot->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= gabot->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nUh, el golpe de %s ha sido critico!\n", gabot->name);
        delay(3);
    }

    DMGTot = DMGMax - (DMGMax * ((player->def) / 100));

    if (DMGMax > 0){
        if (*lps==3){
            DMGMax = DMGMax + ((DMGMax * 50) / 100);
            printf("\nParece que El Guardian ha usado 'Zarpazo Letal' mientras %s estaba Mimido, haciendo mas dano!\n", player->name);
            delay(4);
        }
        player->HP = player->HP - DMGTot;
        printf("\nEl zarpazo de %s te ha herido, recibiste %d de dano!\n", gabot->name, DMGTot);
        atkDebuffchance = GenerateRandomChance();
        if (player->reflect>0){
            ReflectDMG = (DMGMax * ((player->reflect) / 100));
            gabot->HP = gabot->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien %s ha recibido %d de dano reflejado por %s!\n", gabot->name, ReflectDMG, player->name);
        }
        if (atkDebuffchance <=40){
            delay(2);
            player->atkdebuff = 30;
            player->turnsatkdebuff = 1;
            printf("\nNo solo eso, tambien te ha lesionado! Reduciendo tu ataque en tu proximo turno.\n");
        }
        delay(3);
    }


    *les = -7;
}

void GabotAttack_4(Enemy *gabot, int *les, int *uniqueuse1){
    printf("\n%s uso Kit de Reparacion!\n", gabot->name);
    delay(3);

    gabot->HP = gabot->HPMax;
    *uniqueuse1 = 0;

    printf("\nParece que %s ha decidido repararse, recuperando toda su vida al maximo! Por suerte es de uso unico.\n", gabot->name);
    delay(3);
    *les = -8;
}

void ToxAttack_1(Player *player, Enemy *tox, int difficulty, int *les){
    int DMG, DMGMax, DMGTot, Crit, ReflectDMG;

    printf("\n%s uso Impacto Subito!\n", tox->name);

    DMG = GenerateRandom(20, 25, 1);

    DMG = DMG + (tox->speed / 10);
    DMGMax = DMG + (DMG * ((tox->atk) / 100));

    if (difficulty==2){
        DMGMax = DMGMax + ((DMGMax * 30) / 100);
    }
    Crit = GenerateRandomChance();
    delay(2);

    if (Crit <= tox->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nUh, el golpe de %s ha sido critico!\n", tox->name);
        delay(3);
    }

    DMGTot = DMGMax - (DMGMax * ((player->def) / 100));

    if (DMGMax > 0){
        player->HP = player->HP - DMGTot;
        printf("\n%s realiza un golpe casi imperceptible, imposible de esquivar! Te ha causado %d de dano!\n", tox->name, DMGTot);

        if (player->reflect>0){
            ReflectDMG = (DMGMax * ((player->reflect) / 100));
            tox->HP = tox->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien %s ha recibido %d de dano reflejado por %s!\n", tox->name, ReflectDMG, player->name);
        }
        delay(3);
    }
    *les = -9;
}

void ToxAttack_2(Enemy *tox, int *les){

    printf("\n%s uso Reflejos Agudos!\n", tox->name);
    delay(2);

    tox->reflect = 50;
    tox->turnsreflect = 2;
    tox->defbuff = 100;
    tox->turnsdefbuff = 2;

    printf("\n%s te mira detenidamente, como si estuviese esperando que hicieras algo...\n", tox->name);
    delay(3);
    *les = -10;
}

void ToxAttack_3(Player *player, Enemy *tox, int *les){
    int dot=17, turns=3;

    printf("\n%s uso Granada Toxica!\n", tox->name);
    delay(2);
    if (player->dot==0){
        player->dot = dot;
        player->turnsdot = turns;
    } else {
        player->dot = player->dot + (dot);
    }

    printf("\n%s arroja una granada con una toxina altamente letal! Te ha envenenado por 3 turnos! \n", tox->name);
    delay(3);

    *les = -11;
}

void ToxAttack_4(Player *player, Enemy *tox, int difficulty, int *les) {
    int DMG, Dodge;

    printf("\n%s uso Destruccion Organica!\n", tox->name);
    delay(2);

    Dodge = GenerateRandomChance();

    if (Dodge <= player->dodge){
        printf("\nHas evadido el intento de %s por activar el veneno en ti!\n", tox->name);
        delay(3);
    } else if (player->dot == 17) {
        DMG = (player->dot * player->turnsdot) * 1.5;
        if (difficulty == 2) {
            DMG = DMG * 1.8;
        }
        player->dot = 0;
        player->turnsdot = 0;
        player->HP = player->HP - DMG;
        printf("\nOh no, parece que %s ha activado el veneno en tu cuerpo de alguna forma, infligiendote un dano masivo de %d!\n", tox->name, DMG);
    } else {
        printf("\n%s ha intentado hacer algo con el veneno, pero como te lo has quitado su ataque no tuvo efecto!\n", tox->name);
    }
    delay(4);
    *les = -12;
}

void ToxAttack_5(Enemy *tox, int *les){
    int turns=4;

    printf("\n%s uso Rapidez Toxica!\n", tox->name);
    delay(2);

    tox->spdbuff = tox->basespeed;
    tox->turnsspdbuff = turns;

    printf("\nLa velocidad de %s se ha duplicado por 3 turnos! Eso aumentara el dano de su Impacto Subito..\n", tox->name);
    delay(3);

    *les = -13;
}

void ToxAttack_6(Enemy *tox, int *les){
    int critchance=100;

    printf("\n%s uso Peligro Biologico!\n", tox->name);
    delay(2);

    tox->critchancebuff = 90;
    tox->turnscritchancebuff = 2;

    printf("\nParece que El Guardian ha cargado energias. Su proximo golpe sera un critico asegurado!\n");
    delay(3);
    *les = -14;
}

void KAttack_1(Enemy *k, int difficulty, int *les){
    int Heal, turns=3;

    printf("\n%s uso Absorber Primogemas.\n", k->name);
    delay(3);
    Heal = GenerateRandom(24, 29, 1);
    if (difficulty!=1){
        Heal = Heal + ((Heal * 30) / 100);
    }
    k->hot = Heal;
    k->turnshot = turns;
    k->defdebuff = 50;
    k->turnsdefdebuff = turns+1;

    printf("\n%s invoca al poder de Jean para restaurar %d vitalidad cada 3 turnos, pero su defensa se reduce en ese tiempo!\n", k->name, Heal);
    delay(4);

    *les = -15;
}

void KAttack_2(Enemy *k, int *les){
    printf("\n%s uso Estocada Brutal (Carga).\n", k->name);
    delay(3);

    printf("\n%s se prepara para realizar una estocada brutal. El siguiente turno puede ser devastador!\n", k->name);
    delay(3);
    *les = -16;
}

void KAttack_3(Player *player, Enemy *k, int difficulty, int *les){
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Estocada Brutal (Ataque).\n", k->name);

    DMG = GenerateRandom(75, 85, 1);
    DMGMax = DMG + (DMG * ((k->atk) / 100));

    if (difficulty==2){
        DMGMax = DMGMax + ((DMGMax * 30) / 100);
    }
    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();
    for (int i=0; i<2; i++){
        if (Crit > k->critchance){
            delay(1);
            Crit = GenerateRandomChance();
        }
    }

    if (Dodge <= player->dodge){
        printf("\nEl ataque de %s ha fallado!\n", k->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= k->critchance){
        DMGMax = DMGMax + ((DMGMax * 50) / 100);
        printf("\nUh, el golpe de %s ha sido critico!\n", k->name);
        delay(3);
    }

    DMGTot = DMGMax - (DMGMax * ((player->def) / 100));

    if (DMGMax > 0){
        player->HP = player->HP - DMGTot;
        printf("\n%s asesta un espadazo letal, infligiendote %d de dano!\n", k->name, DMGTot);
        if (player->reflect>0){
            ReflectDMG = (DMGMax * ((player->reflect) / 100));
            k->HP = k->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien %s ha recibido %d de dano reflejado por %s!\n", k->name, ReflectDMG, player->name);
        }
        delay(3);
    }
    *les = -17;
}

void KAttack_4(Player *player, Enemy *k, int difficulty, int *les){
    int DMG, MPDmg, DMGMax, DMGTot, Dodge, ReflectDMG;

    printf("\n%s uso Llamarada de almas.\n", k->name);

    MPDmg = GenerateRandom(1, 3, 1);
    if (player->MPMax>10){
        MPDmg = MPDmg + 1;
    }
    DMG = GenerateRandom(20, 30, 1);
    DMGMax = DMG + (DMG * ((k->atk) / 100));

    if (difficulty==2){
        MPDmg = MPDmg + 1;
        DMGMax = DMGMax + ((DMGMax * 30) / 100);
    }
    Dodge = GenerateRandomChance();
    delay(3);
    if (Dodge <= player->dodge){
        printf("\nEl ataque de %s ha fallado!\n", k->name);
        DMGMax = 0;
        MPDmg = 0;
        delay(3);
    }

    DMGTot = DMGMax - (DMGMax * ((player->def) / 100));

    if (DMGMax > 0){
        player->HP = player->HP - DMGTot;
        if (MPDmg > player->MP){
            MPDmg = player->MP;
        }
        player->MP = player->MP - MPDmg;
        printf("\n%s dirige las almas de su espada hacia ti, causandote %d de dano y quitandote %d MP!\n", k->name, DMGTot, MPDmg);
        if (player->reflect>0){
            ReflectDMG = (DMGMax * ((player->reflect) / 100));
            k->HP = k->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien %s ha recibido %d de dano reflejado por %s!\n", k->name, ReflectDMG, player->name);
        }
        delay(4);
    }

    *les = -18;
}

void KAttack_5(Enemy *k, int *les){
    int DefBuff=30, turns=1000;

    printf("\n%s uso Campo de Concentracion Maligno!\n", k->name);
    delay(3);

    k->defbuff = DefBuff;
    k->turnsdefbuff = turns;

    printf("\nLa atmosfera oscura le otorga poderes a su armadura, lo que aumenta la defensa de %s un %d%% durante TODO el combate!\n", k->name, DefBuff);
    delay(4);

    *les = -19;
}

void KAttack_6(Player *player, Enemy *k, int *les){
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Spike Rush!\n", k->name);
    delay(3);
    printf("\nParece que %s no lucha de forma justa, y saca una Shorty del bolsillo para disparar 2 veces!\n", k->name);
    for (int i=0; i<2; i++){
        DMG = GenerateRandom(18, 23, 1);
        DMGMax = DMG + (DMG * ((k->atk) / 100));

        Dodge = GenerateRandomChance();
        delay(2);
        if (Dodge > player->dodge){
                Dodge = GenerateRandomChance();
            }
        delay(2);
        Crit = GenerateRandomChance();

        if (Dodge <= player->dodge){
            if (i==0){
                printf("\nEl primer disparo de %s ha fallado!\n", k->name);
            } else {
                printf("\nEl segundo disparo de %s ha fallado!\n", k->name);
            }
            DMGMax = 0;
        } else if (Crit <= k->critchance){
            DMGMax = DMGMax + ((DMGMax * 75) / 100);
            printf("\nUh, el disparo de %s ha sido critico!\n", k->name);
            delay(3);
        }

        DMGTot = DMGMax - (DMGMax * ((player->def) / 100));

        if (DMGMax > 0){
            player->HP = player->HP - DMGTot;
            if (player->defdebuff==0){
                player->defdebuff = 15;
                player->turnsdefdebuff = 3;
            } else if (player->defdebuff >= 15 && player->turnsdefdebuff == 3){
                player->defdebuff = player->defdebuff + 15;
            } else if (player->defdebuff >= 30){
                player->defdebuff = player->defdebuff + (15 / 2);
            }
            if (i==0){
                printf("\nEl primer disparo ha causado %d de dano, y baja tu defensa por 3 turnos!\n", DMGTot);
            } else {
                if (player->defdebuff >= 30 && player->turnsdefdebuff == 3){
                    printf("\nEl segundo disparo ha causado %d de dano, y baja aun mas tu defensa!\n", DMGTot);
                } else {
                    printf("\nEl segundo disparo ha causado %d de dano, y baja tu defensa por 3 turnos!\n", DMGTot);
                }
            }
            if (player->reflect>0){
                ReflectDMG = (DMGMax * ((player->reflect) / 100));
                k->HP = k->HP - ReflectDMG;
                delay(1);
                printf("\nPero parece que tambien %s ha recibido %d de dano reflejado por %s!\n", k->name, ReflectDMG, player->name);
            }
            delay(1);
        }
    }
    delay(3);
    *les = -20;
}

void FaffyAttack_1(Player *player, Enemy *faffy, int difficulty, int *les, int *rebote){
    int atkdebuff=30, dot;

    printf("\n%s uso Aliento de Fuego!\n", faffy->name);
    delay(3);

    if (*rebote == 1){
        if (difficulty == 1){
            dot = faffy->HPMax / 12;
        } else {
            dot = faffy->HPMax / 16;
        }
        faffy->dot = dot + faffy->dot;
        faffy->turnsdot = 2;
        printf("\nEl espejito rebotin.. ha reflejado el aliento del dragon hacia el!\n");
        delay(3);
        printf("\nEl dragon arde por su propias flamas igneas, sufriendo %d de dano durante 2 turnos.\n", dot);
        if (*les==-26){
            faffy->defdebuff = 300;
            faffy->turnsdefdebuff = 4;
            delay(3);
            printf("\nLa nitroglicerina hizo que la armadura del dragon se destruya por 3 turnos!\n");
        }
    } else {
        dot = player->HPMax / 14;
        player->dot = dot;
        player->turnsdot = 3;
        printf("\nEl fuego inesquivable del dragon te quema muchisimo!.\n");
        delay(3);
        printf("\nRecibiras %d de dano durante 2 turnos!\n", dot);
        if (*les==-26){
            player->defdebuff = 50;
            player->turnsdefdebuff = 3;
            delay(3);
            printf("\nLa nitroglicerina hace que tu defensa baje enormemente por 3 turnos!\n");
        }
    }
    delay(4);

    *les = -21;
}

void FaffyAttack_2(Player *player, Enemy *faffy, int difficulty, int *les, int *rebote){
    int DMG, DMGMax, DMGTot, Dodge, ReflectDMG;

    printf("\n%s uso Aliento de Hielo!\n", faffy->name);
    delay(3);

    DMG = GenerateRandom(30, 35, 1);
    DMGMax = DMG + (DMG * ((faffy->atk) / 100));

    if (difficulty==2){
        DMGMax = DMGMax + ((DMGMax * 30) / 100);
    }

    if (*rebote == 1){
        printf("\nEl espejito rebotin.. ha reflejado el aliento del dragon hacia el!\n");
        delay(3);
        DMGTot = DMGMax - (DMGMax * ((faffy->def) / 100));
        DMGTot = DMGTot * 10;
        if (difficulty == 1){
            DMGTot = DMGTot * 2;
        }
        printf("\nEl dragon ha recibido %d de dano.\n", DMGTot);
        delay(3);
        faffy->HP = faffy->HP - DMGTot;
        faffy->spddebuff = faffy->basespeed / 2;
        faffy->turnsspddebuff = 4;
        printf("\nY su velocidad ha bajado a la mitad por 3 turnos!\n");
        if (*les==-26){
            faffy->defdebuff = 300;
            faffy->turnsdefdebuff = 4;
            delay(3);
            printf("\nLa nitroglicerina hizo que la armadura del dragon se destruya por 3 turnos!\n");
            delay(4);
        }
    } else {
        Dodge = GenerateRandomChance();
        delay(1);

        if (Dodge <= (player->dodge / 2)){
        printf("\nEl ataque del dragon ha fallado!\n");
        DMGMax = 0;
        delay(3);
        }

        DMGTot = DMGMax - (DMGMax * ((player->def) / 100));
        if (DMGMax > 0){
            player->HP = player->HP - DMGTot;
            printf("\nEl aliento congelante del dragon te inflige %d de dano.\n", DMGTot);
            delay(4);
            player->spddebuff = player->basespeed / 2;
            player->turnsspddebuff = 3;
            player->dodgedebuff = 40;
            player->turnsdodgedebuff = 3;
            printf("\nTambien ha reducido tu velocidad a la mitad y evasion en 40%% por 3 turnos!\n");
            delay(4);
            if (player->reflect>0){
                ReflectDMG = (DMGMax * ((player->reflect) / 100));
                faffy->HP = faffy->HP - ReflectDMG;
                delay(1);
                printf("\nPero parece que tambien el dragon ha recibido %d de dano reflejado por %s!\n", ReflectDMG, player->name);
            }
            delay(3);
        }
        if (*les==-26 && DMGMax > 0){
            player->defdebuff = 50;
            player->turnsdefdebuff = 3;
            printf("\nLa nitroglicerina hace que tu defensa baje enormemente por 3 turnos!\n");
            delay(4);
        }
    }

    *les = -22;
}

void FaffyAttack_3(Player *player, Enemy *faffy, int difficulty, int *les, int *rebote){
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Aliento de Rayo!\n", faffy->name);

    DMG = GenerateRandom(45, 65, 1);
    DMGMax = DMG + (DMG * ((faffy->atk) / 100));

    if (difficulty==2){
        DMGMax = DMGMax + ((DMGMax * 30) / 100);
    }
    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();
    for (int i=0; i<2; i++){
        if (Crit > faffy->critchance){
            delay(1);
            Crit = GenerateRandomChance();
        }
    }
    if (Crit <= faffy->critchance){
        DMGMax = DMGMax + ((DMGMax * 50) / 100);
        printf("\nUh, el golpe del dragon ha sido critico!\n");
        delay(3);
    }

    if (*rebote == 1){
        printf("\nEl espejito rebotin.. ha reflejado el aliento del dragon hacia el!\n");
        delay(3);
        DMGTot = DMGMax - (DMGMax * ((faffy->def) / 100));
        DMGTot = DMGTot * 8;
        if (difficulty == 1){
            DMGTot = DMGTot * 1.5;
        }
        printf("\nEl dragon se ha impactado con su propio rayo, causandole %d de dano.\n", DMGTot);
        delay(3);
        faffy->HP = faffy->HP - DMGTot;
        if (*les==-26){
            faffy->defdebuff = 300;
            faffy->turnsdefdebuff = 4;
            delay(3);
            printf("\nLa nitroglicerina hizo que la armadura del dragon se destruya por 3 turnos!\n");
            delay(4);
        }

    } else {
        if (Dodge <= player->dodge){
        printf("\nEl ataque del dragon ha fallado!\n");
        DMGMax = 0;
        delay(3);
        }
        DMGTot = DMGMax - (DMGMax * ((player->def) / 100));
        if (DMGMax > 0){
        player->HP = player->HP - DMGTot;
        printf("\nEl aliento electrico del dragon te impacta de lleno, causandote un dano de %d!\n", DMGTot);
        if (player->reflect>0){
            ReflectDMG = (DMGMax * ((player->reflect) / 100));
            faffy->HP = faffy->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien el dragon ha recibido %d de dano reflejado por %s!\n", ReflectDMG, player->name);
        }
        delay(4);
        }
        if (*les==-26 && DMGMax > 0){
            player->defdebuff = 50;
            player->turnsdefdebuff = 3;
            printf("\nLa nitroglicerina hace que tu defensa baje enormemente por 3 turnos!\n");
            delay(4);
        }
    }

    *les = -23;
}

void FaffyAttack_4(Player *player, Enemy *faffy, int *les){

    printf("\n%s uso Rawr!\n", faffy->name);
    delay(3);

    if (player->atkdebuff == 0){
        player->atkdebuff = 30;
        player->turnsatkdebuff = 4;

        printf("\nSu rugido amenazante te intimida, reduciendo tu dano hacia el un 30%% durante 3 turnos!\n", faffy->name);

    } else {
        printf("\nEl dragon ha realizado su rugido, pero ya estas intimidado y no ha tenido un mayor efecto.\n");
    }

    delay(3);

    *les = -24;
}

void FaffyAttack_5(Player *player, Enemy *faffy, int *les){

    if (player->HP <= player->HPMax / 5){
        printf("\n%s uso..!", faffy->name);
        delay(2);
        printf("\n.\n");
        delay(1);
        printf("\n.\n");
        delay(1);
        printf("\n.\n");
        letter('D', 3);letter('E', 3);letter('V', 3);letter('O', 3);letter('R', 3);letter('A', 3);letter('R', 3);
        delay(2);
        player->HP = 0;
        printf("\nEstas tan debilitado que no puedes anticipar la embestida del dragon..\n");
        delay(4);
        printf("\n..Y en un simple segundo...,\n");
        delay(3);
        printf(" el dragon te logra devorar por completo...\n");
        delay(3);
    } else {
        printf("\n%s uso.. Devorar!", faffy->name);
        delay(3);
        printf("\nEl dragon intenta comerte, pero no te ha debilitado lo suficiente.\n");
        delay(4);
        printf("\nHas esquivado el ataque mortal del dragon!\n");
    }

    *les = -25;
}

void FaffyAttack_6(Enemy *faffy, int *les){

    printf("\n%s uso Nitroglicerina!\n", faffy->name);
    delay(3);

    printf("\nEl proximo aliento del dragon destruira la defensa extraordinariamente! Habra alguna forma de impedirlo?\n");
    delay(4);
    *les = -26;
}

void EduAction_1(Player *player, Enemy *edu, int playerskill, int *les){ /* 1. Facil */
    int Facil=1, RNG;

    if (edu->HP >= ((edu->HPMax*80) / 100)){ /* Si tiene 80%=+ HP.. */
        if (edu->atk<=0){
            EduAttack_3(edu, les);
        } else {
            EduAttack_1(player, edu, Facil, playerskill, les);
        }
    } else if ((edu->HP < ((edu->HPMax*80) / 100)) && (edu->HP >= ((edu->HPMax*30) / 100))){ /* Si tiene entre 79% y 30% HP.. */
        RNG = GenerateRandomChance();
        if (edu->atk>0){
            EduAttack_1(player, edu, Facil, playerskill, les);
        } else if (edu->atk<=0 && RNG>=91){
            EduAttack_3(edu, les);
        } else if (RNG<=10) {
            EduAttack_2(edu, Facil, les);
        } else {
            EduAttack_1(player, edu, Facil, playerskill, les);
        }
    } else if (edu->HP < ((edu->HPMax*30) / 100)){ /* Si tiene menos del 30% HP.. */
        RNG = GenerateRandomChance();
        if (RNG >= 51){
            EduAttack_2(edu, Facil, les);
        } else {
            EduAttack_1(player, edu, Facil, playerskill, les);
        }
    }
}

void EduAction_2(Player *player, Enemy *edu, int playerskill, int *les){ /* 2. Dificil / Willy */
    int Dificil=2, RNG;

    if (edu->HP >= ((edu->HPMax*50) / 100)){ /* Si tiene 50%=+ HP.. */
        if (edu->atk>0){
            EduAttack_1(player, edu, Dificil, playerskill, les);
        } else if (edu->def<=0){
            EduAttack_4(edu, les);
        } else if (edu->atk<=0){
            EduAttack_3(edu, les);
        } else {
            EduAttack_1(player, edu, Dificil, playerskill, les);
        }
    } else if ((edu->HP < ((edu->HPMax*50) / 100)) && (edu->HP >= ((edu->HPMax*20) / 100))){ /* Si tiene entre 50% y 20% HP.. */
        RNG = GenerateRandomChance();
        if (edu->atk>0){
            EduAttack_1(player, edu, Dificil, playerskill, les);
        } else if (edu->atk<=0 && RNG>=91){
            EduAttack_3(edu, les);
        } else if (RNG<=10) {
            EduAttack_2(edu, Dificil, les);
        } else if (edu->def<=0 && (RNG<91 && RNG>49)){
            EduAttack_4(edu, les);
        } else {
            EduAttack_1(player, edu, Dificil, playerskill, les);
        }
    } else if (edu->HP < ((edu->HPMax*20) / 100)){ /*Si tiene menos del 30% HP.. */
        RNG = GenerateRandomChance();
        if (RNG >= 65){
            EduAttack_2(edu, Dificil, les);
        } else {
            EduAttack_1(player, edu, Dificil, playerskill, les);
        }
    }
}

void GabotAction_1(Player *player, Enemy *gabot, int *lps, int *les){
    int Facil=1, RNG;

    if (*les==-5){
        GabotAttack_2(player, gabot, Facil, les);
    } else {
        RNG = GenerateRandomChance();
        if (RNG<=40){
            GabotAttack_1(gabot, les);
        } else {
            GabotAttack_3(player, gabot, Facil, lps, les);
        }
    }
}

void GabotAction_2(Player *player, Enemy *gabot, int *lps, int *les, int *uniqueuse1){
    int Dificil=2, RNG;

    if (gabot->HP < (gabot->HPMax / 3) && *uniqueuse1==1){ /* Si tiene menos del 33% de su vida... */
        GabotAttack_4(gabot, les, uniqueuse1);
    } else if (*les==-5){ /*Si uso imprimir arma antes... */
        GabotAttack_2(player, gabot, Dificil, les);
    } else {
        RNG = GenerateRandomChance();
        if (RNG<=40){
            GabotAttack_1(gabot, les);
        } else {
            GabotAttack_3(player, gabot, Dificil, lps, les);
        }
    }
}

void ToxAction_1(Player *player, Enemy *tox, int *lps, int *les){
    int Facil=1, RNG;

    if (*les==-12) {
        RNG = GenerateRandomChance();
        if (RNG<=80){
            ToxAttack_4(player, tox, Facil, les);
        } else if (RNG>80 && RNG<=90) {
            ToxAttack_1(player, tox, Facil, les);
        } else {
            ToxAttack_2(tox, les);
        }
    } else if (player->dot == 17 || player->dot == 32) {
        RNG = GenerateRandomChance();
        if (RNG<=45){
            ToxAttack_4(player, tox, Facil, les);
        } else if (RNG>45 && RNG<=80){
            ToxAttack_1(player, tox, Facil, les);
        } else {
            ToxAttack_2(tox, les);
        }
    } else {
        RNG = GenerateRandomChance();
        if (RNG<=35){
            ToxAttack_3(player, tox, les);
        } else if (RNG>35 && RNG<70){
            ToxAttack_1(player, tox, Facil, les);
        } else {
            ToxAttack_2(tox, les);
        }
    }
}

void ToxAction_2(Player *player, Enemy *tox, int *lps, int *les){
    int Dificil=2, RNG;

    if (tox->critchancebuff==90){
        ToxAttack_1(player, tox, Dificil, les);
    } else if (*les==-11) {
        RNG = GenerateRandomChance();
        if (RNG<=80){
            ToxAttack_4(player, tox, Dificil, les);
        } else if (RNG>80 && RNG<=90 && tox->spdbuff == 0) {
            ToxAttack_5(tox, les);
        } else {
            ToxAttack_2(tox, les);
        }
    } else if (player->dot == 17 || player->dot == 32) {
        RNG = GenerateRandomChance();
        if (RNG<=30){
            ToxAttack_4(player, tox, Dificil, les);
        } else if (RNG>30 && RNG<=65){
            ToxAttack_1(player, tox, Dificil, les);
        } else if (RNG>65 && RNG<=75) {
            ToxAttack_2(tox, les);
        } else if (RNG>75 && RNG<=85 && tox->spdbuff == 0){
            ToxAttack_5(tox, les);
        } else {
            ToxAttack_6(tox, les);
        }
    } else {
        RNG = GenerateRandomChance();
        if (RNG<=15){
            ToxAttack_3(player, tox, les);
        } else if (RNG>15 && RNG<=30){
            if (player->consumable4>0){
                ToxAttack_3(player, tox, les);
            } else {
                ToxAttack_1(player, tox, Dificil, les);
            }
        } else if (RNG>30 && RNG<=40){
            ToxAttack_1(player, tox, Dificil, les);
        } else if (RNG>40 && RNG<=55) {
            ToxAttack_2(tox, les);
        } else if (RNG>55 && RNG<=80 && tox->spdbuff == 0){
            ToxAttack_5(tox, les);
        } else {
            ToxAttack_6(tox, les);
        }
    }
}

void KAction_1(Player *player, Enemy *k, int *lps, int *les){
    int Facil=1, RNG;

    if (*les==-16){ /* Si K uso Estocada Brutal (carga) */
        KAttack_3(player, k, Facil, les);
    } else if (k->HP < k->HPMax / 3 && k->hot==0) { /* Si K tiene poca vida y no HOT */
        RNG = GenerateRandomChance();
        if (RNG <= 60){
            KAttack_1(k, Facil, les);
        } else if (RNG > 60 && RNG <=80){
            KAttack_2(k, les);
        } else {
            KAttack_4(player, k, Facil, les);
        }
    } else if (player->MP > ((player->MPMax / 2) + 1)) { /* Si el enemigo tiene bastante MP... */
        RNG = GenerateRandomChance();
        if (RNG <= 40){
            KAttack_2(k, les);
        } else {
            KAttack_4(player, k, Facil, les);
        }
    } else {
        RNG = GenerateRandomChance();
        if (RNG <= 60){
            KAttack_2(k, les);
        } else {
            KAttack_4(player, k, Facil, les);
        }
    }
}

void KAction_2(Player *player, Enemy *k, int *lps, int *les, int *uniqueuse1){
    int Dificil=2, RNG;

    if (*uniqueuse1==1){ /* Primer turno, se sube defensa permanentemente */
        KAttack_5(k, les);
        *uniqueuse1 = 0;
    } else if (*les==-16){ /* Si K uso Estocada Brutal (carga) */
        KAttack_3(player, k, Dificil, les);
    } else if (k->HP < k->HPMax / 3 && k->hot==0) { /* Si K tiene poca vida y no HOT */
        RNG = GenerateRandomChance();
        if (RNG <= 50){
            KAttack_1(k, Dificil, les);
        } else if (RNG > 50 && RNG <=67){
            KAttack_2(k, les);
        } else if (RNG > 67 && RNG <= 84 && *les!=-20) {
            KAttack_6(player, k, les);
        } else {
            KAttack_4(player, k, Dificil, les);
        }
    } else if (player->MP > ((player->MPMax / 2) + 1)) { /* Si el enemigo tiene bastante MP... */
        RNG = GenerateRandomChance();
        if (RNG <= 30){
            KAttack_2(k, les);
        } else if (RNG > 30 && RNG <=65){
            KAttack_6(player, k, les);
        } else {
            KAttack_4(player, k, Dificil, les);
        }
    } else {
        RNG = GenerateRandomChance();
        if (RNG <= 40){
            KAttack_2(k, les);
        } else if (RNG > 40 && RNG <=75){
            KAttack_6(player, k, les);
        } else {
            KAttack_4(player, k, Dificil, les);
        }
    }
}

void DragonAction_1(Player *player, Enemy *drag, int *lps, int *les, int *rebote){
    int Facil=1, RNG;

    if (*les==21){
        FaffyAttack_2(player, drag, Facil, les, rebote);
    } else if (*les==22){
        FaffyAttack_3(player, drag, Facil, les, rebote);
    } else if (*les==23){
        FaffyAttack_4(player, drag, les);
    } else {
        FaffyAttack_1(player, drag, Facil, les, rebote);
    }
}

void DragonAction_2(Player *player, Enemy *drag, int *lps, int *les, int *rebote){
    int Dificil=2, RNG;

    if (player->HP < player->HPMax / 5){ /* si player tiene 1/5 de sus HP, instakillea2 */
        FaffyAttack_5(player, drag, les);
    } else if (*les==-26){ /*Si uso nitroglicerina, usa aliento si o si */
        RNG = GenerateRandomChance();
        if (RNG<=36){
            FaffyAttack_1(player, drag, Dificil, les, rebote);
        } else if (RNG>36 && RNG<=63){
            FaffyAttack_2(player, drag, Dificil, les, rebote);
        } else {
            FaffyAttack_3(player, drag, Dificil, les, rebote);
        }
    } else if (*les==-21){ /*Repite los alientos restantes, hasta que termina usando Rawr */
        FaffyAttack_2(player, drag, Dificil, les, rebote);
    } else if (*les==-22){
        FaffyAttack_3(player, drag, Dificil, les, rebote);
    } else if (*les==-23){
        RNG = GenerateRandomChance();
        if (RNG<=40){
            FaffyAttack_4(player, drag, les);
        } else {
            FaffyAttack_6(drag, les);
        }
    } else {
        RNG = GenerateRandomChance();
        if (RNG<=50 && *les!=-24){
            FaffyAttack_4(player, drag, les);
        } else {
            FaffyAttack_6(drag, les);
        }
    };
}

void AlutyAction_1(Player *player, Enemy *aluty, int *lps, int *les){
    int Facil=1, RNG;

}

void AlutyAction_2(Player *player, Enemy *aluty, int *lps, int *les){
    int Dificil=2, RNG;

}


#endif //THE_HERETIC_ENEMIES_H
