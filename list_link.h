/* 
 * File:   list_link.h
 * Author: jawinton
 *
 * Created on 2010��9��13��, ����6:38
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
    LinkList inverse(LinkList L);//����L��ֵ����Ԫ��㣬��ͷ���

    // ���·���ʹ�õ��ǵݹ��㷨ʵ��
    ElemType ListMax_link_recu(LinkList L);//���������е����Ԫ��ֵ,��ߵ�LinkList�Ǵ���Ԫ��㿪ʼ������ͷ���
    int ListCount_link_recu(LinkList L);//����Ľ�����,��ߵ�LinkList�Ǵ���Ԫ��㿪ʼ������ͷ���
    float ListAverage_link_recu(LinkList L,int *n);//��������ֵ��ƽ��ֵ,��ߵ�LinkList�Ǵ���Ԫ��㿪ʼ������ͷ���

    void reverse_by_stack(LinkList L);

#ifdef	__cplusplus
}
#endif

#endif	/* LIST_LINK_H */

