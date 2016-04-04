#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string input, output;
    int i, j, tam, eq;

    while(cin >> input){
        tam = input.size();
        int matrix[tam +1][tam +1];

        for(i = 0; i < tam +1; i++){
            matrix[i][0] = 0;
            matrix[0][i] = 0;
        }

        for(i = 1; i < tam +1; i++){
            for(j = 1; j < tam +1; j++){
                eq = input[i-1] == input[tam-j];
                matrix[i][j] = max(max(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1] + eq);
            }
        }

        output = "";
        i = tam;
        j = tam;
        while(matrix[i][j] != 0){
            if(matrix[i][j] == matrix[i][j-1]) j--;
            else if(input[i-1] == input[tam-j]){
                output += input[i-1];
                i--;
                j--;
            }
            else i--;
        }
        cout << output << '\n';
    }

    return 0;
}
