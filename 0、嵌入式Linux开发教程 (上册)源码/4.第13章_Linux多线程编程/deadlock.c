#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexB = PTHREAD_MUTEX_INITIALIZER;

void * t1(void *arg) {
    pthread_mutex_lock(&mutexA);
    printf("t1 get mutexA\n");
    usleep(1000);
    pthread_mutex_lock(&mutexB);
    printf("t1 get mutexB\n");
    pthread_mutex_unlock(&mutexB);
    printf("t1 release mutexB\n");
    pthread_mutex_unlock(&mutexA);
    printf("t1 release mutexA\n");
    return NULL;
}

void * t2(void *arg) {
    pthread_mutex_lock(&mutexB);
    printf("t2 get mutexB\n");
    usleep(1000);
    pthread_mutex_lock(&mutexA);
    printf("t2 get mutexA\n");
    pthread_mutex_unlock(&mutexA);
    printf("t2 release mutexA\n");
    pthread_mutex_unlock(&mutexB);
    printf("t2 release mutexB\n");
    return NULL;
}

int main(void) {
    int err;
    long i;
        
    err = pthread_create(&(tid[0]), NULL, &t1, NULL );
    if (err != 0) 
        printf("Can't create thread :[%s]", strerror(err));
    
    err = pthread_create(&(tid[1]), NULL, &t2, NULL);
    if (err != 0)
        printf("Can't create thread :[%s]", strerror(err));

    for (i = 0; i < 2; i++) 
        pthread_join(tid[i], NULL);

    return 0;
}
