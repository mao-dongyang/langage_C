#include <stdio.h>
#include <stdlib.h>
#include "Liste.h"

struct SList
{
    SCell *first;
    SCell *last;
};

struct SCell
{
    int data;
    SCell *next;
    SCell *prev;
};

SList *CreateList()
{
    SList *list = (SList *)malloc(sizeof(SList));
    list->first = NULL;
    list->last = NULL;
    return list;
}

void DeleteList(SList *list)
{
    SCell *cell = GetFirstElement(list);
    while (cell != NULL)
    {
        SCell *next = GetNextElement(cell);
        DeleteCell(list, cell);
        cell = next;
    }
    free(list);
}

SCell *AddElementBegin(SList *list, int data)
{
    SCell *cell = (SCell *)malloc(sizeof(SCell));
    cell->data = data;
    cell->next = list->first;
    cell->prev = NULL;
    if (list->first != NULL)
    {
        list->first->prev = cell;
    }
    list->first = cell;
    if (list->last == NULL)
    {
        list->last = cell;
    }
    return cell;
}

SCell *AddElementEnd(SList *list, int data)
{
    SCell *cell = (SCell *)malloc(sizeof(SCell));
    cell->data = data;
    cell->next = NULL;
    cell->prev = list->last;
    if (list->last != NULL)
    {
        list->last->next = cell;
    }
    list->last = cell;
    if (list->first == NULL)
    {
        list->first = cell;
    }
    return cell;
}

SCell *AddElementAfter(SList *list, SCell *cell, int data)
{
    if (cell == NULL)
    {
        return AddElementBegin(list, data);
    }
    else if (cell == list->last)
    {
        return AddElementEnd(list, data);
    }
    else
    {
        SCell *newCell = (SCell *)malloc(sizeof(SCell));
        newCell->data = data;
        newCell->next = cell->next;
        newCell->prev = cell;
        cell->next->prev = newCell;
        cell->next = newCell;
        return newCell;
    }
}

void DeleteCell(SList *list, SCell *cell)
{
    if (cell == list->first)
    {
        list->first = cell->next;
    }
    if (cell == list->last)
    {
        list->last = cell->prev;
    }
    if (cell->prev != NULL)
    {
        cell->prev->next = cell->next;
    }
    if (cell->next != NULL)
    {
        cell->next->prev = cell->prev;
    }
    free(cell);
}

SCell *GetFirstElement(SList *list)
{
    return list->first;
}

SCell *GetLastElement(SList *list)
{
    return list->last;
}

SCell *GetNextElement(SCell *cell)
{
    return cell->next;
}

SCell *GetPrevElement(SCell *cell)
{
    return cell->prev;
}

int GetData(SCell *cell)
{
    return cell->data;
}