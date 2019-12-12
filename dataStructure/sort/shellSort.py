# -*- coding:utf-8 -*-


class Sort:
    def shellSort(self, arr):
        d = len(arr) // 2
        while d >= 1:
            # 当增量 d 为 1 时，执行的就是插入排序。
            # 但实际上当 d = 1 时，此时数组很有序，只需要少量操作就可以排完序。
            for i in range(d, len(arr)):
                t = arr[i]  # 将要插入的元素 t
                j = i - d  # 子序列中，t 前面的一个元素
                while j >= 0 and arr[j] > t:
                    arr[j + d] = arr[j]
                    j -= d
                arr[j + d] = t
            print(arr)
            d //= 2
        return arr


if __name__ == "__main__":
    arr = [9, 8, 5, 6, 3, 5, 7, 1, 2]
    print("原始数组：{}\n排序过程：".format(arr))
    f = Sort()
    f.shellSort(arr)