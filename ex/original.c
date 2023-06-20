#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void* trythis(void* arg)
{
    printf("\n Job %d has started\n", *(int*)arg);
    for (unsigned long i = 0; i < (0xFFFFFFF); i++);
    printf("\n Job %d has finished\n", *(int*)arg);
    return 0;
}
  
int main(void)
{
    pthread_t tid[2];
    int i = 0;
    int error;
  
    while (i < 2) {
        error = pthread_create(&(tid[i]), NULL, &trythis, &i);
        if (error != 0)
            printf("\nThread can't be created : [%s]", strerror(error));
        i++;
    }
  
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
  
    return 0;
}