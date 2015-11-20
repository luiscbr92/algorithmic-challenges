#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);
    int n_of_people, i;
    int people_singing = 0;
    string song[] = {"Happy", "birthday", "to", "you",
                    "Happy", "birthday", "to", "you",
                    "Happy", "birthday", "to", "Rujia",
                    "Happy", "birthday", "to", "you"};
    cin >> n_of_people;
    string person[n_of_people];

    for(i = 0; i < n_of_people; i++){
        cin >> person[i];
    }

    while(people_singing < n_of_people){
        for(i = 0; i < 16; i++){
            cout << person[people_singing % n_of_people] << ": " << song[i] << endl;
            people_singing += 1;
        }
    }

    return 0;
}
