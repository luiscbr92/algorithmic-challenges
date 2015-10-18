#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);
    int cases, moves, position, i, j, pointing;
    string current_move;

    cin >> cases;
    for(i = 0; i < cases; i ++){
        position = 0;
        cin >> moves;
        int mov[moves];
        cin.ignore();

        for(j = 0; j < moves; j++){
            getline(cin, current_move);

            if(current_move == "LEFT"){
                mov[j] = -1;
                position -= 1;
            }
            else if(current_move == "RIGHT"){
                mov[j] = 1;
                position += 1;
            }
            else{
                current_move = current_move.substr(8);
                pointing = atoi(current_move.c_str());
                mov[j] = mov[pointing-1];
                position += mov[j];
            }
        }
        cout << position << endl;
    }

    return 0;
}
