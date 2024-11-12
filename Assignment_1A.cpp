
// ASSIGNMENT 1B
// Title : Design a roll call list, arrange list of students according to roll numbers in ascending order using Insertion Sort 

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :
#include <iostream>
#include<string>
using namespace std;
class stud{
  public:
  int rl;
  string name;
  float sgpa;
  void get(){
      cout<<"ROLL NO :: "<<rl<<"  NAME :: "<<name<<"  SGPA ::  "<<sgpa<<endl;
  }
};
void insert(stud s[] , int n){
    for(int i = 1 ; i < n ; i++){
        stud key = s[i];
        int j = i-1;
        while(j >= 0 && s[j].rl > key.rl){
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}
void printar(stud s[] , int n){
    for(int i = 0 ; i < n ; i++){
        s[i].get();
    }
} 
int main() {
    int n = 15;
    stud s[n] = {
        {5 , "Seb" , 5.0},
        {14, "Alonso" , 2.0},
        {7 , "MSC" , 7.0},
        {99 , "Gio" , 4.5},
        {77 , "Val" , 1.1},
        {7 , "Kimi" , 1.0},
        {45 , "jim" , 1.1},
        {78 , "abc" , 1.8},
        {12 , "Yuki" , 1.3},
        {20 , "GAsly" , 1.9},
        {3 , "Ricciardio" , 2.2},
        {2 , "Logan" , 3.5},
        {47 , "Mick" , 7.5},
        {55 , "Sainz" , 8.5},
        {8 , "patrese",8.8},
        {89 , "Zonta" , 1.7}  
    };
    cout << "ORIGINAL  : "<<endl;
    printar(s,n);
    cout<<"After sorting : : "<<endl;
    insert(s,n);
    printar(s,n);

    return 0;
}

//OUTPUT :: 

// ORIGINAL  : 
// ROLL NO :: 5  NAME :: Seb  SGPA :: 5
// ROLL NO :: 14  NAME :: Alonso  SGPA :: 2
// ROLL NO :: 7  NAME :: MSC  SGPA :: 7
// ROLL NO :: 99  NAME :: Gio  SGPA :: 4.5
// ROLL NO :: 77  NAME :: Val  SGPA :: 1.1
// ROLL NO :: 7  NAME :: Kimi  SGPA :: 1
// ROLL NO :: 45  NAME :: jim  SGPA :: 1.1
// ROLL NO :: 78  NAME :: abc  SGPA :: 1.8
// ROLL NO :: 12  NAME :: Yuki  SGPA :: 1.3
// ROLL NO :: 20  NAME :: GAsly  SGPA :: 1.9
// ROLL NO :: 3  NAME :: Ricciardio  SGPA :: 2.2
// ROLL NO :: 2  NAME :: Logan  SGPA :: 3.5
// ROLL NO :: 47  NAME :: Mick  SGPA :: 7.5
// ROLL NO :: 55  NAME :: Sainz  SGPA :: 8.5
// ROLL NO :: 8  NAME :: patrese  SGPA :: 8.8
  
// After sorting : : 

// ROLL NO :: 2  NAME :: Logan  SGPA :: 3.5
// ROLL NO :: 3  NAME :: Ricciardio  SGPA :: 2.2
// ROLL NO :: 5  NAME :: Seb  SGPA :: 5
// ROLL NO :: 7  NAME :: MSC  SGPA :: 7
// ROLL NO :: 7  NAME :: Kimi  SGPA :: 1
// ROLL NO :: 8  NAME :: patrese  SGPA :: 8.8
// ROLL NO :: 12  NAME :: Yuki  SGPA :: 1.3
// ROLL NO :: 14  NAME :: Alonso  SGPA :: 2
// ROLL NO :: 20  NAME :: GAsly  SGPA :: 1.9
// ROLL NO :: 45  NAME :: jim  SGPA :: 1.1
// ROLL NO :: 47  NAME :: Mick  SGPA :: 7.5
// ROLL NO :: 55  NAME :: Sainz  SGPA :: 8.5
// ROLL NO :: 77  NAME :: Val  SGPA :: 1.1
// ROLL NO :: 78  NAME :: abc  SGPA :: 1.8
// ROLL NO :: 99  NAME :: Gio  SGPA :: 4.5
