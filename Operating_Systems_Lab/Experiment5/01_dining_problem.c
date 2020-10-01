#include<stdio.h>

#define LEFT (i + 4) % 5
#define RIGHT (i + 1) % 5

#define THINKING 0
#define HUNGRY 1
#define EATING 2


int state[6];
void put_forks(int);
void test(int);
void take_forks(int);

void philosopher(int i) {
    if (state[i] == THINKING) {
        take_forks(i);

        if(state[i] == EATING)
            printf("\n Eating in Process....");

        put_forks(i);
    }
}

void put_forks(int i) {

    state[i] = THINKING;
    printf("\n Philosopher %d completed his work.", i);

    test(LEFT);
    test(RIGHT);
}

void take_forks(int i) {
    state[i] = HUNGRY;
    test(i);
}


void test(int i) {
    if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        printf("\n Philosopher %d can eat.", i);
        state[i] = EATING;
    }
}

int main() {
    int i;

    for(i = 1; i <= 5; i++)
        state[i] = THINKING;

    printf("\n\t\t\t Dining Philosopher Problem");
    printf("\n\t\t\t --------------------------");

    for(i = 1; i <= 5; i++) {
        printf("\n\n The Philosopher %d  falls hungry. \n", i);
        philosopher(i);
    }

    return 0;
}
