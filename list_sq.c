#include <stdlib.h>

#include "list_sq.h"

Status ListInit(struct SqList* L) {
    //初始化一个空的线性表
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof (ElemType));
    L->length = 0; //当前长度设为0
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

/**
 * Add an elem before index i
 * @param L
 * @param e
 * @param i
 * @return
 */
Status ListInsert(struct SqList* L, ElemType e, int i) {
    ElemType *newbase;
    int *p, *q; //指针
    if (i < 1 || i > L->length + 1) return ERROR; //i值不合法

    //增加存储空间
    if (L->length >= L->listsize) {
        newbase = (ElemType *) realloc(L->elem, (L->listsize + LIST_INCREMENT) * sizeof (ElemType));
        if (!newbase) exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LIST_INCREMENT;
    }

    q = &(L->elem[i - 1]);
    for (p = &(L->elem[L->length - 1]); p >= q; p--) *(p + 1) = *p;
    *q = e;
    L->length++;

    return OK;
}

/**
 * Delete the elem of index i
 * @param L
 * @param e
 * @param i
 * @return
 */
Status ListDelete(struct SqList* L, ElemType *e, int i) {
    int *p, *q;
    if (i < 1 || i > L->length) return ERROR; //i值不合法

    q = &(L->elem[i - 1]);
    *e = *q;

    for (p = q; p<&(L->elem[L->length - 1]); p++) *p = *(p + 1);
    L->length--;

    return OK;
}

/****************************************/
/*Print the list */
/****************************************/
Status ListPrint(struct SqList * L)
{
  int *p,*q;
  if (L->length == 0)
  {
    printf("The list now is empty!\n");
  }
  else if (L->length == 1)
  {
    printf("The current list:\n%d",*(L->elem));
  }
  else if (L->length == 2)
  {
     printf("The current list:\n%d->%d",*(L->elem),*(L->elem+1));
  }
  else if (L->length >2);
  {
    q = L->elem +L->length-2;
    printf("The current list :\n");
    for (p = L->elem;p<=q;p++)
    {
      printf("%d->",*p);
    }
    printf("%d\n",*(q+1));
  }

  return OK;
}

/****************************************/
/*Find a number if or not in the list*/
/****************************************/
int Findelem(struct SqList * L,int elm)
{
  int *p,*q;
  int totalfind=0;
  for (p=L->elem;p<=L->elem+L->length-1;p++)
  {
    if ((*p)==elm)
    {
/*
	printf("We can find  %d in the list at of the location of %d\n",elm,p-L->elem+1);
*/
	totalfind++;
    }
  }
  return totalfind;
}

Status ListMerge(struct SqList A, struct SqList B, struct SqList* C){
    int i=0,j=0,k=0;
    C->listsize =C->length = A.length + B.length;
    C->elem = (ElemType *)malloc(C->listsize*sizeof(ElemType));
    while(i<A.length && j<B.length){
        if(A.elem[i] <= B.elem[j]){
            C->elem[k]=A.elem[i++];
        }else{
            C->elem[k]=B.elem[j++];
        }
        k++;
    }

    while(i<A.length){
        C->elem[k++] = A.elem[i++];
    }

    while(j<B.length){
        C->elem[k++] = B.elem[j++];
    }
    return OK;
}

Status ListMerge_Point(struct SqList A, struct SqList B, struct SqList* C){
    int *pa,*pb,*pc;
    pa = A.elem;
    pb = B.elem;
    C->length = C->listsize = A.length + B.length;
    pc = C->elem = (ElemType *)malloc(C->listsize*sizeof(ElemType));
    int pa_last = A.elem + A.length;
    int pb_last = B.elem + B.length;
    while(pa < pa_last && pb < pb_last){
        if(*pa <= *pb) *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while(pa < pa_last)
        *pc++ = *pa++;
    while(pb < pb_last)
        *pc++ = *pb++;
    return OK;
}

ElemType ListDeleteMin(struct SqList* L){
    int i = 0, j = 0;
    if(L->length == 0){
        printf("Sequence list is null, exit!");
        return ERROR;
    }
    for(i=1;i<L->length;i++){
        if(L->elem[i] < L->elem[j]) j = i;
    }
    ElemType value = L->elem[j];
    L->elem[j] = L->elem[i-1];
    L->length--;
    return value;
}

Status ListDeleteElem(struct SqList* L, ElemType e){
    if(L->length == 0){
        printf("Sequence list is null, exit!");
        return ERROR;
    }

    int i,j;
    for(i=L->length-1;i>=0;i--){//L->length的值可能变化，因此这边逆序循环，不用顺序循环
        if(L->elem[i] == e){
            for(j=i;j<L->length;){
                L->elem[j] = L->elem[++j];
            }
            L->length--;
        }
    }
}

Status ListDeleteBetween(struct SqList* L,ElemType s,ElemType t){
     if(L->length == 0){
        printf("Sequence list is null, exit!");
        return ERROR;
    }

     if(s > t){
        printf("s should be less than t");
        return ERROR;
     }

    int i,j;
    for(i=L->length-1;i>=0;i--){//L->length的值可能变化，因此这边逆序循环，不用顺序循环
        if(L->elem[i] >= s && L->elem[i] <= t){
            for(j=i;j<L->length;){
                L->elem[j] = L->elem[++j];
            }
            L->length--;
        }
    }
}

Status SortedListDeleteBetween(struct SqList* L,ElemType s,ElemType t){
      if(L->length == 0){
        printf("Sequence list is null, exit!");
        return ERROR;
    }

     if(s > t){
        printf("s should be less than t");
        return ERROR;
     }

      int i,j,range;// range用来记录在s和t之间的元素数

      for(i=0;i<L->length && L->elem[i]<s;i++);//i==大于或等于s的第一个元素的index
      j = i;
      if(j>=L->length) return ERROR;//没有找到>=s的元素
      for(;i<L->length && L->elem[i]<=t;i++);//i==大于t的第一个元素
      range = i - j;
      for(;i<L->length;i++)
          L->elem[i - range] = L->elem[i];
      L->length = L->length - range;
      return OK;
}

Status SortedListDeleteSame(struct SqList* L){
    int i,j;
    for(i=L->length-1;i>=0;i--){
        if(L->elem[i] == L->elem[i-1]){
            for(j=i;j<L->length;j++)
                L->elem[j] = L->elem[j+1];
            L->length--;
        }
    }
}