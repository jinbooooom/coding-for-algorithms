/*
在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
    /*
    提示：
        将 target 与数组右上角所在的元素比较：
        相等：返回找到了
        小于：该元素所在的那一列里肯定是找不到的，只会存在于该元素左边所在的矩形区域
        大于：该元素所在的那一行里肯定是找不到的，只会存在于该元素下方所在的矩形区域
    */
        if (array.empty())
            return false;
        const int rows = array.size();
        const int cols = array[0].size();
        int r = 0, c = cols - 1;

        while (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            if (array[r][c] == target)
                return true;
            else if (target > array[r][c])
                r++;
            else
                c--;
        }
        return false;
    }
};