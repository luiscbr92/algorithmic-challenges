#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string input, output;
    getline(cin, input);
    output = "";

    while(getline(cin, input) && input[0] =='|')
        output += char((input[2]=='o')*64 + (input[3]=='o')*32 + (input[4]=='o')*16 + (input[5]=='o')*8 + (input[7]=='o')*4 + (input[8]=='o')*2 + (input[9]=='o'));

    cout << output;
    return 0;
}
