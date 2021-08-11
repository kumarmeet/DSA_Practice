#include<bits/stdc++.h>
#include<math.h>

using namespace std;

struct node
{
    node *lchild;
    int data;
    node *rchild;
};

node* generateFromTraversal(int *, int *, int, int);
int searchInorder(int[], int, int, int);
//Generating a unique tree from (postorder along with inorder or preorder along with inorder) 
int main()
{
    int prorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1}; //it can be post order also
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    size_t size = sizeof(prorder) / sizeof(int) - 1;
    node *root = generateFromTraversal(inorder, prorder, 0, size);

    //call any traversal function here
    return 0;
}

int searchInorder(int inArray[], int inStart, int inEnd, int data)
{
    for (int i=inStart; i<=inEnd; i++)
        if (inArray[i] == data)
            return i;
    return -1;
}

node* generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd)
{
    static int preIndex = 0;

    if (inStart > inEnd)
        return nullptr;

    node* n = create_node(preorder[preIndex++]);

    if (inStart == inEnd)
        return n;

    int splitIndex = searchInorder(inorder, inStart, inEnd, n->data);
    n->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
    n->rchild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);

    return n;
}

node* create_node(int item)
{
    node *n = new node();
    n->lchild = n->rchild = nullptr;
    n->data = item;
    return n;
}
