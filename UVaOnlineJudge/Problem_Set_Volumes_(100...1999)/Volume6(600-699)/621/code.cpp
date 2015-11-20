#include <iostream>
#include <string>

using namespace std;

int main(){
    int cases, length;
    string s;

    cin >> cases;

    for(int i = 0; i < cases; i++){

        cin >> s;

        if(s=="1" || s == "4" || s == "78") cout << "+\n";

        else if ((length = s.size()) >= 2){
            if(s.substr(length - 2) == "35")                    cout << "-\n";
            else if(s[0] == '9' && s[length-1] == '4')          cout << "*\n";
            else if (length >= 3 && s.substr(0, 3) == "190")    cout << "?\n";
        }


    }
}
