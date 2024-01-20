#include <iostream>
using namespace std;
//一个三元组
class triple
{
    public:
    int i,j,data;
};

//三元表
class triple_list
{
    public:
    triple* l;
    int n,m,t;
};

//转置算法
triple_list* transport_matrix(triple_list& a)
{
    if(!a.t) return NULL;//a为空
    
    //初始化
    triple_list* b = new triple_list;
    b->n=a.m;b->m=a.n;b->t=a.t;
    b->l = new triple[a.t];
    int* num = new int[a.m+1];
    int* cpot = new int[a.m+1];
    memset(num,0,sizeof(num));
    memset(cpot,0,sizeof(cpot));
    
    //完成 num 和 cpot 数组
    for(int i=0;i<a.t;i++)
        num[a.l[i].j]++;
    cpot[1]=1;
    for(int i=2;i<=a.m;i++)
    {
        cpot[i]=cpot[i-1]+num[i-1];
    }

    //转置
    int temp;
    int pos;
    for(int i=0;i<a.t;i++)
    {
        pos = cpot[a.l[i].j];
        cpot[a.l[i].j]++;
        b->l[pos].i=a.l[i].j;
        b->l[pos].j=a.l[i].i;
        b->l[pos].data=a.l[i].data;
    }
    return b;
}