#include <stdlib.h>

#include "list_link.h"
#include "stddef.h"
#include "stack_sq.h"

Status GetElem_link(LinkList L, int i, ElemType* e){
    LinkList p = L->next;//p初始化应该指向第一个结点，而非头结点
    int j = 0;
    while(p && j<i-1){
        p = p->next;
        ++j;
    }

    if(!p || j>i-1) return ERROR;//!p表示i的值超出了链表长度，j>i-1表示i的取值小于1

    *e = p->data;
    return OK;
}

Status ListInsert_link(LinkList L, int i, ElemType e){
    LinkList p = L;//由于需要找到是第i个结点的上一个结点才能进行插入操作，所以p赋值为L，为非L->next

    //找到第i-1个结点
    int j = 0;
    while(p && j<i-1){
        p = p->next;
        ++j;
    }

    if(!p || j>i-1) return ERROR;//!p表示i的值超出了链表长度，j>i-1表示i的取值小于1

    //插入操作
    LinkList node = (LinkList)malloc(sizeof(Node));
    node->data = e;
    node->next = p->next;
    p->next = node;

    return OK;

}

Status ListDelete_link(LinkList L, int i, ElemType *e){
    LinkList p = L;
    int j = 0;
    while(p && j<i-1){
        p = p->next;
        ++j;
    }
    if(!p && j>i-1) return ERROR;

    //删除操作
    LinkList node = p->next;
    p->next = node->next;
    *e = node->data;
    free(node);
    return OK;
}

LinkList ListCreate_link(LinkList L, int n){
    //逆序输入n个元素的值，建立带头结点的单向链表
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    int i;
    for(i=0;i<n;i++){
        LinkList p = (LinkList)malloc(sizeof(Node));
        scanf("%d",&(p->data));
        p->next = L->next;
        L->next = p;
    }
    return L;
}

LinkList ListMerge_link(LinkList A, LinkList B, LinkList C){//该函数也会改变A和B链表的结构
    LinkList pa = A->next, pb = B->next, pc = C = A;//pc表示C链表中当前最后一个结点
    while(pa && pb){
        if(pa->data <= pb->data){
            pc->next = pa;//将pa所指结点添加到pc所指结点之后
            pc = pa;//相当于pc=pc->next;
            pa = pa->next;
        }else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(B);
    return C;
}

void ListPrint_link(LinkList L){
    LinkList p = L->next;
    if(!p) printf("链表为空\n");
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void ListSortPrint_link(LinkList L){
    LinkList p = L->sort;
    if(!p) printf("链表为空\n");
    while(p){
        printf("%d ",p->data);
        p = p->sort;
    }
    printf("\n");
}

LinkList ListSort_link(LinkList L){
    L->sort = L->next;
    L->sort->sort = NULL;
    LinkList p = L->next->next;//如果只有一个元素，p==NULL，则不进入循环，不进行排序
    LinkList s = L->next;//排列链表，初始化指向头结点，s=L->sort,s->sort = NULL
    while(p){
        s = L;//链表中每个数据元都必须和排序好的链表重头开始比较，s指向要比较数据的直接前驱，这样才能进行插入操作
        while(s->sort && s->sort->data <= p->data){//查找p在s中的插入位置，从s链表的第一个元素开始比较
            s=s->sort;
        }

        //往s链表中插入p结点
        p->sort = s->sort;
        s->sort = p;

        p = p->next;
    }
    return L;
}

LinkList ListMax_link(LinkList L){
    if(!L->next) return ERROR;
    LinkList p = L->next;
    LinkList node = p;
    while(p->next){
        if(p->next->data > node->data) node = p->next;
        p = p->next;
    }
    return node;
}

int ListNumber_link(LinkList L, ElemType x){
    int count = 0;
    LinkList p = L->next;
    while(p){
        if(p->data == x) count++;
        p = p->next;
    }
    return count;
}

LinkList ListCreateFromArray_link(ElemType a[], int n){
    LinkList L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    int i;
    for(i=n-1;i>=0;i--){
        LinkList p = ((LinkList)malloc(sizeof(Node)));
        p->next = NULL;
        p->data = a[i];
        p->next = L->next;
        L->next = p;
    }
    return L;
}

Status ListTidyup_link(LinkList L){
    LinkList p = L->next;

    while(p->next){
        if(p->next->data == p->data){
            LinkList q = p->next;
            p->next = q->next;
            free(q);
        }else p = p->next;
    }
    return OK;
}

ElemType ListMax_link_recu(LinkList L){
    if(L->next == NULL) return L->data;
    int temp = ListMax_link_recu(L->next);
    if(temp < L->data) return L->data;
    else return temp;
}

int ListCount_link_recu(LinkList L){
    if(L == NULL) return 0;
    else return 1+ListCount_link_recu(L->next);
}

float ListAverage_link_recu(LinkList L,int *n){
    if(L->next == NULL){
        *n = 1;
        return (float)L->data;
    }
    else{
        float sum = ListAverage_link_recu(L->next, n)*(*n);
        (*n)++;
        return (L->data + sum)/(*n);
    }
}

LinkList inverse(LinkList L){
    if(!L) return;

    LinkList p = L->next;
    L->next = NULL;

    while(p){
        LinkList temp = p->next;
        p->next = L;
        L = p;
        p = temp;
    }
    return L;
}

void reverse_by_stack(LinkList L){
    LinkList q = L->next;
    SqStack s;
    InitStack(&s);
    while(q){
        Push(&s,q->data);
        LinkList temp = q;
        q = q->next;
        free(temp);
    }
    q = L;
    while(!isEmpty_stack(s)){
        Node *p = (Node *)malloc(sizeof(Node));
        p->data = Pop(&s);
        q->next = p;//连接到尾部
        q = q->next;
    }
    q->next = NULL;

}