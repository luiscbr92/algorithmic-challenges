#include <iostream>

using namespace std;

int main(){
    int cases, columns, northern, southern, distance, j;
    bool closed_gap;

    cin >> cases;

    for(int i = 0; i < cases; i++){
        cin >> columns;
        closed_gap = true;

        // Calculate first column distance
        cin >> northern >> southern;
        distance = northern - southern;

        // Compare with successive distances
        for(j = 1; j < columns; j++){
            cin >> northern >> southern;
            if(closed_gap && distance != northern - southern)
                closed_gap = false;
        }

        if(closed_gap)  cout << "yes\n";
        else            cout << "no\n";

        // Print an empty line between two answers
        if(i < cases - 1) cout << "\n";
    }

}
