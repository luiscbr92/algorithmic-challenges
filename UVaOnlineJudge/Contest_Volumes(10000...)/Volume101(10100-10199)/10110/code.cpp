#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    long bulbs, n;

    cin >> bulbs;
    while(bulbs != 0){
        n = (long)(sqrt(bulbs)+0.5);

        if(bulbs == n*n)    cout << "yes" << endl;
        else                cout << "no" << endl;

        cin >> bulbs;
    }

    return 0;
}
