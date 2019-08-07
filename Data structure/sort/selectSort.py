# -*- coding:utf-8 -*-
import random


class Sort:
    def selectSort(self, arr):  # python 风格
        for i in range(len(arr)):
            m = i
            for j in range(i + 1, len(arr)):
                if arr[m] > arr[j]:
                    m = j
            if i != m:
                arr[i], arr[m] = arr[m], arr[i]
            print(arr)
        return arr


if __name__ == "__main__":
    f = Sort()
    arr = [random.randint(0, 99) for _ in range(10)]
    # arr = [3, 4, 71, 7, 9, 8, 5, 6, 2]
    print("原始数组：{}\n排序过程：".format(arr))
    f.selectSort(arr)
