# -*- coding:utf-8 -*-
import random

class Sort:

    def mergeSort(self, arr, start, end):
        """
        分治子序列 arr[start:end + 1]
        """
        if end > start:
            mid = (start + end) // 2
            self.mergeSort(arr, start, mid)
            self.mergeSort(arr, mid + 1, end)
            self.merge(arr, start, mid, end)
            print("start={}, mid={}, end={}\narr={}".format(start, mid, end, arr))

    def merge(self, arr, start, mid, end):
        """
        合并有序的左子序列 arr[start:mid + 1] 与右子序列 arr[mid + 1:end + 1]，并使之有序。
        """
        left_start = start
        left_end = mid
        right_start = mid + 1
        right_end = end

        tmp = []

        while(left_end >= left_start and right_end >= right_start):
            if arr[left_start] <= arr[right_start]:
                # 若左子序列起始指针 left_start 指向的元素小于右子序列起始指针 right_start，
                # 则将左子序列的元素 arr[left_start] 先放到临时列表 tmp 中，
                # 再让 left_start 指向下一个元素
                tmp.append(arr[left_start])
                left_start += 1
            else:
                tmp.append(arr[right_start])
                right_start += 1

        if left_start > left_end:
            # 若先把左子序列的元素全部放到 tmp 中（已经放完了），则右子序列肯定有多余的元素还没有放到 tmp 列表中。
            # 此时直接把右子序列剩余的元素都添加到 tmp。
            tmp += arr[right_start:right_end + 1]  # 用 append 添加一个列表，也会把中括号添加进去。
        else:
            tmp += arr[left_start:left_end + 1]

        arr[start:end + 1] = tmp


if __name__ == "__main__":
    f = Sort()
    # arr = [random.randint(0, 99) for _ in range(10)]
    arr = [3, 5, 71, 7, 9, 8, 5, 6, 2]
    print("原始数组：{}\n排序过程：".format(arr))
    f.mergeSort(arr, 0, len(arr) - 1)
    print(arr)


