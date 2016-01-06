#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    vector<int> permutations;
    vector<string> array;
    string line, tmp;
    int cases, last_space, i, j, size, tmpi;
    bool is_first = true;

    cin >> cases;
    cin.ignore();
    while(cases--){
        permutations.clear();
        array.clear();
        getline(cin, line);
        getline(cin, line);

        last_space = 0;
        for(i = 0; i < line.size(); i++){
            if(line[i] == ' '){
                tmp = line.substr(last_space, i-last_space);
                permutations.push_back(stoi(tmp));
                i++;
                last_space = i;
            }
        }
        tmp = line.substr(last_space, i-last_space);
        permutations.push_back(stoi(tmp));

        getline(cin, line);

        last_space = 0;
        for(i = 0; i < line.size(); i++){
            if(line[i] == ' '){
                tmp = line.substr(last_space, i-last_space);
                array.push_back(tmp);
                i++;
                last_space = i;
            }
        }
        tmp = line.substr(last_space, i-last_space);
        array.push_back(tmp);

        if(is_first) is_first = false;
        else         cout << "\n";

        size = permutations.size();
        for(i = 1 ; i < size;i++){
            j = i-1;
            tmpi = permutations[i];
            tmp = array[i];
            while(j >= 0 && permutations[j] > tmpi){
                permutations[j+1] = permutations[j];
                array[j+1] = array[j];
                j--;
            }
            permutations[j+1] = tmpi;
            array[j+1] = tmp;
        }

        for(i = 0; i < size; i++) cout << array[i] << "\n";
    }

    return 0;
}
