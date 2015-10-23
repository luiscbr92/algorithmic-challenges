#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string line;
    string result = "";
    int i, ascii;

    getline(cin, line);
    getline(cin, line);

    while(line[0] != '_'){
        ascii = 0;

        for(i = 2; i < 6; i++){
            ascii <<= 1;
            if(line.at(i) == 'o'){
                ascii |= 1;
            }
        }

        for(i = 7; i < 10; i++){
            ascii <<= 1;
            if(line.at(i) == 'o') ascii |= 1;
        }
        result += (char)ascii;

        getline(cin, line);
    }
    cout << result;

    return 0;
}
