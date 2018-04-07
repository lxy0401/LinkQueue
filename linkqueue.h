#pragma once
typedef char LinkType;
typedef struct LinkNode
{
    LinkType data;
    struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue
{
    LinkNode* head;
    LinkNode* tail;
}LinkQueue;

//队列初始化
void LinkQueueInit(LinkQueue* q);

//入队
void LinkQueueFush(LinkQueue* q,LinkType value);

//出队
void LinkQueuePop(LinkQueue* q);

//取队首元素
int LinkQueueFront(LinkQueue* q,LinkType* ret);
