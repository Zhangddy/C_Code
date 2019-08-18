#include "BTree.h"
#include "queue.h"
#include "stack.h"
int main()
{
	
	BTNode * root = BinaryTreeCreate("ABD#GI##J###CE#HK###F##");

	BinaryTreePrevOrder(root);
	putchar('\n');
	BinaryTreeInOrder(root);
	putchar('\n');
	BinaryTreePostOrder(root);
	putchar('\n');

	BinaryTreeLevelOrder(root);
	putchar('\n');

	BinaryTreePrevOrderNonR(root);
	putchar('\n');

	BinaryTreeDestory(root);

	system("pause");
	return 0;
}