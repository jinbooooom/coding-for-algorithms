class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int i = 0;
        while (i <= right)
        {
            if (nums[i] == 2)
            {
                swap(nums[i], nums[right]);
                right--;
            }
            else if (nums[i] == 0)
            {
                swap(nums[i], nums[left]);
                left++;
                i++;
            }
            else
                i++;
        }
    }

    void swap(int &x, int &y)
    {
        int t = x;
        x = y;
        y = t;
    }

    // 如果使用 swap2，对测试用例 [2]，不可行。
    // 因为 nums 只含有一个元素，此时 num[i] 与 num[right] 的地址相同，
    // 即 x, y 地址相同，此时改变了 x 也同时改变了 y，只能像上面的函数 swap 增加一个临时变量 t 以实现交换的功能。
    void swap2(int &x, int &y)
    {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
};