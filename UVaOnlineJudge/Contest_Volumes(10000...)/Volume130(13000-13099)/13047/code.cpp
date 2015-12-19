#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, max_length, i, j, curr_arrow_length;
    string line;
    //bool in_equals, in_hyphen;

    cin >> cases;
    cin.ignore();
    for(c = 1; c <= cases; c++){
        getline(cin, line);
        max_length = -1;

        for(i = 0; i < line.size(); i++){
            if(line[i] == '<'){
                curr_arrow_length = 1;
                if(i+1 < line.size()){
                    if(line[i+1] == '-'){
                        curr_arrow_length++;
                        j = i+2;
                        while(j < line.size() && line[j] == '-'){
                            j++;
                            curr_arrow_length++;
                        }
                    }
                    else if(line[i+1] == '='){
                        curr_arrow_length++;
                        j = i+2;
                        while(j< line.size() && line[j] == '='){
                            j++;
                            curr_arrow_length++;
                        }
                    }
                }
                if(curr_arrow_length > max_length) max_length = curr_arrow_length;
            }
            else if(line[i] == '>'){
                curr_arrow_length = 1;
                if(i-1 > -1){
                    if(line[i-1] == '-'){
                        curr_arrow_length++;
                        j = i-2;
                        while(j > -1 && line[j] == '-'){
                            j--;
                            curr_arrow_length++;
                        }
                    }
                    else if(line[i-1] == '='){
                        curr_arrow_length++;
                        j = i-2;
                        while(j > -1 && line[j] == '='){
                            j--;
                            curr_arrow_length++;
                        }
                    }
                }
                if(curr_arrow_length > max_length) max_length = curr_arrow_length;
            }
        }

        cout << "Case " << c << ": " << max_length << "\n";
    }

    return 0;
}
