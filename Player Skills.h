#ifndef THE_HERETIC_PLAYER_SKILLS_H
#define THE_HERETIC_PLAYER_SKILLS_H

#include "Enemies.h"
#include "RNG.h"

void printplayerskills(Player *player);
void printplayernormalskills(Player *player);
void printplayerspecialskills(Player *player);
void printskill(int skillCode); /* 1 al 9 son normales. 10 al 13 son especiales. Ordenadas segun el Word */
int checkMPcosts(Player *player, int skill);
void Player_Action(Player *player, Enemy *enemy, int skill, int *lps, int *les, int *reps_lps, int *reps_les);
void UseSkill_1(Player *player, Enemy *enemy);
void UseSkill_2(Player *player, Enemy *enemy);
void UseSkill_3(Player *player, Enemy *enemy);
void UseSkill_4(Player *player, Enemy *enemy);
void UseSkill_5(Player *player, Enemy *enemy, int *lps, int *reps_lps);
void UseSkill_6(Player *player, Enemy *enemy, int *lps, int *reps_lps);
void UseSkill_7(Player *player, Enemy *enemy);
void UseSkill_8(Player *player, Enemy *enemy);
void UseSkill_9(Player *player, Enemy *enemy);
void UseSkill_10(Player *player, Enemy *enemy, int skill);
void UseSkill_11(Player *player, Enemy *enemy, int skill);
void UseSkill_12(Player *player, Enemy *enemy, int skill);
void UseSkill_13(Player *player, Enemy *enemy, int skill);
void UseSkill_14(Player *player, Enemy *enemy, int skill);
void UseSkill_15(Player *player, Enemy *enemy, int skill);
void UseSkill_16(Player *player, Enemy *enemy, int skill);
void UseSkill_17(Player *player, Enemy *enemy, int skill);
void UseSkill_21(Player *player, Enemy *enemy);
void UseSkill_22(Player *player, Enemy *enemy, int skill);
void UseSkill_23(Player *player, Enemy *enemy, int skill);
void UseSkill_24(Player *player, Enemy *enemy);
void UseSkill_25(Player *player, Enemy *enemy, int *lps, int *reps_lps);
void UseSkill_26(Player *player, Enemy *enemy, int *lps, int *reps_lps);
void UseSkill_27(Player *player, Enemy *enemy);
void UseSkill_28(Player *player, Enemy *enemy);
void UseSkill_29(Player *player, Enemy *enemy);
void usepadineta(Player *player, Enemy *enemy, int *les);
int usetalismanofeve(Player *player); /*Devuelve win=1 si se usa, win=0 si no se usa */



void printplayerskills(Player *player){
    printplayernormalskills(player);
    printplayerspecialskills(player);
}

void printplayernormalskills(Player *player){
    int n=0;

    printf("--->Habilidades Normales:\n");
    while (player->skills[n].skillCode != 0 && (player->skills[n].skillCode < 10 || player->skills[n].skillCode > 17)){
        printf("%d- ", n+1); printskill(player->skills[n].skillCode);
        n++;
    }
}

void printplayerspecialskills(Player *player){
    printf("--->Especiales:\n");
    for (int n=0; n<7; n++){
        if ((player->skills[n].skillCode >= 10 && player->skills[n].skillCode <= 17)){
            printf("%d- ", n+1); printskill(player->skills[n].skillCode);
        }
    }
}

