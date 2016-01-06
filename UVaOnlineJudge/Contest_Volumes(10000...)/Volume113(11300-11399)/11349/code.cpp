#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    vector<vector<long long>> matrix;
    vector<long long> tmp;
    long long size, cases, c, i, j, tmpi;
    string line;
    bool symmetric;

    cin >> cases;
    for(c = 1; c <= cases; c++){
        matrix.clear();
        cout << "Test #" << c << ": ";
        cin.ignore();
        getline(cin, line);
        line = line.substr(4);

        size = stoi(line);
        symmetric = true;

        for(i = 0; i < size; i++){
            tmp.clear();
            for(j = 0; j < size; j++){
                cin >> tmpi;
                tmp.push_back(tmpi);
            }
            matrix.push_back(tmp);
        }

        for(i = 0; i < size; i++){
            for(j = 0; j < size; j++){
                if(matrix[i][j] < 0){
                    symmetric = false;
                    break;
                }
                if(matrix[i][j] != matrix[size-i-1][size-j-1]){
                    symmetric = false;
                    break;
                }
            }
            if(!symmetric) break;
        }

        if(symmetric)   cout << "Symmetric.\n";
        else            cout << "Non-symmetric.\n";
    }

    return 0;
}
