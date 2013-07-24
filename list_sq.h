/* 
 * File:   list_sq.h
 * Author: jawinton
 *
 * Created on 2010年9月13日, 上午10:54
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
        int length; //当前长度
        int listsize; //当前分配的储存空间（以sizeof（ElemType）为单位）
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
    int Findelem(struct SqList * L,int elm);//返回查找到元素的数量
    ElemType ListDeleteMin(struct SqList* L);
#ifdef	__cplusplus
}
#endif

#endif	/* LIST_SQ_H */

