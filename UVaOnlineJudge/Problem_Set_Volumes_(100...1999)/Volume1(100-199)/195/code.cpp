#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, i, index, length;
    string line, result;
    vector<int> input_letters;
    char letters[] = {'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z'};

    cin >> cases;
    while(cases--){
        input_letters.clear();
        cin >> line;
        length = line.size();
        result = "";

        for(i = 0; i < length; i++){
            index = 0;
            while(letters[index] != line[i]) index++;
            input_letters.push_back(index);
        }

        sort(input_letters.begin(), input_letters.end());

        do{
            for(i = 0; i < length; i++){
                result += letters[input_letters[i]];
            }
            result += '\n';
        }while(next_permutation(input_letters.begin(), input_letters.end()));

        cout << result;
    }

    return 0;
}
