class Solution {
public:
	bool isPalindrome(string s) {
		if (!s.size())
			return true;
		int p1 = 0;
		int p2 = s.size() - 1;
		while (p1 < p2)
		{
			while (p1 < p2 && !isAlphaAndDigit(s[p1]))
				p1++;
			while (p1 < p2 && !isAlphaAndDigit(s[p2]))
				p2--;
			//cout << p1 << ' ' << p2 << endl;
			//cout << lower(s[p1]) << ' ' << lower(s[p2]) << endl;
			if (p1 > p2 or lower(s[p1]) != lower(s[p2]))
				return false;
			p1++;
			p2--;
		}
		return true;
	}

	bool isAlphaAndDigit(char ch)
	{
		if ((ch >= 'A' && ch <= 'Z') ||
			(ch >= 'a' && ch <= 'z') ||
			(ch >= '0' && ch <= '9'))
			return true;
		return false;
	}

	char lower(char ch)
	{
		if (ch >= 'A' && ch <= 'Z')
			return ch - 'A' + 'a';
		return ch;
	}
};
