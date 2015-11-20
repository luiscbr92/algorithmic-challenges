#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int n, i, j, a, b, maximum_sum, sum, aa, bb;
    cin >> n;

    int grid[n][n];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++) cin >> grid[i][j];
    }

    maximum_sum = 0;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){

            for(a = i; a < n; a++){
                for(b = j; b < n; b++){

                    sum = 0;
                    for(aa = i; aa <= a; aa++){
                        for(bb = j; bb <= b; bb++){
                            sum += grid[aa][bb];
                        }
                    }
                    if(maximum_sum < sum) maximum_sum = sum;
                }
            }

        }
    }

    cout << maximum_sum << endl;

    return 0;
}
