#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> index;
    int i, j;

    for (i = 0; i < nums.size(); i++)
    {
        for (j = 0; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j] == target) && (i != j))
            {
                index.push_back(i);
                index.push_back(j);
                return index;
            }
        }
    }

    return index;
}
