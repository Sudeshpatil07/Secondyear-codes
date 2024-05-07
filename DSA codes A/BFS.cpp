#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Node
{
public:
int data;
Node *next;
};
class Graph
{
public:
stack <Node*> st;
queue <Node*> q;
Node *head[30];
int no, v[30];
void adjacencyList();
void insertEdge(int, int);
void dfs();
void bfs();
};
void Graph :: insertEdge (int v1,int v2)
{
Node *a, *b, *c;
a = new Node;
a->data = v1;
a->next = NULL;
b = new Node;
b->data = v2;
b->next = NULL;
c = head[v1];
if (c == NULL)
{
a->next = b;
head[v1] = a;
}
else
{
while (c->next)
c = c->next;
c->next = b;
}
};
void Graph :: adjacencyList()
{
int i;
Node *f;
for (int i = 0; i < no; i++)
{
cout<<endl;
f = head[i];
while(f)
{
cout<<"\t"<<f->data;
f = f->next;
}
}
cout<<endl;
};
void Graph :: dfs()
{
Node *a, *b;
while (!st.empty())
{
b = st.top();
st.pop();
if (v[b->data] == 0)
{
v[b->data] = 1;
a = head[b->data];
cout<<" "<<a->data;
a = a->next;
while(a)
{
st.push(a);
a = a->next;
}
}
}
};
void Graph :: bfs()
{
Node *a, *b;
while (!q.empty())
{
a = q.front();
q.pop();
if (v[a->data] == 0)
{
v[a->data] = 1;
b = head[a->data];
cout<<" "<<b->data;
b = b->next;
while(b)
{
q.push(b);
b = b->next;
}
}
}
};
int main()
{
Graph g;
int v1,v2,v3;
char ch;
cout<<"\n Enter number of vertices :";
cin>>g.no;
for (int i = 0; i < g.no; i++)
{
g.head[i] = NULL;
g.v[i] = 0;
}
cout<<"\n Vertices of edge";
cout<<"\n The vertices are labelled from 0 to "<<g.no-1<<endl;
do
{
cout<<"\n Enter the edge (v1,v2)";
cin>>v1>>v2;
g.insertEdge(v1,v2);
g.insertEdge(v2,v1);
cout<<"\n Are more edges to be included ?";
cin>>ch;
}while (ch == 'y');
cout<<"\n The adjacency list is :"<<endl;
g.adjacencyList();
cout<<"\n Enter 1st vertex of graph :";
cin>>v3;
g.st.push(g.head[v3]);
cout<<"\n dfs :"<<endl;
g.dfs();
cout<<endl;
for (int i =0; i < g.no; i++)
g.v[i] = 0;
cout<<"\n Enter 1st vertex of graph :";
cin>>v3;
g.q.push(g.head[v3]);
cout<<"\n bfs :"<<endl;
g.bfs();
cout<<endl;
return 0;
}