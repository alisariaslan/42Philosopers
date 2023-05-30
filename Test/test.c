#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
  

  /*
pthread_t tid[2];
int counter;
  
void* trythis(void* arg)
{
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d has started\n", counter);
  
    for (i = 0; i < (0xFFFFFFFF); i++)
        ;
    printf("\n Job %d has finished\n", counter);
  
    return NULL;
}
  
int main(void)
{
    int i = 0;
    int error;
  
    while (i < 2) {
        error = pthread_create(&(tid[i]), NULL, &trythis, NULL);
        if (error != 0)
            printf("\nThread can't be created : [%s]", strerror(error));
        i++;
    }
  
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
  
    return 0;
}*/


int counter;

  


void* trythis(void* arg)
{
    pthread_mutex_lock(arg);
  
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d has started\n", counter);
  
    for (i = 0; i < (0xFFFFFFFF / 5); i++);
  
    printf("\n Job %d has finished\n", counter);
  
    pthread_mutex_unlock(arg);
  
    return NULL;
}



  
int main(void)
{
    int i = 0;
    int error;
  
    pthread_t threads[4];

    pthread_mutex_t lock;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }
  
    while (i < 4) {
        error = pthread_create(&(threads[i]), NULL, &trythis, &lock);
        if (error != 0)
            printf("\nThread can't be created :[%s]",
                   strerror(error));
        i++;
    }
  
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);
    
    pthread_mutex_destroy(&lock);
  
    return 0;
}