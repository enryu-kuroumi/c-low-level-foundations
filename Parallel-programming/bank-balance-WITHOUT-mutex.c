#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static int balance = 1000;  

void *deposit(void *arg) {
    int id = *(int *)arg;

    int tmp = balance;        
    usleep(1);               /* Race condition Emulation */
    tmp += 1000;
    balance = tmp;            

    printf("Thread %d Balance: %d\n", id, balance);
    return NULL;
}

int main(void) {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, deposit, &id1);
    pthread_create(&t2, NULL, deposit, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Balance: %d  (must be 3000)\n", balance);
    return 0;
}
