#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, size, i, j, num, k, sum;
    vector<vector<int>> square;
    vector<int> tmp;
    vector<int> sums;
    cases = 1;

    while(cin >> size && size != 0){
        cout << "Case " << cases << ":";
        square.clear();
        sums.clear();
        for(i = 0; i < size; i++){
            tmp.clear();
            for(j = 0; j < size; j++){
                cin >> num;
                tmp.push_back(num);
            }
            square.push_back(tmp);
        }

        for(k = 0; k < size/2.0 + 0.5; k++){
            sum = 0;
            for(j = k; j < size - k; j++){
                sum += square[k][j];
                sum += square[size-k-1][j];
                if(j != k && j != size-k-1){
                    sum += square[j][k];
                    sum += square[j][size-k-1];
                }
                if(j == k && j == size - k-1 && size %2 == 1) sum = square[j][k];
            }
            sums.push_back(sum);
        }

        if(size % 2 == 0) sums.pop_back();
        for(i = 0; i < sums.size(); i++) cout << " " << sums[i];
        cout << "\n";
        cases++;
    }

    return 0;
}
