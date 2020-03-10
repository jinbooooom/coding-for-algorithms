/*
题目：
在一个长度为 n 的数组里的所有数字都在 0 到 n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字是重复的，
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组 {2,3,1,0,2,5,3}，
那么对应的输出是重复的数字 2 或者 3。
*/

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (numbers == nullptr || length == 0)
            return false;
        // 检查数据是否在区间[0, length-1]内
        for (int i = 0; i < length; ++i)
        {
            if (numbers[i] < 0 || numbers[i] >= length)
                return false;
        }

        for (int i = 0; i < length; ++i)
        {
            while (numbers[i] != i)
            {
                if (numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;        // 有重复的数字
                }
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false;                   // 没有重复数字
    }

    void swap(int& x, int& y)
    {
        int t = y;
        y = x;
        x = t;
    }
};