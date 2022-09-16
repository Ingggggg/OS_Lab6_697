#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int csum;
int msum;
void *runner(void *param);

int main(int argc, char *argv[]) {
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, runner, argv[1]);

    int upper = atoi(argv[1]);
    int i;
    msum = 0;
    if (upper > 0) {
        for (i = 0; i <= upper; i++)
            msum += i;
    }

    // pthread_join(tid, NULL);
    printf("I am Parent thread, csum - msum = %d\n", csum - msum);
    return 0;
}

void *runner(void *param) {
    int upper = atoi(param);
    int i;
    csum = 0;
    if (upper > 0) {
        for (i = 0; i <= upper * 2; i++)
            csum += i;
    }
    pthread_exit(0);
}