#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string dictionary[100];
    int dictionary_length = 0;
    string line, cipher_message, message, possible_message;
    int i, j, c, words_from_dictionary, max_words_from_dictionary, index;

    getline(cin, line);
    while(line[0] != '#'){
        dictionary[dictionary_length] = line;
        dictionary_length +=1;
        getline(cin, line);
    }

    getline(cin, cipher_message);
    int message_length = cipher_message.size();
    int cipher_ascii[message_length];

    // SAVING THE MESSAGE AS A LIST OF ASCII VALUES
    for(i = 0; i < message_length; i++){
        if((int)cipher_message[i] == 32)    cipher_ascii[i] = 0; // SPACE
        else                                cipher_ascii[i] = (int)(cipher_message[i]) - 64;
    }

    // SUM FROM 1 TO 26 EACH ASCII VALUE AND CONSTRUCT A NEW POSSIBLE MESSAGE
    // THEN COMPROBE EACH POSSIBLE MESSAGE WITH THE DICTIONARY
    max_words_from_dictionary = 0;
    for(i = 1; i < 27; i++){
        possible_message = "";
        for(j = 0; j < message_length; j++){
            c = cipher_ascii[j] + i;
            if(c > 26) c -= 27;

            if(c == 0)  possible_message += ' ';
            else        possible_message += (char)(c + 64);
        }
        words_from_dictionary = 0;

        for(j = 0; j < dictionary_length; j++){
            // find() returns string::npos when the little string isn't in the big string
            if(possible_message.find(" " + dictionary[j] + " ") != string::npos) words_from_dictionary += 1;
        }

        if(words_from_dictionary > max_words_from_dictionary){
            max_words_from_dictionary = words_from_dictionary;
            message = possible_message;
        }
    }

    // PRINTING THE ANSWER WITH THE REQUISITES GIVEN
    string output_word;
    int next_space;
    int line_lenght = 0;
    while(message.size() > 0){
        next_space = message.find(" ");
        if(next_space != string::npos){
            output_word = message.substr(0,next_space);
            message = message.substr(next_space+1);

            if(line_lenght + next_space < 60){
                if(line_lenght > 0) cout << " ";
                cout << output_word;
                line_lenght += next_space + 1;
            }
            else{
                cout << endl << output_word;
                line_lenght = next_space + 1;
            }
        }
        // When there are no more spaces and words
        else break;
    }
    cout << endl;

    return 0;
}
