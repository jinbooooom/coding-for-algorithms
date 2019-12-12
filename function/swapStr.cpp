// 引用符号 & 去掉就不能交换了，用引用指针代表传的指针是实参而不是形参，s1, s2便不是一个临时的拷贝。
void swap(char *&s1, char *&s2)
{
	char *tmp;
	tmp = s1;
	s1 = s2;
	s2 = tmp;
}

int main(int argc, char* argv[]) {
	char * s1 = "hello ";
	char * s2 = "world ";
	cout << s1 << s2 << endl;
	swap(s1, s2);
	cout << s1 << s2 << endl;
	system("pause");
}
/* 打印
hello world
world hello
*/