#include<iostream>
using namespace std;
class node
{
public:
int data;
int weight;
node *next;
};
class Graph
{
public:
node *head[20], *p[20];
int no, visited[20], span_V[20], count, min_wt;
void AdjacencyList();
void insertEdge(int, int, int);
void Prims_Algo(int v);
node *get_min_edge();
};
void Graph :: AdjacencyList()
{
int i;
node *f;
for(i = 0 ; i < no; i++)
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
}
void Graph :: insertEdge(int v1, int v2, int weight)
{
node *n, *f, *h;
//creating link from v1 to v2
h = new node;
h->data = v1;
h->next = NULL;
n = new node; //allocate memory for new node
n->data = v2; //assign vertex
n->weight = weight;
n->next = NULL; //next link will be NULL
f = head[v1]; //head vertex is v1
if(f == NULL)
{
h->next = n;
head[v1] = h;
}
else
{
while(f->next)
f = f->next;
f->next = n;
}
}
node* Graph :: get_min_edge()
{
node *f, *n;
int min_wt = 1000;
for(int i = 0; span_V[i]!=-1; i++)
{
int v = span_V[i]; //get element from set of vertex
f = head[v]; //get header node
f = f->next;
while(f)//if n != NULL
{
if(visited[f->data] == 0)
if(f->weight<=min_wt){
n = f;
min_wt = f->weight;
//cout<<"|"<<n->data<<"|"<<n->weight<<"|"<<endl;
}
f = f->next;
}
}
return n;
}
void Graph :: Prims_Algo(int v)
{
node *n;
int cost = 0;
for(int i=0; i<no; i++)
span_V[i]=-1;
int j=0;
span_V[j++]=v;
visited[v]=1;
cout<<v;
for(int i = 0; i<no-1; i++){
n = get_min_edge();
span_V[j++]=n->data;
cout<<"->|"<<n->data<<"|";
cost = cost + n->weight;
}
cout<<"\nTotal Cost = "<<cost;
}
int main()
{
Graph g;
int v, v1, v2, wt;
char ch;
cout<<"\n Enter the number of vertice in graph:";
cin>>g.no;
for(int i = 0; i<g.no; i++)
{
g.head[i] = NULL;
g.visited[i] = 0;
}
cout<<"\n Now you have to vertices of edge"
<<"\n The vertices lebel as 0 to "<<g.no-1<<endl;
do{
cout<<"\n Enter edge (V1, V2, Weight)";
cin>>v1>>v2>>wt;
g.insertEdge(v1, v2, wt);
g.insertEdge(v2, v1, wt);
cout<<"\n Do u want more edge(y/n)";
cin>>ch;
}while(ch == 'y');
cout<<"\n The adjacency list of the graph is \n";
g.AdjacencyList();
//Prims
cout<<"\n Enter the first vertex of graph : ";
cin>>v;
g.Prims_Algo(v);
return 0;
}