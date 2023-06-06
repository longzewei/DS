//算法5.1 中序遍历的递归算法
#include<iostream>
using namespace std;
typedef struct BiNode{				//二叉链表定义
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

//用算法5.3 先序遍历的顺序建立二叉链表
void CreateBiTree(BiTree &T){	
	//按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//递归结束，建空树
	else{							
		T=new BiTNode;
		T->data=ch;					//生成根结点
		CreateBiTree(T->lchild);	//递归创建左子树
		CreateBiTree(T->rchild);	//递归创建右子树
	}								//else
}									//CreateBiTree

void Copy(BiTree T, BiTree &NewT)
{ 
	if(T==NULL ) 
	{   							//如果是空树，递归结束
		NewT=NULL; 
		return; 
	} 
	else
	{
		NewT=new BiTNode;
		NewT->data= T->data;					//复制根结点
		Copy(T->lchild, NewT->lchild);    		//递归复制左子树
		Copy(T->rchild, NewT->rchild);   		//递归复制右子树
	}											//else
}												//CopyBiTree

int Depth(BiTree T)
{ 
	int m,n;
	if(T == NULL ) return 0;        //如果是空树，深度为0，递归结束
	else 
	{							
		m=Depth(T->lchild);			//递归计算左子树的深度记为m
		n=Depth(T->rchild);			//递归计算右子树的深度记为n
		if(m>n) return(m+1);		//二叉树的深度为m 与n的较大者加1
		else return (n+1);
	}
}

int NodeCount(BiTree T)
{
     if(T==NULL) return 0;  			// 如果是空树，则结点个数为0，递归结束
     else return NodeCount(T->lchild)+ NodeCount(T->rchild) +1;
     //否则结点个数为左子树的结点个数+右子树的结点个数+1
} 

void InOrderTraverse(BiTree T){  
	//中序遍历二叉树T的递归算法
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}