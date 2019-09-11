"""
继 MIUI8 推出手机分身功能之后，MIUI9计划推出一个电话号码分身的功能：
首先将电话号码中的每个数字加上8取个位，然后使用对应的大写字母代替
（"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"），
然后随机打乱这些字母，所生成的字符串即为电话号码对应的分身。

输入：
第一行是一个整数 T（1<=T<=100)表示测试样例数；
接下来 T行，每行给定一个分身后的电话号码的分身（长度在3到10000之间）。

样例输入：
4
EIGHT
ZEROTWOONE
OHWETENRTEO
OHEWTIEGTHENRTEO

输出：
输出T行，分别对应输入中每行字符串对应的分身前的最小电话号码（允许前导0）。

样例输出
0
234
345
0345

"""


class Solution():
    def main(self, s):
        fenshen = self.get_nums(self.stastr(s))
        telephone = self.get_telephone(fenshen)
        telephone.sort()
        telephone = [str(tel) for tel in telephone]
        return ''.join(telephone)

    def stastr(self, s):
        s = list(s)
        nums = [0] * 10

        # 数字 0，2，4，6，8 可以根据分身字符串中是否含有 'Z' 'W' 'U' 'X' 'G'唯一确定
        nums[0] = s.count('Z')
        self.remove_more(s, 'ZERO', nums[0])
        nums[2] = s.count('W')
        self.remove_more(s, 'TWO', nums[2])
        nums[4] = s.count('U')
        self.remove_more(s, 'FOUR', nums[4])
        nums[6] = s.count('X')
        self.remove_more(s, 'SIX', nums[6])
        nums[8] = s.count('G')
        self.remove_more(s, 'EIGHT', nums[8])

        # 去掉了数字 0，2，4，6，8 的分身字符串后，
        # 1，3，5，7 的分身可以由字符 'O' 'R' 'F' 'S' 唯一确定
        nums[1] = s.count('O')
        self.remove_more(s, 'ONE', nums[1])
        nums[3] = s.count('R')
        self.remove_more(s, 'THREE', nums[3])
        nums[5] = s.count('F')
        self.remove_more(s, 'FIVE', nums[5])
        nums[7] = s.count('S')
        self.remove_more(s, 'SEVEN', nums[7])

        # 删除了除 9 外的所有分身后,
        # 剩下的数字 9 的分身，可以由 'I' 唯一确定
        nums[9] = s.count('I')
        self.remove_more(s, 'NINE', nums[9])
        return nums

    def remove_more(self, s, chs, cnt_loop):
        for i in range(cnt_loop):
            for ch in chs:
                s.remove(ch)

    def get_nums(self, nums):
        digit = []
        for i in range(len(nums)):
            if nums[i]:
                digit += [i] * nums[i]
        return digit

    def get_telephone(self, fenshen):
        """
        将分身转换成打散的数字列表

        :param fenshen: list
        :return: list
        """
        tel = []
        for x in fenshen:
            if 8 > x >= 0:
                tel.append(x + 2)
            else:
                tel.append(x - 8)
        return tel


if __name__ == "__main__":
    f = Solution()
    T = int(input().strip())
    for i in range(T):
        fenshen = input().strip()
        print(f.main(fenshen))

    """
    测试用例:
    10
    OZONETOWER
    WEIGHFOXTOURIST
    OURNEONFOE
    ETHER
    OEIHGERTZ
    EIVEOUXISEFNRFSV
    NESINOEOX
    ORNOEZE
    IEENNEOENNNNNNOIIE
    ITERWNIUNVNNFFIOEOE
    """




