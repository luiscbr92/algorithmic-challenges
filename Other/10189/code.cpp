#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int game = 1;
    char field[100][100];
    int rows, columns, i, j, count, ii, jj;
    string line;

    cin >> rows >> columns;
    cin.ignore();
    while(rows > 0 && columns > 0){
        for(i = 0; i < rows; i++){
            getline(cin, line);
            for(j = 0; j < columns; j++) field[i][j] = line[j];
        }

        if(game > 1) cout << endl;
        cout << "Field #" << game << ":" << endl;
        for(i = 0; i < rows; i++){
            for(j = 0; j < columns; j++){
                if(field[i][j] == '*') cout << '*';
                else{
                    count = 0;
                    for(ii = i-1; ii <= i+1; ii++){
                        if(ii < 0 || ii >= rows) continue;
                        for(jj = j-1; jj <= j+1; jj++){
                            if(jj < 0 || jj >= columns) continue;
                            if(ii == i && jj == j) continue;

                            if(field[ii][jj] == '*') count +=1;
                        }
                    }

                    cout << count;
                }
            }
            cout << endl;
        }

        cin >> rows >> columns;
        cin.ignore();
        game +=1;
    }

    return 0;
}
