# -*- coding:utf-8 -*-
import random

class Sort:

    def selectSort(self, arr):
        for i in range(len(arr)):
            m = i
            for j in range(i + 1, len(arr)):
                if arr[m] > arr[j]:
                    m = j
            if i != m:
                arr[i], arr[m] = arr[m], arr[i]
            print(arr)
        return arr

    def selectSort2(self, arr):  # python 风格的递归实现
        if not arr:
            return arr
        m = min(arr)
        arr.remove(m)
        arr.insert(0, m)
        return arr[:1] + self.selectSort2(arr[1:])


if __name__ == "__main__":
    f = Sort()
    # arr = [random.randint(0, 99) for _ in range(10)]
    arr = [3, 5, 71, 7, 9, 8, 5, 6, 2]
    print("原始数组：{}\n排序过程：".format(arr))
    f.selectSort(arr)

    print("\npython 风格的递归实现")
    arr = [3, 5, 71, 7, 9, 8, 5, 6, 2]
    print("原始数组：{}\n排序过程：".format(arr))
    print(f.selectSort2(arr))
