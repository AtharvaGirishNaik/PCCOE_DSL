// ASSIGNMENT 2A

// Title : Arrange list of employees according to EMP-ID in ascending order using Quick Sort 

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :

#include <iostream>
#include <string>

using namespace std;
class emp{
    public:
  int id;
  string name;
  int sal;
  void get(){
      cout<<"ID ="<< id << "   :  NAME = "<< name << " :: Salary = " << sal<<endl;
  }
};

void swp(emp a[] , int x , int y){
    emp t = a[x];
    a[x] = a[y];
    a[y] = t;
}

int part( emp a[] , int lo , int hi ){
    int i = lo-1;
    int p = a[hi].id;
    
    for(int j = lo ; j < hi ; j++ ){
        if(a[j].id < p){
            i++;
            swp(a , i , j);
        }
    }
    swp(a , i+1 , hi);
    return i+1;
}

void print(emp a[] , int n){
    for(int i = 0 ; i < n ; i++ ){
        a[i].get();
    }
}

void quick(emp a[] , int lo , int  hi){
    if( lo < hi ){
        int pi = part(a , lo , hi);
        quick(a , lo , pi - 1);
        quick(a , pi + 1 , hi);
    }
}
int main(){
    int n = 15;
    emp a[n] = {
        {5 , "Seb" , 50000},
        {14, "Alonso" , 20000},
        {7 , "MSC" , 70000},
        {99 , "Gio" , 45000},
        {77 , "Val" , 11000},
        {7 , "Kimi" , 10000},
        {45 , "jim" , 11000},
        {78 , "abc" , 18000},
        {12 , "Yuki" , 13000},
        {20 , "GAsly" , 19000},
        {3 , "Ricciardio" , 22000},
        {2 , "Logan" , 35000},
        {47 , "Mick" , 75000},
        {55 , "Sainz" , 85000},
        {8 , "patrese",88000},
        {89 , "Zonta" , 17000},
    };
    
   cout<<"Original Array"<<endl;
	print(a , n);
	
	quick(a , 0 , n);
	
	cout<<"After Sorting"<<endl;
	print(a , n);

    return 0;
}

//OUTPUT :: 

// Original Array
// ID =5   :  NAME = Seb :: Salary = 50000
// ID =14   :  NAME = Alonso :: Salary = 20000
// ID =7   :  NAME = MSC :: Salary = 70000
// ID =99   :  NAME = Gio :: Salary = 45000
// ID =77   :  NAME = Val :: Salary = 11000
// ID =7   :  NAME = Kimi :: Salary = 10000
// ID =45   :  NAME = jim :: Salary = 11000
// ID =78   :  NAME = abc :: Salary = 18000
// ID =12   :  NAME = Yuki :: Salary = 13000
// ID =20   :  NAME = GAsly :: Salary = 19000
// ID =3   :  NAME = Ricciardio :: Salary = 22000
// ID =2   :  NAME = Logan :: Salary = 35000
// ID =47   :  NAME = Mick :: Salary = 75000
// ID =55   :  NAME = Sainz :: Salary = 85000
// ID =8   :  NAME = patrese :: Salary = 88000
// After Sorting
// ID =2   :  NAME = Logan :: Salary = 35000
// ID =3   :  NAME = Ricciardio :: Salary = 22000
// ID =5   :  NAME = Seb :: Salary = 50000
// ID =7   :  NAME = Kimi :: Salary = 10000
// ID =7   :  NAME = MSC :: Salary = 70000
// ID =8   :  NAME = patrese :: Salary = 88000
// ID =12   :  NAME = Yuki :: Salary = 13000
// ID =14   :  NAME = Alonso :: Salary = 20000
// ID =20   :  NAME = GAsly :: Salary = 19000
// ID =45   :  NAME = jim :: Salary = 11000
// ID =47   :  NAME = Mick :: Salary = 75000
// ID =55   :  NAME = Sainz :: Salary = 85000
// ID =77   :  NAME = Val :: Salary = 11000
// ID =78   :  NAME = abc :: Salary = 18000
// ID =89   :  NAME = Zonta :: Salary = 17000
