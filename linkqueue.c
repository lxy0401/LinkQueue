#include "linkqueue.h"
#include<stdlib.h>
#include<malloc.h>

//队列初始化
void LinkQueueInit(LinkQueue* q)
{
    if(q == NULL)
    {
        //非法操作
        return ;
    }
    q->head = NULL;
    q->tail = NULL;
}

LinkNode* CreateLinkNode(LinkType value)
{
    LinkNode* new_node=(LinkNode*)malloc(sizeof(LinkNode));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}

//入队(尾插)
void LinkQueueFush(LinkQueue* q,LinkType value)
{
    if(q == NULL)
    {
        //非法操作
        return;
    }
    LinkNode* new_node=CreateLinkNode(value);
    if(q->head == NULL)
    {
        q->head=q->tail=new_node;
        //空队列
        return ;
    } 
    //LinkNode* new_node =CreateLinkNode(value);
    q->tail->next=new_node;
    q->tail=q->tail->next;
}


//出队
void LinkQueuePop(LinkQueue* q)
{
    if(q == NULL)
    {
        //非法操作
        return;
    }
    if(q->head == NULL)
    {
        //空队列
        return;
    }
    LinkNode* to_delete=q->head;
    if(q->head == q->tail)
    {
        free(to_delete);
        q->head=q->tail=NULL;
        return ;
    }
    q->head=to_delete->next;
    free(to_delete);
}
//取队首元素
int LinkQueueFront(LinkQueue* q,LinkType* value)
{
    if(q == NULL || value == NULL)
    {
        //非法操作
        return 0;
    }
    if(q->head == NULL)
    {
        //空队列
        return 0;
    }
    *value=q->head->data;
    return 1;
}

/*****
 *
 *
 * 以下为测试代码
 *
 *
 * ***/

 
#include <stdio.h>
#define TEST_HEADER printf("\n========%s=========\n",__FUNCTION__)

void TestLinkQueue()
{
    TEST_HEADER;
    LinkQueue queue;
    LinkQueueInit(&queue);
    LinkQueueFush(&queue,'a');
    LinkQueueFush(&queue,'b');
    LinkQueueFush(&queue,'c');
    LinkQueueFush(&queue,'d');

    LinkType value;
    int ret=0;
    ret =LinkQueueFront(&queue,&value);
    printf("ret expected 1,actual %d\n",ret);
    printf("value expected a,actual %c\n",value);
    LinkQueuePop(&queue);

    ret =LinkQueueFront(&queue,&value);
    printf("ret expected 1,actual %d\n",ret);
    printf("value expected b,actual %c\n",value);
    LinkQueuePop(&queue);
    
    ret =LinkQueueFront(&queue,&value);
    printf("ret expected 1,actual %d\n",ret);
    printf("value expected c,actual %c\n",value);
    LinkQueuePop(&queue);
    
    ret =LinkQueueFront(&queue,&value);
    printf("ret expected 1,actual %d\n",ret);
    printf("value expected d,actual %c\n",value);
    LinkQueuePop(&queue);

    ret =LinkQueueFront(&queue,&value);
    printf("ret expected 0,actual %d\n",ret);
    //printf("value expected a,actual %c",value);
    LinkQueuePop(&queue);
}
int main()
{
    TestLinkQueue();
    return 0;
}
