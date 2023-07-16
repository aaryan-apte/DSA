#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class CircularQueue
{

    int *q;
    int rear;
    int front;
    int size;

public:
    // Initialize your data structure.

    CircularQueue(int n)
    {
        q = new int[n];
        rear = 0;
        front = -1;
        size = n;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.

    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
            return false; // Queue is full

        q[rear] = value;
        rear = (rear + 1) % size;

        if (front == -1)
            front++;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.

    int dequeue()
    {
        if (front != -1 && (front != rear))
        {
            int value = q[front];
            front = (front + 1) % (size);
            if (front == rear)
            {
                front = -1;
                rear = 0;
            }
            return value;
        }

        return -1;
    }
};

int main()
{
    CircularQueue q(3);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(8);
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.dequeue();

    return 0;
}