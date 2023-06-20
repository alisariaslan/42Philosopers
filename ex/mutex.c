# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_my
{
    int thread_id;
    pthread_mutex_t	lock;
} t_my;

void* trythis(void* arg)
{
    t_my *my = (t_my *)arg;
    pthread_mutex_lock(&my->lock);
    my->thread_id++;
    printf("\n Job %d has started\n", my->thread_id);
    for (unsigned long i = 0; i < 0xFFFFFF; i++);
    printf("\n Job %d has finished\n", my->thread_id);
    pthread_mutex_unlock(&my->lock);
    return 0;
}
  
int main(void)
{
    t_my *my = (t_my *)malloc(sizeof(t_my));
    pthread_t threads[4];
    int i = 0;

    if(!my)
    {
        printf("malloc error");
        return 1;
    }

    if (pthread_mutex_init(&(my->lock), NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }

    while (i < 4) {
        if (pthread_create(&(threads[i]), NULL, &trythis, my) != 0) {
            printf("\n thread create has failed\n");
            return 1;
        }
       i++;
    }
    
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);

    pthread_mutex_destroy(&(my->lock));

    return 0;
}