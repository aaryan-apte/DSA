#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{

    int i = 0;
    int j = 1;

    while (j < nums.size() && i < nums.size())
    {
        while (j < nums.size() && i < nums.size() && nums[i] != 0)
        {
            i++;
            j++;
        }
        while (j < nums.size() && nums[j] == 0)
        {
            j++;
        }
        while (j < nums.size() && i < nums.size() && nums[i] == 0 && nums[j] != 0)
        {
            if (i < nums.size() && j < nums.size())
            {
                swap(nums[i], nums[j]);
                cout << "Swapping " << nums[i] << " and " << nums[j] << endl;
                if (j < nums.size() - 1 && i < nums.size() - 1)
                {
                    i++;
                    j++;
                }
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    vector<int> nums = {0, 9, 2, 5, 0};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
