#include <iostream>
using namespace std;
class graph
{
	struct node
	{
		int data;
		node *next;
	};
public:
	node *head[20], *stack[20], *Q[20];
	int no, top, front, rear;
	int visited[20];

	graph()
	{
	  top = -1;
	  front = 0;
	  rear = 0;
	}

	void push(node *v)
	{
	   stack[++top] = v;
	}

	node *pop()
	{
	   return(stack[top--]);
	}

	int empty()
	{
	    if(top == -1)
		return 1;
	    else
		return 0;
	}

	void queue(node *v)
	{
		Q[rear++] = v;
	}

	node *dequeue()
	{
		return(Q[front++]);
	}

	int Qempty()
	{
		if(front == rear)
			return 1;
		else
			return 0;
	}

	void display();
	void insert_edge(int, int);
	void DFS();
	void BFS();
};
void graph :: insert_edge(int v1, int v2)
{
	node *n, *f, *h;
	h = new node;
	h->data = v1;
	h->next = NULL;
	n = new node;
	n->data = v2;
	n->next = NULL;
	f = head[v1];
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
void graph :: display()
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
}
void graph :: DFS()
{
   node *v, *f;
   while(!empty())
   {
       f = pop();
       if(visited[f->data] == 0)
       {
		visited[f->data] = 1;
		v = head[f->data];
		cout<<" "<<v->data;
		v = v->next;
		while(v)
		{
			push(v);
			v = v->next;
		}
	}
   }
}
void graph :: BFS()
{
   node *v, *f;
   while(!Qempty())
   {
       f = dequeue();
       if(visited[f->data] == 0)
       {
		visited[f->data] = 1;
		v = head[f->data];
		cout<<" "<<v->data;
		v = v->next;
		while(v)
		{
			queue(v);
			v = v->next;
		}
	}

   }
}

int main()
{
	graph g, *h;
	int choice, v1, v2, ver;
	int i;
	char ch;

	cout<<"\n Enter the number of vertices in graph:";
	cin>>g.no;
	for(i = 0; i<g.no; i++)
	{
		g.head[i] = NULL;
		g.visited[i] = 0;
	}
	do{
		cout<<"\n Enter edge (V1, V2)";
		cin>>v1>>v2;
		g.insert_edge(v1, v2);
		g.insert_edge(v2, v1);
		cout<<"\n Do u want more edge(y/n)";
		cin>>ch;
	}while(ch == 'y');
	cout<<"\n The adjacency list of the graph is \n";
	g.display();
	cout<<"\n Now perform Traversing"<<endl;
	do{
		cout<<"\n Press"
		    <<"\n \t 1. DFS"
		    <<"\n \t 2. BFS"
		    <<"\n \t 3. Exit"<<endl;
		cout<<"\n Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"\n Enter the first vertex of graph : ";
			cin>>ver;
			g.push(g.head[ver]);
			cout<<"\n The DFS Traversing of graph"<<endl;
			cout<<"\t";
			g.DFS();
			cout<<endl;
			for(i = 0; i<g.no; i++)
			{
				g.visited[i] = 0;
			}
			break;
		case 2:
			cout<<"\n Enter the first vertex of graph";
			cin>>ver;
			g.queue(g.head[ver]);
			cout<<"\n The BFS Traversing of graph"<<endl;
			cout<<"\t";
			g.BFS();
			cout<<endl;
			for(i = 0; i<g.no; i++)
			{
				g.visited[i] = 0;
			}
			break;
		default:
			exit(0);
			break;
		}
	}while(choice != 3);
	return 0;
}
