#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int words_to_check, cool_words, i;
    int cas = 0;
    string word;
    bool is_cool;

    while(cin >> words_to_check){
        cas++;
        cin.ignore();
        cool_words = 0;
        while(words_to_check--){
            getline(cin, word);
            vector<int> occurrences (26, 0);
            for(i = 0; i < word.size(); i++) occurrences[word[i]-97]++;

            sort(occurrences.begin(), occurrences.end());
            i = 0;
            while(occurrences[i] == 0) i++;
            i++;
            if(i == 26) is_cool = false;
            else        is_cool = true;
            while(i < occurrences.size() && is_cool){
                if(occurrences[i-1] == occurrences[i]) is_cool = false;
                i++;
            }
            if(is_cool) cool_words++;
        }
        cout << "Case " << cas << ": " << cool_words << "\n";
    }

    return 0;
}
