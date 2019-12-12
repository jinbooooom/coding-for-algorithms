

class Solution {
public:
// 比如求 3的 31 次方 result，如果知道 3 的 15 次方为 a，那么可知 3 的 30次方为 = a * a ，
// 由于 31 为奇数所以再在 3 的 30 次方基础上再乘以 3，时间复杂度 O(logn)。
    double Power(double base, int exponent) {
        if (exponent == 0)
            return 1;
        if (exponent == 1)
            return base;
        double result = Power(base, exponent >> 1);
        result *= result;
        if (exponent & 1)  // 奇数与 1 位与为 true
            result *= base;
        return result;
    }
};