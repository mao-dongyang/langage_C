#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *InitTab(unsigned int nbVal, int min, int max);
bool Verif(int *t, unsigned int nbVal);
void MonTri(int *t, unsigned int nbVal);
void quickSort(int *t, int left, int right);

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

int main()
{
    int *t = InitTab(10, 0, 100);
    printBool(Verif(t, 10));
    // MonTri(t, 10);
    quickSort(t, 0, 9);
    printBool(Verif(t, 10));
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

    for (int i = 0; i < nbVal; i++)
    {
        printf("%d ", t[i]);
    }
    return flg;
}

void MonTri(int *t, unsigned int nbVal)
{
    int i, j, tmp;
    for (i = 0; i < nbVal; i++)
    {
        for (j = i + 1; j < nbVal; j++)
        {
            if (t[i] > t[j])
            {
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}

// quick sort
void quickSort(int *t, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = t[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (t[i] < pivot)
            i++;
        while (t[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = t[i];
            t[i] = t[j];
            t[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(t, left, j);
    if (i < right)
        quickSort(t, i, right);
}