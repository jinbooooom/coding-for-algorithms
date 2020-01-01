
// 答案错误:您提交的程序没有通过所有的测试用例
// case通过率为30.77%
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (matrix == nullptr || strlen(str) == 0 || rows <= 0 || cols <= 0)
            return false;
        int pathLength = 0;
        int* vis = new int[rows * cols];
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                vis[i * cols + j] = 0;

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (hasPathCore(matrix, rows, cols, i, j, str, pathLength, vis))
                    return true;
        return false;
    }

    bool hasPathCore(char* matrix, int rows, int cols, int i, int j, char* str, int pathLength, int* vis)
    {
        if (pathLength == strlen(str))
            return true;
        bool inPath = false;
        if (i >= 0 && i < rows && j >= 0 && j < cols && matrix[i * cols + j] == str[pathLength] && vis[i * cols + j] == 0)
        {
            pathLength++;
            vis[i * rows + j] = 1;
            inPath = hasPathCore(matrix, rows, cols, i - 1, j, str, pathLength, vis) ||
                     hasPathCore(matrix, rows, cols, i, j + 1, str, pathLength, vis) ||
                     hasPathCore(matrix, rows, cols, i + 1, j, str, pathLength, vis) ||
                     hasPathCore(matrix, rows, cols, i, j - 1, str, pathLength, vis);
            if (!inPath)
            {
                pathLength--;
                vis[i * rows + j] = 0;
            }
        }
        return inPath;
    }
};