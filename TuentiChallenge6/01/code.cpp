#include <iostream>

using namespace std;

int main(){

    int cases, dinners, i, tables;
    string output;

    cin >> cases;

    for(i = 1; i <= cases; i++){
        cout << "Case #" << i << ": ";
        cin >> dinners;

        if(dinners == 0)
            cout << 0 << '\n';
        else if(dinners <= 4)
            cout << 1 << '\n';
        else{
            tables = 0;
            while(dinners > 4){
                tables++;
                dinners -= 2;
            }
            tables++;
            cout << tables << '\n';
        }
    }

    return 0;
}