void printskill(int skillCode){
    switch (skillCode){
        case 1:
            printf("Ataque Directo(-2MP): Inflige 30HP de dano.\n");
            break;
        case 2:
            printf("Defensa Personal: Cubre 30%% del dano recibido, y reflejas 30%% del dano. Dura hasta tu siguiente turno. \n");
            break;
        case 3:
            printf("A mimir!: Recupera TODOS los MP, pero te deja vulnerable a varios ataques..\n");
            break;
        case 4:
            printf("Cafecito: Recupera la mitad de los MP, y otorga 25%% de evasion hasta tu proximo turno.\n");
            break;
        case 5:
            printf("Figurita repetida(-2MP): Inflige 16HP de dano. El dano aumenta 50%% cada vez que es usado de forma seguida, y no varia. \n");
            break;
        case 6:
            printf("Levantamuros(-4MP): Eleva un muro que sube un 60%% tu defensa, y al turno siguiente lo lanza contra el enemigo. Hace 35HP de dano y baja 25 de velocidad por 3 turnos. Es un ataque de 2 turnos.\n");
            break;
        case 7:
            printf("Chancla afilada(-2MP): Lanzas una chancla supersonica al enemigo, causando 20HP de dano. Reduce evasion en 25%% por 4 turnos. Imposible de esquivar, y atraviesa defensa.\n");
            break;
        case 8:
            printf("(Pasiva)Odio la suerte: No puedes recibir ni dar golpes criticos, tampoco esquivar o ser esquivado.\n");
            break;
        case 9:
            printf("Fuego ninja(-4MP): Inflige 18HP de dano durante 3 turnos al enemigo. Tiene una chance de disminuir su ataque en 30%% por 2 turnos\n");
            break;
        case 10:
            printf("Monito Blaster(-8MP): Causa 20%% de la vida ACTUAL del objetivo como dano. Este dano no puede aumentarse. Ignora defensa. Tiene 4 turnos de enfriamiento\n");
            break;
        case 11:
            printf("Patagonia Strike(-5MP): Golpea el suelo con fuerza titanica, infligiendo 75HP de dano. Ataca siempre segundo. Tiene 4 turnos de enfriamiento.\n");
            break;
        case 12:
            printf("Arsat1(-xMP): Consume todo el MP para disparar un laser satelital. Entre mas MP gastado, mas dano. Si se usa con todo el MP, ignora defensa. No puede hacer criticos ni fallar. 4 turnos de enfriamiento.\n");
            break;
        case 13:
            printf("Tackle de Rugbier violento(-3MP): Se abalanza contra el rival, tirandolo al suelo violentamente. Ataca primero, hace 40HP de dano y baja su ataque en 60%% por 1 turno, pero recibes 15HP de dano. Alta chance de golpe critico.\n");
            break;
        case 14:
            printf("Macaco Ragnarok(-12MP): Causa 30%% de la vida ACTUAL del objetivo como dano, pero recibes 1/5 del dano causado. Este dano no puede aumentarse. Ignora defensa. Tiene 4 turnos de enfriamiento\n");
            break;
        case 15:
            printf("Terremoto Cordillerano(-10MP): Crea una grieta en el suelo, causando dano devastador de 115HP al rival. Los aumentos de ataque son el doble de efectivos con esta habilidad. Ataca siempre segundo. Tiene 5 turnos de enfriamiento\n");
            break;
        case 16:
            printf("Alineacion Orbital de SpaceX(-xMP): Consume todo el MP para disparar varios satelites. Entre mas MP gastado, mas dano. Si se usa con todo el MP, ignora defensa, reduce atk, def, evasion, criticos, velocidad del rival en 25%% por 2 turnos. No puede hacer criticos. Tiene 5 turnos de enfriamiento\n");
            break;
        case 17:
            printf("Valores del Rugby(-7MP): Aumenta tu velocidad en 50%% durante 2 turnos, y golpea infligiendo 40HP, y recibes 10HP de dano. Tanto el dano causado como el recibido aumenta cuanto menos HP tengas, hasta 200%%+ con 1HP. Reduce el atk del enemigo en un 70%% por 1 turno. Alta chance de golpe critico. 2 turnos de enfriamiento.\n");
            break;
        case 21:
            printf("Ataque Celestial(-4MP): Ataca con una espada angelical, infligiendo 45HP de dano, y reduciendo la defensa del rival por 25%% durante 2 turnos.\n");   /* 21 en adelante se refieren a las habilidades normales mejoradas  (1+20), (2+20), etc..*/
            break;
        case 22:
            printf("Escudo de la oscuridad(-7MP): Aumenta tu defensa en 50%% y tu ataque en 35%% durante 4 turnos, pero recibes 25HP de dano. Tiene 5 turnos de enfriamiento\n");
            break;
        case 23:
            printf("Mimir Recargado!: Recuperas todos tus MP, y 15HP cada 3 turnos despues de usarlo. Ademas, tu paz hace que el rival no pueda causarte golpes criticos por 3 turnos. Tiene 1 turno de enfriamiento.\n");
            break;
        case 24:
            printf("Cafe Martinez: Recuperas la mitad de tus MP, y aumenta tu evasion, chance critica y reflejo en 25%% por 2 turnos.\n");
            break;
        case 25:
            printf("Messi repetido(-3MP): Inflige 16HP de dano. El dano aumenta 100%% cada vez que es usado de forma seguida, y no varia. Si al usar el ataque, tus MP quedan en 0, el golpe sera critico. \n");
            break;
        case 26:
            printf("DetonaMuros(-6MP): Le das un muro falso al enemigo, con un explosivo escondido. El proximo turno detonas el muro, lo que inflige 65HP de dano y reduce su velocidad y ataque en 30%% por 3 turnos.\n");
            break;
        case 27:
            printf("Chancla de la Armada Domestica(-3MP): Lanzas una chancla contundente al enemigo, causando 35HP de dano. Reduce evasion en 25%% por 4 turnos. Imposible de esquivar, ignora defensa. Si el enemigo tiene defensa, aumenta el dano de la chancla por esa cantidad.\n");
            break;
        case 28:
            printf("(Pasiva)Amo la Suerte: Aumenta un 75%% tu chance de evasion y golpes criticos, pero tambien duplica la chance critica del enemigo.\n");
            break;
        case 29:
            printf("Lanzallamas ninja(-5MP): Inflige 25HP de dano por turno durante 4 turnos, pero recibes 5HP de dano por turno durante 4 turnos. Tiene una chance alta de disminuir el ataque del enemigo en 30%% por 2 turnos\n");
            break;
    }
}

int checkMPcosts(Player *player, int skill){
    switch (skill) {
        case 1:
           if (player->MP < 2){
               return 0;
           }
           break;
        case 5: if (player->MP < 2){
               return 0;
           }
           break;
        case 6: if (player->MP < 4){
               return 0;
           }
           break;
        case 7: if (player->MP < 2){
               return 0;
           }
           break;
        case 9: if (player->MP < 4) {
                return 0;
            }
            break;
        case 10: if (player->MP < 8){
               return 0;
           }
            break;
        case 11: if (player->MP < 5){
               return 0;
           }
            break;
        case 12:
            break;
        case 13: if (player->MP < 3){
               return 0;
           }
            break;
        case 14: if (player->MP < 12){
               return 0;
           }
            break;
        case 15: if (player->MP < 10){
               return 0;
           }
            break;
        case 16:
            break;
        case 17: if (player->MP < 7){
               return 0;
           }
            break;
        case 21: if (player->MP < 4){
               return 0;
           }
            break;
        case 22: if (player->MP < 7){
               return 0;
           }
            break;
        case 25: if (player->MP < 3){
               return 0;
           }
            break;
        case 26: if (player->MP < 6){
               return 0;
           }
            break;
        case 27: if (player->MP < 3){
               return 0;
           }
            break;
        case 29: if (player->MP < 5){
               return 0;
           }
            break;
    }
    return 1;
}

