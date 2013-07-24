/* 
 * File:   list_sq.h
 * Author: jawinton
 *
 * Created on 2010��9��13��, ����10:54
 */

#ifndef LIST_SQ_H
#define	LIST_SQ_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "datastructure.h"
#define LIST_INIT_SIZE  100
#define LIST_INCREMENT  10
    struct SqList{
        ElemType *elem;
        int length; //��ǰ����
        int listsize; //��ǰ����Ĵ���ռ䣨��sizeof��ElemType��Ϊ��λ��
    };

    Status ListInit(struct SqList* L);
    Status ListInsert(struct SqList* L, ElemType e, int i);
    Status ListDelete(struct SqList* L, ElemType *e, int i);
    Status ListDeleteElem(struct SqList* L, ElemType e);
    Status ListDeleteBetween(struct SqList* L,ElemType s,ElemType t);
    Status SortedListDeleteBetween(struct SqList* L,ElemType s,ElemType t);
    Status SortedListDeleteSame(struct SqList* L);
    Status ListPrint(struct SqList* L);
    Status ListMerge(struct SqList A, struct SqList B, struct SqList* C);
    Status ListMerge_Point(struct SqList A, struct SqList B, struct SqList* C);
    int Findelem(struct SqList * L,int elm);//���ز��ҵ�Ԫ�ص�����
    ElemType ListDeleteMin(struct SqList* L);
#ifdef	__cplusplus
}
#endif

#endif	/* LIST_SQ_H */

