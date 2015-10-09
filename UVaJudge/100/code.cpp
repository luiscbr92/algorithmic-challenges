#include <iostream>

using namespace std;

int algorithm(int n){
    int cycle = 1;

    while (n != 1){
        cycle = cycle + 1;
        if(n%2 == 1)    n = 3*n+1;
        else            n = n/2;
    }

    return cycle;
}

int main(){
    int i, j, cycle, n, tmp, chg;

    while(cin >> i >> j){
        cycle = 0;

        cout << i << " " << j << " ";

        if(i>j){
            chg = i; i = j; j = chg;
        }

        for(n = i; n <= j; n++)
            if((tmp = algorithm(n)) > cycle) cycle = tmp;

        cout << cycle << "\n";
    }
}
