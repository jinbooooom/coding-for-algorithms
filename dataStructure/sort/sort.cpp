#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "mysort.h"

using namespace std;

const unsigned size = 25;
const unsigned randMax = 1000;

void show(int *arr, bool notSort = true, unsigned int size = size)
{
    if (notSort)
        printf("产生 %d 个 0～%d 范围的随机数：", size, randMax);
    else
        printf("排序后，数组为：                 ");
    for (unsigned int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void randArr(int *arr, unsigned int size = size, unsigned int randmax = randMax)
{
    srand((unsigned int)time(0));
    for (unsigned int i = 0; i < size; ++i)
        arr[i] = rand() % randmax;      // range: 0 to randmax - 1
}

int main(int argc, char **argv)
{

	int arr[size] = { };

    cout << "call merge()" << endl;
    randArr(arr);
    show(arr);
	merge(arr, 0, size - 1);
	show(arr, false);

    cout << "call quick()" << endl;
    randArr(arr);
    show(arr);
    quick(arr, 0, size - 1);
    show(arr, false);

    cout << "call shell()" << endl;
    randArr(arr);
    show(arr);
    shell(arr, size);
    show(arr, false);

    cout << "call bubble()" << endl;
    randArr(arr);
    show(arr);
    bubble(arr, size);
    show(arr, false);

    cout << "call insert()" << endl;
    randArr(arr);
    show(arr);
    insert(arr, size);
    show(arr, false);

    cout << "call select()" << endl;
    randArr(arr);
    show(arr);
    select(arr, size);
    show(arr, false);
}
