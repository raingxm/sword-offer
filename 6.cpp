#include <stdio.h>

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructNode(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder){
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = NULL;
	root->m_pRight = NULL;
	
	if(startPreorder == endPreorder){
		return root;
	}
	
	int* rootIndexInInorder = startInorder;
	while(rootIndexInInorder <= endInorder){
		if(*rootIndexInInorder == rootValue){
			break;
		}
		rootIndexInInorder++;
	}
	
	int leftTreeNodeNums = rootIndexInInorder - startInorder;
	int rightTreeNodeNums = endInorder - rootIndexInInorder;

	if(leftTreeNodeNums > 0){
		//表示有左子树
		root->m_pLeft = ConstructNode(startPreorder+1,startPreorder+leftTreeNodeNums,
		startInorder,startInorder+leftTreeNodeNums-1);
	}

	if(rightTreeNodeNums > 0){
		//表示有右子树
		root->m_pRight = ConstructNode(endPreorder-rightTreeNodeNums+1,endPreorder,endInorder-rightTreeNodeNums+1,
		endInorder);
	}
			
	return root;
}

BinaryTreeNode* ConstructTree(int* preorder,int* inorder,int length){
	if(preorder == NULL || inorder == NULL || length <= 0){
		return NULL;
	}
	return ConstructNode(preorder,preorder+length-1,inorder,inorder+length-1);
}

// 输出先序遍历结果
void PrintPreorder(BinaryTreeNode* pRoot){
	if(pRoot != NULL){
		printf("%d ",pRoot->m_nValue);
		if(pRoot->m_pLeft != NULL){
			PrintPreorder(pRoot->m_pLeft);
		}
		
		if(pRoot->m_pRight != NULL){
			PrintPreorder(pRoot->m_pRight);
		}
	}
}

void Test(int* preorder,int* inorder,int length){
	BinaryTreeNode* pRoot = ConstructTree(preorder,inorder,length);	
	printf("excepted:\n");
	for(int i=0;i<length;i++){
		printf("%d ",preorder[i]);
	}
	printf("\n");
	
	printf("actual:\n");
	PrintPreorder(pRoot);
	printf("\n");
}

void Test1(){
	int preorder[] = {1};
	int inorder [] = {1};
	int length = 1;
	printf("Test1:\n");
	Test(preorder,inorder,length);
}

void Test2(){
	int preorder[] = {1,2,4,7,3,5,6,8};
	int inorder [] = {4,7,2,1,5,3,8,6};
	int length = 8;
	printf("Test2:\n");
	Test(preorder,inorder,length);
}

void Test3(){
	int preorder[] = {2,6,10,7,8,3};
	int inorder [] = {10,6,7,2,3,8};
	int length = 6;
	printf("Test3:\n");
	Test(preorder,inorder,length);
}

int main(){
	Test1();
	Test2();
	Test3();	
	return 0;
}