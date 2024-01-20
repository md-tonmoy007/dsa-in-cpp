#include<bits/stdc++.h>


#define rn(i, n) for(int i = 0; i < n; i++)
using namespace std;

int at = 10 ;
int c1 = 0;
int c2 = 0;
int m1 = 0;
int m2 = 0;

int is_in(string s, char n){
    for (int i = 0 ; i < s.size() ; i++)
    {   
        if(s[i] == n) return 1;
        else return 0;
    }

}

int main(){

    string s1, s2;
    cin >> s1 >> s2;
    
    rn(i, s1.size()){

        cout << s1[i] << endl;
        if(s1[i] == '@'){
            c1++;
            cout << c1 << endl;
            continue;
        } 
        if(!is_in(s2, s1[i])  && !is_in("atcoder", s1[i])){
            at = 0; 
            break;       
        }
        if(!is_in(s2, s1[i]) && is_in("atcoder", s1[i])){
            m1++;
        }
    }
    
    rn(i, s2.size())
    {
        if(s2[i] == '@') {
            c2++;
            continue;
        }
        if(!is_in(s1, s2[i]) && !is_in("atcoder", s2[i])){
           at = 0;
            break;
        }
        if(!is_in(s1, s2[i]) && is_in("atcoder", s2[i])){
            m2++;
        }
    }

    if(at == 0 || m1 > c2 || m2 > c1)
    {
        cout << at << m1 << c1 << c2 << m2 << endl;
        cout<< "NO" << endl;
    }
    else cout << "YES" << endl;


}