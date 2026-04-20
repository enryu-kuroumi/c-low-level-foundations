// my_sem.h
#ifndef SEM_H
#define SEM_H

#include <pthread.h>

typedef struct {
    int             count;
    pthread_mutex_t mtx;
    pthread_cond_t  cond;
} msem_t;

/* Initialize semaphore with starting value */
void sem_init(msem_t *s, int val);

/* Decrease by n - block until count >= n */
void sem_wait(msem_t *s, int n);

/* Increase by n */
void sem_post(msem_t *s, int n);

/* Get current value */
int sem_value(msem_t *s);

/* Destroy semaphore */
void sem_destroy(msem_t *s);

#endif