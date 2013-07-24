#include <stdlib.h>

#include "list_link.h"
#include "stddef.h"
#include "stack_sq.h"

Status GetElem_link(LinkList L, int i, ElemType* e){
    LinkList p = L->next;//p��ʼ��Ӧ��ָ���һ����㣬����ͷ���
    int j = 0;
    while(p && j<i-1){
        p = p->next;
        ++j;
    }

    if(!p || j>i-1) return ERROR;//!p��ʾi��ֵ�����������ȣ�j>i-1��ʾi��ȡֵС��1

    *e = p->data;
    return OK;
}

Status ListInsert_link(LinkList L, int i, ElemType e){
    LinkList p = L;//������Ҫ�ҵ��ǵ�i��������һ�������ܽ��в������������p��ֵΪL��Ϊ��L->next

    //�ҵ���i-1�����
    int j = 0;
    while(p && j<i-1){
        p = p->next;
        ++j;
    }

    if(!p || j>i-1) return ERROR;//!p��ʾi��ֵ�����������ȣ�j>i-1��ʾi��ȡֵС��1

    //�������
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

    //ɾ������
    LinkList node = p->next;
    p->next = node->next;
    *e = node->data;
    free(node);
    return OK;
}

LinkList ListCreate_link(LinkList L, int n){
    //��������n��Ԫ�ص�ֵ��������ͷ���ĵ�������
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

LinkList ListMerge_link(LinkList A, LinkList B, LinkList C){//�ú���Ҳ��ı�A��B����Ľṹ
    LinkList pa = A->next, pb = B->next, pc = C = A;//pc��ʾC�����е�ǰ���һ�����
    while(pa && pb){
        if(pa->data <= pb->data){
            pc->next = pa;//��pa��ָ�����ӵ�pc��ָ���֮��
            pc = pa;//�൱��pc=pc->next;
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
    if(!p) printf("����Ϊ��\n");
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void ListSortPrint_link(LinkList L){
    LinkList p = L->sort;
    if(!p) printf("����Ϊ��\n");
    while(p){
        printf("%d ",p->data);
        p = p->sort;
    }
    printf("\n");
}

LinkList ListSort_link(LinkList L){
    L->sort = L->next;
    L->sort->sort = NULL;
    LinkList p = L->next->next;//���ֻ��һ��Ԫ�أ�p==NULL���򲻽���ѭ��������������
    LinkList s = L->next;//����������ʼ��ָ��ͷ��㣬s=L->sort,s->sort = NULL
    while(p){
        s = L;//������ÿ������Ԫ�����������õ�������ͷ��ʼ�Ƚϣ�sָ��Ҫ�Ƚ����ݵ�ֱ��ǰ�����������ܽ��в������
        while(s->sort && s->sort->data <= p->data){//����p��s�еĲ���λ�ã���s����ĵ�һ��Ԫ�ؿ�ʼ�Ƚ�
            s=s->sort;
        }

        //��s�����в���p���
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
        q->next = p;//���ӵ�β��
        q = q->next;
    }
    q->next = NULL;

}