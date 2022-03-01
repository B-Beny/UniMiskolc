#include <stdio.h>
#include <stdlib.h>

void kiir();
int sum();
int min();
int max();

int main()
{
    int array[10];

    for(int i=0; i<10; i++)
    {
        printf("Add meg a tomb %d. elemet (egesz): ",i+1);
        scanf("%d", &array[i]);
    }

    printf("\n");
    kiir(array);
    printf("\n");
    printf("A tomb elemeinek osszege: %d\n", sum(array));
    printf("\n");
    printf("A tomb legkisebb eleme: %d\n", min(array));
    printf("\n");
    printf("A tomb legnagyobb eleme: %d\n", max(array));

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

int sum(int* array)
{
    int sum=0;

    for(int i=0; i<10; i++)
    {
        sum+=array[i];
    }

    return sum;
}

int min(int* array)
{
    int min=array[0];

    for(int i=1; i<10; i++)
    {
        if(array[i]<min)
        {
            min=array[i];
        }
    }

    return min;
}

int max(int* array)
{
    int max=array[0];

    for(int i=1; i<10; i++)
    {
        if(array[i]>max)
        {
            max=array[i];
        }
    }

    return max;
}
