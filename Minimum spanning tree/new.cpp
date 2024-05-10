#include<bits/stdc++.h>
#include<iostream>
 
using namespace std;
 
int myFunction(int n, vector<int>&myList){
    if(n == 1){
        return n;
    }

    return myList[n] = myFunction(n-1, myList);
}
int main(){
    int n = 5;
    vector<int>myList(n,0);

    myFunction(n, myList);

    for (int i= 0; i < n; i++)
    {
        cout << myList[i] << endl;
    }

 
}