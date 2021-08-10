#include<bits/stdc++.h>

using namespace std;

void array_representation_binary_tree(vector<int> &); // copy binary tree keys level order in array
int find_parent(int); // key / 2 ///index starts from 1
int find_lchild(int); // key * 2 + 1 // index starts from 0
int find_rchild(int); // key * 2 + 1 // index starts from 0

int main()
{
    vector<int> keys{1, 2, 5, 4, 7, 8, 9};
    array_representation_binary_tree(keys);
    return 0;
}

void array_representation_binary_tree(vector<int> &keys)
{
    /**
      Binary Tree
           1
          / \
         2   5
        / \ / \
       4  7 8  9
    */
    //fill these keys by level order
    vector<int>BT_representation =  keys;
    cout<<"Binary Tree Keys are -> ";

    for(auto i: BT_representation) //binary tree keys
        cout<<i<<" ";

    cout<<endl;
    //root node never has parent node
    cout<<"Parent of -> "<<BT_representation[0]<<" is -> "<<find_parent(0)<<" "<<endl;
    for(int k = 1; k < BT_representation.size(); k++)
        cout<<"Parent of -> "<<BT_representation[k]<<" is -> "<<BT_representation[find_parent(k - 1)]<<endl;

    //left child
    for(int k = 0; k < BT_representation.size(); k++)
    {
        if(find_lchild(k) >= BT_representation.size())
            cout<<"Left child of -> "<<BT_representation[k]<<" is -> "<<0<<endl;
        else
            cout<<"Left child of -> "<<BT_representation[k]<<" is -> "<<BT_representation[find_lchild(k)]<<endl;
    }

    //right child
    for(int k = 0; k < BT_representation.size(); k++)
    {
        if(find_lchild(k) >= BT_representation.size())
            cout<<"Right child of -> "<<BT_representation[k]<<" is -> "<<0<<endl;
        else
            cout<<"Right child of -> "<<BT_representation[k]<<" is -> "<<BT_representation[find_rchild(k)]<<endl;
    }
}

int find_rchild(int key_index)
{
  return ((2 * key_index) + 2); //right child = (2 * i) + 2
}

int find_lchild(int key_index)
{
    return ((2 * key_index) + 1); // left child = (2 * i) + 1
}

int find_parent(int key_index)
{
    return (key_index / 2); // parent node = index / 2
}


