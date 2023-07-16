#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class stack
{
    int *st;
    int top;
    int size;
    map<int, int> mem;

public:
    stack(int s)
    {
        st = new int[s];
        top = -1;
        size = s;
    }
    void pop()
    {
        if (top != -1)
        {
            top--;
        }
    }

    int topp()
    {
        if (top != -1)
            return st[top];

        cout << "Stack underflow!\n";
        return INT_MIN;
    }

    int getMin()
    {
        if (top != -1)
            return mem[top];
        cout << "Stack underflow!\n";

        return INT_MIN;
    }
    void push(int num)
    {
        if (top < size - 1)
        {
            st[++top] = num;

            if (top == 0)
            {
                mem[0] = num;
            }
            else
            {
                int mini = min(num, mem[top - 1]);
                mem[top] = mini;
            }
        }
        else
            cout << "Stack overflow!\n";
    }

    void printMap()
    {
        for (auto i : mem)
        {
            cout << i.first << " -> " << i.second << endl;
        }
        cout << endl;
    }
};

int main()
{
    stack st(10);
    st.push(10);
    st.push(2);
    st.push(7);
    st.push(1);
    st.push(0);
    st.printMap();

    return 0;
}