#include<iostream>

using namespace std;
#define ll  long long


int main()
{
    ll number;
    ll status = 0;
    cin >> number;

    while(number>0){
        if (number % 10 == 4 || number % 10 == 7)
        {
            status += 1;
        }
        number /= 10;
        

    }
    if(status == 4 || status == 7){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}