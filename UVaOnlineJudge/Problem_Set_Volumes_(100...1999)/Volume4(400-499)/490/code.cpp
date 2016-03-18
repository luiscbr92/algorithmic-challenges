#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string input, output;
    int max_length, i, j, number_of_sentences;
    vector<string> sentences;

    max_length = 0;
    while(getline(cin, input)){
        if(max_length < input.size()) max_length = input.size();
        sentences.push_back(input);
    }

    output = "";
    number_of_sentences = sentences.size();
    for(i = 0; i < max_length; i++){
        for(j = number_of_sentences-1; j >= 0; j--){
            if(i < sentences[j].size()) output += sentences[j][i];
            else                        output += ' ';
        }
        output += '\n';
    }
    cout << output;

    return 0;
}
