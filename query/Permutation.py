# -*- coding:utf-8 -*-
"""
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
"""

代码有问题。后面再补充

class Solution:
    def Permutation(self, ss):
        result = []
        self.pailie(ss, result)
        self.search(result, 0)
        return result

    def search(self, strlist, fixn=-1):
        for s in strlist:
            if self.pailie(s, result, fixn):
                self.search(set(result), fixn+1)



    def pailie(self, ss, result, fixn=-1):
        """
        把字符串 ss 里的每一个字符与第一个字符交换一下位置（如果该字符与第一个字符不同），
        再用 fix 作为交换后字符串的前缀。
        如：
        'abac' 经处理后得到 ['abac', 'baac', 'cbaa']，再用 fix 作为这些字符串的前缀。

        :return: 当 fixn == len(ss) 时，返回 False，代表已经全排列了
        """
        if fixn < 0:
            fix = ''
        elif fixn < len(ss)-1:
            fix = ss[fixn]
        else:
            return False
        ss = list(ss)
        #print(ss)
        for i in range(len(ss)):
            if i:
                s = ss[:]
                #print(s)
                if s[0] != s[i]:
                    s[0], s[i] = s[i], s[0]
                    result.append(fix.join(s))
            else:
                result.append(fix.join(ss))
        return True

if __name__ == "__main__":
    result = []
    ss = 'abac'
    f = Solution()
    f.pailie(ss, result, -1)
    f.Permutation(ss)
    print(result)