void UseSkill_1(Player *player, Enemy *enemy){
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Ataque Directo!\n", player->name);

    player->MP = player->MP - 2;
    DMG = GenerateRandom(26,34, 1);
    DMGMax = DMG + (DMG * ((player->atk) / 100));

    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();
    delay(1);

    if (Dodge <= enemy->dodge){
        printf("\nEl ataque de %s ha fallado!\n", player->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= player->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nEl golpe de %s ha sido critico!\n", player->name);
        delay(3);
    }

    DMGTot = DMGMax - (DMGMax * ((enemy->def) / 100));

    if (DMGMax > 0){
        enemy->HP = enemy->HP - DMGTot;
        printf("\nHas causado %d de dano!\n", DMGTot);
        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien tu has recibido %d de dano reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(4);
    }
}

void UseSkill_2(Player *player, Enemy *enemy){
    int BuffDef=30;

    printf("\n%s uso Defensa Personal!\n", player->name);
    delay(2);

    if (player->defbuff==0){
        player->defbuff = BuffDef;
        player->turnsdefbuff = 2;
    } else if (player->defbuff>0){
        player->defbuff = player->defbuff + BuffDef;
    }
    if (player->reflect>0){

    } else {
        player->reflect = 30;
        player->turnsreflect = 2;
    }

    printf("\nAfilas tu guardia, lo que hace que recibas menos dano, y lo reflejes, hasta tu siguiente turno!\n", player->name);
    delay(3);
}

void UseSkill_3(Player *player, Enemy *enemy){

    printf("\n%s uso A Mimir!\n", player->name);
    delay(2);
    player->MP = player->MPMax;
    printf("\n%s se ha ido a mimir, recuperando todos sus MP! Pero dejandolo expuesto..\n", player->name);
    delay(3);
}

void UseSkill_4(Player *player, Enemy *enemy){
    int DodgeBuff = 25;
    printf("\n%s uso Cafecito!\n", player->name);
    delay(2);
    player->MP = player->MP + (player->MPMax / 2);
    if (player->MP > player->MPMax){
        player->MP = player->MPMax;
    }
    player->dodgebuff = DodgeBuff;
    player->turnsdodgebuff = 2;
    printf("\nTomarse un cafecito hizo que recuperes MP, y mejoro tu atencion.\n");
    delay(3);
}

void UseSkill_5(Player *player, Enemy *enemy, int *lps, int *reps_lps){
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Figurita Repetida!\n", player->name);
    delay(1);

    player->MP = player->MP - 2;
    DMG = 16;
    if (*lps == 5){
        DMG = DMG + ((DMG/2) * (*reps_lps - 1));
    }
    DMGMax = DMG + (DMG * ((player->atk) / 100));

    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();

    if (Dodge <= enemy->dodge){
        printf("\nEl ataque de %s ha fallado!\n", player->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= player->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nEl golpe de %s ha sido critico!\n", player->name);
        delay(3);
    }

    DMGTot = DMGMax - (DMGMax * ((enemy->def) / 100));

    if (DMGMax > 0){
        enemy->HP = enemy->HP - DMGTot;
        printf("\nHas causado %d de dano!\n", DMGTot);

        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien tu has recibido %d de dano reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(3);
    }
}

void UseSkill_6(Player *player, Enemy *enemy, int *lps, int *reps_lps){
    int BuffDef=60, DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    if (*lps==6 && *reps_lps==1 || (*lps==6 && *reps_lps==3)) {
        printf("\n%s uso LevantaMuros!\n", player->name);
        delay(2);
        player->MP = player->MP - 4;
        if (player->defbuff == 0) {
            player->defbuff = BuffDef;
            player->turnsdefbuff = 2;
        } else if (player->defbuff > 0) {
            player->defbuff = player->defbuff + BuffDef;
        }
        printf("\nLevantas un muro solido enfrente tuyo, lo que te brinda cobertura!\n");
        delay(3);
    } else if ((*lps==6 && *reps_lps==2) || (*lps==6 && *reps_lps==4)){
        printf("\nArrojas el muro violentamente hacia %s, partiendose en mil pedazos!\n", enemy->name);
        delay(1);


        DMG = GenerateRandom(30, 40, 1);
        DMGMax = DMG + (DMG * ((player->atk) / 100));
        delay(1);

        Dodge = GenerateRandomChance();
        delay(1);
        Crit = GenerateRandomChance();
        if (Dodge <= enemy->dodge){
            printf("\nEl ataque de %s ha fallado!\n", player->name);
            DMGMax = 0;
            delay(3);
        } else if (Crit <= player->critchance){
            DMGMax = DMGMax + ((DMGMax * 75) / 100);
            printf("\nEl golpe de %s ha sido critico!\n", player->name);
            delay(3);
        }

        DMGTot = DMGMax - (DMGMax * ((enemy->def) / 100));

        if (DMGMax > 0){
            enemy->HP = enemy->HP - DMGTot;
            if (enemy->spddebuff==0){
                enemy->spddebuff = enemy->spddebuff + 25;
                enemy->turnsspddebuff = 3;
            }
            printf("\nEl muro le ha causado %d HP de dano! Y su velocidad ha bajado!\n", DMGTot);
        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien tu has recibido %d de dano reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(3);
        }
    }
}

void UseSkill_7(Player *player, Enemy *enemy){
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Chancla Afilada!\n", player->name);
    delay(2);

    player->MP = player->MP - 2;
    DMG = GenerateRandom(17, 23, 1);
    DMGMax = DMG + (DMG * ((player->atk) / 100));

    Crit = GenerateRandomChance();

    if (Crit <= player->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nEl golpe de %s ha sido critico!\n", player->name);
        delay(3);
    }

    DMGTot = DMGMax;
    if (enemy->dodgedebuff==0){
        enemy->dodgedebuff = 25;
        enemy->turnsdodgedebuff = 4;
    } else {
        enemy->dodgedebuff = enemy->dodgedebuff + (25/2);
    }
    if (DMGMax > 0){
        enemy->HP = enemy->HP - DMGTot;
        printf("\nHas causado %d de dano! La evasion de %s se redujo por 4 turnos.\n", DMGTot, enemy->name);
        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero reflejaron tu chancla! Has recibido %d de dano, reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(3);
    }
}

void UseSkill_8(Player *player, Enemy *enemy){

}

void UseSkill_9(Player *player, Enemy *enemy){
    int atkdebuff=30, dot=18, turns=3, RNG;

    printf("\n%s uso Fuego Ninja!\n", player->name);
    delay(2);
    player->MP = player->MP - 4;
    if (enemy->dot > 0){
        enemy->dot = enemy->dot + dot;
    } else if (enemy->dot == 0){
        enemy->dot = dot;
        enemy->turnsdot = turns;
    }
    printf("\nPrendes fuego al enemigo, causandole 18HP de dano durante 3 turnos!\n");
    delay(1);
    RNG = GenerateRandomChance();
    delay(1);
    if (RNG <=30){
        if (enemy->atkdebuff==0){
            enemy->atkdebuff = atkdebuff;
            enemy->turnsatkdebuff = 2;
        } else {
            enemy->atkdebuff = enemy->atkdebuff + atkdebuff/2;
        }
    printf("\nParece que el fuego hizo que disminuya su ataque.\n");
    delay(3);
    }
}

void UseSkill_10(Player *player, Enemy *enemy, int skill){
    int Dodge, DMGTot;

    printf("\n%s uso Macaco Blaster!\n", player->name);
    delay(2);

    player->MP = player->MP - 8;
    Dodge = GenerateRandomChance();
    if (Dodge <= enemy->dodge){
        printf("\nEl ataque de %s ha fallado!\n", player->name);
        delay(3);
    } else {
        if (strcmp("El dragon", enemy->name)==0){
            DMGTot = enemy->HP / 11;
            printf("\n          |¬¬¬> De verdad pensabas que iba a ser tan facil? Esos monitos no son nada!. <¬¬¬|\n");
            delay(5);
            printf("\nLos monitos logran herirlo, pero la magia antigua del dragon mitiga parte del dano! Has causado %d de dano.\n", DMGTot);
            delay(3);
        } else {
            DMGTot = (enemy->HP / 5);
            printf("\nDisparas muchos monitos hacia el rival, logrando que se enfaden con el! Han causado %d de dano!\n", DMGTot);
            delay(3);
        }
        enemy->HP = enemy->HP - DMGTot;

    }
    for (int i=0; i<7; i++){
        if (player->skills[i].skillCode == skill){
            player->skills[i].cooldown = 5;
        }
    }
}

void UseSkill_11(Player *player, Enemy *enemy, int skill){
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Patagonia Strike!\n", player->name);
    delay(1);

    player->MP = player->MP - 5;
    DMG = GenerateRandom(65, 85, 1);
    DMGMax = DMG + (DMG * ((player->atk) / 100));

    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();

    if (Dodge <= enemy->dodge){
        printf("\nEl ataque de %s ha fallado!\n", player->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= player->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nEl golpe de %s ha sido critico!\n", player->name);
        delay(3);
    }

    DMGTot = DMGMax - ((DMGMax * (enemy->def)) / 100);

    if (DMGMax > 0){
        enemy->HP = enemy->HP - DMGTot;
        printf("\nLa tierra tiembla con tu golpe temerario. Infligiste %d de dano!\n", DMGTot);

        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien tu has recibido %d de dano reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(3);
    }

    for (int i=0; i<7; i++){
        if (player->skills[i].skillCode == skill){
            player->skills[i].cooldown = 5;
        }
    }
}

void UseSkill_12(Player *player, Enemy *enemy, int skill){
    int MPConsumed, DMG, DMGTot;

    printf("\n%s uso Arsat1!\n", player->name);
    delay(2);
    MPConsumed = player->MP;
    player->MP = 0;

    DMG = MPConsumed * 10;
    if (MPConsumed == player->MPMax) {
        DMGTot = DMG;
        enemy->HP = enemy->HP - DMGTot;
        printf("\nEl laser satelital fue usado con la carga maxima. Es la fuerza del barrilete cosmico que inflige %d de dano!\n", DMGTot);
        delay(3);
        printf("\nTus MPs ahora son 0.\n");
        delay(2);
    } else {
        DMGTot = DMG - (DMG * ((enemy->def) / 100));
        enemy->HP = enemy->HP - DMGTot;
        printf("\nEl laser satelital drena todos tus MP para causar %d de dano. Tus MPs ahora son 0.\n", DMGTot);
        delay(3);
    }

    for (int i=0; i<7; i++){
        if (player->skills[i].skillCode == skill){
            player->skills[i].cooldown = 5;
        }
    }
}

void UseSkill_13(Player *player, Enemy *enemy, int skill){
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Tackle de Rugbier violento!\n", player->name);

    player->MP = player->MP - 3;
    DMG = GenerateRandom(33, 47, 1);
    DMGMax = DMG + (DMG * ((player->atk) / 100));

    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();
    for (int i=0; i<2; i++){
        if (Crit > player->critchance){
            delay(1);
            Crit = GenerateRandomChance();
        }
    }
    if (Dodge <= enemy->dodge){
        printf("\nEl ataque de %s ha fallado!\n", player->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= player->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nEl golpe de %s ha sido critico!\n", player->name);
        delay(3);
    }

    DMGTot = DMGMax - ((DMGMax * (enemy->def)) / 100);

    if (DMGMax > 0){
        enemy->HP = enemy->HP - DMGTot;
        if (enemy->atkdebuff==0){
            enemy->atkdebuff = 60;
            enemy->turnsatkdebuff = 1;
        } else {
            enemy->atkdebuff = enemy->atkdebuff + 70/2;
        }
        player->HP = player->HP - 15;
        printf("\nEmbistes contra el enemigo, lastimandolo por %d de dano y lesionandolo por un corto tiempo!\n", DMGTot);
        delay(2);
        printf("\nAunque tambien has recibido 15HP de dano por tu propia agresion..\n");
        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien tu has recibido %d de dano reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(3);
    }
}

void UseSkill_14(Player *player, Enemy *enemy, int skill){
    int Dodge, DMGTot;

    printf("\n%s uso Macaco Ragnarok!\n", player->name);
    delay(2);

    player->MP = player->MP - 12;
    Dodge = GenerateRandomChance();
    if (Dodge <= enemy->dodge){
        printf("\nEl ataque de %s ha fallado!\n", player->name);
        delay(3);
    } else {
        DMGTot = ((enemy->HP * 30) / 100);
        enemy->HP = enemy->HP - DMGTot;
        player->HP = player->HP - (DMGTot/5);
        printf("\nEl Armagedon ha sido invocado. El rey mono, liderando a sus monitos, destrozan todo lo que ven.\n");
        delay(4);
        printf("\n%s ha recibido %d de dano.\n", enemy->name, DMGTot);
        delay(2);
        printf("\nTu, %s, has recibido %d de dano.\n", player->name, (DMGTot/5));
        delay(3);
    }
    for (int i=0; i<7; i++){
        if (player->skills[i].skillCode == skill){
            player->skills[i].cooldown = 5;
        }
    }
}

void UseSkill_15(Player *player, Enemy *enemy, int skill){
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Terremoto Cordillerano!\n", player->name);
    delay(1);

    player->MP = player->MP - 10;
    DMG = GenerateRandom(100, 130, 1);
    DMGMax = DMG + (DMG * ((player->atk * 2) / 100));

    Dodge = GenerateRandomChance();
    delay(2);
    Crit = GenerateRandomChance();

    if (Dodge <= enemy->dodge){
        printf("\nEl ataque de %s ha fallado!\n", player->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= player->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nEl golpe de %s ha sido critico!\n", player->name);
        delay(3);
    }

    DMGTot = DMGMax - ((DMGMax * (enemy->def)) / 100);

    if (DMGMax > 0){
        enemy->HP = enemy->HP - DMGTot;
        printf("\nEjecutas un golpe que causa una poderosa catastrofe natural. El suelo se resquebraja abruptamente!\n");
        delay(3);
        printf("\n%s ha recibido un dano inmenso de %d\n", enemy->name, DMGTot);
        delay(3);
        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien tu has recibido %d de dano reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(3);
    }

    for (int i=0; i<7; i++){
        if (player->skills[i].skillCode == skill){
            player->skills[i].cooldown = 6;
        }
    }
}

void UseSkill_16(Player *player, Enemy *enemy, int skill){
    int MPConsumed, DMG, DMGTot;

    printf("\n%s uso Alineacion Orbital de SpaceX!\n", player->name);

    delay(2);
    MPConsumed = player->MP;
    player->MP = 0;

    DMG = MPConsumed * 12;

    printf("\nTodos tus MP son utilizados como energia para efectuar un disparo satelital devastador.\n");
    delay(3);
    if (MPConsumed == player->MPMax) {
        DMGTot = DMG;
        enemy->HP = enemy->HP - DMGTot;
        if (enemy->atkdebuff==0){
            enemy->atkdebuff = 25;
            enemy->turnsatkdebuff = 3;
        } else {
            enemy->atkdebuff = enemy->atkdebuff + 25/2;
        }
        if (enemy->defdebuff==0){
            enemy->defdebuff = 25;
            enemy->turnsdefdebuff = 3;
        } else {
            enemy->defdebuff = enemy->defdebuff + 25/2;
        }
        if (enemy->critchancedebuff==0){
            enemy->critchancedebuff = 25;
            enemy->turnscritchancedebuff = 3;
        } else {
            enemy->critchancedebuff = enemy->critchancedebuff + 25/2;
        }
        if (enemy->dodgedebuff==0){
            enemy->dodgedebuff = 25;
            enemy->turnsdodgedebuff = 3;
        } else {
            enemy->dodgedebuff = enemy->dodgedebuff + 25/2;
        }
        if (enemy->spddebuff==0){
            enemy->spddebuff = 25;
            enemy->turnsspddebuff = 3;
        } else {
            enemy->spddebuff = enemy->spddebuff + 25/2;
        }
        printf("\nEl impacto del ataque hizo que %s reciba una cantidad masiva de %d de dano!\n", enemy->name, DMGTot);
        delay(3);
        printf("\nNo solo eso, todas sus estadisticas disminuyeron. (Gracias, Elon Musk!)\n");
        delay(3);
    } else {
        DMGTot = DMG - (DMG * ((enemy->def) / 100));
        enemy->HP = enemy->HP - DMGTot;
        printf("\nEl ataque satelital ha causado %d de dano!\n", DMGTot);
        delay(3);
    }

    for (int i=0; i<7; i++){
        if (player->skills[i].skillCode == skill){
            player->skills[i].cooldown = 6;
        }
    }
}

void UseSkill_17(Player *player, Enemy *enemy, int skill){ /* chequear si este ataque funca bien.. */
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;
    float cien=100, cincuenta=50;

    printf("\n%s uso Valores del Rugby!\n", player->name);

    player->MP = player->MP - 7;
    DMG = GenerateRandom(30, 50, 1);
    DMGMax = DMG + (DMG * ((player->atk) / 100)) + (DMG * ( (cien - ((player->HP * 100) / player->HPMax)) / cincuenta ) );

    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();
    for (int i=0; i<2; i++){
        if (Crit > player->critchance){
            delay(1);
            Crit = GenerateRandomChance();
        }
    }
    if (Dodge <= enemy->dodge){
        printf("\nEl ataque de %s ha fallado!\n", player->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= player->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nEl golpe de %s ha sido critico!\n", player->name);
        delay(3);
    }

    DMGTot = DMGMax - ((DMGMax * (enemy->def)) / 100);

    if (DMGMax > 0){
        enemy->HP = enemy->HP - DMGTot;
        if (enemy->atkdebuff==0){
            enemy->atkdebuff = 70;
            enemy->turnsatkdebuff = 1;
        } else {
            enemy->atkdebuff = enemy->atkdebuff + 70/2;
        }
        player->HP = player->HP - 10 + (10 * ( (cien - ((player->HP * 100) / player->HPMax)) / cincuenta ) );
        printf("\nEmbistes contra el enemigo, lastimandolo por %d de dano y lesionandolo por un corto tiempo!\n", DMGTot);
        delay(2);
        printf("\nAunque tambien has recibido 15HP de dano por tu propia agresion..\n");
        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien tu has recibido %d de dano reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(3);
    }
}

void UseSkill_21(Player *player, Enemy *enemy){
int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG, defdebuff=25, turns=2;

    printf("\n%s uso Ataque Celestial!\n", player->name);

    player->MP = player->MP - 4;
    DMG = GenerateRandom(39, 51, 1);
    DMGMax = DMG + (DMG * ((player->atk) / 100));

    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();
    delay(1);

    if (Dodge <= enemy->dodge){
        printf("\nEl ataque de %s ha fallado!\n", player->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= player->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nEl golpe de %s ha sido critico!\n", player->name);
        delay(3);
    }

    DMGTot = DMGMax - (DMGMax * ((enemy->def) / 100));

    if (DMGMax > 0){
        enemy->HP = enemy->HP - DMGTot;
        if (enemy->defdebuff==0){
            enemy->defdebuff = defdebuff;
            enemy->turnsdefdebuff = 2;
        } else {
            enemy->defdebuff = enemy->defdebuff + (defdebuff/2);
        }
        printf("\nEl impacto celestial ha causado %d de dano, y ha reducido la defensa de %s!\n", DMGTot, enemy->name);
        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien tu has recibido %d de dano reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(4);
    }


}

void UseSkill_22(Player *player, Enemy *enemy, int skill){

    printf("\n%s uso Escudo de la Oscuridad!\n", player->name);
    delay(2);

    player->MP = player->MP - 7;
    player->HP = player->HP - 25;

    if (player->atkbuff==0){
        player->atkbuff = 35;
        player->turnsatkbuff = 5;
    } else {
        player->atkbuff = player->atkbuff + (40/2);
    }
    if (player->defbuff==0){
        player->defbuff = 50;
        player->turnsdefbuff = 5;
    } else {
        player->defbuff = player->defbuff + (50/2);
    }
    printf("\nLos poderes del Escudo aumentan la fuerza y resistencia de %s, pero pagando con 25 HP!\n", player->name);
    delay(4);

    for (int i=0; i<7; i++){
        if (player->skills[i].skillCode == skill){
            player->skills[i].cooldown = 6;
        }
    }
}

void UseSkill_23(Player *player, Enemy *enemy, int skill){
    int hot=15, turns=3;

    printf("\n%s uso Mimir Recargado!\n", player->name);
    delay(2);
    player->MP = player->MPMax;
    if (player->hot > 0){
        player->hot = player->hot + hot/2;
    } else if (player->hot == 0){
        player->hot = player->hot + hot;
        player->turnshot = turns;
    }
    enemy->critchancedebuff = 100;
    enemy->turnscritchancedebuff = 3;

    printf("\nIrse a mimir temprano hizo que recuperes todo tu MP. Y te despiertas vigorizado!\n");
    delay(4);

    for (int i=0; i<7; i++){
        if (player->skills[i].skillCode == skill){
            player->skills[i].cooldown = 2;
        }
    }
}

void UseSkill_24(Player *player, Enemy *enemy){
    int DodgeBuff = 25, CritBuff = 25, Reflejo = 25;

    printf("\n%s uso Cafe Martinez!\n", player->name);
    delay(2);
    player->MP = player->MP + (player->MPMax / 2);
    if (player->MP > player->MPMax){
        player->MP = player->MPMax;
    }
    if (player->dodgebuff==0){
        player->dodgebuff = DodgeBuff;
        player->turnsdodgebuff = 3;
    }
    if (player->critchancebuff==0){
        player->critchancebuff = CritBuff;
        player->turnscritchancebuff = 3;
    }
    if (player->reflect==0){
        player->reflect = 25;
        player->turnsreflect = 3;
    }
    printf("\nEl cafe de increible calidad aumento tus MP, y te dio un drastico aumento de energia!\n");
    delay(4);
}

void UseSkill_25(Player *player, Enemy *enemy, int *lps, int *reps_lps){
    int DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    printf("\n%s uso Messi Repetido!\n", player->name);
    delay(1);

    player->MP = player->MP - 3;
    DMG = 16;
    if (*lps == 25){
        DMG = DMG + ((DMG) * (*reps_lps - 1));
    }
    DMGMax = DMG + (DMG * ((player->atk) / 100));

    Dodge = GenerateRandomChance();
    delay(1);
    Crit = GenerateRandomChance();
    if (player->MP == 0){
        Crit = 0;
    }
    if (Dodge <= enemy->dodge){
        printf("\nEl ataque de %s ha fallado!\n", player->name);
        DMGMax = 0;
        delay(3);
    } else if (Crit <= player->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nEl golpe de %s ha sido critico!\n", player->name);
        delay(3);
    }

    DMGTot = DMGMax - (DMGMax * ((enemy->def) / 100));

    if (DMGMax > 0){
        enemy->HP = enemy->HP - DMGTot;
        printf("\nHas causado %d de dano!\n", DMGTot);

        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien tu has recibido %d de dano reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(3);
    }
}

void UseSkill_26(Player *player, Enemy *enemy, int *lps, int *reps_lps){
    int Debuff=30, DMG, DMGMax, DMGTot, Dodge, Crit, ReflectDMG;

    if (*lps==26 && *reps_lps==1 || (*lps==26 && *reps_lps==3)) {
        printf("\n%s uso DetonaMuros!\n", player->name);
        delay(1);
        player->MP = player->MP - 6;
        printf("\nFormas un muro con un explosivo escondido, enfrente del enemigo!\n");
        delay(3);
    } else if ((*lps==26 && *reps_lps==2) || (*lps==26 && *reps_lps==4)){
        printf("\nDetonas el muro enfrente de %s!\n", enemy->name);
        delay(3);
        printf("\nLos escombros debilitaron la velocidad y ataque de %s!\n", enemy->name);
        delay(1);
        if (enemy->spddebuff==0){
            enemy->spddebuff = Debuff;
            enemy->turnsspddebuff = 3;
        } else {
            enemy->spddebuff = enemy->spddebuff + (Debuff/2);
        }
        if (enemy->atkdebuff==0){
            enemy->atkdebuff = Debuff;
            enemy->turnsatkdebuff = 3;
        } else {
            enemy->atkdebuff = enemy->atkdebuff + (Debuff/2);
        }
        DMG = GenerateRandom(55, 75, 1);
        DMGMax = DMG + (DMG * ((player->atk) / 100));
        delay(1);

        Dodge = GenerateRandomChance();
        delay(1);
        Crit = GenerateRandomChance();

        if (Dodge <= enemy->dodge){
            printf("\nSin embargo, el ataque de %s ha fallado y no le ha sacado HP!\n", player->name);
            DMGMax = 0;
            delay(3);
        } else if (Crit <= player->critchance){
            DMGMax = DMGMax + ((DMGMax * 75) / 100);
            printf("\nEl golpe de %s ha sido critico!\n", player->name);
            delay(3);
        }

        DMGTot = DMGMax - (DMGMax * ((enemy->def) / 100));

        if (DMGMax > 0){
            enemy->HP = enemy->HP - DMGTot;
            printf("\nLa explosion le ha causado %d HP de dano! Su velocidad y ataque han bajado.\n", DMGTot);
        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero parece que tambien tu has recibido %d de dano reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(3);
        }
    }
}

void UseSkill_27(Player *player, Enemy *enemy) {
    int DMG, DMGMax, DMGTot, Crit, ReflectDMG;

    printf("\n%s uso Chancla de la Armada Domestica!\n", player->name);
    delay(2);

    player->MP = player->MP - 3;
    DMG = GenerateRandom(29, 41, 1);
    DMGMax = DMG + (DMG * ((player->atk) / 100));

    Crit = GenerateRandomChance();

    if (Crit <= player->critchance){
        DMGMax = DMGMax + ((DMGMax * 75) / 100);
        printf("\nEl golpe de %s ha sido critico!\n", player->name);
        delay(3);
    }

    DMGTot = DMGMax;
    if (enemy->dodgedebuff==0){
        enemy->dodgedebuff = 25;
        enemy->turnsdodgedebuff = 4;
    } else {
        enemy->dodgedebuff = enemy->dodgedebuff + (25/2);
    }
    if (DMGMax > 0){
        if (enemy->def>0){
            DMGTot = DMGTot + (DMGTot * ((enemy->def) / 100));
            printf("\nLa defensa del enemigo aumenta el poder de la chancla!\n");
            delay(3);
        }
        enemy->HP = enemy->HP - DMGTot;
        printf("\nEl chanclazo causo %d de dano! La evasion del enemigo bajo\n", DMGTot);
        if (enemy->reflect>0){
            ReflectDMG = (DMGMax * ((enemy->reflect) / 100));
            player->HP = player->HP - ReflectDMG;
            delay(1);
            printf("\nPero reflejaron tu chancla! Has recibido %d de dano, reflejado por %s!\n", ReflectDMG, enemy->name);
        }
        delay(3);
    }
}

void UseSkill_28(Player *player, Enemy *enemy){

}

void UseSkill_29(Player *player, Enemy *enemy){
    int atkdebuff=30, dot=25, dot2=5, turns=4, RNG;

    printf("\n%s uso Lanzallamas Ninja!\n", player->name);
    delay(2);
    player->MP = player->MP - 5;
    if (enemy->dot > 0){
        enemy->dot = enemy->dot + dot;
    } else if (enemy->dot == 0){
        enemy->dot = dot;
        enemy->turnsdot = turns;
    }
    if (player->dot > 0){
        player->dot = player->dot + dot2;
    } else if (player->dot == 0){
        player->dot = player->dot + dot2;
        player->turnsdot = turns;
    }

    printf("\nTodo el campo se cubre de flamas! El enemigo recibe 25HP de dano durante 4 turnos, pero tu tambien recibes 5HP de dano por turno!\n");
    delay(1);
    RNG = GenerateRandomChance();
    delay(2);
    if (RNG <=75){
        if (enemy->atkdebuff==0){
            enemy->atkdebuff = atkdebuff;
            enemy->turnsatkdebuff = 2;
        } else {
            enemy->atkdebuff = enemy->atkdebuff + atkdebuff/2;
        }
    printf("\nParece que el fuego hizo que disminuya su ataque.\n");
    delay(3);
    }
}

void Player_Action(Player *player, Enemy *enemy, int skill, int *lps, int *les, int *reps_lps, int *reps_les) {
    switch (skill) {
        case 1:
            UseSkill_1(player, enemy);
            break;
        case 2:
            UseSkill_2(player, enemy);
            break;
        case 3:
            UseSkill_3(player, enemy);
            break;
        case 4:
            UseSkill_4(player, enemy);
            break;
        case 5:
            UseSkill_5(player, enemy, lps, reps_lps);
            break;
        case 6:
            UseSkill_6(player, enemy, lps, reps_lps);
            break;
        case 7:
            UseSkill_7(player, enemy);
            break;
        case 8:
            UseSkill_8(player, enemy);
            break;
        case 9:
            UseSkill_9(player, enemy);
            break;
        case 10:
            UseSkill_10(player, enemy, skill);
            break;
        case 11:
            UseSkill_11(player, enemy, skill);
            break;
        case 12:
            UseSkill_12(player, enemy, skill);
            break;
        case 13:
            UseSkill_13(player, enemy, skill);
            break;
        case 14:
            UseSkill_14(player, enemy, skill);
            break;
        case 15:
            UseSkill_15(player, enemy, skill);
            break;
        case 16:
            UseSkill_16(player, enemy, skill);
            break;
        case 17:
            UseSkill_17(player, enemy, skill);
            break;
        case 21:
            UseSkill_21(player, enemy);    /* 21 en adelante se refieren a las habilidades normales mejoradas. faltan mas, asi que ojo */
            break;
        case 22:
            UseSkill_22(player, enemy, skill);
            break;
        case 23:
            UseSkill_23(player, enemy, skill);
            break;
        case 24:
            UseSkill_24(player, enemy);
            break;
        case 25:
            UseSkill_25(player, enemy, lps, reps_lps);
            break;
        case 26:
            UseSkill_26(player, enemy, lps, reps_lps);
            break;
        case 27:
            UseSkill_27(player, enemy);
            break;
        case 28:
            UseSkill_28(player, enemy);
            break;
        case 29:
            UseSkill_29(player, enemy);
            break;

    }
}

void usepadineta(Player *player, Enemy *enemy, int *les){
    int DMG=15;
    printf("\n%s ha sacado la Padineta!\n", player->name);
    delay(2);

    enemy->HP = enemy->HP - 15;
    enemy->defdebuff = 50;
    enemy->turnsdefdebuff = 2;

    printf("\nHaces un backflip super fachero, y le partis la tabla en la cara a %s!\n", enemy->name);
    delay(3);
    printf("\nLe has infligido %d de dano, y esta aturdido y debilitado! Aunque no parece que puedas usar tu tabla por lo pronto..\n", DMG);
    delay(4);

    *les = 19;
}

int usetalismanofeve(Player *player){
    char c;
    delay(2);
    printf("\nTu salud ha bajado a 0, pero sientes una fuerte energia...\n");
    delay(2);
    printf("\n       |_|_|_|_|_|_|_|>>EL TALISMAN DE EVE BRILLA CON SU VERDE RESPLANDOR<<|_|_|_|_|_|_|_|\n");
    delay(5);
    printf("\n\n  Deseas utilizar el Talisman para revivir? S/N\n");
    scanf("%c", &c);
    fflush(stdin);
    while (c!= 's' && c!='S' && c!='n' && c!='N'){
        printf("S/N\n");
        scanf("%c", &c);
        fflush(stdin);
    }
    if (c=='s' || c=='S'){
        player->keyitem2 = -1;
        player->HP = player->HPMax / 5;
        printf("\nEl Talisman se fragmenta, liberando toda su energia encerrada. Devolviendote a la vida!\n");
        delay(3);
        return 1;
    } else {
        printf("Estas seguro? Moriras si no lo usas. S/N\n");
        scanf("%c", &c);
        fflush(stdin);
        while (c!= 's' && c!='S' && c!='n' && c!='N'){
            printf("S/N\n");
            scanf("%c", &c);
            fflush(stdin);
        }
        if (c=='n' || c=='N'){
            player->keyitem2 = -1;
            player->HP = player->HPMax / 5;
            printf("\nEl Talisman se fragmenta, liberando toda su energia encerrada. Devolviendote a la vida!\n");
            delay(3);
            return 1;
        } else {
            return 0;
        }
    }
}

#endif //THE_HERETIC_PLAYER_SKILLS_H
