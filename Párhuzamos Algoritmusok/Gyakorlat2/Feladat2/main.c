#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LIMIT 10

void kiir();
int randomInt();
void randomDuplicateArray();
bool isUniqueArray();

int main()
{
    int array[LIMIT];
    bool isValid = true;

    srand(time(NULL));

    for(int i=0; i<LIMIT; i++)
    {
        array[i]=randomInt(0,LIMIT*10);

        for(int j=0; j<i; j++)
        {
            if(array[j]==array[i])
            {
                isValid=false;
            }
        }
    }

    kiir(array);

    if(!isValid)
    {
        printf("\nA tomb elemei nem mind kulonbozo!\n");
        return 1;
    }

    printf("\n");
    isUniqueArray(LIMIT, array);
    randomDuplicateArray(array);
    printf("\nA random duplikalassal a tomb:\n\n");
    kiir(array);
    printf("\n");
    isUniqueArray(LIMIT, array);

    return 0;
}

void kiir(int* array)
{
    for(int i=0; i<10; i++)
    {
        printf("A tomb %d. eleme: %d\n", i+1, array[i]);
    }
    return;
}

int randomInt(int minimum, int maximum)
{
    return (rand()%(maximum-minimum+1));
}

void randomDuplicateArray(int* array)
{
    int random;

    for(int i=0; i<LIMIT; i++)
    {
        random=randomInt(0,LIMIT);
        if(random<5)
        {
            array[i]=array[randomInt(0,LIMIT)];
        }
    }
    return;
}

bool isUniqueArray(int limit, int* array)
{

    for(int i=0; i<limit; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(array[j]==array[i])
            {
                printf("Nem minden elem egyedi!\n");
                return false;
            }
        }
    }

    printf("Minden elem egyedi!\n");
    return true;
}
