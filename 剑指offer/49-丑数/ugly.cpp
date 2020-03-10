/*
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
	// 法一：暴力法
		if (index < 1)
			return 0;
		int cnt = 0;
		int num = 1;
		while (cnt < index)
		{
			if (isUgly(num))
			{
				++cnt;
				cout << num << " ";
			}
			++num;
		}
		return num;
	}

	bool isUgly(int num)
	{
		if (num < 1)
			return false;
		while (num % 2 == 0)
			num /= 2;
		while (num % 3 == 0)
			num /= 3;
		while (num % 5 == 0)
			num /= 5;
		return num == 1;
	}

    int GetUglyNumber_Solution2(int index) {
    /*
    法二：丑数只包含质因子2、3和5，那么将之前已经计算的丑数与2、3、5相乘，得到的数必定是丑数，取得到的最小的数。
    */
        if (index < 1)
            return 0;
        vector<int> res(index, 0);
        res[0] = 1;
        int id2 = 0, id3 = 0, id5 = 0;
        for (int i = 1; i < index; ++i)
        {
            res[i] = min(res[id2] * 2, min(res[id3] * 3, res[id5] * 5));
            if (res[i] == res[id2] * 2)
                ++id2;
            if (res[i] == res[id3] * 3)
                ++id3;
            if (res[i] == res[id5] * 5)
                ++id5;
        }
        return res[index - 1];
    }
};

int main(int argc, char* argv[])
{
	Solution A;
	int index;
	while (cin >> index)
	{
		cout << A.GetUglyNumber_Solution(index) << endl;
	}
}

