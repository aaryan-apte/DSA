#include <iostream>
#include <vector>
using namespace std;

void maxSubarray(vector<int> &nums, int k)
{
    if (k > nums.size())
    {
        cout << "Invalid condition\n";
        return;
    }
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    int max = sum;
    for (int i = k; i < nums.size(); i++)
    {
        sum += nums[i];
        sum -= nums[i - k];
        if (sum > max)
            max = sum;
    }
    cout << "The maximum sum is: " << max;
}

int main()
{
    vector<int> nums = {8, 67, 65, 9, 8, 7};
    maxSubarray(nums, 3);
    return 0;
}