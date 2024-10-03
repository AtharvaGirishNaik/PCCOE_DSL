// ASSIGNMENT 2B

// Title : Arrange list of Employee alphabetically using Merge Sort  

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :

// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include<cmath>
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
void print(emp a[], int n){
    for(int  i = 0 ; i < n ; i++){
        a[i].get();
    }
}
void mergesort(emp a[] , int b , int m , int e){
    int n1 , n2;
    n1 = m - b + 1;
    n2 = e - m;
    emp ar1[n1] ;
    emp ar2[n2];
    for(int i = 0 ; i < n1 ; i++){
        ar1[i] = a[b + i];
    }
    for(int i = 0 ; i < n2 ; i++){
        ar2[i] = a[m + i + 1];
    }
    int i , j , k;
    i = j = 0;
    k = b;
    
    while( i < n1 && j < n2 ){
        if( ar1[i].name <= ar2[j].name){
            a[k] = ar1[i];
            i++;
        }else{
            a[k] = ar2[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = ar1[i];
        k++;
        i++;
    }
    while(j < n2){
        a[k] = ar2[j];
        k++;
        j++;
    }
}

void merge(emp a[] , int b , int e){
    if(b < e){
        int m = floor((b + e) / 2);
        merge(a , b , m);
        merge(a , m + 1 , e);
        mergesort(a , b , m , e);
    }
}
int main(){
    int n = 16;
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
	
	merge(a , 0 , n - 1);
	
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
// ID =89   :  NAME = Zonta :: Salary = 17000
  
// After Sorting

// ID =14   :  NAME = Alonso :: Salary = 20000
// ID =20   :  NAME = GAsly :: Salary = 19000
// ID =99   :  NAME = Gio :: Salary = 45000
// ID =7   :  NAME = Kimi :: Salary = 10000
// ID =2   :  NAME = Logan :: Salary = 35000
// ID =7   :  NAME = MSC :: Salary = 70000
// ID =47   :  NAME = Mick :: Salary = 75000
// ID =3   :  NAME = Ricciardio :: Salary = 22000
// ID =55   :  NAME = Sainz :: Salary = 85000
// ID =5   :  NAME = Seb :: Salary = 50000
// ID =77   :  NAME = Val :: Salary = 11000
// ID =12   :  NAME = Yuki :: Salary = 13000
// ID =89   :  NAME = Zonta :: Salary = 17000
// ID =78   :  NAME = abc :: Salary = 18000
// ID =45   :  NAME = jim :: Salary = 11000
// ID =8   :  NAME = patrese :: Salary = 88000
