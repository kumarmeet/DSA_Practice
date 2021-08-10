#include<bits/stdc++.h>
#include<math.h>

using namespace std;

void count_leaf_nodes(int);
void is_strict_binary_tree(int, int);
void max_min_nodes_strict_binary_tree(int);
void max_min_height_strict_binary_tree(int);
void internal_external_nodes_strict_binary_tree(int);

int main()
{
    internal_external_nodes_strict_binary_tree(5);
    return 0;
}

void internal_external_nodes_strict_binary_tree(int internal_nodes)
{
  cout<<"Internal nodes are -> "<<internal_nodes<<endl;
  //external nodes = internal nodes + 1
  int external_nodes = (internal_nodes + 1);
  cout<<"External nodes are -> "<<external_nodes<<endl;
}

void max_min_height_strict_binary_tree(int nodes)
{
    if(nodes <= 0)
        cout<<-1;
    else
    {
        //minimum node required, height = log base 2 (n + 1) - 1;
        int min_height = (int)log2(nodes + 1) - 1;
        //maximum height, n number of nodes = (n - 1) / 2
        int max_height = (nodes - 1) / 2;

        cout<<"Height of tree is -> "<<nodes<<endl;
        cout<<"Minimum height is -> "<<min_height<<endl;
        cout<<"Maximum height is -> "<<max_height;
    }
}

void max_min_nodes_strict_binary_tree(int height_of_tree)
{
    if(height_of_tree <= 0)
        cout<<-1;
    else
    {
        //minimum node required = (2 * height) + 1;
        int min_nodes = (2 * height_of_tree) + 1;
        //maximum nodes required = (2 ^ height + 1) - 1
        int max_nodes = (pow(2, height_of_tree + 1) - 1);

        cout<<"Height of tree is -> "<<height_of_tree<<endl;
        cout<<"Minimum nodes are -> "<<min_nodes<<endl;
        cout<<"Maximum nodes are -> "<<max_nodes;
    }
}

//strict binary tree means node degree is either 0 or 2 but not 1 or more than 2
void is_strict_binary_tree(int node, int degree)
{
  if(degree == 2)
    cout<<node<<" node has "<<degree<<" degree, this is a strict binary tree"<<endl;
  else
    cout<<node<<" has "<<degree<<" degree, this is not a strict binary tree"<<endl;
}

//for finding how many terminal/external/leaf nodes, leaf nodes direct relation with two degree nodes
void count_leaf_nodes(int two_degree_nodes)
{
  int leaf_nodes = (two_degree_nodes + 1); //degree (0) = degree (2) + 1
  cout<<"Two degree nodes is -> "<<two_degree_nodes<<" with "<<leaf_nodes<<" leaf nodes."<<endl;
}

