
// ASSIGNMENT 1A
// Title : Arrange list of students alphabetically using shell sort 

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :
#include <iostream>
#include<string>
#include<cmath>
using namespace std;
class stud{
  public:
  int rl;
  string name;
  float sgpa;
  void get(){
      cout<<"  NAME :: "<<name<<"  ROLL NO :: "<<rl<<"  SGPA :: "<<sgpa<<endl;
  }
};
void Shell(stud s[] , int n){
    for( int gap =floor( n / 2) ; gap > 0 ; gap /= 2 ){
        for( int i = gap ; i < n ; i++ ){
            stud key = s[i];
            int j;
            for( j = i ; j >= 0 && s[j - gap].name > key.name ; j -= gap ){
                s[j] = s[j - gap];
            }
            s[j] = key;
        }
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
    Shell(s,n);
    printar(s,n);

    return 0;
}
// OUTPUT

// ORIGINAL  : 
//   NAME :: Seb  ROLL NO :: 5  SGPA :: 5
//   NAME :: Alonso  ROLL NO :: 14  SGPA :: 2
//   NAME :: MSC  ROLL NO :: 7  SGPA :: 7
//   NAME :: Gio  ROLL NO :: 99  SGPA :: 4.5
//   NAME :: Val  ROLL NO :: 77  SGPA :: 1.1
//   NAME :: Kimi  ROLL NO :: 7  SGPA :: 1
//   NAME :: Jim  ROLL NO :: 45  SGPA :: 1.1
//   NAME :: Abc  ROLL NO :: 78  SGPA :: 1.8
//   NAME :: Yuki  ROLL NO :: 12  SGPA :: 1.3
//   NAME :: GAsly  ROLL NO :: 20  SGPA :: 1.9
//   NAME :: Ricciardio  ROLL NO :: 3  SGPA :: 2.2
//   NAME :: Logan  ROLL NO :: 2  SGPA :: 3.5
//   NAME :: Mick  ROLL NO :: 47  SGPA :: 7.5
//   NAME :: Sainz  ROLL NO :: 55  SGPA :: 8.5
//   NAME :: Patrese  ROLL NO :: 8  SGPA :: 8.8
//   NAME :: Zonta  ROLL NO :: 89  SGPA :: 1.7
// After sorting : : 
//   NAME :: Abc  ROLL NO :: 78  SGPA :: 1.8
//   NAME :: Alonso  ROLL NO :: 14  SGPA :: 2
//   NAME :: GAsly  ROLL NO :: 20  SGPA :: 1.9
//   NAME :: Gio  ROLL NO :: 99  SGPA :: 4.5
//   NAME :: Jim  ROLL NO :: 45  SGPA :: 1.1
//   NAME :: Kimi  ROLL NO :: 7  SGPA :: 1
//   NAME :: Logan  ROLL NO :: 2  SGPA :: 3.5
//   NAME :: MSC  ROLL NO :: 7  SGPA :: 7
//   NAME :: Mick  ROLL NO :: 47  SGPA :: 7.5
//   NAME :: Patrese  ROLL NO :: 8  SGPA :: 8.8
//   NAME :: Ricciardio  ROLL NO :: 3  SGPA :: 2.2
//   NAME :: Sainz  ROLL NO :: 55  SGPA :: 8.5
//   NAME :: Seb  ROLL NO :: 5  SGPA :: 5
//   NAME :: Val  ROLL NO :: 77  SGPA :: 1.1
//   NAME :: Yuki  ROLL NO :: 12  SGPA :: 1.3
//   NAME :: Zonta  ROLL NO :: 89  SGPA :: 1.7
