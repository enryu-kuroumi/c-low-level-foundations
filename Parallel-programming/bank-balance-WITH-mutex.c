#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static int balance = 1000;
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *deposit(void *arg) {
    int id = *(int *)arg;

    pthread_mutex_lock(&lock);    

        int tmp = balance;            /* RWD operation */
        usleep(1);                    /* Race condition emulation */ 
        tmp += 1000;                     
        balance = tmp;
        printf("Thread %d  Balance: %d\n", id, balance);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void) {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    /* mutex init */

    pthread_create(&t1, NULL, deposit, &id1);
    pthread_create(&t2, NULL, deposit, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    /* Just good habit to destroy mutex after use */
    pthread_mutex_destroy(&lock);

    printf("Balance: %d\n", balance);
    return 0;
}
