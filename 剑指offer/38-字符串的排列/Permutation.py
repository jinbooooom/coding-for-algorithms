# -*- coding:utf-8 -*-
"""
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
"""


class Solution:
    def Permutation(self, ss):
        if len(ss) <= 1:
            return ss
        res = [list(ss)]
        p = 0
        self.pailie(res, p)
        result = [''.join(x) for x in sorted(res)]
        return result

    def pailie(self, res, p):
        """
        提示;
        执行过程：
        res = [aabc]
        固定索引 p 处的元素 a，使 a与 a 后面的元素（若后面的元素不是 a）交换，得到 baac, caba。
        更新 res = [aabc, baac, caba], p = p+1
        对 res 内的每一个串，固定索引为 p+1 的元素，然后与后面的元素交换。
        比如对 caba 固定索引为 1的字符 a，然后与 a 后面的不同于 a 的字符交换，得到 cbaa。
        如此反复，当 p 指向最后一个字符的时候，没有可以交换的，得到的 res 就是全排列。

        :param res: 当固定索引 p 处的字符时，已经找到的（部分）全排列。
                    将索引 p 等于字符串长度-1 的时候，就找到了所有的全排列。
                    res 的结构为 [list(str),list(str),...]，如 [['a', 'b', 'c'], ['a', 'c', 'b']]
        :param p: 固定索引为 p 位置的字符
        :return: res
        """
        if p >= len(res[0]) - 1:
            return res
        ex = []
        for s in res:
            for i in range(p+1, len(s)):
                if s[i] != s[p]:
                    ts = s[:]  # 修改了 s 会改变 for 内的 s, 故使用浅拷贝
                    ts[i], ts[p] = ts[p], ts[i]
                    ex.append(ts)
        res.extend(ex)
        # print(res)
        return self.pailie(res, p+1)


if __name__ == "__main__":
    result = []
    ss = 'aabc'
    f = Solution()
    r = f.Permutation(ss)
    print(r)


