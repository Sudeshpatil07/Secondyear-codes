#include<iostream>
using namespace std;

class node {
private:
    char name[10];
    long prn;
    node* next;

public:
    node() : prn(0), next(nullptr) {}

    friend class list;
};

class list {
private:
    node* president;
    node* secretary;
    int count;

public:
    list() : president(nullptr), secretary(nullptr), count(0) {}

    void gethead();
    void gettail();
    void addmember();
    void displaylist();
    void remove();
    void display_count();
    void disp_rev();
    friend void display_reverse(list* a, node* head);
};

void list::gethead() {
    count++;
    cout << "Enter Name of President:" << endl;
    president = new node;
    cin >> president->name;
    cout << "Enter PRN of President:" << endl;
    cin >> president->prn;
    president->next = nullptr;
}

void list::gettail() {
    count++;
    cout << "Enter the name of the secretary:" << endl;
    secretary = new node;
    cin >> secretary->name;
    cout << "Enter PRN of secretary:" << endl;
    cin >> secretary->prn;
    secretary->next = nullptr;
}

void list::addmember() {
    count++;
    node* tmp = new node;
    cout << "Enter Member name:" << endl;
    cin >> tmp->name;
    cout << "Enter PRN of Member:" << endl;
    cin >> tmp->prn;

    if (president == nullptr || president->prn > tmp->prn) {
        tmp->next = president;
        president = tmp;
    }
    else if (tmp->prn > secretary->prn) {
        secretary->next = tmp;
        tmp->next = nullptr;
        secretary = tmp;
    }
    else {
        node* current = president;
        node* currentminus1 = nullptr;
        while (current != nullptr && current->prn < tmp->prn) {
            currentminus1 = current;
            current = current->next;
        }
        currentminus1->next = tmp;
        tmp->next = current;
    }
}

void list::display_count() {
    cout << "Member count: " << count << endl;
}

void list::displaylist() {
    node* current = president;
    while (current != nullptr) {
        cout << "Name of the Member:" << current->name << endl;
        cout << "PRN of the Member:" << current->prn << endl;
        current = current->next;
    }
}

void list::remove() {
    count--;
    long pno = 0;
    cout << "Enter the PRN of the member to be removed:" << endl;
    cin >> pno;

    node* tmp = nullptr;
    node* current = president;
    node* currentminus1 = nullptr;

    while (current != nullptr && current->prn != pno) {
        currentminus1 = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Member Not found!" << endl;
        count++;
        return;
    }

    tmp = current;

    if (currentminus1 == nullptr) {
        // Removing the first node
        president = current->next;
    }
    else {
        currentminus1->next = current->next;
    }

    delete tmp;
}

void display_reverse(list* a, node* head) {
    // Implementation of display_reverse
    // ...
}

void list::disp_rev() {
    display_reverse(this, president);
}

int main() {
    list a;
    a.gethead();
    a.gettail();
    int c = 0;
    int bl = 1;
    while (bl) {
        cout << "Enter Choice:\n1.Add Member\n2.Delete Member\n3.Display No of Members\n4.Display Members\n5.Display in Reverse\n6.Enter for another division\n";
        cin >> c;
        switch (c) {
        case 1:
            a.addmember();
            break;
        case 2:
            a.remove();
            break;
        case 3:
            a.display_count();
            break;
        case 4:
            a.displaylist();
            break;
        case 5:
            a.disp_rev();
            break;
        case 6:
            bl = 0;
            break;
        default:
            cout << "Wrong choice\n";
            break;
        }
    }

    list b;
    b.gethead();
    b.gettail();
    int ch = 0;
    int boo = 1;
    while (boo) {
        cout << "Enter Choice:\n1.Add Member\n2.Delete Member\n3.Display No of Members\n4.Display Members\n5.Display in Reverse\n6.Concatenate\n7.Exit\n";
        cin >> ch;
        switch (ch) {
        case 1:
            b.addmember();
            break;
        case 2:
            b.remove();
            break;
        case 3:
            b.display_count();
            break;
        case 4:
            b.displaylist();
            break;
        case 5:
            b.disp_rev();
            break;
        case 6:
            // Concatenate logic goes here
            break;
        case 7:
            boo = 0;
            break;
        default:
            cout << "Wrong choice\n";
            break;
        }
    }

    return 0;
}