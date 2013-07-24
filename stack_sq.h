/* 
 * File:   stack_sq.h
 * Author: jawinton
 *
 * Created on 2010年9月20日, 上午10:38
 */

#ifndef STACK_SQ_H
#define	STACK_SQ_H

#include "datastructure.h"


#ifdef	__cplusplus
extern "C" {
#endif
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

    typedef struct SqStack{
        ElemType *base;
        ElemType *top;
        int stacksize;
    }SqStack;

    Status InitStack(SqStack *s);
    ElemType GetTop(SqStack s);
    ElemType Pop(SqStack *s);
    Status Push(SqStack *s,ElemType e);
    int isEmpty_stack(SqStack s);

    void conversion(int decimal,int M);//数制转化函数
    void lineEdit();
    int bracketsCheck(char* f);
#ifdef	__cplusplus
}
#endif

#endif	/* STACK_SQ_H */

