
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) {
			return size;
		}
		int p_this = 0;
		int p_next = 1;
		while (p_next < size) {
			if (nums[p_next] == nums[p_this])
				p_next++;
			else
				nums[++p_this] = nums[p_next++];
		}
		return p_this + 1;
	}
};




