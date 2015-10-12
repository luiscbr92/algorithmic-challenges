#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int cases, n;

    cin >> cases;

    for (int i = 0; i < cases; i++){
        cin >> n;
        n = ((n*567/9)+7492)*235/47-498;

        cout << abs((n/10)%10) << "\n";
    }

}
