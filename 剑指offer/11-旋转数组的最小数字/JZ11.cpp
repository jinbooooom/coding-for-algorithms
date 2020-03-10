class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        // 特例：把最开始的零个元素搬到数组的末尾，即数组未旋转。
        if (rotateArray[0] < rotateArray[rotateArray.size() - 1])
            return rotateArray[0];

        int begin = 0, end = rotateArray.size() - 1;
        int mid = 0;

        while (begin < end)
        {
            if (end - begin == 1)
                return rotateArray[end];
            mid = (begin + end)/2;
            if (rotateArray[begin] == rotateArray[mid] && rotateArray[mid] == rotateArray[end])
            {
                int m = rotateArray[begin];
                for (int i = begin + 1; i <= end; ++i)
                    if (rotateArray[i] < m)
                        m = rotateArray[i];
                return m;
            }
            else if (rotateArray[begin] <= rotateArray[mid])
                begin = mid;
            else
                end = mid;
        }
    }
};