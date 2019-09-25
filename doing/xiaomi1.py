# -*- coding:utf-8 -*-
"""
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
美团某部门在拍年度纪念照时，一般要求员工按照 非递减 的高度顺序排列。

请你返回至少有多少个员工没有站在正确位置数量。该人数指的是：能让所有员工以 非递减 高度排列的必要移动人数。

例如：有高度为 1,1,4,2,1,3 的6个学生

共有3个学生没有站在正确的位置（高度为 4、3 和最后一个 1 的学生，没有站在正确的位置）

如遇到空输入的情况，需输出0

输入
一行正整数，以逗号隔开

输出
输出没有站在正确位置的员工数量


样例输入
1,1,4,2,1,3
样例输出
3


"""
from typing import List
import os

class Solution:
    def file_name(self, file_dir):
        for root, dirs, files in os.walk(file_dir):
            if not files:
                continue
            files = [os.path.join(r, d, f) for r in root for d in dirs for f in files]
            for file in files:
                cnt = 0
                with open(file, 'r') as f:
                    for line in f.readlines():
                        if 'ruijie' in line:
                            print("{},{}".format(dirs, cnt))
                            cnt += 1

if __name__ == "__main__":
    f = Solution()
    L = []
    f.file_name('./f')
    #print(L)
