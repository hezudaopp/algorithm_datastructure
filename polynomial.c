#include <stdlib.h>

#include "polynomial.h"

Polynomial createPoly(){
    Polynomial p = (Polynomial)malloc(sizeof(Term));
    if(!p) return ERROR;
    Polynomial h = p, pre;
    h->link = NULL;
    h->exp = -1;//��Ҫ����
    float coef;
    int exp,i;
    printf("Input the 1 item\n");
    for(scanf("%f %d",&coef,&exp),i=1;exp;scanf("%f %d",&coef,&exp)){
        
        Polynomial term = (Polynomial)malloc(sizeof(Term));
        if(!term) return ERROR;
        term->coef = coef;
        term->exp = exp;

        p = h->link,pre = h;//��ͷ��ʼ����
        while(p!=NULL && p->exp > exp){//���� ����λ��,p->exp<exp�Ļ��ǰ���������
            pre = p;
            p = p->link;
        }
        if(p!=NULL && p->exp == exp){//�ж��Ƿ���ָ�����
            printf("The input exp is duplicated, input again:\n");
            continue;//����һ�����ָ�����
        }else{//��ǰ���p��ָ��ֵС���������ָ��ֵ,��pre��p֮�����ý��
            term->link = pre->link;//pre->link����p
            pre->link = term;
        }
        
        printf("Input the %d item\n",++i);
    }
    return h;
}

void insertPoly(Polynomial p){
    float coef;
    int exp;
    printf("Please input the value of coef and exp of the term to be inserted.\n");
    scanf("%f %d",&coef,&exp);
    if(coef==0 || exp<=0) return ERROR;

    Polynomial pre = p, q = p->link;
    while(q && q->exp > exp){
        pre = q;
        q = q->link;
    }
    if(q && q->exp == exp){
        q->coef += coef;
        if(q->coef == 0){
            pre->link = q->link;
            free(q);
        }
    }else{
        Polynomial temp = (Polynomial)malloc(sizeof(Term));
        temp->coef = coef;
        temp->exp = exp;
        temp->link = q;
        pre->link = temp;
    }
}

void insertPoly_with_value(Polynomial p, float coef, int exp){
    Polynomial pre = p, q = p->link;
    while(q && q->exp > exp){
        pre = q;
        q = q->link;
    }
    if(q && q->exp == exp){
        q->coef += coef;
        if(q->coef == 0){
            pre->link = q->link;
            free(q);
        }
    }else{
        Polynomial temp = (Polynomial)malloc(sizeof(Term));
        temp->coef = coef;
        temp->exp = exp;
        temp->link = q;
        pre->link = temp;
    }
}

 Polynomial multiplePoly(Polynomial a,Polynomial b){
     Polynomial c = (Polynomial)malloc(sizeof(Term));
     c->exp = -1;
     c->link = NULL;

     a = a->link;
     b = b->link;
     Polynomial first = b;
     while(a){
         b =first;
         while(b){
             float coef = a->coef * b->coef;
             int exp = a->exp + b->exp;
             insertPoly_with_value(c,coef,exp);
             b = b->link;
         }
         a = a->link;
     }
     return c;
 }

void printPoly(Polynomial p){
    if(!p->link){
        printf("This Polynomial is NULL.\n");
        return;
    }
    for(p = p->link;p && p->link ;p=p->link){
        printf("%.2fX%d+",p->coef,p->exp);
    }
    printf("%.2fX%d\n",p->coef,p->exp);
}