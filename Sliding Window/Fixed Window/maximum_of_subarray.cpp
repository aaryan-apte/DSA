#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void getMax(vector<int> &nums, int k)
{
    deque<int> q;

    for (int i = 0; i < k; i++)
    {
        if (q.empty())
        {
            q.push_back(nums[i]);
            continue;
        }
        while (q.back() < nums[i])
        {
            q.pop_back();
        }
        q.push_back(nums[i]);
    }
    cout << "Queue is: \n";
    for (auto i : q)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Max 0: " << q.front() << endl;

    for (int i = k; i < nums.size(); i++)
    {
        if (q.empty())
        {
            q.push_back(nums[i]);
        }
        else
        {
            cout << q.front() << " popped!\n";
            if (q.front() == nums[i - k])
                q.pop_front();
            while (!q.empty() && q.back() < nums[i])
            {
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        cout << "Max " << i - k + 1 << ": " << q.front() << endl;
    }
}

int main()
{
    vector<int> nums = {3, 2, 1, 0, 5};
    getMax(nums, 3);

    return 0;
}