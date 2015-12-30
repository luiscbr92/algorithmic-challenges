#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int rows, cols, row, col, curr_row, curr_col, pockets, i, j;
    string line;
    vector<string> grid;
    stack<int> rows_to_check;
    stack<int> cols_to_check;

    while(cin >> rows >> cols && rows != 0){
        pockets = 0;
        grid.clear();
        for(row = 0; row < rows; row++){
            cin >> line;
            grid.push_back(line);
        }

        for(row = 0; row < rows; row++){
            for(col = 0; col < cols; col++){
                if(grid[row][col] == '@'){
                    grid[row][col] = '*';
                    rows_to_check.push(row);
                    cols_to_check.push(col);
                    pockets++;
                    while(!rows_to_check.empty()){
                        curr_row = rows_to_check.top();
                        curr_col = cols_to_check.top();
                        rows_to_check.pop();
                        cols_to_check.pop();

                        for(i = -1; i < 2; i++){
                            if(curr_row + i < rows && curr_row + i > -1){
                                for(j = -1; j < 2; j++){
                                    if(curr_col + j < cols && curr_col + j > -1){
                                        if(i != 0 || j != 0){
                                            if(grid[curr_row+i][curr_col+j] == '@'){
                                                grid[curr_row+i][curr_col+j] = '*';
                                                rows_to_check.push(curr_row+i);
                                                cols_to_check.push(curr_col+j);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << pockets << "\n";
    }

    return 0;
}
