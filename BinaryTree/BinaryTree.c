// BinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  //getch()头文件
#include "BinaryTree.h"

//前序生成二叉树
/*按前序输入二叉树中结点的值（一个字符）*/
/*#表示空树，构造二叉链表表示二叉树T*/
unsigned char g_charFlag = 0;
void CreatBinaryTree(BinaryTree_Node_S **T)
{
	char ch;
	printf("\n input 1 \n");
	//ch = getch();
	if(*T == NULL)
	{
		return;
	}
	scanf_s("%c",&ch,1);

	if(ch == '\n')
	{
		/*if(g_charFlag == 1)
		{
			return;
		}*/
		scanf_s("%c",&ch,1);
	}
	
	if(ch =='#')
	{
		g_charFlag = 1;
		printf("\n input 2\n");
		*T = NULL;
	}
	else
	{
		g_charFlag = 0;
		printf("\n input 3\n");
		*T = (BinaryTree_Node_S *)malloc(sizeof(BinaryTree_Node_S));
		if(*T == NULL)
		{
			printf("\n input 4\n");
			//exit(OVERFLOW);
			return;
		}
		(*T)->m_nValue = ch;
		CreatBinaryTree(&((*T)->pLeft));
		printf("\n input 7\n");
		CreatBinaryTree(&((*T)->pRight));
		printf("\n input 5\n");
	}
	printf("\n input 6\n");
	return;
}

void VistRootNode(BinaryTree_Node_S * pRoot)
{
	if(pRoot == NULL)
	{
		return;
	}
	printf("%c\n",pRoot->m_nValue);
	return;
}
//前序遍历二叉树
void PreOrderTraverse(BinaryTree_Node_S * pRoot)
{
	if(pRoot == NULL)
	{
		return;
	}
	VistRootNode(pRoot);
	PreOrderTraverse(pRoot->pLeft);
	PreOrderTraverse(pRoot->pRight);
	return;
}
//中序遍历
void MidOrderTraverse(BinaryTree_Node_S * pRoot)
{
	if(pRoot == NULL)
	{
		return;
	}
	
	PreOrderTraverse(pRoot->pLeft);
	VistRootNode(pRoot);
	PreOrderTraverse(pRoot->pRight);
	return;
}

//后续遍历
void PostOrderTraverse(BinaryTree_Node_S * pRoot)
{
	if(pRoot == NULL)
	{
		return;
	}

	PreOrderTraverse(pRoot->pLeft);
	
	PreOrderTraverse(pRoot->pRight);

	VistRootNode(pRoot);

	return;
}
int _tmain(int argc, _TCHAR* argv[])
{
	BinaryTree_Node_S *T;
	printf("\n input 0");
	CreatBinaryTree(&T);
	PreOrderTraverse(T);
	MidOrderTraverse(T);
	PostOrderTraverse(T);
	system("pause");
	return 0;
}

