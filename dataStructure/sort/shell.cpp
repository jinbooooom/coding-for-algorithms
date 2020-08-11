/*
shell 排序是对插入排序的一个改进
*/
void shell(int *arr,int len)
{
    int i, j, x, d;
    d = len/2;
    // 当增量 d 为 1 时，执行的就是插入排序。
    // 但实际上当 d = 1 时，此时数组很有序，只需要少量操作就可以排完序。
    while(d >= 1)
    {
        for(i = d; i < len; ++i)
        {
            x = arr[i];
            j = i - d;
            while(j >= 0 && arr[j] > x)
            {
                arr[j + d] = arr[j];
                j -= d;
            }
            arr[j + d] = x;
        }
        d /= 2;
    }
}