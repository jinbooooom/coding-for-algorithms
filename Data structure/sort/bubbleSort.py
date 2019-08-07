# -*- coding:utf-8 -*-

class Sort:
    def bubbleSort(self, arr):
        # 需要 len(l)-1 次遍历
        for i in range(len(arr) - 1):
            # 第 i 次遍历，说明已经使 i 个大的数沉底，那么只需要对列表 arr[:len(arr)-i]部分相邻的元素比较大小
            # 且只需要比较 len(l)-i-1 次
            print(arr)
            # len(arr) - i 个元素，需要比较 len(arr) - i - 1 次
            for j in range(len(arr) - i - 1):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
        return arr

if __name__ == "__main__":
    f = Sort()
    arr = [9, 8, 5, 6, 3]
    print(f.bubbleSort(arr))
