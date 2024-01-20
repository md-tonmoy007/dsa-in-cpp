#include<bits/stdc++.h>
using namespace std;

#define rn(i, n) for(int i = 0; i < n; i++)


long long power(long long a, long long b){
    rn(i, b) {a*=a;}

    return a;
}

int main(){
    long long a, b, c, d;
    cin  >> a >> b >> c >> d;

    if (power(a, b) > power(c, d)) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    // if (pow(a, b) > pow(c, d)) cout << "YES" << endl;
    // else cout << "NO" << endl;

    
}