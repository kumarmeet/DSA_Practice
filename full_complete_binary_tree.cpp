#include<bits/stdc++.h>
#include<math.h>

using namespace std;

void is_full_binary_tree(int, int);
int main()
{
    vector<int> keys{1, 2, 5, 4, 7, 8, 9};
    is_full_binary_tree(2,7);
    return 0;
}

/**
      Full Binary Tree, The height of tree has contain maximum number of nodes = (2 ^ height + 1) - 1
           1   //height starts from 0
          / \
         2   5
        / \ / \
       4  7 8  9

      Full Binary Tree can be a Complete binary tree but Complete binary tree not need to Full Binary Tree
      Complete Binary Tree (Will be a height - 1 = Full Binary Tree) and last level filled from left to right

           1
          / \
         2   5
        / \
       4  7

           1   //not complete binary tree
          / \
         2   5
        /   / \
       4    8  9

    Why we need complete binary tree?
    When we insert the keys of binary tree, while inserting without blank space while copying level order
*/

void is_full_binary_tree(int height, int nodes)
{
  //nodes = (2 ^ height + 1) - 1
  //height = log base 2 (height + 1) - 1

  int max_height = (pow(2, height + 1) - 1);
  int max_nodes = (log2(nodes + 1) - 1);

  //1 height wants 1 max nodes, full binary tree
  //2 height wants 7 max nodes, full binary tree
  //3 height wants 15 max nodes, full binary tree
  //4 height wants 31 max nodes, full binary tree
  //5 height wants 63 max nodes, full binary tree
  //6 height wants 127 max nodes, full binary tree

  if(height == max_nodes && nodes == max_height && height > 0 && nodes > 0)
    cout<<"Full binary tree";
  else
    cout<<"Not a full binary tree";
}

