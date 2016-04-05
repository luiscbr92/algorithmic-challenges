#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int m, n, i, j;
    bool not_equals;
    string x, y;

    while(cin >> m >> x >> n >> y){
        int table[m+1][n+1];
        table[0][0] = 0;
        for(i = 1; i < m+1; i++) table[i][0] = i;
        for(j = 1; j < n+1; j++) table[0][j] = j;

        for(i = 1; i < m+1; i++){
            for(j =1; j < n+1; j++){
                not_equals = x[i-1] != y[j-1];
                table[i][j] = min(not_equals + table[i-1][j-1], min(table[i-1][j]+1, table[i][j-1]+1));
            }
        }
        cout << table[m][n] << '\n';
    }

    return 0;
}
