#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#include"windows.h"
#include <sys/time.h>
#include <string.h>//radix sort need memset function
//#define N 1000000       //N :the length of array

/*
本科时在 windows 上写的排序算法，
建议阅读同目录下 ./sort/* 里的文件，应该写的更好一些
*/

void printarr(int *arr,int len)
{
    for(int i=0;i<len;i++)
        printf("%d ",arr[i]);
    puts("\n");
}

void Randnum(int *arr,int len,int randmax)
{
    srand((unsigned)time(NULL));
    for(int i=0;i<len;i++)
        arr[i]=rand()%randmax;//range 0 to randmax-1
}

void Insert_sort(int *arr,int len)
{
    int i,j,t;
    for (i=1;i<len;++i)
    {
        t=arr[i];
        for(j=i-1;j>=0 && t<arr[j];--j)
            arr[j+1]=arr[j];
        arr[j+1]=t;
    }
}

void Shell_sort(int *arr,int len)
{
    int i,j,x,d;
    d=len/2;
    while(d>=1)
    {
        for(i=d;i<len;i++)
        {
            x=arr[i];
            j=i-d;
            while(j>=0&&arr[j]>x)
            {
                arr[j+d]=arr[j];
                j-=d;
            }
            arr[j+d]=x;
        }
        d/=2;
    }
}

void Bubble_sort(int *arr,int len)
{
    int t;
    for(int i=0;i<len-1;++i)
        for(int j=0;j<len-i-1;++j)
            if(arr[j]>arr[j+1])
                t=arr[j], arr[j]=arr[j+1],arr[j+1]=t;
}

int Partition(int *arr, int low, int high)
{
    int key = arr[low];
    while(low<high){
        while(low <high && arr[high]>= key )
            high--;
        if(low<high)
            arr[low++] = arr[high];
        while( low<high && arr[low]<=key )
            low++;
        if(low<high)
            arr[high--] = arr[low];
    }
    arr[low] = key;
    return low;
}

void Quick_sort(int *arr, int start, int end)
{
    int pos;
    if (start<end)
    {
        pos = Partition(arr, start, end);
        Quick_sort(arr,start,pos-1);
        Quick_sort(arr,pos+1,end);
    }

}

void Select_sort(int *arr,int len)
{
    int i,j,k,t;
    for(i=0;i<len-1;++i)
    {
        k=i;
        for(j=i+1;j<len;j++)
            if(arr[j]<arr[k])
                k=j;
        if(k!=i)
            t=arr[i],arr[i]=arr[k],arr[k]=t;
    }
}

void Creat_heap(int *arr,int node,int len)
{
    int parent=node,child=2*parent,t=arr[parent-1];
    while(child<=len)
    {
        if((child<len)&&(arr[child-1]<arr[child+1-1]))
            child++;
        if(t<arr[child-1])
        {
            arr[parent-1]=arr[child-1];
            parent=child;
            child=2*parent;
        }
        else
            break;
    }
    arr[parent-1]=t;
}

void Heap_sort(int *arr,int len)
{
    int child,t;
    for(child=len/2;child>=1;child--)
        Creat_heap(arr,child,len);
    for(child=len;child>1;child--)
    {
        t=arr[1-1];
        arr[1-1]=arr[child-1];
        arr[child-1]=t;
        Creat_heap(arr,1,child-1);
    }
}

void Merge(int *arr, int low, int mid, int high)
{
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    int left_low = low,left_high = mid;
    int right_low = mid + 1, right_high = high;
    for(k=0; left_low<=left_high && right_low<=right_high; k++)
        if(arr[left_low]<=arr[right_low])
            tmp[k] = arr[left_low++];
        else
            tmp[k] = arr[right_low++];
    if(left_low <= left_high)
        for(i=left_low;i<=left_high;i++)
            tmp[k++] = arr[i];
    if(right_low <= right_high)
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = arr[i];
    for(i=0; i<high-low+1; i++)
        arr[low+i] = tmp[i];
    free(tmp);
}

