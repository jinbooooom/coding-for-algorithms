class Solution {

public:
    int jumpFloorII(int number) {
        if (number <= 0)
            return 0;
        else if (number == 1)
            return number;
        int fn = 1;
        for (int i = 2; i <= number; ++i)
            fn *= 2;
        return fn;
    }
};