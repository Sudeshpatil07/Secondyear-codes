#include<iostream>
#include<string>

using namespace std;

struct Node{
	Node *prev;
	int seatno;
	bool Booked = false;
	string ID;
	Node *next;
};

class LinkedList{
public:
	Node *head;
	Node *tail;

	Node* CreateNode();
	Node* CreateList();
	Node* Select(int);
	void DisplayList();
};

void LinkedList::DisplayList(){
	Node *p = head;

	do{
		cout<<"Seat no. : "<<p->seatno<<"\n";
		cout<<"Seat ID : "<<p->ID<<"\n";
		p = p->next;
	}while(p->next != head);

	cout<<"Seat no. : "<<p->seatno<<"\n";
	cout<<"Seat ID : "<<p->ID<<"\n";

}

Node* LinkedList::Select(int ele){
	Node *p = head;
	int i = 0;

	do{
		if(i == ele)
			break;
		p = p->next;
		i++;
	}while(p->next != head);
	
	return p;
}

Node* LinkedList::CreateNode(){
	Node *s = new Node();
	
/*	cout<<"Enter seat no. to book"<<"\n";
	cin>>s->seatno;

	cout<<"Enter ID to book"<<"\n";
	cin>>s->ID;
*/
	s->seatno = 999;
	s->ID = "\0";
	s->next = NULL;
	s->prev = NULL;	

	return s;
}

Node* LinkedList::CreateList(){

	head = CreateNode();
	Node *q , *p = head;
	
	for(int i = 0 ; i < 6 ; i++){
		q = CreateNode();
		p->next = q;
		q->prev = p;
		p = q;		
	}
	
	tail = p;
	head->prev = tail;
	tail->next = head;	
	
	return head;
}

class Cinemax{
public:
	LinkedList list[10];
	Cinemax();
	void Display();
	void Book();
	void Cancel();
};

Cinemax::Cinemax(){
	for(int i = 0 ; i < 10 ; i++){
		LinkedList l;
		l.CreateList();
		list[i] = l;
	}
}

void Cinemax::Display(){
	for(int i = 0 ; i < 10 ; i++){
		LinkedList l = list[i];
		for(int j = 0 ; j < 7 ; j++){	
			Node *n = l.Select(j);
			if(n->Booked)
				cout<<(i)<<":"<<(j)<<" |_B_| "<<" ";
			else 
				cout<<(i)<<":"<<(j)<<" |___| "<<" ";
		}
		cout<<"\n";
	}
}

void Cinemax::Book(){
	int r , s;
	cout<<"Enter row no. and seat no. to book"<<"\n";
	cin>>r>>s;	
	LinkedList l = list[r];
	Node *n = l.Select(s);
	
	if(!n->Booked){
		cout<<"Enter Name : "<<"\n";
		cin>>n->ID;
		n->seatno = s;	
		n->Booked = true;
	}
	else{
		cout<<"Seat Booked"<<"\n";
	}

}

void Cinemax::Cancel(){
	int r , s;
	cout<<"Enter row no. and seat no. to cancel "<<"\n";
	cin>>r>>s;
	
	LinkedList l = list[r];
	Node *n = l.Select(s);

	if(n->Booked){
		n->Booked = false;
		cout<<"Ticket cancelled"<<"\n";
	}
	else {
		cout<<"Seat was vaccant"<<"\n";
	}

}


int main(){
	//LinkedList l;
	//l.CreateList();
	//l.DisplayList();

	Cinemax c;

	while(true){
		int i;	
		cout<<"-------------------------------------------------------------------------\n";
		cout<<"Enter what action to perform"<<"\n";
		cout<<"1. Book ticket"<<"\n";
		cout<<"2. Cancel ticket"<<"\n";
		cout<<"3. Display availability"<<"\n";
		cout<<"4. Exit"<<"\n";
		cin>>i;
		if(i == 1)
			c.Book();
		else if(i == 2)	
			c.Cancel();
		else if(i == 3)
			c.Display();	
		else if(i == 4)
			break;
			
	}
	return 0;
}

