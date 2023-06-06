#include <iostream>
#include <vector>
using namespace std;

int maxLength(vector<int> &nums, int k)
{
    int i = 0, j = 0, sum = nums[0];
    int maxSize = 0;
    while (j < nums.size() && i < nums.size())
    {
        while (j < nums.size() && i < nums.size() && sum < k)
        {
            j++;
            sum += nums[j];
            cout << "Sum in 1st if is: " << sum << endl;
            cout << "i :" << i << " j: " << j << endl;
        }
        if (j < nums.size() && i < nums.size() && sum == k)
        {
            if (maxSize < j - i + 1)
                maxSize = j - i + 1;
            cout << "Sum: " << sum << endl;
            cout << "i :" << i << " j: " << j << endl;
            sum += nums[j];
            j++;
            cout << "Sum: " << sum << endl;
            cout << "i :" << i << " j: " << j << endl;
        }
        while (j < nums.size() && i < nums.size() && sum > k)
        {
            sum -= nums[i];
            cout << "Sum in 3rd if is: " << sum << endl;
            i++;
            cout << "i :" << i << " j: " << j << endl;
        }
    }
    return maxSize;
}

int main()
{
    vector<int> nums = {3, 2, 1, 1, 1, 1, 1};
    cout << maxLength(nums, 5);

    return 0;
}