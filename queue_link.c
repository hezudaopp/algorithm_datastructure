#include <stdlib.h>
#include <stdio.h>

#include "queue_link.h"
#include "stack_sq.h"

Status initQueue(LinkQueue *q){
    q->front = q->rear = (QNode *)malloc(sizeof(QNode));
    if(!q->front) exit(OVERFLOW);

    q->front->next = NULL;
    return OK;
}

int isEmpty_queue(LinkQueue q){
    if(q.front == q.rear) return TRUE;
    return FALSE;
}

Status enQueue(LinkQueue *q, ElemType e){
    QueuePoint qPoint = (QueuePoint)malloc(sizeof(QNode));
    if(!qPoint) exit(OVERFLOW);

    qPoint->data = e;
    qPoint->next = NULL;

    (*q).rear->next = qPoint;
    (*q).rear = qPoint;
    return OK;
}

ElemType deQueue(LinkQueue *q){
    if(q->front == q->rear) return ERROR;

    //����ͷ���Ķ��г�ջ����
    QNode *node = q->front->next;
    ElemType ret = node->data;
    
    q->front->next = node->next;
    /*
     * �޸Ķ���ͷԪ��ʱ�����޸�ͷ����ָ�룬
     * ���ǵ��������һ��Ԫ�ر�ɾ���󣬶�βָ��Ҳ�Ͷ�ʧ�ˣ���ʱ��βָ����Ҫ����ָ��ͷ���
     */
    if(node == q->rear) q->rear = q->front;
    free(node);

    return ret;
}

ElemType getFront_queue(LinkQueue q){
    if(!q.front || q.front == q.rear)
        return NULL;
    return q.front->data;
}

Status print_queue(LinkQueue q){
    if(q.front == q.rear) printf("This queue is empty.");
    QueuePoint p = q.front->next;
    while(p){
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n");
}

void reverse_queue(LinkQueue *q){
    SqStack s;
    InitStack(&s);
    while(!isEmpty_queue(*q)) Push(&s,deQueue(q));
    while(!isEmpty_stack(s)) enQueue(q,Pop(&s));
}

int equal_queue(LinkQueue q1, LinkQueue q2){
    while(!isEmpty_queue(q1) &&!isEmpty_queue(q2)){
        ElemType data1 = deQueue(&q1), data2 = deQueue(&q2);
        if(data1!=data2) return FALSE;
    }
    if(isEmpty_queue(q1) && !isEmpty_queue(q2)) return FALSE;
    if(isEmpty_queue(q2) && !isEmpty_queue(q1)) return FALSE;
    return TRUE;
}

void clear_queue(LinkQueue *q){
    while(!isEmpty_queue(*q)) deQueue(q);
}

