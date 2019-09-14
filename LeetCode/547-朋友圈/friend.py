"""
https://leetcode-cn.com/problems/friend-circles

班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。
如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。
所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。
如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
你必须输出所有学生中的已知的朋友圈总数。

示例 1:
输入:
[[1,1,0],
 [1,1,0],
 [0,0,1]]

输出: 2
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。

示例 2:
输入:
[[1,1,0],
 [1,1,1],
 [0,1,1]]

输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，
所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。

注意：
    N 在[1,200]的范围内。
    对于所有学生，有M[i][i] = 1。
    如果有M[i][j] = 1，则有M[j][i] = 1。

"""
from typing import List


class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        """
        提示：并查集

        """

        class UnionFind:
            def __init__(self, n):
                self.count = n
                self.parent = [i for i in range(n)]
                self.rank = [1 for _ in range(n)]

            def find(self, p):
                root = p
                # 只要不是最上层的那个结点，就不停向上找
                while root != self.parent[root]:
                    root = self.parent[root]
                # 此时 root 就是大 boss
                # 接下来把 p 到 root 沿途所有的结点都指向 root
                # 让老大成为各个小弟的直接大哥
                while p != self.parent[p]:
                    temp = self.parent[p]
                    self.parent[p] = root
                    p = temp
                return root

            def is_connected(self, p, q):
                # 判断小弟 p, q 的老大是不是同一个人，若是，则属于同一个阵营
                return self.find(p) == self.find(q)

            def union(self, p, q):
                p_id = self.find(p)
                q_id = self.find(q)
                # 如果 p, q 的老大都是同一个人，那 p, q 属于同一个阵营，什么都不用操作。
                if p_id == q_id:
                    return

                # 已知 p, q 是同一阵营，但 p, q 的老大不是同一人，
                # 此时应合并两个阵营，才能使 p, q 有相同的老大。
                # 合并规则是小弟少的（rank小的）那一个老大认小弟多的那一个老大为老大。
                if self.rank[p_id] > self.rank[q_id]:
                    self.parent[q_id] = p_id
                    self.rank[p_id] += 1
                else:
                    self.parent[p_id] = q_id
                    self.rank[q_id] += 1
                # 两个阵营合并了，老大数量减一
                self.count -= 1

        m = len(M)
        uf = UnionFind(m)
        # 只看下三角矩阵(不包括对角线)，因为矩阵 M 必定沿着对角线对称
        for i in range(m):
            for j in range(i):
                if M[i][j] == 1:
                    uf.union(j, i)
        # print(uf.parent)
        # print(uf.rank)
        return uf.count


if __name__ == "__main__":
    f = Solution()
    M = [[1, 1, 0, 1],
         [1, 1, 0, 1],
         [0, 0, 1, 0],
         [1, 1, 0, 1]]
    print(f.findCircleNum(M))
