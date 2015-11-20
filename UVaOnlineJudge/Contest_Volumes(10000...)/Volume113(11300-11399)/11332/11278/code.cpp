#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    char lower_qwerty[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    char lower_dvorak[] = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
    char upper_qwerty[] = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    char upper_dvorak[] = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

    char letter;
    string line, result;
    int i, j;

    while(getline(cin, line)){
        result = "";

        for(i = 0; i < line.size(); i++){
            letter = line[i];
            if(letter == ' '){
                result += ' ';
                continue;
            }
            else{
                for(j = 0; j < 47; j++){
                    if(letter == lower_qwerty[j]){
                        result += lower_dvorak[j];
                        break;
                    }
                    else if(letter == upper_qwerty[j]){
                        result += upper_dvorak[j];
                        break;
                    }
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
