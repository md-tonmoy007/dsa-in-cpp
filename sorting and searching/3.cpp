#include<bits/stdc++.h>
using namespace std;

#define rn(i, n) for(int i = 0; i < n; i++)


int main(){
    int t;
    int count = 0;
    cin >> t;

    string s;

    cin >> s;
    rn(i, t){
        if(s[i] == 'x'){
            count = 0;
            break;
        }
        if(s[i] == 'o'){
            count++;
        }
    }

    if(count>0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}