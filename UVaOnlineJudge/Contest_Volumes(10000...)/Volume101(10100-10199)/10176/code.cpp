#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    char input;
    int current_number = 0;
    string output = "";

    while(cin >> input){
        if(input != '#'){
            current_number <<= 1;
            current_number += int(input) - '0';
            current_number %= 131071;
        }
        else{
            if(current_number == 0)     output += "YES\n";
            else                        output += "NO\n";
            current_number = 0;
        }
    }
    cout << output;

    return 0;
}
