#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &a)
{
    if (a.size() == 1 || a.size() == 2)
    {
        return true;
    }

    int count = 0, i = 0;
    for (; i < a.size() - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            count++;
        }
    }
    if (a[a.size() - 1] > a[0])
    {
        count++;
    }
    if (count > 1)
    {
        return false;
    }
    return true;

    // if(a.size() == 1 || a.size() == 2)
    // {
    //     return true;
    // }
    // int i = 0,j = 1, count1 = 0;
    // while(j < a.size() && a[i] <= a[j]){
    //     count1++;
    //     i++;
    //     j++;
    // }
    // i++;
    // j++;
    // int count2 = 0;
    // while(j < a.size() && a[i] <= a[j] && a[j] <= a[0]){
    //     count2++;
    //     j++;
    //     i++;
    // }
    // if((count1 == a.size() - 1) || (count1 + count2 == a.size() - 2 && a.size() != 3)){
    //     return true;
    // }
    // return false;

    // int count1 = 0, i = 1;
    // while(nums[i] >= nums[0] && i < nums.size())
    // {
    //     count1++;
    //     i++;
    // }
    // int j = i;
    // int count2 = 0;
    // i++;
    // while(nums[j] <= nums[i] && nums[i] <= nums[0] && i < nums.size())
    // {
    //     count2++;
    //     i++;
    // }

    // if(count1 + count2 == nums.size() - 1)
    // {
    //     return true;
    // }
    // return false;
}
