#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printFirstNegNo(vector<int> &nums, int k)
{
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        if (nums[i] < 0)
        {
            q.push(nums[i]);
        }
    }
    cout << q.front() << endl;

    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            q.push(nums[i]);
        if (q.empty())
        {
            cout << 0 << endl;
        }
        else
        {
            if (nums[i - k] == q.front())
            {
                q.pop();
                if (q.empty())
                    cout << 0 << endl;
                else
                    cout << q.front() << endl;
            }
            else
            {
                cout << q.front() << endl;
            }
        }
    }
}

int main()
{
    vector<int> nums = {4, -6, -9, 5, -1, 2, -87, 5, 2, 8};
    printFirstNegNo(nums, 3);

    return 0;
}