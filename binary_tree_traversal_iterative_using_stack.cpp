#include<bits/stdc++.h>
#include<math.h>

using namespace std;

struct node
{
    node *lchild;
    int data;
    node *rchild;
};

void iter_preorder(node *);
node* create_node(int);
void binary_tree(node **);


int main()
{
    node *root = NULL;

    binary_tree(&root);

    iter_preorder(root);
    return 0;
}

void iter_preorder(node *p)
{
    stack<node*> s;
    while(!s.empty() || p) // stack and root will be null then loop finished
    {
        if(p)
        {
            cout<<p->data<<" "; //print data
            s.emplace(p); // push address into the stack of node
            p = p->lchild; // go to left child
        }
        else //if root is null
        {
            p = s.top(); //pop out the address of node
            s.pop();
            p = p->rchild; // go to right child of node
        }
    }
}

void binary_tree(node **r)
{
    int item{0};
    cin>>item;
    node *t = nullptr, *n = nullptr;
    (*r) = create_node(item);

    queue<node*> q;
    q.emplace(*r);

    while(!q.empty())
    {
        t = q.front();
        q.pop();
        cin>>item;
        if(item != -1)
        {
            n = create_node(item);
            t->lchild = n;
            q.emplace(n);
        }

        cin>>item;
        if(item != -1)
        {
            n = create_node(item);
            t->rchild = n;
            q.emplace(n);
        }
    }

}

node* create_node(int item)
{
    node *n = new node();
    n->lchild = n->rchild = nullptr;
    n->data = item;
    return n;
}
