#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int number_of_notes, highest_pitched, deepest, key_pointer, i;
    string input, result;

    while(cin >> number_of_notes && number_of_notes){
        vector<int> key_taps (84, 0);
        deepest = 83;
        highest_pitched = 0;
        while(number_of_notes--){
            cin >> input;
            key_pointer = (input.at(input.size()-1) - '1') *12;

            if(input.at(0) == 'D'){
                if(input.size() == 4){
                    if(input.at(2) == 'b')  key_pointer--;
                    else                    key_pointer++;
                }
            }
            else if(input.at(0) == 'R'){
                key_pointer += 2;
                if(input.size() == 4){
                    if(input.at(2) == 'b')  key_pointer--;
                    else                    key_pointer++;
                }
            }
            else if(input.at(0) == 'M'){
                key_pointer += 4;
                if(input.size() == 4){
                    if(input.at(2) == 'b')  key_pointer--;
                    else                    key_pointer++;
                }
            }
            else if(input.at(0) == 'F'){
                key_pointer += 5;
                if(input.size() == 4){
                    if(input.at(2) == 'b')  key_pointer--;
                    else                    key_pointer++;
                }
            }
            else if(input.at(0) == 'L'){
                key_pointer += 9;
                if(input.size() == 4){
                    if(input.at(2) == 'b')  key_pointer--;
                    else                    key_pointer++;
                }
            }
            else{ // Sol or Si
                if(input.at(1) == 'i'){
                    key_pointer += 11;
                    if(input.size() == 4){
                        if(input.at(2) == 'b')  key_pointer--;
                        else                    key_pointer++;
                    }
                }
                else{ // Sol
                    key_pointer += 7;
                    if(input.size() == 5){
                        if(input.at(3) == 'b')  key_pointer--;
                        else                    key_pointer++;
                    }
                }
            }

            if(key_pointer < deepest)           deepest = key_pointer;
            if(key_pointer > highest_pitched)   highest_pitched = key_pointer;
            key_taps[key_pointer]++;
        }

        result = "";
        for(i = deepest; i <= highest_pitched; i++){
            if(i != deepest)    result += ' ';
            result += to_string(key_taps[i]);
        }
        cout << result << '\n';
    }

    return 0;
}
