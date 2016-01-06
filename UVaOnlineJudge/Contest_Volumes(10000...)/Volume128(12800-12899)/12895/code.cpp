#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    long input, input_copy, calculated;
    int cases, exponent;
    bool armstrong;

    cin >> cases;
    while(cases--){
        armstrong = false;
        cin >> input;
        exponent = 1;

        while(exponent < 10){
            calculated = 0;
            input_copy = input;
            while(input_copy != 0){
                calculated += pow(input_copy%10, exponent);
                input_copy /= 10;
            }
            if(calculated == input){
                armstrong = true;
                break;
            }
            exponent++;
        }

        if(armstrong)   cout << "Armstrong\n";
        else            cout << "Not Armstrong\n";
    }

    return 0;
}
