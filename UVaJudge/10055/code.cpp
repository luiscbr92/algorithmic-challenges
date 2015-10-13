#include <iostream>

using namespace std;

int main(){
    unsigned long a, b, dif;

    while(cin >> a >> b){
        if(a > b)   dif = a - b;
        else        dif = b - a;

        cout << dif << "\n";
    }
}
