#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    map<string, int> money;
    int n_of_people, people_given, money_given, amount, i, j;
    string person;
    bool isfirst = true;

    while(cin >> n_of_people){
        if(!isfirst)    cout << endl;
        else            isfirst = false;

        string names[n_of_people];
        for(i = 0; i < n_of_people; i++){
            cin >> names[i];
            money[names[i]] = 0;
        }

        for(i = 0; i < n_of_people; i++){
            cin >> person;
            cin >> money_given >> people_given;
            //cout << money_given << " " << people_given << endl;
            if(people_given != 0)   amount = money_given / people_given;
            else                    amount = 0;
            money[person] -= amount * people_given;

            for(j = 0; j < people_given; j++){
                cin >> person;
                money[person] += amount;
            }
        }

        for(i = 0; i < n_of_people; i++)
            cout << names[i] << " " << money[names[i]] << endl;

        money.clear();
    }

    return 0;
}
