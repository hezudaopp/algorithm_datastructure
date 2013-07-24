/* 
 * File:   list_sq.c
 * Author: jawinton
 *
 * Created on 2010年9月13日, 上午11:03
 */

#include <stdio.h>
#include <stdlib.h>
#include "list_sq.h"

/*
 * 
 */
/*
int main(int argc, char** argv) {
    struct SqList L;
    int i = 0;
    if (ListInit(&L)) {
        for (; i < 10; i++)
            ListInsert(&L, 5*i, i);
    }
    ListInsert(&L,5,1);
    ListInsert(&L,5,1);
    ListInsert(&L,99,12);
    ListInsert(&L,99,12);
    ListInsert(&L,99,12);
    ListPrint(&L);
    SortedListDeleteSame(&L);
    ListPrint(&L);
    SortedListDeleteBetween(&L,24,35);
    ListPrint(&L);
    ListInsert(&L,55,3);
    ListInsert(&L,55,3);
    ListPrint(&L);
    ListDeleteElem(&L,55);
    ListPrint(&L);
    ListDeleteBetween(&L,5,16);
    ListPrint(&L);

    struct SqList L1,L2;
    if (ListInit(&L1)) {
        for (i=0; i < 12; i++)
            ListInsert(&L1, 200-i*i, i);
    }
    ListPrint(&L1);
    printf("%d",ListDeleteMin(&L1));
    ListPrint(&L1);
    ListMerge_Point(L,L1,&L2);
    ListPrint(&L2);

    return (EXIT_SUCCESS);
}

*/
