class double_stack
{
public:
    int* base;
    int size;
    int* top1;
    int* top2;

    bool init_stack(int num)//初始化
    {
        base=new int[num];
        if(base) 
        {
            top1=base;
            top2=base+num-1;
            return true;
        }
        else return false;
    }

    bool empty()//栈空
    {
        if(top1==base&&top2==base+size-1) return true;
        else return false;
    }

    bool push_one(int x)//入栈
    {
        if(top1>top2) return false;
        *top1++=x;
        return true;
    }

    bool push_two(int x)
    {
        if(top1>top2) return false;
        *top2--=x;
        return true;
    }

    bool pop_one()//出栈
    {
        if(top1==base) return false;
        top1--;
    }

    bool pop_two()
    {
        if(top2==base+size-1) return false;
        top2++;
    }
};