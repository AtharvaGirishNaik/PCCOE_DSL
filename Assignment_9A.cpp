//ASSIGNMENT  9A

// Title : Write a program to implement waiting list in a restaurant by using a queue  1) Add 2) Seat 3) Display List 

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :
#include <iostream>
#include<string>
#include<vector>
using namespace std;
class waitlist{
        public:
    string name;
    int size;
 
    int frnt = -1 ; int rear = -1;
    vector <string> wait;
    // waitlist(){
    //     size = 10;
    //     wait(10);
    // }
    void add(){
        if(frnt == size - 1){cout<<"LIST IS FULL "<<endl; return;}
        if(rear == -1){
            frnt ++;
        }
        string str;
        cout<<"ENTER YOUR NAME"<<endl;
        cin>>str;
        rear ++;
        wait.push_back(str);
        cout<<"Added "<<str<<" To the Waiting list"<<endl;
    }
    void seat(){
        if(frnt >= 9 || frnt > wait.size() - 1){
             cout<<"Frnt = "<<frnt<<endl;
            cout<<"Nobody is in the waiting list MAte ! "<<endl;
            return;
            }else{
                cout<<"Frnt = "<<frnt<<endl;
            cout<<wait[frnt]<<"  IS SEATED"<<endl;
            wait[frnt] = " ";
            frnt++;
            }
    }
    void display() {
        if (frnt >= 9 || frnt > wait.size() - 1) {
            cout << "The waiting list is empty." << endl;
            return;
        }
        cout << "Current Waiting List:" << endl;
        for (const auto& name : wait) {
            cout << name << endl;
        }
    }
};
int main() {
    int ch;
    waitlist w;
    
    cout<<" 1)ADD 2)SEAT 3)DISPLAY 4)EXIT"<<endl;
    
    do{
        cout<<"Enter choice :: "<<endl;
        cin>>ch;
        
        switch(ch){
            case 1:
            w.add();
            break;
            
            case 2:
            w.seat();
            break;
            
            
            case 3:
            w.display();
            break;
            
            case 4:
            cout<<"Closing For The Day !!!!!!!"<<endl;
            break;
            
            default:
            cout<<"Don't push the wrong buttons mate ... NOTCOOL !!@"<<endl;
        }
    }while(ch != 4);
    return 0;
}


//OUTPUT :: 

//  1)ADD 2)SEAT 3)DISPLAY 4)EXIT
// Enter choice :: 
// 1
// ENTER YOUR NAME
// Atharvca
// Added Atharvca To the Waiting list
// Enter choice :: 
// 1
// ENTER YOUR NAME
// Alonso
// Added Alonso To the Waiting list
// Enter choice :: 
// 1
// ENTER YOUR NAME
// Seb
// Added Seb To the Waiting list
// Enter choice :: 
// 1
// ENTER YOUR NAME
// Max
// Added Max To the Waiting list
// Enter choice :: 
// 3
// Current Waiting List:
// Atharvca
// Alonso
// Seb
// Max
// Enter choice :: 
// 2
// Frnt = 0
// Atharvca  IS SEATED
// Enter choice :: 
// 3
// Current Waiting List:
 
// Alonso
// Seb
// Max
// Enter choice :: 
// 2
// Frnt = 1
// Alonso  IS SEATED
// Enter choice :: 
// 3
// Current Waiting List:
 
 
// Seb
// Max
// Enter choice :: 
// 2
// Frnt = 2
// Seb  IS SEATED
// Enter choice :: 
// 3
// Current Waiting List:
 
 
 
// Max
// Enter choice :: 
// 2
// Frnt = 3
// Max  IS SEATED
// Enter choice :: 
// 3
// The waiting list is empty.
// Enter choice :: 
