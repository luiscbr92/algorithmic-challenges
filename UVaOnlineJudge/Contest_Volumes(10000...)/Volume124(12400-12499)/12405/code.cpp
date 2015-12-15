#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, length, i, scarecrops;
    string field;

    cin >> cases;
    for(c=1; c <= cases; c++){
        scarecrops = 0;
        cin >> length;
        cin.ignore();
        getline(cin, field);

        for(i = 0; i < length; i++){
            if(field[i] == '.'){
                scarecrops++;
                field[i] = '#';
                field[i+1] = '#';
                field[i+2] = '#';
                i += 2;
            }
        }
        cout << "Case " << c << ": " <<  scarecrops << "\n";
    }

    return 0;
}
