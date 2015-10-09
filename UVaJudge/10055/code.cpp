#include <iostream>

using namespace std;

int main(){
    long a, b, dif;

    while(cin >> a >> b){
        dif = a - b;

        if(dif < 0) dif = -dif;

        cout << dif << "\n";
    }
}
