
#include<stdio.h>

#define TRUE 1
#define FALSE 0


//方法一：暴力排序，快速排序，时间效率O(nlogn)

void Quiksort(int *a, int left, int right)
{
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
     
    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
        /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
        序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/ 
        {
            j--;/*向前寻找*/
        }
         
        a[i] = a[j];
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
        a[left]，那么就是给key）*/
         
        while(i < j && key >= a[i])
        /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
        因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }
         
        a[j] = a[i];
    }
     
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    Quiksort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    Quiksort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
                       /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}

int DupNumInArray(int array[], int count, int* DupNum)
{
	Quiksort(array,0,count-1);
	

	for(int j = 0;j < count;j++)
	{
		printf("%d\n",array[j]);
	}	
	for(int i = 0; i < count;i++)
	{
		if(array[i]!= i)
		{
			*DupNum = array[i];
			return TRUE;
		}	
	}

	return FALSE;
} 
//方法二：BITmap位判断,空间复杂度O(1),时间复杂度O(N);缺陷：保存hashkey的空间需要计算，int型只能用于长度小于32的数组
int DupNumInArray2(int array[], int count, int* DupNum)
{

	int Hashkey = 0;

	for(int i = 0;i < count;i++)
	{
		if(Hashkey & 1<<array[i] )
		{
			*DupNum = array[i];
			return TRUE;
		}
		Hashkey = Hashkey | 1<<array[i];
	}

	return FALSE;
}


int main()
{
	//
	int Dup=0;
	int array[] = {2,3,1,0,4,5,3};
	if(TRUE!=DupNumInArray2(array,7,&Dup))
	{
		printf("no repeat num");
		return 0;
	}
	
	printf("repeating Num %d\n",Dup);
	return 0;
}


