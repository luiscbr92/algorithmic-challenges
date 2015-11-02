#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, i, male, female;
    string line;
    bool searching_track, is_first, loop;

    cin >> cases;
    cin.ignore();
    for(c = 0; c < cases; c++){
        getline(cin, line);
        male = 0;
        female = 0;

        if(line.size() == 2){
            cout << "NO LOOP" << endl;
            continue;
        }

        for(i = 0; i < line.size(); i++){
            if(line[i] != ' '){
                if(line[i] == line[i+1]){
                    if(line[i] == 'M')  male++;
                    else                female++;
                }
                i += 2;
            }
        }
        if(male == female)  cout << "LOOP" << endl;
        else                cout << "NO LOOP" << endl;
    }

    return 0;
}
