class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        int mid = nums.size() / 2;
        // 将 nums 分成小的第一部分 nums[mid:] 和较大的第二部分 nums[:mid]
        vector<int> part1(nums.begin() + mid, nums.end());
        vector<int> part2(nums.begin(), nums.begin() + mid);
        int p1 = 0, p2 = 0;
        int i = 0;
        while (i < nums.size())
        {
            // 如果 nums 的长度为奇数，第一部分必定多于第二部分，
            // 如 [3, 2, 1]，part1: [2, 1]，part2: [3]
			if (p1 < part1.size())
				nums[i++] = part1[p1++];
			if (p2 < part2.size())
			    nums[i++] = part2[p2++];
        }
    }

    // sort 里的 comp 不能是类的成员函数，故加 static
    static bool comp(int x, int y)  // 按降序排序，大的在前面。
    {
        return x > y;
    }
};