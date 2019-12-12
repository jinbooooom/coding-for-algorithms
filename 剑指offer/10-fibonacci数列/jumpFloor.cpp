class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 0)
            return 0;
        else if (number == 1 || number == 2)
            return number;
        int fn_1 = 2, fn_2 = 1; // f(n-1) 与 f(n-2)
        int fn;
        for (int i = 3; i <= number; ++i)
        {
            fn = fn_1 + fn_2;  // f(n) = f(n-1) + f(n-2)
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
};