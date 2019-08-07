# -*- coding:utf-8 -*-


class Sort:
    def quickSort(self, arr, start, end):
            if start < end:
                pos = self.partition(arr, start, end)
                self.quickSort(arr, start, pos - 1)
                self.quickSort(arr, pos + 1, end)

    def partition(self, arr, left, right):
        key = arr[left]
        print("left = {}，right = {}，key = {}".format(left, right, key))
        while right > left:
            while right > left and arr[right] >= key:
                right -= 1
            if right > left:
                arr[left] = arr[right]  # 把 right 处位置的元素赋值到 left 处，可以想象 right 处位置空出来了
                left += 1
            while right > left and arr[left] <= key:
                left += 1
            if right > left:
                arr[right] = arr[left]
                right -= 1
            # 每一步操作前都必须判断 right > left，因为每一步操作后都紧跟着改变了 left 或者 right.
        # 此时 right 与 left 指向数组同一个位置
        arr[left] = key
        print("partition 后 arr = {}".format(arr))
        return left




if __name__ == "__main__":
    arr = [3, 5, 7, 1, 9, 8, 5, 6, 2]
    print("原始数组：{}\n排序过程：".format(arr))
    f = Sort()
    f.quickSort(arr, 0, len(arr) - 1)