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

// vector<int> merge(vector<int> &v1, int v1Start, int v1End, int v2Start, int v2End, vector<int> &v2)
// {
//     int i = v1Start, j = v2Start;
//     vector<int> v;

//     while (i < v1End && j < v2End)
//     {
//         if (v1[i] >= v2[j])
//         {
//             v.push_back(v2[j]);
//             j++;
//         }
//         else
//         {
//             v.push_back(v1[i]);
//             i++;
//         }
//     }
//     while (i < v1End)
//     {
//         v.push_back(v1[i]);
//         i++;
//     }
//     while (j < v2End)
//     {
//         v.push_back(v2[j]);
//         j++;
//     }
//     return v;
// }

// vector<int> mergeSort(vector<int> &nums, int start, int end)
// {
//     if (start == end)
//     {
//         return {nums[start]};
//     }
//     if (start < end)
//     {
//         int mid = (start + end) / 2;
//         vector<int> v1 = mergeSort(nums, start, mid);
//         vector<int> v2 = mergeSort(nums, mid + 1, end);
//         vector<int> ans = merge(v1, start, mid, mid + 1, end, v2);
//         return ans;
//     }
//     return {};
// }

int maxDistance(vector<pair<int, int>> &nums)
{
    sort(nums.begin(), nums.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
        if(a.second == b.second)
            return a.first < b.first;
        else
        return a.second< b.second; });

    for (auto i : nums)
    {
        cout << i.first << " " << i.second << endl;
    }
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[0].second < nums[i].first)
        {
            if (ans < nums[i].first - nums[0].second)
                ans = nums[i].first - nums[0].second;
        }
    }
    return ans;
}

int highest(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n1 = nums[0] * nums[1] * nums[nums.size() - 1];
    int n2 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
    return max(n2, n1);
}

void maxNumber(vector<int> &nums, int b)
{
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < nums.size(); i++)
    {
        q.push({nums[i], i});
    }

    int index = 0;
    while (index >= 0 && b > 0)
    {
        if (nums[index] < q.top().first)
        {
            swap(nums[index], nums[q.top().second]);
            q.pop();
            b--;
        }
        else if (nums[index] == q.top().first)
        {
            q.pop();
        }
        index++;
    }

    for (auto i : nums)
        cout << i << " ";
}

int minRooms(vector<pair<int, int>> &meetings)
{
    int maxNo = 0;
    map<int, int> mem;

    for (auto i : meetings)
    {
        mem[i.first]++;
        mem[i.second]--;
    }

    int count = 0;
    // int maxNo = 0;

    for (auto i : mem)
    {
        if (i.second >= 1)
            count++;
        else if (i.second <= -1)
            count--;

        if (count > maxNo)
            maxNo = count;
    }
    // vector<int> time(maxNo, 0);
    // // maxNo = 0;
    // int size = maxNo;
    // maxNo = 0;
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = meetings[i].first; j <= meetings[i].second; j++)
    //     {
    //         time[j]++;
    //         if (maxNo < time[j])
    //             maxNo = time[j];
    //     }
    // }
    return maxNo;
}

int totalCandies(vector<int> &kids)
{
    map<int, int> mem;
    for (int i : kids)
    {
        mem[i]++;
    }
    int noOfCandies = 1;
    int totalCandies = 0;

    for (auto i : mem)
    {
        totalCandies += noOfCandies * i.second;
        noOfCandies++;
    }

    return totalCandies;
}

int minMoves(vector<bool> &seats)
{
    int windowSize = 0;
    for (bool i : seats)
    {
        if (i)
            windowSize++;
    }
    int ones = 0;

    for (int i = 0; i < windowSize; i++)
    {
        if (seats[i])
            ones++;
    }
    int maxOnes = ones;

    for (int i = windowSize; i < seats.size(); i++)
    {
        ones -= seats[i - windowSize];
        ones += seats[i];
        if (ones > maxOnes)
            maxOnes = ones;
    }
    return windowSize - maxOnes;
}

int main()
{
    // vector<int> nums = {5, 2, 1, 8, 1};
    vector<bool> nums = {1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1};
    cout << minMoves(nums);
    // vector<int> n = mergeSort(nums, 0, n.size() - 1);
    // for (int i : n)
    //     cout << i << " ";

    // vector<pair<int, int>> nums = {{1, 4}, {8, 9}, {4, 6}, {2, 3}};
    // cout << minRooms(nums);
    // cout << maxDistance(nums);
    // maxNumber(nums, 2);

    return 0;
}