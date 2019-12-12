class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
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