void Merge_sort(int *arr, unsigned int first, unsigned int last)
{
    int mid = 0;
    if(first<last)
    {
        mid = (first+last)/2;
        Merge_sort(arr, first, mid);
        Merge_sort(arr, mid+1,last);
        Merge(arr,first,mid,last);
    }
}

int Get_index(int num,  int order)
{
    int index;
    for(int i=0;i<order;i++)
        index=num%10,num/=10;
    return index;
}

void Radix_sort(int *arr, int len, int dec, int order)
{
    int i,index, zero=0;
    int tmp[len], num[10];
    memset(num, 0, 10*sizeof(int));
    memset(tmp, 0, len*sizeof(int));
    if (dec < order)
        return;
    for (i=0; i<len; i++)
        index = Get_index(arr[i], order),num[index]++;
    for (i=1; i<10; i++)
        num[i] += num[i-1];
    for (i=0;i<len;i++)
        if(!(index=Get_index(arr[i],order)))
            tmp[zero++]=arr[i];
        else
            tmp[num[--index]++]=arr[i];
    for (i=0; i<len; i++)
        arr[i] = tmp[i];
    Radix_sort(arr, len, dec, order+1);
}

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//Green
    puts("By Fang Jinbo In Hubei Normal University");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//white
    while (1){
    long N;//when dec=5,max=9,the program not work.
    puts("please input the length of array:");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED); //red
    scanf("%ld",&N);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//white
    int randmax =10000000;
    int *a = (int *)malloc(N*sizeof(int));
    struct timeval start,end;
    float timeuse;
    int dec=7, order=1;

/******sort begin *****/

    printf("N=%ld\n",N);

    Randnum(a,N,randmax);
    puts("Insert sort:");
    gettimeofday(&start,NULL);
    Insert_sort(a,N);
    gettimeofday(&end,NULL);
    timeuse=(1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec)/1000000.0;
    printf("%fs\n",timeuse);

    Randnum(a,N,randmax);
    puts("Shell sort:");
    gettimeofday(&start,NULL);
    Shell_sort(a,N);
    gettimeofday(&end,NULL);
    timeuse=(1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec)/1000000.0;
    printf("%fs\n",timeuse);

    Randnum(a,N,randmax);
    puts("Bubble sort:");
    gettimeofday(&start,NULL);
    Bubble_sort(a,N);
    gettimeofday(&end,NULL);
    timeuse=(1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec)/1000000.0;
    printf("%fs\n",timeuse);

    Randnum(a,N,randmax);
    puts("Quick sort:");
    gettimeofday(&start,NULL);
    Quick_sort(a,0,N-1);
    gettimeofday(&end,NULL);
    timeuse=(1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec)/1000000.0;
    printf("%fs\n",timeuse);

    Randnum(a,N,randmax);
    puts("Select sort:");
    gettimeofday(&start,NULL);
    Select_sort(a,N);
    gettimeofday(&end,NULL);
    timeuse=(1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec)/1000000.0;
    printf("%fs\n",timeuse);

    Randnum(a,N,randmax);
    puts("heap sort:");
    gettimeofday(&start,NULL);
    Heap_sort(a,N);
    gettimeofday(&end,NULL);
    timeuse=(1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec)/1000000.0;
    printf("%fs\n",timeuse);

    Randnum(a,N,randmax);
    puts("Merge sort:");
    gettimeofday(&start,NULL);
    Merge_sort(a,0,N-1);
    gettimeofday(&end,NULL);
    timeuse=(1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec)/1000000.0;
    printf("%fs\n",timeuse);

    Randnum(a,N,randmax);
    puts("Radix sort:");
    gettimeofday(&start,NULL);
    Radix_sort(a,N,dec,order);
    gettimeofday(&end,NULL);
    timeuse=(1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec)/1000000.0;
    printf("%fs\n",timeuse);

    getchar();
    //return 0;
    }
}
