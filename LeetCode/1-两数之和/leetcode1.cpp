class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        map<int, int> index;
        vector<int> id(2);
        for (int i = 0; i < size; ++i)
        {
            index[nums[i]] = i;
        }
        for (int i = 0; i < size; ++i)
        {
            if (index.count(target - nums[i]) && index[target - nums[i]] != i)
            {
                id[0] = i;
                id[1] = index[target - nums[i]];
                return id;
            }
        }
        return id;
    }
};