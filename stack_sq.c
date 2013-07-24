#include <stdlib.h>
#include <stdio.h>

#include "stack_sq.h"

Status InitStack(SqStack *s){
    s->base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(!s->base) exit(OVERFLOW);

    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    
    return OK;
}

ElemType GetTop(SqStack s){
    if(s.top ==s.base) return ERROR;
    return *(s.top-1);
}

ElemType Pop(SqStack* s){
    if(s->top ==s->base) return ERROR;
    return *(--s->top);
}

Status Push(SqStack* s,ElemType e){
    if(s->top - s->base >= s->stacksize){
        s->base = (ElemType *)realloc(s->base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(ElemType));
        if(!s->base) exit(OVERFLOW);
        s->top = s->base + s->stacksize;
        s->stacksize += STACKINCREMENT;
    }

    *s->top++ = e;
    return OK;
}

int isEmpty_stack(SqStack s){
    if(s.top ==  s.base) return TRUE;
    return FALSE;
}

void conversion(int decimal, int M){
    SqStack s;
    InitStack(&s);
    int N = decimal;
    while(N){
        Push(&s,N%M);
        N = N/M;
    }
    printf("%d->",decimal);
    while(s.top!=s.base){
        printf("%d",Pop(&s));
    }
    printf("\n");
}

void lineEdit(){
    SqStack s;
    InitStack(&s);

    char ch = getchar();
    while(ch!=EOF && ch!='\n'){//单引号表示单个字符
        switch (ch){
            case '#':Pop(&s);
            case '@':s.top = s.base;
            default:Push(&s,ch);
        }
        ch = getchar();
    }

    while(s.top!=s.base){
        printf("%c",Pop(&s));
    }
}

int bracketsCheck(char* f){
    SqStack s;
    InitStack(&s);
    char *p;
    while(p != "\0"){
        switch (*p){
            case '{':case '(':case'[':
                Push(&s,*f);
                break;
            case '}':
                if(Pop(&s) !='{') break;
            case ')':
                if(Pop(&s) != '(') break;
            case ']':
                if(Pop(&s) != '[') break;
        }
        p++;
    }
    if(isEmpty_stack(s)) return TRUE;
    else return FALSE;
}