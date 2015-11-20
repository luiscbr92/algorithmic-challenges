#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, rows, columns, days, i, j, k, d;
    char cell, offensive;
    char grid[100][100];
    char aux[100][100];
    bool isFirst = true;
    string line;

    cin >> cases;
    for(i = 0; i < cases; i++){
        cin >> rows >> columns >> days;
        cin.ignore();
        if(rows == 0 && columns == 0) continue;

        for(j = 0; j < rows; j++){
            getline(cin, line);
            for(k = 0; k < columns; k++) grid[j][k] = line[k];
        }

        for(d = 0; d < days; d++){
            for(j = 0; j < rows; j++){
                for(k = 0; k < columns; k++){
                    cell = grid[j][k];

                    if(cell == 'R')         offensive = 'P';
                    else if(cell == 'P')    offensive = 'S';
                    else                    offensive = 'R';

                    if(j-1 >= 0 && grid[j-1][k] == offensive)
                        aux[j][k] = offensive;

                    else if(j+1 < rows && grid[j+1][k] == offensive)
                        aux[j][k] = offensive;

                    else if(k-1 >= 0 && grid[j][k-1] == offensive)
                        aux[j][k] = offensive;

                    else if(k+1 < columns && grid[j][k+1] == offensive)
                        aux[j][k] = offensive;

                    else aux[j][k] = cell;
                }
            }

            for(j = 0; j < rows; j++){
                for(k = 0; k < columns; k++) grid[j][k] = aux[j][k];
            }
        }

        if(i > 0 && !isFirst) cout << endl;

        for(j = 0; j < rows; j++){
            for(k = 0; k < columns; k++) cout << grid[j][k];
            cout << endl;
        }
        isFirst = false;
    }

    return 0;
}
