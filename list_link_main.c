/* 
 * File:   list_link_main.c
 * Author: jawinton
 *
 * Created on 2010年9月14日, 下午10:51
 */

#include <stdio.h>
#include <stdlib.h>
#include "list_link.h"
#include "list_sq.h"
/*
 * 
 */
/*
int main(int argc, char** argv) {
    LinkList L,L1,L2;
    int i = 1;
    L = ListCreate_link(L,0);//如果没有返回值的话不能将L的值改变，及L指向的地址不变
    L1 = ListCreate_link(L1,0);
    ListPrint_link(L);
    for (; i <= 10; i++)
            ListInsert_link(L, i, 20-i);
    ListInsert_link(L,5,30);
    ListPrint_link(L);
    ListPrint_link(inverse(L->next));
    LinkList node = ListMax_link(L);
    printf("%d\n",node->data);

    ElemType a[5] = {3,29,4,2,5};
    ListPrint_link(ListCreateFromArray_link(a,5));

    ListInsert_link(L,10,30);
    ListSort_link(L);
    ListPrint_link(L);

    printf("%d\n",ListNumber_link(L,30));

    ListSortPrint_link(L);
    for (i=0; i < 12; i++)
            ListInsert_link(L1, i, i*i);
    ListInsert_link(L1,11,121);
    ListPrint_link(L1);
    ListTidyup_link(L1);
    ListPrint_link(L1);

    printf("Max value:%d\n",ListMax_link_recu(L->next));

    printf("List count:%d\n",ListCount_link_recu(L->next));

    int n =12;//n的取值无所谓
    printf("List average:%f\n",ListAverage_link_recu(L->next,&n));

    L2 = ListMerge_link(L,L1,L2);
    printf("L:");
    ListPrint_link(L);
    printf("L1:");
    ListPrint_link(L1);
    printf("L2:");
    ListPrint_link(L2);
    return (EXIT_SUCCESS);
}
*/

