#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    char segment_a[] = {'-', ' ', '-', '-', ' ', '-', '-', '-', '-', '-'};
    char segment_b[] = {'|', '|', '|', '|', '|', ' ', ' ', '|', '|', '|'};
    char segment_c[] = {'|', '|', ' ', '|', '|', '|', '|', '|', '|', '|'};
    char segment_d[] = {'-', ' ', '-', '-', ' ', '-', '-', ' ', '-', '-'};
    char segment_e[] = {'|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', ' '};
    char segment_f[] = {'|', ' ', ' ', ' ', '|', '|', '|', ' ', '|', '|'};
    char segment_g[] = {' ', ' ', '-', '-', '-', '-', '-', ' ', '-', '-'};

    string input, top_line, middle_line, inferior_line, interline1, interline2, result;
    int size, index_of_number, current_number, i;

    while(cin >> size >> input && (size != 0 || input != "0")){
        top_line = "";
        interline1 = "";
        middle_line = "";
        interline2 = "";
        inferior_line = "";

        for(index_of_number = 0; index_of_number < input.size(); index_of_number++){
            current_number = input[index_of_number] -48;
            if(index_of_number != 0){
                top_line += ' ';
                interline1 += ' ';
                middle_line += ' ';
                interline2 += ' ';
                inferior_line += ' ';
            }

            top_line += ' ';
            interline1 += segment_f[current_number];
            middle_line += ' ';
            interline2 += segment_e[current_number];
            inferior_line += ' ';

            for(i = 0; i < size; i++){
                top_line += segment_a[current_number];
                interline1 += ' ';
                middle_line += segment_g[current_number];
                interline2 += ' ';
                inferior_line += segment_d[current_number];
            }

            top_line += ' ';
            interline1 += segment_b[current_number];
            middle_line += ' ';
            interline2 += segment_c[current_number];
            inferior_line += ' ';
        }

        result = top_line + "\n";
        for(i = 0; i < size; i++) result += interline1 + "\n";
        result += middle_line + "\n";
        for(i = 0; i < size; i++) result += interline2 + "\n";
        result += inferior_line + "\n\n";

        cout << result;
    }

    return 0;
}
