#include <iostream>
#include <vector>

using namespace std;

int main(){

    int cases, c, rows, columns, i, j, k, l, value, row_sum, col_sum, complete_sum, sol, temp;
    char char_input;
    vector<vector<int>> matrix;
    vector<vector<int>> four_matrix;
    vector<int> tmp;
    bool infinity;

    cin >> cases;

    for(c = 1; c <= cases; c++){
        matrix.clear();
        cin >> rows >> columns;
        infinity = false;

        for(i = 0; i < rows; i++){
            tmp.clear();
            row_sum = 0;
            for(j = 0; j < columns; j++){
                cin >> char_input;
                if(char_input >= 'A' && char_input <= 'Z')
                    value = int(char_input - 'A' +1);
                else if(char_input >= 'a' && char_input <= 'z')
                    value = -int(char_input - 'a' +1);
                else
                    value = 0;
                tmp.push_back(value);
                row_sum += value;
            }
            matrix.push_back(tmp);
            if(row_sum > 0)
                infinity = true;
        }

        if(!infinity){
            complete_sum = 0;
            for(j = 0; j < columns; j++){
                col_sum = 0;
                for(i = 0; i < rows; i++){
                    col_sum += matrix[i][j];
                    complete_sum += matrix[i][j];
                }
                if(col_sum > 0 || complete_sum > 0)
                    infinity = true;
            }
        }

        if(infinity)
            cout << "Case #" << c << ": INFINITY\n";
        else{
            four_matrix.clear();
            for(i = 0; i < rows; i++){
                tmp.clear();
                for(j = 0; j < columns; j++){
                    tmp.insert(tmp.begin()+j, matrix[i][j]);
                    tmp.push_back(matrix[i][j]);
                }
                four_matrix.insert(four_matrix.begin()+i, tmp);
                four_matrix.push_back(tmp);
            }

            for(i = 0; i < 2*rows; i++)
                for(j = 0; j < 2*columns; j++){
                    if(i > 0)
                        four_matrix[i][j] += four_matrix[i-1][j];
                    if(j > 0)
                        four_matrix[i][j] += four_matrix[i][j-1];
                    if(i > 0 && j > 0)
                        four_matrix[i][j] -= four_matrix[i-1][j-1];
                }

            sol = 0;
            for(i = 0; i < 2*rows; i++)
                for(j = 0; j < 2*columns; j++)
                    for(k = i; k < 2*rows; k++)
                        for(l = j; l < 2*columns; l++){
                            temp = four_matrix[k][l];
                            if (i > 0)
                                temp -= four_matrix[i - 1][l];
                            if (j > 0)
                                temp -= four_matrix[k][j - 1];
                            if (i > 0 && j > 0)
                                temp += four_matrix[i - 1][j - 1];

                            if (temp > sol)
                                sol = temp;
                        }

            cout << "Case #" << c << ": " << sol << '\n';
        }


    }


    return 0;
}
