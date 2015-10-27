#include <iostream>
#include <math.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int n;
    double p;
    long k;

    while(cin >> n){
        cin >> p;
        k = exp(log(p) / n) + 0.5;
        cout << k << endl;
    }

    return 0;
}
