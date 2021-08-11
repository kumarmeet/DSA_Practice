#include<bits/stdc++.h>
#include<math.h>

using namespace std;

struct node
{
    node *lchild;
    int data;
    node *rchild;
};

node* create_node(int);
void binary_tree(node **);
void pretorder(node *);
void inorder(node *);
void postorder(node *);
void iter_preorder(node *);
void iter_inorder(node *);
//void iter_postorder(node *);
void levelorder(node *);

int main()
{
    node *root = NULL;

    binary_tree(&root);

    levelorder(root);
    return 0;
}

void levelorder(node *p)
{
    queue<node*> q;
    cout<<p->data<<" ";
    q.emplace(p);

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            q.push(p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            q.push(p->rchild);
        }
    }
}

void postorder(node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " " << flush;
    }
}

//void iter_postorder(node *p)
//{
//    stack<long int> stk;
//    long int temp;
//    while (p || !stk.empty())
//    {
//        if (p)
//        {
//            stk.emplace((long int)p); //error on this line
//            p = p->lchild;
//        }
//        else
//        {
//            temp = stk.top();
//            stk.pop();
//            if (temp > 0)
//            {
//                stk.emplace(-temp);
//                p = ((node*)temp)->rchild;
//            }
//            else
//            {
//                cout << ((node*)(-1 * temp))->data << " ";
//                p = nullptr;
//            }
//        }
//    }
//}

void preorder(node *p)
{
    if (p)
    {
        cout << p->data << " " << flush;
        preorder(p->lchild);
        preorder(p->rchild);
    }
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

void inorder(node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " " << flush;
        inorder(p->rchild);
    }
}

void iter_inorder(node *p)
{
    stack<node*> s;
    while(!s.empty() || p) // stack and root will be null then loop finished
    {
        if(p)
        {
            s.emplace(p); // push address into the stack of node
            p = p->lchild; // go to left child
        }
        else //if root is null
        {
            p = s.top(); //pop out the address of node
            s.pop();
            cout<<p->data<<" "; //print data
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

