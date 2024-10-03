
// ASSIGNMENT 6

// Title : Consider two polynomial expressions of any degree. Design solution to perform addition of these two polynomials with suitable data structure and display results. 

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :
// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;
class node{
    public:
    int coef;
    int pwr;
    node *nxt;
    
    node(){
        nxt = NULL;
    }
    
    void get(){
        cout<<"Coef : "<<coef<<" ^ "<< "  pwr : "<<pwr<<endl;
    }
};

class list{
    public:
    node *head;
    
    list(){
        head = NULL;
    }
    
    void create(int x , int y){
        node *nn = new node();
        nn->coef = x;
        nn->pwr = y;
        
        if(head == NULL){
            head = nn;
        }else{
            node *tmp = head;
            while(tmp->nxt != NULL){
                tmp = tmp->nxt;
            }
            tmp->nxt = nn;
        }
    }
    
    void merge(list l1 , list l2){
        node *p1 = l1.head;
        node *p2 = l2.head;
        node *res = new node();
        node *tmp = res;
        
        while(p1 != NULL && p2 != NULL){
            node *nn = new node();
            if(p1->pwr > p2->pwr){
                nn->coef = p1->coef;
                nn->pwr = p1->pwr;
                p1 = p1->nxt;
            }else if(p1->pwr < p2->pwr){
                nn->coef = p2->coef;
                nn->pwr = p2->pwr;
                p2 = p2->nxt;
            }else if(p1->pwr == p2->pwr){
                nn->coef = p1->coef + p2->coef;;
                nn-> pwr = p1->pwr;
                p1 = p1->nxt;
                p2 = p2->nxt;
            }
            tmp->nxt = nn;
            tmp = tmp->nxt;
        }
        while(p1 != NULL){
            node *nn = new node();
            nn->coef = p1->coef;
            nn->pwr = p1->pwr;
            tmp->nxt = nn;
            tmp = tmp->nxt;
            p1=p1->nxt;
        }
        while(p2 != NULL){
            node *nn = new node();
            nn->coef = p2->coef;
            nn->pwr = p2->pwr;
            tmp->nxt = nn;
            tmp = tmp->nxt;
            p2=p2->nxt;
        }
         head = res->nxt;
    }
    
    void print(){
        for(node *tmp = head ; tmp != NULL ; tmp = tmp->nxt){
            tmp->get();
        }
    }
};
int main() {
    list l1,l2,l3;
   l1.create(41,7);
   l1.create(12,5);
   l1.create(65,0);
   l2.create(21,5);
   l2.create(15,2);
   
   cout<<"polynomial 1: "<<endl;
  l1.print();
   cout<<"polynomial 2: "<<endl;
   l2.print();
   
   l3.merge(l1, l2);
   cout<<"polynomial after adding p1 and p2 : "<<endl;
   l3.print();
   

    return 0;
}


//OUTPUT :: 

// polynomial 1: 
// Coef : 41 ^   pwr : 7
// Coef : 12 ^   pwr : 5
// Coef : 65 ^   pwr : 0
  
// polynomial 2: 
  
// Coef : 21 ^   pwr : 5
// Coef : 15 ^   pwr : 2
  
// polynomial after adding p1 and p2 : 

// Coef : 41 ^   pwr : 7
// Coef : 33 ^   pwr : 5
// Coef : 15 ^   pwr : 2
// Coef : 65 ^   pwr : 0
