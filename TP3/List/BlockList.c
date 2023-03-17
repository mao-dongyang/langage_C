#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BlockList.h"
#define BLOCK_SIZE 5

struct SList
{
    SCell *first;
    SCell *last;
    SBlock *block;
    SCell *recycle;
};

struct SCell
{
    int data;
    SCell *next;
    SCell *prev;
};

struct SBlock
{
    SCell tab[BLOCK_SIZE];
    SBlock *bnext;
};

SList *CreateList()
{
    SList *list;
    list->block = CreateBlock();
    list->first = NULL;
    list->last = NULL;
    list->recycle = NULL;
    return list;
}

SBlock *CreateBlock()
{
    SBlock *block = (SBlock *)malloc(sizeof(SBlock));
    block->bnext = NULL;
    for (int i; i < BLOCK_SIZE; i++)
    {
        block->tab[i].data = NULL;
        block->tab[i].prev = NULL;
        block->tab[i].next = NULL;
    }
    return block;
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

SCell *GetCellFromBlock(SList *list)
{
    SCell *pcell;
    while (!(pcell = _GetCellFromBlock(list->block)))
    {
        AddBlock(list->block);
    }
    return pcell;
}

SBlock *AddBlock(SBlock *blist)
{
    SBlock *pblock = CreateBlock();
    while (blist->bnext != NULL)
    {
        blist = blist->bnext;
    }
    blist->bnext = pblock;
    return pblock;
}

SCell *_GetCellFromBlock(SBlock *bList)
{
    while (bList != NULL)
    {
        for (int i = 0; i < BLOCK_SIZE; i++)
        {
            if ((bList->tab)[i].data == NULL)
            {
                return &(bList->tab)[i];
            }
        }
        bList = bList->bnext;
    }
    return NULL;
}

SCell *AddElementBegin(SList *list, int data)
{
    SCell *cell = GetCellFromBlock(list);
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
    SCell *cell = GetCellFromBlock(list);
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
        SCell *newCell = GetCellFromBlock(list);
        newCell->data = data;
        newCell->next = cell->next;
        newCell->prev = cell;
        cell->next->prev = newCell;
        cell->next = newCell;
        return newCell;
    }
}

SCell *RecycleCell(SCell *head, SCell *cell)
{
    cell->next = NULL;
    SCell *recycle = head;
    if (recycle == NULL)
    {
        return cell;
    }
    while (recycle->next != NULL)
    {
        recycle = recycle->next;
    }
    recycle->next = cell;
    return head;
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
    list->recycle = RecycleCell(list->recycle, cell);
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

void PrintBlockList(SList *list)
{
    printf("Block: ");
    SBlock *pBlock = list->block;
    while (pBlock != NULL)
    {
        for (size_t i = 0; i < BLOCK_SIZE; i++)
        {
            if (pBlock->tab[i].data != NULL)
            {
                printf(" [%d] ", pBlock->tab[i].data);
            }
            else
            {
                printf(" | NULL | ");
            }
        }
        printf("-->");
        pBlock = pBlock->bnext;
    }
    printf("\n");
}

void PrintRecycleList(SList *list)
{
    printf("Recycle: ");
    SCell *pCell = list->recycle;
    while (pCell != NULL)
    {
        printf("[%d] -> ", pCell->data);
        pCell = pCell->next;
    }
    printf("\n");
}