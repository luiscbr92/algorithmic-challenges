#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int apparitions[26] = {0};
    int number_of_lines, i, j, tmp_apparition;
    char tmp_char;
    string line;

    cin >> number_of_lines;
    cin.ignore();
    while(number_of_lines--){
        getline(cin,line);
        for(i = 0; i < line.size(); i++){
            if(line[i] >= 'a' && line[i] <= 'z')        apparitions[int(line[i]) - 97]++;
            else if(line[i] >= 'A' && line[i] <= 'Z')   apparitions[int(line[i]) - 65]++;
        }
    }

    for(i = 1; i < 26; i++){
        j = i-1;
        tmp_apparition = apparitions[i];
        tmp_char = letters[i];
        while(j >= 0 && apparitions[j] < tmp_apparition){
            apparitions[j+1] = apparitions[j];
            letters[j+1] = letters[j];
            j--;
        }
        apparitions[j+1] = tmp_apparition;
        letters[j+1] = tmp_char;
    }

    for(i = 0; i < 26; i++){
        if(apparitions[i] == 0) break;
        cout << letters[i] << " " << apparitions[i] << "\n";
    }

    return 0;
}
