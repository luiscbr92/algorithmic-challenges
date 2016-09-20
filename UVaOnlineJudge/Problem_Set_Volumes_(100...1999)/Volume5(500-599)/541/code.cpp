#include <iostream>

using namespace std;

int main(){

  int size, input, odd_row_index, odd_col_index, odd_rows, odd_cols;

  while(cin >> size && size){
    int row_sum[size] = {0};
    int col_sum[size] = {0};

    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        cin >> input;
        row_sum[i] += input;
        col_sum[j] += input;
      }
    }

    odd_rows = 0;
    odd_cols = 0;
    for(int i = 0; i < size; i++){
      if(row_sum[i] % 2 == 1){
        odd_rows++;
        odd_row_index = i+1;
      }
      if(col_sum[i] % 2 == 1){
        odd_cols++;
        odd_col_index = i+1;
      }
    }

    if(odd_rows == 0 && odd_cols == 0)
      cout << "OK\n";
    else if(odd_rows == 1 && odd_cols == 1)
      cout << "Change bit (" << odd_row_index << ',' << odd_col_index << ")\n";
    else
      cout << "Corrupt\n";
  }

  return 0;
}
