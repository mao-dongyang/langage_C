#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NBVAL 1E4
#define MIN 0
#define MAX 1E5

clock_t start, finish;
double duration;

int *InitTab(unsigned int nbVal, int min, int max);
bool Verif(int *t, unsigned int nbVal);
void bubbleSort(int *t, unsigned int nbVal, int (*compare)(int, int));
void quickSort(int *t, unsigned int nbVal, int (*compare)(int, int));
void _quickSort(int *t, int left, int right, int (*compare)(int, int));
void sort(int *t, unsigned int nbVal, void (*sortMethod)(int *t, unsigned int nbVal, int (*compare)(int, int)), int (*compare)(int, int))
{
    sortMethod(t, nbVal, compare);
}

int min2max(int a, int b)
{
    return a - b;
}
int max2min(int a, int b)
{
    return b - a;
}
int pair(int a, int b)
{
    if (a % 2 == 0 && b % 2 != 0)
        return -1;
    if (a % 2 != 0 && b % 2 == 0)
        return 1;
    return a - b;
}

// if true print "true"
// if false print "false"
void printBool(bool b)
{
    if (b)
    {
        printf("\ntrue\n");
    }
    else
    {
        printf("\nfalse\n");
    }
}

int *duplicate(int *t, unsigned int nbVal)
{
    int *t2 = (int *)malloc(nbVal * sizeof(int));
    for (int i = 0; i < nbVal; i++)
    {
        t2[i] = t[i];
    }
    return t2;
}

void printMethod(void (*sortMethod)(int *t, unsigned int nbVal, int (*compare)(int, int)))
{
    if (sortMethod == bubbleSort)
    {
        printf("bubbleSort");
    }
    else if (sortMethod == quickSort)
    {
        printf("quickSort");
    }
}

int main()
{
    void *sortMethodArray[2] = {bubbleSort, quickSort};

    for (int i = 0; i < 2; i++)
    {
        srand(0);
        int *t = InitTab(NBVAL, MIN, MAX);
        printf("----------------------");
        printMethod(sortMethodArray[i]);
        printf("---------------------\n");
        printBool(Verif(t, NBVAL));
        start = clock();
        sort(t, NBVAL, sortMethodArray[i], min2max);
        finish = clock();
        printBool(Verif(t, NBVAL));
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("%f seconds\n", duration);
        printf("----------------------------------------------------\n");
    }
    return 0;
}

int *InitTab(unsigned int nbVal, int min, int max)
{
    int *t = (int *)malloc(nbVal * sizeof(int));
    for (int i = 0; i < nbVal; i++)
    {
        t[i] = rand() % (max - min + 1) + min;
    }
    return t;
}

bool Verif(int *t, unsigned int nbVal)
{
    bool flg = true;
    if (nbVal >= 2)
    {
        for (int i = 0; i < nbVal - 1 && flg; i++)
        {
            if (t[i] > t[i + 1])
            {
                flg = false;
            }
        }
    }

    // print array 10 head and  10 tail
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", t[i]);
    }
    printf("....... ");
    for (int i = nbVal - 10; i < nbVal; i++)
    {
        printf("%d ", t[i]);
    }

    return flg;
}

void bubbleSort(int *t, unsigned int nbVal, int (*compare)(int, int))
{
    int tmp;
    for (int i = 0; i < nbVal - 1; i++)
    {
        for (int j = 0; j < nbVal - 1 - i; j++)
        {
            if (compare(t[j], t[j + 1]) > 0)
            {
                tmp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tmp;
            }
        }
    }
}

// quick sort
void quickSort(int *t, unsigned int size, int (*compare)(int, int))
{
    _quickSort(t, 0, size - 1, compare);
}

void _quickSort(int *t, int left, int right, int (*compare)(int, int))
{
    if (right - left < 1)
        return;

    int i = left + 1, j = right;
    int tmp;
    int pivot = t[left];

    /* partition */
    while (i <= j)
    {
        if (compare(t[i], pivot) < 0)
            i++;
        else if (compare(t[j], pivot) >= 0)
            j--;
        else
        {
            tmp = t[i];
            t[i] = t[j];
            t[j] = tmp;
            i++;
            j--;
        }
    }
    tmp = t[left];
    t[left] = t[j];
    t[j] = tmp;

    /* recursion */

    _quickSort(t, left, j - 1, compare);
    _quickSort(t, j + 1, right, compare);
}
