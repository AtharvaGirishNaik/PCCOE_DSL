
// ASSIGNMENT 1C
// Title : Arrange list of students to find out first ten toppers from a class using Radix sort   

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
int getmax(stud s[] , int n){
    int max = int((s[0].sgpa)*100);
    for(int i = 1 ; i < n ; i++){
        if(max < int((s[i].sgpa)*100)){
            max = int((s[i].sgpa)*100);
        }
    }
    return max;
}
void countsort(stud s[] , int n , int pos){
    stud out[n];
    int count[10] = {0};
    for(int i = 0 ; i < n ; i++){
        int d = (int(s[i].sgpa*100)/pos)%10;
        count[d]++;
    }
    for(int i = 8 ; i >= 0 ; i--){
        count[i] += count[i + 1];
    }
    for(int i = n - 1 ; i >= 0 ; i-- ){
        int d = (int(s[i].sgpa*100)/pos)%10;
        out[count[d]-1] = s[i];
        count[d]--;
    }
    for(int i = 0 ; i < n ; i++){
        s[i] = out[i];
    }
}
void Radix(stud s[] , int n){
    int max = getmax(s,n);
    for( int pos = 1 ; max/pos > 0 ; pos *= 10 ){
        countsort(s,n,pos);
    }
}
void printar(stud s[] , int n){
    for(int i = 0 ; i < n ; i++){
        s[i].get();
    }
} 
int main() {
    int n = 16;
    stud s[n] = {
        {5 , "Seb" , 5.3},
        {14, "Alonso" , 2.1},
        {7 , "MSC" , 7.3},
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
    cout<<" 10 TOPPERS  "<<endl;
    Radix(s,n);
    printar(s,10);

    return 0;
}

//OUTPUT :: 

// ORIGINAL  : 
//   NAME :: Seb  ROLL NO :: 5  SGPA :: 5.3
//   NAME :: Alonso  ROLL NO :: 14  SGPA :: 2.1
//   NAME :: MSC  ROLL NO :: 7  SGPA :: 7.3
//   NAME :: Gio  ROLL NO :: 99  SGPA :: 4.5
//   NAME :: Val  ROLL NO :: 77  SGPA :: 1.1
//   NAME :: Kimi  ROLL NO :: 7  SGPA :: 1
//   NAME :: jim  ROLL NO :: 45  SGPA :: 1.1
//   NAME :: abc  ROLL NO :: 78  SGPA :: 1.8
//   NAME :: Yuki  ROLL NO :: 12  SGPA :: 1.3
//   NAME :: GAsly  ROLL NO :: 20  SGPA :: 1.9
//   NAME :: Ricciardio  ROLL NO :: 3  SGPA :: 2.2
//   NAME :: Logan  ROLL NO :: 2  SGPA :: 3.5
//   NAME :: Mick  ROLL NO :: 47  SGPA :: 7.5
//   NAME :: Sainz  ROLL NO :: 55  SGPA :: 8.5
//   NAME :: patrese  ROLL NO :: 8  SGPA :: 8.8
//   NAME :: Zonta  ROLL NO :: 89  SGPA :: 1.7
//  10 TOPPERS  
//   NAME :: patrese  ROLL NO :: 8  SGPA :: 8.8
//   NAME :: Sainz  ROLL NO :: 55  SGPA :: 8.5
//   NAME :: Mick  ROLL NO :: 47  SGPA :: 7.5
//   NAME :: MSC  ROLL NO :: 7  SGPA :: 7.3
//   NAME :: Seb  ROLL NO :: 5  SGPA :: 5.3
//   NAME :: Gio  ROLL NO :: 99  SGPA :: 4.5
//   NAME :: Logan  ROLL NO :: 2  SGPA :: 3.5
//   NAME :: Ricciardio  ROLL NO :: 3  SGPA :: 2.2
//   NAME :: Alonso  ROLL NO :: 14  SGPA :: 2.1
//   NAME :: GAsly  ROLL NO :: 20  SGPA :: 1.9
