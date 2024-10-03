// ASSIGNMENT 5

// Title : Implement a navigation system for a delivery service using a circular linked list to represent routes. The navigation system should support the following functionalities: a. Add route b. Remove route 
            // c. Display route

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :
// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>

using namespace std;

class node{
    public:
    string rt;
    node *nxt;
    
    node(){
        nxt = NULL;
    }
    
    void get(){
        cout<<rt<<endl;
    }
    
    void set(){
        cout<<"Enter Route "<<endl;
        cin>>rt;
    }
};

class list{
    public:
    node *head;
    
    list(){
        head = NULL;
    }
    
    void insert(){
        node *nn = new node();
        nn->set();
        if(head == NULL){
            head = nn;
            nn->nxt = head;
        }else{
            node *tmp = head;
            while(tmp->nxt != head){tmp = tmp->nxt;}
            tmp->nxt = nn;
            nn->nxt = head;
        }
    }
    void insertAt(){
        int pos;
        cout<<"Insert location to insert At"<<endl;
        cin>>pos;
        node *nn = new node();
        nn->set();
        
        if(pos == 1){
         nn->nxt = head;
         head = nn;
        }else{
            node *tmp = head;
            int cnt = 1; 
            while(tmp->nxt != head && cnt < pos-1){
                tmp = tmp->nxt;
                cnt++;
            }
            if(cnt == pos-1){
            if(tmp->nxt->nxt == head){
                tmp->nxt = nn;
                nn->nxt=head;
                return;
            }else{
                nn->nxt = tmp->nxt;
                tmp->nxt = nn;
                return;
            }
            }
        }
    }  
    
    void remv(){
        string s;
        cout<<"ENter Node to remove "<<endl;
        cin>>s;
        node *tmp = head;
        if(head == NULL){
            cout<<"Empty List"<<endl;
            return;
        }else if(head->rt == s){
            head = head->nxt;
            delete tmp;
            return;
        }else{
            node *prv = NULL;
            while(tmp->nxt != head){
               if(tmp->rt == s){
                   if(tmp->nxt == head){
                       prv->nxt = head;
                       delete tmp;
                       return;
                   }else{
                       prv->nxt = tmp->nxt;
                       delete tmp;
                       return;
                   }
               }else{
                   prv = tmp;
                   tmp = tmp->nxt;
               }
            }
             cout<<"Route Not Found "<<endl;
        }4
    }
    void display(){
        if(head == NULL){
            cout<<"EMPTY "<<endl;
        }else{
            node *tmp = head;
            tmp->get();
            tmp = tmp->nxt;
            while(tmp != head){
                tmp->get();
                tmp = tmp->nxt;
            }
        }
    }
};

int main() {
    int ch;
    list l;
    
    cout<<"1) Insert 2) Insert At 3) Remove 4) Display Routes 5) Exit"<<endl;
    
    do{
        cout<<"Enter Choice"<<endl;
        cin>>ch;
        
        switch(ch){
            case 1:
            l.insert();
            break;
            
            case 2:
            l.insertAt();
            break;
            
            case 3:
            l.remv();
            break;
            
            case 4:
            l.display();
            break;
            
            case 5:
            cout<<"EXiting !!!"<<endl;
            break;
            
            default:
            cout<<"Invalid Choice "<<endl;
        }
    }while( ch != 5 );

    return 0;
}

//OUTPUT :: 

// 1) Insert 2) Insert At 3) Remove 4) Display Routes 5) Exit
// Enter Choice
// 1
// Enter Route 
// 1
// Enter Choice
// 1
// Enter Route 
// 2
// Enter Choice
// 1
// Enter Route 
// 3
// Enter Choice
// 1
// Enter Route 
// 4
// Enter Choice
// 1
// Enter Route 
// 5
// Enter Choice
// 4
// 1
// 2
// 3
// 4
// 5
// Enter Choice
// 3
// ENter Node to remove 
// 3
// Enter Choice
// 4
// 1
// 2
// 4
// 5
// Enter Choice
// 4
// 1
// 2
// 4
// 5
// Enter Choice
// 5
// EXiting !!!
