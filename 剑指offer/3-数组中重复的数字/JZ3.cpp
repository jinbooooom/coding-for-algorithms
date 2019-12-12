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