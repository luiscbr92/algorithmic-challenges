#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, possible_spaces, i, j;
    string line;

    cin >> cases;
    cin.ignore();
    for(c = 1; c <= cases; c++){
        getline(cin, line);
        possible_spaces = line.size();

        for(i = 0; i < line.size(); i++){
            if(line[i] != '-'){
                possible_spaces--;
            }
            else{
                if(i-1 > -1 && line[i-1] == 'S')
                    possible_spaces--;
                else if(i+1 < line.size() && (line[i+1] == 'B' || line[i+1] == 'S'))
                    possible_spaces--;
                else if(i+2 < line.size() && line[i+2] == 'B')
                    possible_spaces--;
            }
        }


        cout << "Case " << c << ": " << possible_spaces << "\n";
    }

    return 0;
}
