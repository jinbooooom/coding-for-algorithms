class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        if (target < nums[0])
            return 0;
        if (target > nums[nums.size() - 1])
            return nums.size();
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right)  // 不可缺少等于号
        {
            mid = (left + right) / 2;
            if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
            else
                return mid;
        }
        if (target <= nums[mid])
            return mid;
        else
            return mid + 1;
    }
};