#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string line, current_a, current_b;
    vector<string> words;
    int i, j, k;
    bool del;

    while(cin >> line && line != "#") words.push_back(line);

    i = 0;
    while(i < words.size()){
        current_a = "";
        for(k = 0; k < words.at(i).size(); k++) current_a += char(toupper(words.at(i).at(k)));
        sort(current_a.begin(), current_a.end());
        del = false;
        j = i+1;
        while(j < words.size()){
            current_b = "";
            for(k = 0; k < words[j].size(); k++) current_b += char(toupper(words[j].at(k)));
            sort(current_b.begin(), current_b.end());
            if(current_a == current_b){
                words.erase(words.begin()+j);
                del = true;
            }
            else j++;
        }
        if(del) words.erase(words.begin()+i);
        else    i++;
    }

    sort(words.begin(), words.end());
    for(i = 0; i < words.size(); i++){
        cout << words[i] << endl;
    }

    return 0;
}
