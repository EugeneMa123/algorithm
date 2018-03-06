// StringReverse.cpp : 定义控制台应用程序的入口点。
//字符串翻转

#include "stdafx.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

//方法一：暴力循环 时间复杂度O(N*M),空间复杂度O（1）
int StringReverseSingleChar(char * str, int n)
{

	int i;

	if(str ==  NULL)
	{
		return 0;
	}
	char t = str[0];

	for(i = 1;i < n;i++)
	{
		str[i-1] = str[i];
	}
	str[i-1] = t;
	return 0;
}

int StringReverseFrontM(char* s,int n,int m)
{
	if(m > n)
	{
		return 0;
	}
	
	if(s == NULL)
	{
		return 0;
	}

	while(m--)
	{
		StringReverseSingleChar(s,  n);
	}

	return 0;
}

//方法二：分段反转再反转

int StrReverse2(char* chPtrStr,int inStart,int inEnd)
{
	if(chPtrStr == NULL)
	{
		return 0;

	}
	if(inStart >= inEnd)
	{
		return 0;

	}
	while(inStart < inEnd)
	{
		char t = chPtrStr[inStart];
		
		chPtrStr[inStart++] = chPtrStr[inEnd];
		chPtrStr[inEnd--] = t;

	}
	return 0;
}

int StrReverseFrontM2(char* chPtrStr,int n,int m)
{
	StrReverse2(chPtrStr,0,m-1);
	StrReverse2(chPtrStr,m,n-1);
	StrReverse2(chPtrStr,0,n-1);
	return 0;
}

//将后M个字符反转到字符串前,eg.后7个字符
//"Ilovebaofeng"--------->"baofengIlove"
int StrReverseBackM(char* chPtrStr,int n,int m)
{
	StrReverseFrontM2( chPtrStr, n, n-m);
	return 0;
}


//将I am a student.反转成student. a am I
//句首有空格会怎么样？
//句中有多个空格会怎么样？
//句末有空格会怎么样？
int StrReverseOfSentence(char* chPtrStr)
{
	int i = 0;
	int j = 0;
	int len = 0;
	char* chPtrStrTmp = chPtrStr;
	while(chPtrStrTmp[j])
	{
		
		if(chPtrStrTmp[j] == ' ')
		{
			StrReverse2(chPtrStr,i,j-1);
			i = j+1;
			
		}
		j++;
		
	}
	if(i != j)
	{
		StrReverse2(chPtrStr,i,j-1);
	}
	//len = strlen(chPtrStr);
	StrReverse2(chPtrStr,0,j-1);
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char s1[] = "abcdef";
	char s2[] = "abcdef";
	char s3[] = "Ilovebaofeng";
	char s4[] = "Ilovebaofeng";
	char s5[] = "I love     baofeng.";
	StringReverseSingleChar(s1, 6);
	StringReverseFrontM(s2,6,3);
	StrReverseFrontM2(s3,12,5);
	StrReverseBackM(s4,12,7);
	StrReverseOfSentence( s5);
	printf("%s\n",s1);
	printf("%s\n",s2);
	printf("%s\n",s3);
	printf("%s\n",s4);
	printf("%s\n",s5);
	system("pause");
	return 0;
}

