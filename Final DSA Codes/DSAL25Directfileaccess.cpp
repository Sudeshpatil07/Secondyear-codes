#include <iostream>
using namespace std;
class Node
{
public:
char name[10];
Node *left;
Node *right;
};
class Tree
{
public:
void insert (Node* , Node*);
void display (Node*);
};
void Tree :: insert (Node *root, Node *key)
{
char ch;
cout<<"\n Where do you want to insert the node ? (Left [L] / Right [R]) : ";
cin>>ch;
if (ch == 'L')
{
    if (root->left == NULL)
    root->left = key;
else
insert (root->left , key);
}
else
{
if (root->right == NULL)
root->right = key;
else
insert (root->right , key);
}
}
void Tree :: display (Node *root)
{
if (root)// if(root!=NULL)
{
display (root->left);
cout <<" "<< root->name <<" ";
display (root->right);
}
}
int main()
{
Tree t;
Node *root, *key;
root = new Node();
root->left = NULL;
root->right = NULL;
cout <<"\nEnter the name of the book : ";
cin >> root->name;
int n;
cout <<"\nEnter the number of chapters to be inserted in the book : ";
cin >> n;
for (int i =1; i<=n; i++)
{
key = new Node();
key->left = NULL;
key->right = NULL;
cout <<"\nEnter the name of the chapter to be inserted : ";
cin >> key->name;
t.insert (root , key);
}
t.display (root);
return 0;
}