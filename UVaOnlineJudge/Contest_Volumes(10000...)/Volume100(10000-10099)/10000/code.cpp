#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int nodes, start, finish, length, cases, p, q, i, j, k;
    string output = "";
    cases = 0;

    while(cin >> nodes && nodes){
        cases++;
        cin >> start;
        output += "Case " + to_string(cases) + ": The longest path from " + to_string(start) + " has length ";

        int adjacency[nodes][nodes];
        for(i = 0; i < nodes; i++)
            for(j = 0; j < nodes; j++)
                if(i == j)  adjacency[i][j] = 0;
                else        adjacency[i][j] = -1;

        while(cin >> p >> q && p && q) adjacency[p-1][q-1] = 1;

        for(k = 0; k < nodes; k++)
            for(i = 0; i < nodes; i++)
                for(j = 0; j < nodes; j++)
                    if(adjacency[i][k] != -1 && adjacency[k][j] != -1)
                        if(adjacency[i][k] + adjacency[k][j] > adjacency[i][j])
                            adjacency[i][j] = adjacency[i][k] + adjacency[k][j];

        length = -1;
        for(i = 0; i < nodes; i++)
            if(adjacency[start-1][i] > length){
                length = adjacency[start-1][i];
                finish = i+1;
            }

        output += to_string(length) + ", finishing at " + to_string(finish) + ".\n\n";
    }
    cout << output;

    return 0;
}
