#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int chars, i;

    cin >> chars;
    cin.ignore();
    string line0, line1, line2, line3, line4;
    getline(cin, line0);
    getline(cin, line1);
    getline(cin, line2);
    getline(cin, line3);
    getline(cin, line4);

    for(i = 0; i < chars; i++){
        // Detect 1
        if(line0[4*i] == '.') cout << 1;

        // Detect 2
        else if(line3[4*i] == '*') cout << 2;

        else cout << 3;
    }
    cout << endl;

    return 0;
}
