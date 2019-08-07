# -*- coding:utf-8 -*-


class Sort:
    def insertSort(self, arr):
        for i in range(1, len(arr)):  # 需要 len(l)-1 轮插入才排序完毕
            t = arr[i]
            j = i - 1
            # 每一轮跟排序好的部分最多比较 i 次，而排序好的部分是 arr[:i]
            while j >= 0 and arr[j] > t:
                arr[j+1] = arr[j]  # 前面一个数 arr[j] 大于 t，就把该数后移一位
                j -= 1
            arr[j+1] = t
            print(arr)
        return arr

    def insertSort2(self, arr):
        """
        python 风格插入排序
        """
        for i in range(1, len(arr)):
            t = arr[i]
            for j in range(i):
                if arr[j] > t:
                    del arr[i]
                    arr.insert(j, t)
                    print(arr)
                    break
        return arr


if __name__ == "__main__":
    arr = [9, 8, 5, 6, 3]
    f = Sort()
    print("原始数组：{}\n排序过程：".format(arr))
    f.insertSort(arr)
    print('\npython风格插入排序：')
    print("原始数组：{}\n排序过程：".format(arr))
    arr = [9, 8, 5, 6, 3]
    f.insertSort2(arr)
