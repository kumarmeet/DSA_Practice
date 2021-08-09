#include<bits/stdc++.h>
#include<math.h>

using namespace std;

void max_min_nodes(int);
void max_min_height(int);

int main()
{
    max_min_height(1);
    return 0;
}

void max_min_height(int nodes) //height is start from 0
{
    if(nodes <= 0)
        cout<<-1;
    else
    {
        //minimum node required, height = log base 2 (n + 1) - 1;
        int min_height = (int)log2(nodes + 1) - 1;
        //maximum height, n number of nodes = n - 1
        int max_height = (nodes - 1);

        cout<<"Height of tree is -> "<<nodes<<endl;
        cout<<"Minimum nodes are -> "<<min_height<<endl;
        cout<<"Maximum nodes are -> "<<max_height;
    }
}

void max_min_nodes(int height_of_tree)
{
    if(height_of_tree <= 0)
        cout<<-1;
    else
    {
        //minimum node required = height + 1;
        int min_nodes = (height_of_tree + 1);
        //maximum nodes required = (2 ^ height + 1) - 1
        int max_nodes = (pow(2, height_of_tree + 1) - 1);

        cout<<"Height of tree is -> "<<height_of_tree<<endl;
        cout<<"Minimum nodes are -> "<<min_nodes<<endl;
        cout<<"Maximum nodes are -> "<<max_nodes;
    }
}
