#ifndef THE_HERETIC_TIME_DELAY_H
#define THE_HERETIC_TIME_DELAY_H

#include <time.h>

void delay(int number_of_seconds);
void delay100ms(int number_of_seconds);
void letter(char s, int n);

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void delay100ms(int number_of_seconds){
    // Converting time into milli_seconds
    int milli_seconds = 100 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void letter(char s, int n){
    printf("%c", s);
    delay100ms(n);
}

#endif //THE_HERETIC_TIME_DELAY_H
