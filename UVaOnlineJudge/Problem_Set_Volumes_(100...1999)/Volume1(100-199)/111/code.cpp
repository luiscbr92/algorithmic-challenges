#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int number_of_events, eq, i, j, rank;
    cin >> number_of_events;

    int table[number_of_events+1][number_of_events+1];
    for(i = 0; i < number_of_events+1; i++){
        table[0][i] = 0;
        table[i][0] = 0;
    }

    int original[number_of_events];
    for(i = 1; i <= number_of_events; i++){
        cin >> rank;
        original[rank-1] = i;
    }

    int other[number_of_events];

    while(cin >> rank){
        other[rank-1] = 1;
        for(i = 2; i <= number_of_events; i++){
            cin >> rank;
            other[rank-1] = i;
        }

        for(i = 1; i < number_of_events+1; i++){
            for(j = 1; j < number_of_events+1; j++){
                eq = original[j-1] == other[i-1];
                table[i][j] = max(table[i-1][j-1] + eq, max(table[i-1][j], table[i][j-1]));
            }
        }

        cout << table[number_of_events][number_of_events] << '\n';
    }


    return 0;
}
