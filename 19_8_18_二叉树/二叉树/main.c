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

	BinaryTreeInOrderNonR(root);
	putchar('\n');

	BinaryTreePostOrderNonR(root);
	putchar('\n');

	printf("%d \n", BinaryTreeSize(root));

	printf("%d \n", BinaryTreeLeafSize(root));


	printf("%d \n", BinaryTreeLevelKSize(root, 5));

	BTNode* cur = BinaryTreeFind(root, 'L');
	if (cur)
	{
		BinaryTreeLevelOrder(cur);
	}
	else
	{
		printf("Did Not Find!");
	}

	BinaryTreeDestory(root);
	putchar('\n');
	BTNode * root2 = BinaryTreeCreate("ABDH##I##EJ###CF##G##");

	printf("%d\n", BinaryTreeComplete(root2));



	BinaryTreeDestory(root2);
	system("pause");
	return 0;
}