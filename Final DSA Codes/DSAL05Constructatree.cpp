//============================================================================
// Name        : Hello.cpp
// Author      : Dinesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//create a structure of node
class node
{
	public:
		int data;
		node *link[10];	//10-ary tree
};

class Tree
{
public:
	void insertChap(node *); //function to insert Chapter
	void insertSec(node *); //function to insert Section
	void insertSubSec(node *); //function to insert SubSection
	void display(node *);  //function to display Book Index
};

void Tree::insertChap(node *root){
	int chap;
	node *n;
	cout<<"\nHow many chapters are in the Book?";
	cin>>chap;
	for(int i = 0; i<chap; i++){
		n = new node;
		n->data = i+1;
		for(int j = 0; j<10; j++)
			n->link[j] = NULL;
		root->link[i]=n;
		insertSec(root->link[i]);
	}
}

void Tree::insertSec(node *root){
	int sec;
	node *n;
	cout<<"\nHow many sections are in the chapter "<<root->data<<"?";
	cin>>sec;
	for(int i = 0; i<sec; i++){
		n = new node;
		n->data = i+1;
		for(int j = 0; j<10; j++)
			n->link[j] = NULL;
		root->link[i]=n;
		insertSubSec(root->link[i]);
	}
}

void Tree::insertSubSec(node *root){
	int subsec;
	node *n;
	cout<<"\nHow many subsections are in the section "<<root->data<<"?";
	cin>>subsec;
	for(int i = 0; i<subsec; i++){
		n = new node;
		n->data = i+1;
		for(int j = 0; j<10; j++)
			n->link[j] = NULL;
		root->link[i]=n;
	}
}

void Tree::display(node *root){
	if(root){
		cout<<"\nBook Index";
		for(int i = 0; root->link[i]!=NULL; i++){
			node *ch;
			ch = root->link[i];
			cout<<"\n"<<ch->data<<" Chapter";
			for(int j = 0; ch->link[j]!=NULL; j++){
				node *s;
				s =  ch->link[j];
				cout<<endl;
				cout<<"\t"<<ch->data<<"."<<s->data<<" Section";
				for(int k = 0; s->link[k]!=NULL; k++){
					node *ss;
					ss = s->link[k];
					cout<<endl;
					cout<<"\t\t"<<ch->data<<"."<<s->data<<"."<<ss->data<<" Subsection";
				}
			}

		}
	}
}
int main() {
	node *root;
	Tree t;

	root = new node;	//allocate memory for new node
	root->data = 0;
	for(int i = 0; i<10; i++)
		root->link[i]=NULL;

	t.insertChap(root);
	t.display(root);

	return 0;
}
