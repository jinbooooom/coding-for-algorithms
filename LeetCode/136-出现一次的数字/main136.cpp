
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i < nums.size(); ++i) {
			result ^= nums[i];
		}
		return result;
	}
};

int main()
{
	Solution method;
	int arr[10] = {1, 2, 2, 4, 6, 1, 5, 4, 6, 0};
	vector<int> vec(arr, arr + 10);
	std::cout << method.singleNumber(vec);
}


