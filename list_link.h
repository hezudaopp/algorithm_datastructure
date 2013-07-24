/* 
 * File:   list_link.h
 * Author: jawinton
 *
 * Created on 2010年9月13日, 下午6:38
 */

#ifndef LIST_LINK_H
#define	LIST_LINK_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "datastructure.h"
    typedef struct Node{
        ElemType data;
        struct Node *next;
        struct Node *sort;
    }Node,  *LinkList;
    Status GetElem_link(LinkList L, int i, ElemType *e);
    Status ListInsert_link(LinkList L, int i, ElemType e);
    Status ListDelete_link(LinkList L, int i, ElemType *e);
    LinkList ListCreate_link(LinkList sL, int n);
    LinkList ListMerge_link(LinkList A, LinkList B, LinkList C);
    void ListPrint_link(LinkList L);
    void ListSortPrint_link(LinkList L);
    LinkList ListSort_link(LinkList L);
    LinkList ListMax_link(LinkList L);
    int ListNumber_link(LinkList L, ElemType x);
    LinkList ListCreateFromArray_link(ElemType a[], int n);
    Status ListTidyup_link(LinkList L);
    LinkList inverse(LinkList L);//参数L的值是首元结点，非头结点

    // 以下方法使用的是递归算法实现
    ElemType ListMax_link_recu(LinkList L);//计算链表中的最大元素值,这边的LinkList是从首元结点开始，而非头结点
    int ListCount_link_recu(LinkList L);//链表的结点个数,这边的LinkList是从首元结点开始，而非头结点
    float ListAverage_link_recu(LinkList L,int *n);//链表所有值的平均值,这边的LinkList是从首元结点开始，而非头结点

    void reverse_by_stack(LinkList L);

#ifdef	__cplusplus
}
#endif

#endif	/* LIST_LINK_H */

