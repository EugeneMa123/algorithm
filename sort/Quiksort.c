//对于快速排序有不同的版本
//方法一：以第一个数为基准，挖坑填坑法
//方法二：以第一个数为基准，后边的数进行互换，最后的中间一个数与第一个数交换位置
#include<stdio.h>

//方法一：以第一个数为基准，挖坑填坑法
void Quiksort1(int a[],int left,int right)
{
    int i = left;
    int j = right;
    int  key = a[i];
    //
    if(left >= right)
    {
        return;
    }
    while(i<j)
    {
        while(i<j && key <= a[j])
        {
            j--;
        }
        a[i] = a[j];
        while(i<j && key > a[i])
        {
            i++;
        }
        a[j] = a[i];
      
        
    }
    a[i] = key;
    Quiksort1(a,left,i-1);
    Quiksort1(a,i+1,right);
    return;
  
}
