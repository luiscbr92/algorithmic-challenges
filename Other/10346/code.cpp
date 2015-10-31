#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int n, k, t, temp;

    while(cin >> n >> k){
        t = n;
        while(t >= k){
            temp = t/k;
            n += temp;
            t = temp + t%k;
        }
        cout << n << endl;
    }

    return 0;
}
