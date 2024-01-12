#include <iostream>

class node  //节点定义
{
public:
    int data;
    node* next;
};

class list   //链表定义
{
    public:
    node* head;
    list(){this->head=new node;}//初始化
    
    bool empty()//判断空链表
    {
        if(head->next) return false;
        else return true;
    }
    
    bool push_back(int x)//尾插
    {
        node* cur=head;
        while(cur->next) cur=cur->next;
        node* new_node = new node;
        new_node->next=NULL;
        new_node->data=x;
        cur->next=new_node;
        return true;
    }

    bool push_head(int x)//头插
    {
        node* cur=head;
        node* new_node = new node;
        new_node->next=cur->next;
        new_node->data=x;
        cur->next=new_node;
        return true;
    }

    bool push(node* pos,int x) //指定节点后插入节点
    {
        node* new_node=new node;
        new_node->next=pos->next;
        pos->next=new_node;
        new_node->data=x;
    } 

    int size()//求表长
    {
        node* cur=head;
        int len=0;
        while(cur->next){cur=cur->next;len++;}
        return len;
    }

    bool delete_node(node* pos)//删除指定节点
    {
        node* cur=head;
        while(cur->next!=pos)
        {
            cur=cur->next;
        }
        cur->next=pos->next;
        free(pos);
        return true;
    }
};