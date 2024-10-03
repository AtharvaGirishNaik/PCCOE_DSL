// ASSIGNMENT 4

// Title : Design a text editor using doubly linked list 1) Insert 2) Remove 3) search 4)Backwards Display 

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :
#include <iostream>
#include<string>

using namespace std;

class node{
  public:
  string text;
  node *nxt;
  node *prv;
 
  node(){
      nxt = prv = NULL;
  }
 
  void set(){
      cout<<"Enter text "<<endl;
      cin>>text;
  }
  void get(){
      cout<<text<<endl;
  }
};

class list{
    public:
    node *head;
     list(){
         head = NULL;
     }
     
     void insertSt(){
         node *nn = new node();
         nn->set();
         if(head == NULL){
             head = nn;
         }else{
             nn->nxt = head;
             head->prv = nn;
             head = nn;
         }
     }
    void insertEn(){
        node *nn = new node();
         nn->set();
        if(head == NULL){
             head = nn;
         }
        else{
             node *tmp = head;
             for( ; tmp->nxt != NULL ; tmp = tmp->nxt){}
             tmp->nxt = nn;
             nn->prv = tmp;
         }
    }
    void insert(){
        cout<<"Enter po9sition to enter at and the text"<<endl;
        int pos;
        cin>>pos;
        if(pos == 1){
            insertSt();
        }else{
           node *nn = new node();
           nn->set();
           int cnt = 1;
           
           node * tmp = head;
           for( ; tmp->nxt != NULL && cnt < pos - 1 ; tmp = tmp->nxt){
              cnt++;
           }
           
           if(cnt + 1 == pos){
               nn->nxt = tmp->nxt;
               tmp->nxt->prv = nn;
               nn->prv = tmp;
               tmp->nxt = nn;
               return;
           }else{
               insertEn();
           }
        }
    }
    
    void rem(){
        string txt;
        cout<<"Enter string to remove"<<endl;
        cin>>txt;
        
        node *tmp = head;
        if(head == NULL){
            cout<<"Empty "<<endl;
        }else if(head->text == txt){
            head  = head->nxt;
            head->prv = NULL;
            delete tmp;
            return;
        }else{
            for( ; tmp != NULL ; tmp = tmp->nxt){
                if(tmp->text == txt){
                    if(tmp->nxt == NULL){
                        tmp->prv->nxt = NULL;
                        delete tmp;
                        return;
                    }else{
                        tmp->prv->nxt = tmp->nxt;
                        tmp->nxt->prv = tmp->prv;
                        delete tmp;
                        return;
                    }
                }
            }
            if(tmp == NULL){
                cout<<"Node Not Found "<<endl;
           } 
        }
    }
    
    void search(){
        cout<<"Enter Text to search"<<endl;
        string s ;
        cin>>s;
        for(node *tmp = head ; tmp != NULL ; tmp = tmp->nxt){
            if(tmp->text == s){
                cout<<s<<" Found in the File"<<endl;
                return;
            }
        }
        cout<<s<<"  Not Found in the Fiole Kingdom from Firy Tail "<<endl;
    }
    
    void printback(){
        if(head != NULL){
            node *tmp = head;
         for( ; tmp->nxt != NULL ; tmp = tmp->nxt){}
         for(; tmp != NULL ; tmp = tmp->prv ){
             tmp->get();
         }
        }
    }
};

int main() {
    list l;
    int ch;
    cout<<"1) Insert 2)InsertAt 3)Remove 4) search 5)Backwards Display 6) Exit"<<endl;
    do{
        cout<<"Enter choice "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            l.insertEn();
            break;
            
            case 2:
            l.insert();
            break;
            
            case 3:
            l.rem();
            break;
            
            case 4:
            l.search();
            break;
            
            case 5:
            l.printback();
            break;
            
            default:
            cout<<"Invalid choice ";
        }
    }while( ch != 6 );
    return 0;
}


//OUTPUT :: 

// 1) Insert 2)InsertAt 3)Remove 4) search 5)Backwards Display 6) Exit
// Enter choice 
// 1
// Enter text 
// 1
// Enter choice 
// 1
// Enter text 
// 2
// Enter choice 
// 1
// Enter text 
// 3
// Enter choice 
// 1
// Enter text 
// 4
// Enter choice 
// 1
// Enter text 
// 5
// Enter choice 
// 1
// Enter text 
// 6
// Enter choice 
// 5
// 6
// 5
// 4
// 3
// 2
// 1
// Enter choice 
// 2
// Enter po9sition to enter at and the text
// 4
// Enter text 
// Alonso
// Enter choice 
// 5
// 6
// 5
// 4
// Alonso
// 3
// 2
// 1
// Enter choice 
// 3
// Enter string to remove
// 5
// Enter choice 
// 5
// 6
// 4
// Alonso
// 3
// 2
// 1
// Enter choice 
// 4
// Enter Text to search
// ALonso
// ALonso  Not Found in the Fiole Kingdom from Firy Tail 
// Enter choice 
// 4
// Enter Text to search
// Alonso
// Alonso Found in the File
// Enter choice 
// 6
