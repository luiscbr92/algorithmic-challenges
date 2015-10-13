#include <iostream>
#include <string>

using namespace std;

int main(){
    int cases, length;
    string line;

    cin >> cases;

    // Read first line appart from 'cases'. After this sentence line values "\n"
    getline(cin, line);

    for(int i; i < cases; i++){
        getline(cin, line);
        length = line.size();

        if(length == 3){
            if(line[0] == 'o' && line[1] == 'n' || line[0] == 'o' && line[2] == 'e' || line[1] == 'n' && line[2] == 'e')
                cout << "1\n";
            else cout << "2\n";
        }
        else cout << "3\n";

    }
}
