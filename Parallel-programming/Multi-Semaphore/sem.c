#include "sem.h"

void sem_init(msem_t *s, int val) {
    s->count = val;
    pthread_mutex_init(&s->mtx, NULL);
    pthread_cond_init(&s->cond, NULL);
}

void sem_wait(msem_t *s, int n) {
    if (n <= 0) return;
    pthread_mutex_lock(&s->mtx);
    while (s->count < n)
        pthread_cond_wait(&s->cond, &s->mtx);
    s->count -= n;
    pthread_mutex_unlock(&s->mtx);
}

void sem_post(msem_t *s, int n) {
    if (n <= 0) return;
    pthread_mutex_lock(&s->mtx);
    s->count += n;
    pthread_cond_broadcast(&s->cond);
    pthread_mutex_unlock(&s->mtx);
}

int sem_value(msem_t *s) {
    pthread_mutex_lock(&s->mtx);
    int val = s->count;
    pthread_mutex_unlock(&s->mtx);
    return val;
}

void sem_destroy(msem_t *s) {
    pthread_mutex_destroy(&s->mtx);
    pthread_cond_destroy(&s->cond);
}