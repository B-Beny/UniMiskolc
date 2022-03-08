#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>

void* waitFour(void* args);
void* waitOne(void* args);

int main()
{

    // Elso pont kezdete

    pthread_t t;
    printf("[thread] most kezd el varakozni.\n");
    pthread_create(&t,NULL,waitFour,NULL);

    printf("[main] elkezdte a varakozast.\n");
    Sleep(8000);
    printf("[main] befejezte a varakozast.\n");

    pthread_join(t,NULL);

    //Elso pont vege
    printf("\n");
    //Masodik pont kezdete

    clock_t begin = clock();

    pthread_t tid[60];

    for(int i=1;i<=60;i++)
    {
        pthread_create(&tid[i],NULL,waitOne,i);
    }
    for(int i=1;i<=60;i++)
    {
        pthread_join(tid[i],NULL);
    }

    clock_t end = clock();

    double runtime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nFutasi ido(sec): %lf\n\n",runtime);

    //Masodik pont vege
    //Harmadik pont kezdete

    /*pthread_t titi[10];

    for(int i=0;i<10;i++)
    {
        pthread_create(&titi[i],NULL,,i);
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(titi[i],NULL);
    }*/

    //Harmadik pont vege

    return 0;
}

void* waitFour(void* args)
{
    Sleep(4000);
    printf("[thread] most fejezte be a varakozast.\n");
    return;
}

void* waitOne(void* args)
{
    Sleep(1000);
    printf("[thread %d] most fejezte be a varakozast.\n", args);
    return;
}

