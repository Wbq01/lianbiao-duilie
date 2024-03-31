#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    unsigned char id;
    unsigned char name[10];
    struct student* pnext;
    
}student_list;

student_list* listInit()
{
    return NULL;
}

//从头部开始删除节点
void listRemHead(student_list** head) 
{
    student_list* cur = *head; 
    if(cur == NULL)
    {
        printf("空链表");
    }
    else
    {
        *head = cur->pnext;
        free(cur);
    }

}

//尾部删除节点
void listRemTail(student_list** head)
{
    student_list* cur = *head;
    student_list* last = *head;
    if(cur == NULL)
    {
        printf("空链表\r\n");
    }
    // else if (cur->pnext == NULL) //只有一个节点
    // {
    //     free(*head);
    // }
    else
    {
        while(cur->pnext != NULL)
        {
            last = cur;
            cur = cur->pnext;
        }
        last->pnext = NULL;
        free(cur);     
    }
}

// 从尾部开始增加节点
void listAddTail(student_list** head, unsigned char name[10], unsigned char num)
{
    student_list* new_node = (student_list*)malloc(sizeof(student_list));
    new_node->id = num;
    strcpy(new_node->name, name);
    new_node->pnext = NULL;
    if(*head == NULL) //第一个节点，头结点初始化为NULL
    {
        *head = new_node;
    }
    else
    {
        student_list* cur = *head;
        while(cur->pnext != NULL) //寻找最后一个节点
        {
            cur = cur->pnext;
        }
        cur->pnext = new_node;
    }
    
}
// 从头部开始增加节点
void listAddHead(student_list** head, unsigned char name[10], unsigned char num)
{
    student_list* new_node = (student_list*)malloc(sizeof(student_list));
    new_node->id = num;
    strcpy(new_node->name, name);
    new_node->pnext = *head;
    *head = new_node;
}

//查找指定节点
student_list* lookNode(student_list* head, unsigned char* name)
{
    student_list* cur = head;
    while(strcmp(cur->name, name) != 0)
    {
        cur = cur->pnext;
    }
    return cur;
}
//在指定位置插入节点
void listAddPos(student_list* head, )
{



}
void printList(student_list* head)
{
    student_list* cur = head;
    while (cur != NULL)
    {
        printf("student:%s\r\n", cur->name);
        printf("student:%d\r\n", cur->id);
        printf("---------------------------------\r\n");
        cur = cur->pnext;
    }
}

void clearList(student_list* head)
{
    student_list* cur = head;
    student_list* next = NULL;
    
    while (cur != NULL) 
    {
        next = cur->pnext;
        free(cur);
        cur = next;
    }
}

void main(void)
{
    student_list* head = listInit();
    student_list* temp;
    // listAddTail(&head, "wbq", 1);
    // listAddTail(&head, "ysm", 2);
    // listAddTail(&head, "xxx", 3);
    listAddTail(&head, "wbq", 1);
    listAddTail(&head, "ysm", 2);
    listAddTail(&head, "xxx", 3);
    
    printList(head);
    listRemHead(&head);
    printList(head);
    // temp = lookNode(head, "xxx");
    // printf("id:%d\r\n", temp->id);
    // clearList(head);
    // printList(head);

}