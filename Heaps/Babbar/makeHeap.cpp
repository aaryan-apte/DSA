#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;

    void insert(int element)
    {
        if (size < 100)
        {
            arr[size] = element;
            size++;
        }
        int cur = size - 1;
        int parent;

        if (cur % 2 == 0)
            parent = (cur - 2) / 2;
        else
            parent = (cur - 1) / 2;

        while (parent >= 0 && arr[parent] < arr[cur])
        {
            swap(arr[parent], arr[cur]);
            cur = parent;

            if (cur % 2 == 0)
                parent = (cur - 2) / 2;
            else
                parent = (cur - 1) / 2;
        }
        cout << element << " inserted at " << cur << endl;
    }

    int getMax()
    {
        if (size > 0)
            return arr[0];
        return -1;
    }

    int extractMax()
    {
        if (size == 0)
            return -1;

        int ans = arr[0];
        arr[0] = arr[size - 1];
        size--;

        int i = 0;

        while (i < size)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && arr[left] > arr[i] && arr[left] > arr[right])
            {
                swap(arr[left], arr[i]);
                i = left;
            }
            else if (right < size && arr[right] > arr[i] && arr[right] > arr[left])
            {
                swap(arr[right], arr[i]);
                i = right;
            }
            else
                break;
        }
        return ans;
    }
};

int main()
{
    Heap maxi;
    maxi.insert(6);
    maxi.insert(5);
    maxi.insert(8);
    maxi.insert(2);
    maxi.insert(1);
    cout << maxi.getMax() << endl;

    for (int i = 0; i < maxi.size; i++)
        cout << maxi.arr[i] << " ";

    cout << endl
         << "Size of heap is: " << maxi.size << endl;

    cout << maxi.extractMax() << endl;
    cout << maxi.extractMax() << endl;

    return 0;
}