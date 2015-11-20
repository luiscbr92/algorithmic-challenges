#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int letters[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    int cases, i, j, length, ascii, presses;
    string s;

    cin >> cases;
    cin.ignore();
    for(i = 1; i <= cases; i++){
        getline(cin, s);
        length = s.size();
        presses = 0;

        for(j = 0; j < length; j++){
            if(s[j] != ' '){
                ascii = (int)s[j];
                presses += letters[ascii-97];
            }
            else presses += 1;
        }

        cout << "Case #" << i << ": " << presses << endl;
    }

    return 0;
}
