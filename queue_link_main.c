/* 
 * File:   queue_link_main.c
 * Author: jawinton
 *
 * Created on 2010年9月21日, 下午1:07
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue_link.h"
#include "list_link.h"
#include "stack_sq.h"
/*
 * 
 */
/*
int main(int argc, char** argv) {
    int i;
    LinkQueue q;
    initQueue(&q);
    enQueue(&q,2);
    for(i=0;i<12;i=i++)
        enQueue(&q,(i+4)*2);
    print_queue(q);
    deQueue(&q);
    print_queue(q);

    reverse_queue(&q);
    print_queue(q);

    clear_queue(&q);
    print_queue(q);

    LinkQueue q1;
    initQueue(&q1);
    for(i=0;i<12;i=i++)
        enQueue(&q1,(i+4)*2);
    print_queue(q1);
    if(equal_queue(q,q1)) printf("Queue q and q1 are equal.");
    else printf("Queue q is not equal to q1.");

    LinkList L;
    i = 1;
    L = ListCreate_link(L,0);//如果没有返回值的话不能将L的值改变，及L指向的地址不变
    ListPrint_link(L);
    for (; i <= 10; i++)
            ListInsert_link(L, i, 20-i);
    ListInsert_link(L,5,30);
    ListPrint_link(L);
    reverse_by_stack(L);
    ListPrint_link(L);

    return (EXIT_SUCCESS);
}
*/

