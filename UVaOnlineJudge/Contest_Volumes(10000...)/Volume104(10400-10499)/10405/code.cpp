#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string str_a, str_b;
    int i, j, equals, tam_a, tam_b;

    while(getline(cin, str_a) && getline(cin, str_b)){
        tam_a = str_a.size();
        tam_b = str_b.size();
        int matrix [tam_a +1][tam_b +1];

        for(i = 0; i < tam_a +1; i++) matrix[i][0] = 0;
        for(i = 0; i < tam_b +1; i++) matrix[0][i] = 0;

        for(i = 1; i < tam_a +1; i++){
            for(j = 1; j < tam_b +1; j++){
                equals = str_a[i-1] == str_b[j-1];
                matrix[i][j] = max(max(matrix[i-1][j], matrix[i-1][j-1] + equals), matrix[i][j-1]);
            }
        }

        cout << matrix[tam_a][tam_b] << '\n';
    }

    return 0;
}
