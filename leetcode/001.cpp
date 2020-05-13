#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        m[target - nums[0]] = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
                return {m[nums[i]], i};
            m[target - nums[i]] = i;
        }

        return {0, 0};
    }
};

int main()
{
    vector<int> inp = {2, 7, 11, 15};
    int target = 9;

    Solution a;
    vector<int> ans = a.twoSum(inp, target);
    cout << ans[0] << ', ' << ans[1] << endl;
}