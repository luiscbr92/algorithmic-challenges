#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool my_comp(pair<string,int> p1, pair<string,int> p2){
    return p1.second > p2.second;
}

int main(){

    vector<pair<int,int>> input_cases;
    set<int> marks;
    int cases, i, begin, end;

    cin >> cases;
    for(i = 0; i < cases; i++){
        cin >> begin >> end;
        marks.insert(begin);
        marks.insert(end);
        input_cases.push_back(make_pair(begin, end));
    }

    ifstream corpus_file;
    string corpus_word;

    corpus_file.open("corpus.txt");
    map<int,map<string,int>> buff;
    map<string,int> partial_freq;
    i = 0;
    while(corpus_file >> corpus_word){
        if(partial_freq.find(corpus_word) == partial_freq.end())
            partial_freq[corpus_word] = 1;
        else
            partial_freq[corpus_word]++;

        if(marks.find(i) != marks.end())
            buff[i] = partial_freq;
        i++;
    }
    corpus_file.close();

    vector<pair<string,int>> words;
    map<string,int> initial;
    map<string,int> final;
    map<string,int>::iterator it;
    for(i = 1; i <= cases; i++){
        words.clear();

        initial = buff[input_cases[i-1].first];
        final = buff[input_cases[i-1].second];

        for(it = final.begin(); it != final.end(); ++it){
            if(initial.find(it->first) == initial.end())
                words.push_back(make_pair(it->first, it->second));
            else
                words.push_back(make_pair(it->first, it->second - initial[it->first]));
        }

        sort(words.begin(), words.end(), my_comp);
        cout << "Case #" << i << ": ";
        cout << words[0].first << ' ' << words[0].second << ',';
        cout << words[1].first << ' ' << words[1].second << ',';
        cout << words[2].first << ' ' << words[2].second << '\n';
    }

    return 0;
}
