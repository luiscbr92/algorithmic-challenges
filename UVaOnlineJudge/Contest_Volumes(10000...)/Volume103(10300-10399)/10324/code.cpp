#include <iostream>
#include <string>

using namespace std;

int main(){
    string s, subs;
    int cases, a, b, i, j, distance, length;
    int count = 1;
    bool same_char;
    char first;

    while(cin >> s){
        cout << "Case " << count << ":\n";

        cin >> cases;

        for(i = 0; i < cases; i++){
            cin >> a >> b;
            same_char = true;

            if(a <= b){
                distance = b - a;

            }
            else {
                distance = a - b;
                a = b;
            }

            distance = distance + 1; // Because the last character is included

            subs = s.substr(a, distance);
            first = subs[0];

            j = 1;
            length = subs.size();

            while(same_char && j < length){
                if(first != subs[j]){
                    same_char = false;
                }

                j = j + 1;
            }

            if(same_char)    cout << "Yes\n";
            else        cout << "No\n";
        }

        count = count + 1;
    }
}
