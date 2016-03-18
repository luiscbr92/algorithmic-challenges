#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool is_separator(string str){
    for(int i = 0; i < str.size(); i++){
        if(str[i] != '_') return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio (false);

    int cases, rows_count, found, row, col;
    string input, separator, output;
    vector<string> grid;
    stack<int> rows_to_check;
    stack<int> cols_to_check;
    bool start_found;

    cin >> cases;
    cin.ignore();

    for(int current_case = 0; current_case < cases; current_case++){
        output = "";
        grid.clear();

        rows_count = 0;
        start_found = false;
        while(getline(cin, input) && !is_separator(input)){
            grid.push_back(input);
            if(!start_found){
                if((found = input.find('*')) != string::npos){
                    cols_to_check.push(found);
                    rows_to_check.push(rows_count);
                    start_found = true;
                }
            }
            rows_count++;
        }
        separator = input;

        grid[rows_to_check.top()][cols_to_check.top()] = '#';
        while(!cols_to_check.empty() && !rows_to_check.empty()){
            col = cols_to_check.top();
            row = rows_to_check.top();
            cols_to_check.pop();
            rows_to_check.pop();

            if(grid[row-1][col] == ' '){
                grid[row-1][col] = '#';
                cols_to_check.push(col);
                rows_to_check.push(row-1);
            }
            if(grid[row+1][col] == ' '){
                grid[row+1][col] = '#';
                cols_to_check.push(col);
                rows_to_check.push(row+1);
            }
            if(grid[row][col-1] == ' '){
                grid[row][col-1] = '#';
                cols_to_check.push(col-1);
                rows_to_check.push(row);
            }
            if(grid[row][col+1] == ' '){
                grid[row][col+1] = '#';
                cols_to_check.push(col+1);
                rows_to_check.push(row);
            }

        }

        for(col = 0; col < grid.size(); col++) output += grid[col] + '\n';
        output += separator + '\n';

        cout << output;
    }
    return 0;
}
