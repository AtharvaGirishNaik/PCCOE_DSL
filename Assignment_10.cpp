//ASSIGNMENT  10

// // Title : mplement a job scheduling system for a manufacturing plant using a double-ended queue. The system needs to efficiently manage the processing of jobs on various machines throughout the plant. Each job has a Job_priority. The system should support the following operations:
// a. Add Job
// b. Remove Job
// c. Display Job
// d. Search Job

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :

#include <iostream>
using namespace std;

class node {
public:
    int d;  // Data
    int p;  // Priority
    node *prv; // Pointer to previous node
    node *nxt; // Pointer to next node

    node() : nxt(nullptr), prv(nullptr) {}

    void set() {
        cout << "Enter data and its priority: "<<endl;
        cin >> d ;
        cin >> p;
    }

    void get() {
        cout << "Data: " << d << "  Priority: " << p << endl;
    }
};

class list {
public:
    node *head;
    node *frnt;
    node *rear;

    list() : frnt(nullptr), rear(nullptr), head(nullptr) {}

    void insertR() {
        node *nn = new node();
        nn->set();
        if (head == nullptr) {
            head = frnt = rear = nn;
        } else {
            if (rear->p <= nn->p) {
                // Insert at the rear
                rear->nxt = nn;
                nn->prv = rear;
                rear = nn;
            } else {
                // Insert in the middle or at the front
                node *tmp = rear;
                while (tmp != nullptr && tmp->p > nn->p) {
                    tmp = tmp->prv;
                }
                if (tmp) {
                    // Insert after tmp
                    nn->nxt = tmp->nxt;
                    nn->prv = tmp;
                    if (tmp->nxt) {
                        tmp->nxt->prv = nn;
                    }
                    tmp->nxt = nn;
                } else {
                    // Insert at the front
                    nn->nxt = head;
                    head->prv = nn;
                    head = nn;
                }
            }
        }
    }

    void insertF() {
        node *nn = new node();
        nn->set();
        if (head == nullptr) {
            head = frnt = rear = nn;
        } else {
            if (frnt->p >= nn->p) {
                // Insert at the front
                nn->nxt = frnt;
                frnt->prv = nn;
                frnt = nn;
                head = frnt;  // Update head to frnt
            } else {
                // Insert in the middle or at the rear
                node *tmp = frnt;
                while (tmp != nullptr && tmp->p < nn->p) {
                    tmp = tmp->nxt;
                }
                if (tmp) {
                    // Insert before tmp
                    nn->prv = tmp->prv;
                    nn->nxt = tmp;
                    if (tmp->prv) {
                        tmp->prv->nxt = nn;
                    }
                    tmp->prv = nn;
                } else {
                    // Insert at the rear
                    rear->nxt = nn;
                    nn->prv = rear;
                    rear = nn;
                }
            }
        }
    }

    void remF() {
        if (head == nullptr) {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }
        node *tmp = frnt;
        frnt = frnt->nxt;
        if (frnt) {
            frnt->prv = nullptr;
            head = frnt;
        } else {
            head = nullptr; // List is now empty
        }
        cout << "Data " << tmp->d << " deleted !!" << endl;
        delete tmp;
    }

    void remR() {
        if (head == nullptr) {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }
        node *tmp = rear;
        rear = rear->prv;
        if (rear) {
            rear->nxt = nullptr;
        } else {
            head = nullptr; // List is now empty
        }
        cout << "Data " << tmp->d << " deleted !!" << endl;
        delete tmp;
    }

    void disp() {
        if (head == nullptr) {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }
        for (node *tmp = head; tmp != nullptr; tmp = tmp->nxt) {
            tmp->get();
        }
    }

    void search() {
        if (head == nullptr) {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }
        int x;
        cout << "Enter Data to be searched: ";
        cin >> x;
        int c = 1;
        for (node *tmp = head; tmp != nullptr; tmp = tmp->nxt) {
            if (tmp->d == x) {
                cout << "Element found at position " << c << " in list." << endl;
                return;
            }
            c++;
        }
        cout << "Element NOT FOUND" << endl;
    }
};

int main() {
    int ch;
    list l;
    cout << "1) Insert Rear 2) Insert Front 3) Remove Front 4) Remove Rear 5) Display 6) Search 7) Exit" << endl;
    do {
        cout << "Enter Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                l.insertR();
                break;
            case 2:
                l.insertF();
                break;
            case 3:
                l.remF();
                break;
            case 4:
                l.remR();
                break;
            case 5:
                l.disp();
                break;
            case 6:
                l.search();
                break;
            case 7:
                cout << "Exiting !!!" << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
    } while (ch != 7);

    return 0;
}

//OUTPUT : : 
// 1) Insert Rear 2) Insert Front 3) Remove Front 4) Remove Rear 5) Display 6) Search 7) Exit
// Enter Choice: 1
// Enter data and its priority: 
// 100
// 1
// Enter Choice: 1
// Enter data and its priority: 
// 200
// 1
// Enter Choice: 1
// Enter data and its priority: 
// 300
// 2
// Enter Choice: 1
// Enter data and its priority: 
// 400
// 2
// Enter Choice: 1
// Enter data and its priority: 
// 500
// 2
// Enter Choice: 5
// Data: 100  Priority: 1
// Data: 200  Priority: 1
// Data: 300  Priority: 2
// Data: 400  Priority: 2
// Data: 500  Priority: 2
// Enter Choice: 2
// Enter data and its priority: 
// 101
// 1
// Enter Choice: 5
// Data: 101  Priority: 1
// Data: 100  Priority: 1
// Data: 200  Priority: 1
// Data: 300  Priority: 2
// Data: 400  Priority: 2
// Data: 500  Priority: 2
// Enter Choice: 2
// Enter data and its priority: 
// 600
// 3
// Enter Choice: 5
// Data: 101  Priority: 1
// Data: 100  Priority: 1
// Data: 200  Priority: 1
// Data: 300  Priority: 2
// Data: 400  Priority: 2
// Data: 500  Priority: 2
// Data: 600  Priority: 3
// Enter Choice: 3
// Data 101 deleted !!
// Enter Choice: 5
// Data: 100  Priority: 1
// Data: 200  Priority: 1
// Data: 300  Priority: 2
// Data: 400  Priority: 2
// Data: 500  Priority: 2
// Data: 600  Priority: 3
// Enter Choice: 4
// Data 600 deleted !!
// Enter Choice: 5
// Data: 100  Priority: 1
// Data: 200  Priority: 1
// Data: 300  Priority: 2
// Data: 400  Priority: 2
// Data: 500  Priority: 2
// Enter Choice: 6
// Enter Data to be searched: 500
// Element found at position 5 in list.
// Enter Choice: 7
// Exiting !!!
