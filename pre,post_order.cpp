#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode* left, * right;
}TreeNode;
//tree root
//            15
//     5             20
//   1             16   25

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 5,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20,&n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode* root = &n6;

//중위 순회
int inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);
		printf("[%d]", root->data);
		inorder(root->right);
	}
	return 0;
}
//전위 순회
int preorder(TreeNode* root)
{
	if (root) 
	{
		printf("[%d]", root->data);
		preorder(root->left);
		preorder(root->right);
	}
	return 0;
}
//후위 순회
int postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d]", root->data);
	}
	return 0;
}
//메인 함수
int main(void)
{
	printf("중위 순회 =");
	inorder(root);
	printf("\n");

	printf("전위 순회 =");
	preorder(root);
	printf("\n");

	printf("후위 순회 =");
	postorder(root);
	printf("\n");
	return 0;
}