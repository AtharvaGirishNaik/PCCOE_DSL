//ASSIGNMENT  9B

// Title : Write a program to implement checkout list by using a Circular queue  1) Add 2) Seat 3) Check if Checkout Counter is closed 

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :

#include <iostream>
#include<string>
using namespace std;

class Motel{
  int size;
  string q[10]; 
  int frnt = -1;
  int rear = -1;
  public:
 Motel(){
     size = 10;
 } 
  void arrive(){
      string s;
      cout<<"Enter Name "<<endl;
       cin>>s;
       if((frnt == 0 && rear == size - 1 ) || rear == (frnt - 1) % (size - 1)){
           cout<<"No Rooms Available "<<endl;
           return;
       }
       else if(rear == -1){
           frnt = 0;rear = 0;
       }
       else if(rear == size - 1 && frnt != 0){
           rear = 0;
       }
       else{
           rear++;
       }
       q[rear] = s;
       cout<<"frnt = "<<frnt;
       cout<<"   REAR ="<<rear<<endl;
  }
  
  void checkout(){
      if(rear == -1){
          cout<<"No Check In's Recorded"<<endl;
      }else if(frnt == rear ){
          q[frnt] = "";
          frnt = rear = -1;
      }else if(frnt == size - 1){
          frnt = 0;
      }else{
          q[frnt] = "";
          frnt++;
      }
      cout<<"frnt = "<<frnt;
      cout<<"   REAR =  "<<rear<<endl;
  }
  
  void isClosed(){
      if(rear == -1){
          cout<<"Sorry the Checkout Counter is Closed "<<endl;
      }else{
          cout<<"The checkout Counter is Open for Checkouts"<<endl;
          cout<<"Number of checkouts Scheduled"<<endl;
          int  i = 0;
          while( i < size ){
              if(q[i] != ""){
                cout<<q[i]<<endl;
              }
              i++;
          }
      }
      cout<<"frnt = "<<frnt;
      cout<<"   REAR =  "<<rear<<endl;
  }
};
int main() {
  int ch;
  Motel m;
  cout << "1) Check-in 2) Check-Out 3) Check if Checkout Counter is Open 4) Exit"<<endl;
  do{
      cout<<"Enter Choice : : ";
      cin>>ch;
      
      switch(ch){
          case 1:
          m.arrive();
          break;
          
          case 2:
          m.checkout();
          break;
          
          case 3:
          m.isClosed();
          break;
          
          case 4:
          cout<<"Done for The Day !!"<<endl;
          break;
          
          default:
          cout<<"Nope Not an option , Stick to the Description !!"<<endl;
      }
  }while(ch != 4);
    return 0;
}

//OUTPUT :: 

// 1) Check-in 2) Check-Out 3) Check if Checkout Counter is Open 4) Exit
// Enter Choice : : 1
// Enter Name 
// Atharva 
// frnt = 0   REAR =0
// Enter Choice : : 1
// Enter Name 
// Seb
// frnt = 0   REAR =1
// Enter Choice : : 1
// Enter Name 
// Alonso
// frnt = 0   REAR =2
// Enter Choice : : 1
// Enter Name 
// Max
// frnt = 0   REAR =3
// Enter Choice : : 2
// frnt = 1   REAR =  3
// Enter Choice : : 2
// frnt = 2   REAR =  3
// Enter Choice : : 3
// The checkout Counter is Open for Checkouts
// Number of checkouts Scheduled
// Alonso
// Max
// frnt = 2   REAR =  3
// Enter Choice : : 1
// Enter Name 
// Kevin
// frnt = 2   REAR =4
// Enter Choice : : 1
// Enter Name 
// Yuki
// frnt = 2   REAR =5
// Enter Choice : : 1
// Enter Name 
// Pierre
// frnt = 2   REAR =6
// Enter Choice : : 1
// Enter Name 
// Charles
// frnt = 2   REAR =7
// Enter Choice : : 1
// Enter Name 
// Logan
// frnt = 2   REAR =8
// Enter Choice : : 1
// Enter Name 
// Albon
// frnt = 2   REAR =9
// Enter Choice : : 1
// Enter Name 
// Russell
// frnt = 2   REAR =0
// Enter Choice : : 1
// Enter Name 
// Mick
// frnt = 2   REAR =1
// Enter Choice : : 3
// The checkout Counter is Open for Checkouts
// Number of checkouts Scheduled
// Russell
// Mick
// Alonso
// Max
// Kevin
// Yuki
// Pierre
// Charles
// Logan
// Albon
// frnt = 2   REAR =  1
// Enter Choice : : 1
// Enter Name 
// Seb
// No Rooms Available 
// Enter Choice : : 3
// The checkout Counter is Open for Checkouts
// Number of checkouts Scheduled
// Russell
// Mick
// Alonso
// Max
// Kevin
// Yuki
// Pierre
// Charles
// Logan
// Albon
// frnt = 2   REAR =  1
// Enter Choice : : 2
// frnt = 3   REAR =  1
// Enter Choice : : 2
// frnt = 4   REAR =  1
// Enter Choice : : 2
// 2frnt = 5   REAR =  1
// Enter Choice : : 
// 2
// frnt = 6   REAR =  1
// Enter Choice : : 2
// frnt = 7   REAR =  1
// Enter Choice : : 2
// frnt = 8   REAR =  1
// Enter Choice : : 2
// frnt = 9   REAR =  1
// Enter Choice : : 2
// frnt = 0   REAR =  1
// Enter Choice : : 2
// frnt = 1   REAR =  1
// Enter Choice : : 2
// frnt = -1   REAR =  -1
// Enter Choice : : 2
// No Check In's Recorded
// frnt = -1   REAR =  -1
// Enter Choice : : 3
// Sorry the Checkout Counter is Closed 
// frnt = -1   REAR =  -1
// Enter Choice : : 4
// Done for The Day !!
