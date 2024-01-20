#include<bits/stdc++.h>
using namespace std;

#define rn(i, n) for(int i = 0; i < n; i++)


int main(){
    int t, c1=0, c2=0;
    cin >>t;
    while(t--){
        int x, y;
        cin >> x >> y;
        if(x < 0){
            c1++;
        }else c2++;
  
    }
    if(c1 == 0 || c2 == 0) {cout << "YES" << endl;}
    else if (c1 == 1 || c2 == 1) {
        cout << "YES" << endl;
        }
    else cout << "NO" << endl;
    
}