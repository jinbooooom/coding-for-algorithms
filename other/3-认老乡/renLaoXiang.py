# -*- coding:utf-8 -*-
"""
https://exercise.acmcoder.com/online/online_judge_ques?ques_id=1683&konwledgeId=135

大学的同学来自全国各地，对于远离家乡步入陌生大学校园的大一新生来说，碰到老乡是多么激动的一件事，
于是大家都热衷于问身边的同学是否与自己同乡，来自新疆的小赛尤其热衷。
但是大家都不告诉小赛他们来自哪里，只是说与谁同乡，从所给的信息中，你能告诉小赛有多少人确定是她的同乡吗？

输入:
每个测试实例首先包括2个整数，N（1 <= N <= 1000），M(0 <= M <= N*(N-1)/2)，代表现有N个人（用1~N编号）和M组关系；
在接下来的M行里，每行包括2个整数，a，b，代表a跟b是同乡；
当N = 0，M = 0输入结束；
已知1表示小赛本人。

样例输入:
3 1
2 3
5 4
1 2
3 4
2 5
3 2
0 0

输出:
对于每个测试实例，输出一个整数，代表确定是小赛同乡的人数。

样例输出:
0
4
"""


if __name__ == "__main__":
    while 1:
        sameCity = {1,}  # 编号处于 relationship 里的人都是老乡
        relationship = []
        N, M = list(map(int, input().strip().split()))
        if N <= 0 or M <= 0:
            continue
        for i in range(M):
            relationship.append(list(map(int, input().strip().split())))
        relationship = sorted(relationship, key=lambda x: (x[0], x[1]))
        print(relationship)
        for r in relationship:
            same = set(r) & sameCity
            # print(same)
            if same:
                sameCity = sameCity | set(r)
        # print(sameCity,'\n')
        print(len(sameCity) - 1)



