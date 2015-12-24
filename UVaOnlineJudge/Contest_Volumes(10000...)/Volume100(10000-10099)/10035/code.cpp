#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int a, b;
    int index, carry_operations, current_carry, aa, bb;

    cin >> a >> b;

    while(a != 0 || b != 0){
        current_carry = 0;
        carry_operations = 0;

        while(a != 0 || b != 0){
            if(a%10 + b%10 + current_carry > 9){
                carry_operations++;
                current_carry = 1;
            }
            else current_carry = 0;
            a /= 10;
            b /= 10;
        }

        if(carry_operations == 0)       cout << "No carry operation.\n";
        else if(carry_operations == 1)  cout << "1 carry operation.\n";
        else                            cout << carry_operations << " carry operations.\n";

        cin >> a >> b;
    }

    return 0;
}
