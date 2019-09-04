# -*- coding:utf-8 -*-
"""
https://exercise.acmcoder.com/online/online_judge_ques?ques_id=1662&konwledgeId=135

有n个格子，从左到右放成一排，编号为1-n。
共有m次操作，有3种操作类型：
1.修改一个格子的权值，
2.求连续一段格子权值和，
3.求连续一段格子的最大值。
对于每个2、3操作输出你所求出的结果。

输入:
输入第一行两个整数，n表示格子个数，m表示操作次数，n和m中间用空格隔开；
接下来输入n行，每行一个整数表示一个格子的权值。
接下来输入m行，每行有三个整数，中间用空格隔开；第一个是选择的操作类型1-3,第二和第三个整数是操作格子的编号。

样例输入:
3 3
7
8
9
2 1 3
3 1 3
2 1 2

输出：
若执行1操作则无输出
若执行2和3操作则输出一个整数

样例输出:
24
9
15
"""


def opera(arr, op, var1, var2):
    if op == 1:
        pass
        # arr[var1] = var2
    elif op == 2:
        print(sum(arr[var1 - 1: var2]))
    elif op == 3:
        print(max(arr[var1 - 1: var2]))


if __name__ == "__main__":
    n, m = list(map(int, input().strip().split()))
    L = []
    for i in range(n):
        L.append(int(input().strip()))
    for i in range(m):
        ops = list(map(int, input().strip().split()))
        opera(L, *ops)
