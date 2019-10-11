class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		vector<int>::iterator it = digits.end() - 1;
		vector<int>::iterator start = digits.begin();
		for (; it != start - 1; --it) {
			*it += carry;
			carry = 0;
			if (*it >= 10) {
				*it %= 10;
				carry = 1;
				if (it == start)
					digits.insert(start, carry);
			}
		}
		return digits;
	}
};

