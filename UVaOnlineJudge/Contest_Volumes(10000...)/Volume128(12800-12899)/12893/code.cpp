#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, count;
    long long input;

    cin >> cases;
    while(cases--){
        count = 0;
        cin >> input;
        while(input != 0){
            if(input%2 == 1) count++;
            input /= 2;
        }
        cout << count << "\n";
    }

    return 0;
}
