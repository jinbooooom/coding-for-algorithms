// 基于加减法交换两个数
void swap(int &x, int &y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}

// 基于异或运算交换两个数
void swap1(int &x, int &y)
{
	x ^= y;
	y ^= x;
	x ^= y;
}
