/* 
 * File:   queue_link.h
 * Author: jawinton
 *
 * Created on 2010年9月20日, 下午12:57
 */

#ifndef QUEUE_LINK_H
#define	QUEUE_LINK_H

#include "list_link.h"


#include "stack_sq.h"


#include "datastructure.h"


#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct QNode{
        ElemType data;
        struct QNode *next;
    }QNode,*QueuePoint;//包含头结点的队列

    typedef struct{
        QueuePoint front;
        QueuePoint rear;
    }LinkQueue;

    int isEmpty_queue(LinkQueue q);
    ElemType getFront_queue(LinkQueue q);
    Status initQueue(LinkQueue *q);
    Status enQueue(LinkQueue *q, ElemType e);
    ElemType deQueue(LinkQueue *q);
    Status print_queue(LinkQueue q);

    void reverse_queue(LinkQueue *q);
    int equal_queue(LinkQueue q1, LinkQueue q2);
    void clear_queue(LinkQueue *q);
#ifdef	__cplusplus
}
#endif

#endif	/* QUEUE_LINK_H */

