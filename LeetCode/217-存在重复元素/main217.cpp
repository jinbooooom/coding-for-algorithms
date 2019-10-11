class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		// 使用集合，vector 的长度与 set 不相等，说明有重复
		set<int> sn(nums.begin(), nums.end());
		return !(sn.size() == nums.size());
	}

	bool containsDuplicate2(vector<int>& nums) {
		// 使用 hash map
		map<int, int> hash_nums;
		for (int i = 0; i < nums.size(); ++i) {
			if (hash_nums.count(nums[i]))
				return true;
			hash_nums[nums[i]]++;
		}
		return false;
	}

	bool containsDuplicate3(vector<int>& nums) {
		//使用排序，之后判断相邻的元素是否相等
		if (nums.size() <= 1)
			return false;
		sort(nums.begin(), nums.end());
		vector<int>::iterator start = nums.begin();
		vector<int>::iterator finish = nums.end();
		for (; start != finish - 1; ++start) {
			if ((*start) == *(start + 1))
				return true;
		}
		return false;
	}
};