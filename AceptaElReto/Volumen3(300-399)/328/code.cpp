#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, rows, cols, number_of_chicks, x, y, steps, length, pos;
    char direction;
    bool change_length;
    string result;

    cin >> cases;
    while(cases--){
        cin >> rows >> cols >> number_of_chicks;

        vector<int> tmp (cols, 0);
        vector<vector<int>> henhut (rows, tmp);

        while(number_of_chicks--){
            cin >> y >> x >> direction >> steps;
            y--;
            x--;
            henhut[y][x]++;

            change_length = false;
            length = 2;
            pos = 1;

            while(steps--){
                if(direction == 'N')        y--;
                else if(direction == 'E')   x++;
                else if(direction == 'S')   y++;
                else                        x--;

                if(x < 0 || y < 0 || x >= cols || y >= rows) break;
                henhut[y][x]++;

                pos++;
                if(pos == length){
                    pos = 1;
                    if(direction == 'N')        direction = 'E';
                    else if(direction == 'E')   direction = 'S';
                    else if(direction == 'S')   direction = 'W';
                    else                        direction = 'N';

                    if(change_length){
                        length++;
                        change_length = false;
                    }
                    else change_length = true;
                }

            }
        }

        result = "";
        for(y = 0; y < rows; y++){
            for(x = 0; x < cols; x++){
                if(x != 0) result += ' ';
                result += to_string(henhut[y][x]);
            }
            result += '\n';
        }
        result += "---\n";
        cout << result;
    }

    return 0;
}
