#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool possible_mother(string a, string b){
    int length, errors, i;
    if(a.size() == b.size()){
        length = a.size();
        i = 0;
        errors = 0;
        while(i < length && errors < 2){
            if(a[i] != b[i]) errors++;
            i++;
        }
        return errors < 2;
    }
    else return false;
}

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, contact_length, i;
    string tmp, mother_phone;
    queue<string> contact_list;

    cin >> cases;

    for(c = 1; c <= cases; c++){
        cout << "Case " << c << ":\n";

        cin >> contact_length;
        for(i = 0; i < contact_length; i++){
            cin >> tmp;
            contact_list.push(tmp);
        }

        cin >> mother_phone;

        while(!contact_list.empty()){
            if(possible_mother(mother_phone, contact_list.front()))
                cout << contact_list.front() << "\n";
            contact_list.pop();
        }

    }

    return 0;
}
