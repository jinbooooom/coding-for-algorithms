/* 一种方法是将数字 n 右移，与 1 与，但这样可能会引起死循环，
因为当 n 为负数的时候，n 的最高位补码为 1，
这样一直右移，最终这个数字就会变成 0xFFFFFFFF，而陷入死循环。
为了避免死循环，设置 flag = 1，将 flag 左移，
在 32 位机器上 flag 移动 32 次就会变成 0，跳出 while 循环。
*/

int numberOf1(int n)
{
    unsigned int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if (n & flag)
            count++;
        flag = flag << 1;
    }
    return count;
}