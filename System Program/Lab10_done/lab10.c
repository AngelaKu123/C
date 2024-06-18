#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void put_pull_rod(int signum);
void fish_eating(int signum);
void exit_game(int signum);

int fishNum = 0;    // counting fish number
int boolean = 0;    // used as a boolean to track rod state

int main(void) {
    struct sigaction sig_put_pull_rod;
    sig_put_pull_rod.sa_handler = put_pull_rod;
    sigemptyset(&sig_put_pull_rod.sa_mask);
    sig_put_pull_rod.sa_flags = 0;

    struct sigaction sig_fish_eating;
    sig_fish_eating.sa_handler = fish_eating;
    sigemptyset(&sig_fish_eating.sa_mask);
    sig_fish_eating.sa_flags = 0;

    struct sigaction sig_exit_game;
    sig_exit_game.sa_handler = exit_game;
    sigemptyset(&sig_exit_game.sa_mask);
    sig_exit_game.sa_flags = 0;

    sigaction(SIGINT, &sig_put_pull_rod, NULL); // ctrl + C to put/pull rod
    sigaction(SIGALRM, &sig_fish_eating, NULL); // SIGALRM for fish eating
    sigaction(SIGTSTP, &sig_exit_game, NULL);   // ctrl + Z to exit game

    srand(time(NULL));

    while (1) {
        if (boolean == 0)
            printf("Fishing rod is ready!\n");
        
        pause(); // wait for signals
    }

    return 0;
}

void put_pull_rod(int signum) {
    if (boolean == 0) { // rod isn't in water
        printf("\nPut the fishing rod\n");
        printf("Bait into water, waiting fish...\n");
        boolean = 1; // Rod in water
        int fish_eating_time = rand() % 2 + 1; // fish will start eat in 1 ~ 2 seconds
        alarm(fish_eating_time); // set an alarm for fish to start eat
    } else if (boolean == 1) { // rod is in water, and fish doesn't bite
        printf("\nPull the fishing rod\n");
        boolean = 0; // reset state
        alarm(0);
    } else if (boolean == 2) { // rod is in water, and player catch a fish
        printf("\nPull the fishing rod\n");
        printf("Catch a fish!!\n");
        fishNum++;
        printf("Totally caught fishes: %d\n", fishNum);
        boolean = 0;
        alarm(0);
    } else if (boolean == 3) { // rod is in water, and player failed to catch fish
        printf("\nPull the fishing rod\n");
        printf("The bait was eaten!\n");
        boolean = 0;
        alarm(0);
    }
}

void fish_eating(int signum) {
    if (rand() % 2 == 0) {
        printf("Seems like there isn't fish nearby...Let pull rod and try again.\n");
    } else {
        printf("A fish is biting, pulling the fishing rod\n");
        if (rand() % 2 == 0) { // 50% chance to catch the fish
            boolean = 2;
        } else {
            printf("The fish escaped!\n");
            boolean = 3;
        }
    }
}

void exit_game(int signum) {
    printf("\nTotally caught fishes: %d\n", fishNum);
    exit(0);
}