#include<iostream>
//检查该长度是否可行
bool check(char* t,int pos,int len)
{
    int s=0,e=pos-len;
    while(t[s]==t[e]&&e<pos){s++;e++;}
    if(e==pos) return true;
    else return false;
}
//构建 next 数组
int* build_next(char* t,int lent)
{
    if(!t||!lent) return NULL;//子串为空

    int* next=new int[lent];
    int s,e,len;

    for(int i=0;i<lent;i++)
    {
        if(i==0) {next[i]=-1;continue;}
        for(len=1;len<=i;len++)
        {
            if(!check(t,i,len)) {len--;break;}
        }
        next[i]=len;
        while(t[next[i]]==t[i]) next[i]=next[next[i]];
    }
    return next;
}
//KMP
int KMP(char* s,char* t,int lens,int lent)
{
    if(!s||!t||!lens||!lent) return -1;//主串或子串为空
    int i=0,j=0;
    int* next=build_next(t,lent);
    while(i<lens && j<lent)
    {
        if(s[i]==t[j]||j==-1){i++;j++;continue;}//主串移动
        j=next[j];
    }
    if(j==lent) return i - lent;//成功匹配
    else return -1;//失配
}