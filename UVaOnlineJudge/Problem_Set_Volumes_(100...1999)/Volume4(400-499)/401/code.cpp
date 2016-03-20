#include <iostream>
#include <string>
#include <map>

using namespace std;

bool reversible(char c){
    return c=='A' || c=='E' || c=='3' || c=='H' || c=='I' || c=='J' || c=='L' || c=='M' || c=='O' || c=='S' || c=='2' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z' || c=='5' || c=='1' || c=='8';
}

int main(){
    ios_base::sync_with_stdio (false);

    bool mirrored, palindrome;
    string input, output;
    int length, index;
    map<char,char> valid_reverses;
    valid_reverses['A'] = 'A';
    valid_reverses['E'] = '3';
    valid_reverses['3'] = 'E';
    valid_reverses['H'] = 'H';
    valid_reverses['I'] = 'I';
    valid_reverses['J'] = 'L';
    valid_reverses['L'] = 'J';
    valid_reverses['M'] = 'M';
    valid_reverses['O'] = 'O';
    valid_reverses['S'] = '2';
    valid_reverses['2'] = 'S';
    valid_reverses['T'] = 'T';
    valid_reverses['U'] = 'U';
    valid_reverses['V'] = 'V';
    valid_reverses['W'] = 'W';
    valid_reverses['X'] = 'X';
    valid_reverses['Y'] = 'Y';
    valid_reverses['Z'] = '5';
    valid_reverses['5'] = 'Z';
    valid_reverses['1'] = '1';
    valid_reverses['8'] = '8';

    output = "";
    while(cin >> input){
        mirrored = true;
        palindrome = true;
        length = input.size();
        index = 0;

        while((mirrored || palindrome) && index <= length/2){
            if(mirrored){
                if(reversible(input[index])){
                    if(valid_reverses[input[index]] != input[length-index-1]) mirrored = false;
                }
                else mirrored = false;
            }
            if(palindrome && input[index] != input[length-index-1]) palindrome = false;
            index++;
        }

        if(mirrored && palindrome)          output += input + " -- is a mirrored palindrome.\n\n";
        else if(mirrored && !palindrome)    output += input + " -- is a mirrored string.\n\n";
        else if(!mirrored && palindrome)    output += input + " -- is a regular palindrome.\n\n";
        else                                output += input + " -- is not a palindrome.\n\n";
    }
    cout << output;

    return 0;
}
