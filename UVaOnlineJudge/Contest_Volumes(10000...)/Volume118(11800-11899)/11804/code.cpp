#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_before(string first, string second){
    if(first[0] != second[0])
        return first[0] < second[0];
    else{
        if(first.size() > 1 && second.size() > 1)
            return is_before(first.substr(1), second.substr(1));
        if(first.size() == 1)
            return true;
        else return false;
    }
}

int main(){
    ios_base::sync_with_stdio (false);

    vector<string> names;
    vector<int> attack;
    vector<int> defense;
    int cases, c, i, j, atta, defe;
    string name;

    cin >> cases;
    for(c = 1; c <= cases; c++){
        cout << "Case " << c << ":\n";
        names.clear();
        attack.clear();
        defense.clear();
        for(i = 0; i < 10; i++){
            cin >> name >> atta >> defe;
            names.push_back(name);
            attack.push_back(atta);
            defense.push_back(defe);
        }

        for(i = 1; i < 10; i++){
            j = i-1;
            name = names[i];
            atta = attack[i];
            defe = defense[i];
            while(j >= 0 && !is_before(name, names[j])){
                names[j+1] = names[j];
                attack[j+1] = attack[j];
                defense[j+1] = defense[j];
                j--;
            }
            names[j+1] = name;
            attack[j+1] = atta;
            defense[j+1] = defe;
        }

        for(i = 1; i < 10; i++){
            j = i-1;
            name = names[i];
            atta = attack[i];
            defe = defense[i];
            while(j >= 0 && defense[j] < defe){
                names[j+1] = names[j];
                attack[j+1] = attack[j];
                defense[j+1] = defense[j];
                j--;
            }
            names[j+1] = name;
            attack[j+1] = atta;
            defense[j+1] = defe;
        }

        for(i = 1; i < 10; i++){
            j = i-1;
            name = names[i];
            atta = attack[i];
            while(j >= 0 && attack[j] > atta){
                names[j+1] = names[j];
                attack[j+1] = attack[j];
                j--;
            }
            names[j+1] = name;
            attack[j+1] = atta;
        }

        for(i = 1; i < 5; i++){
            j = i-1;
            name = names[i];
            while(j >= 0 && is_before(name, names[j])){
                names[j+1] = names[j];
                j--;
            }
            names[j+1] = name;
        }

        for(i = 5; i < 10; i++){
            j = i-1;
            name = names[i];
            while(j >= 5 && is_before(name, names[j])){
                names[j+1] = names[j];
                j--;
            }
            names[j+1] = name;
        }

        cout << "(" << names[5] << ", " << names[6] << ", " << names[7] << ", " << names[8] << ", " << names[9] << ")\n";
        cout << "(" << names[0] << ", " << names[1] << ", " << names[2] << ", " << names[3] << ", " << names[4] << ")\n";
    }

    return 0;
}
