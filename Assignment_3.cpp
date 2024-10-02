
// ASSIGNMENT 3
// Title : Consider the playlist in a music player. Implement a playlist feature in music player application using singly linked list. Each song in the playlist is represented as a node in the linked list. Each node contains information about the song (such as title or artist or duration, etc.). The playlist should allow users to:  
      // a. Add songs 
      // b. Remove songs 
      // c. Display the entire playlist 
      // d. Play specific songs

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :
#include <iostream>
#include <cmath>
#include<string>
using namespace std;
class song{
  public:
  string na;
  song *nxt;
  
  song(){
      nxt = NULL;
  }
  
  void get(){
      cout<<"Song Name : : "<<na<<endl;
  }
  
  void set(){
      cout<<"Enter Song Name "<<endl;
      cin>>na;
  }
};

class list{
  public:
  song *head;
  
  list(){
      head = NULL;
  }
  
  void insert(){
      song *nn = new song();
      nn->set();
      if(head == NULL){
          head = nn;
      }else{
          song *tmp = head;
          while(tmp->nxt != NULL){
              tmp = tmp -> nxt;
          }
          tmp->nxt = nn;
      }
  }
  
  void removes(){
      string s;
      cout<<"Enter Song to Delete "<<endl;
      cin>>s;
      song *tmp = head;
      if(head == NULL){
          cout<<"List is Empty"<<endl;
          return;
      }else if(head->na == s){
          head = head->nxt;
          delete tmp;
      }else{
          song *prv = NULL;
          while(tmp != NULL){
              if(tmp -> na == s){
                  prv->nxt = tmp->nxt;
                  delete tmp;
                  return;
              }else{
                  prv = tmp;
                  tmp = tmp->nxt;
              }
          }
          cout<<"Song "<< s << "  Doesn't Exist"<<endl;
      }
  }
  
  void display(){
      if(head == NULL){
          cout<<"List is Empty";
      }else{
          song *tmp = head;
          while(tmp != NULL){
              tmp->get();
              tmp = tmp->nxt;
          }
      }
  }
  
  void play(){
      string s;
      cout<<"Enter Song to play "<<endl;
      cin>>s;
      if(head == NULL){
          cout<<"List is  Empty";
      }else{
          song *tmp = head;
          while(tmp != NULL){
              if(tmp->na == s){
                  cout<<"Now PLAYING "<<s<<"  !!!!!"<<endl;
                  return;
              }else{
                  tmp = tmp->nxt;
              }
          }
          cout<<"Song "<<s<<"  Doesn't Exist !!!!"<<endl;
      }
  }
};
int main() {
    int ch;
    list l;
    string s;
    cout<<"1) Insert  2) Delete  3) Display  4)Play  5)EXIT "<<endl;
    do{
        cout<<"Enter Choice"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            l.insert();
            break;
            
            case 2:
            l.removes();
            break;
            
            case 3:
            l.display();
            break;
            
            case 4:
            l.play();
            break;
            
            default:
            cout<<"Invalid Choice"<<endl;
        }
    }while(ch != 5);
  return 0;
}

// Output: 

// 1) Insert  2) Delete  3) Display  4)Play  5)EXIT 
// Enter Choice
// 1
// Enter Song Name 
// song1
// Enter Choice
// 1s
// Enter Song Name 
// ong2
// Enter Choice
// 1s
// Enter Song Name 
// song3
// Enter Choice
// 1s
// Enter Song Name 
// song3
// Enter Choice
// 1
// Enter Song Name 
// song4
// Enter Choice
// 3
// Song Name : : song1
// Song Name : : ong2
// Song Name : : song3
// Song Name : : song3
// Song Name : : song4
// Enter Choice
// 2
// Enter Song to Delete 
// song3
// Enter Choice
// 3
// Song Name : : song1
// Song Name : : ong2
// Song Name : : song3
// Song Name : : song4
// Enter Choice
// 4
// Enter Song to play 
// song4
// Now PLAYING song4  !!!!!
// Enter Choice
// 4
// Enter Song to play 
// ssong
// Song ssong  Doesn't Exist !!!!
