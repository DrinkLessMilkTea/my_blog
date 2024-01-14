class queue
{
public:
    int* q;
    int size;
    int front;
    int rear;
    bool init_queue(int num)//初始化
    {
        q = new int[num];
        size = num;
        if(q)
        {
            front = rear = 0;
            return true;
        }
        return false;
    }

    bool empty()//判空
    {
        if(front==rear) return true;
        else return false;
    }

    bool push(int x)//入队
    {
        if((rear+1)%size==front) return false;
        q[rear]=x;
        rear=(rear+1)%size;
        return true;
    }

    bool pop()//出队
    {
        if(empty()) return false;
        front = (front+1)%size;
        return true;
    }

    int top()//队头元素
    {
        if(empty()) return -1;
        else return q[front];
    }
};