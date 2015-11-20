#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int n_of_students, queries, position, distance, l, r, i, j;
    bool name_found;
    cin >> n_of_students;
    string students[n_of_students];

    for(i = 0; i < n_of_students; i++){
        cin >> students[i];
    }

    cin >> queries;
    for(i = 0; i < queries; i++){
        cin >> position;
        position -= 1;
        if(students[position] != "?") cout << students[position] << endl;
        else{
            distance = 0;
            name_found = false;
            while(!name_found){
                distance +=1;
                l = position - distance;
                r = position + distance;
                if(l >= 0 && students[l] != "?"){
                    name_found = true;
                    if(r < n_of_students && students[r] != "?"){
                        cout << "middle of " << students[l] << " and " << students[r] << endl;
                    }
                    else{
                        for(j = 0; j < distance; j++) cout << "right of ";
                        cout << students[l] << endl;
                    }
                }
                else if(r < n_of_students && students[r] != "?"){
                    name_found = true;
                    for(j = 0; j < distance; j++) cout << "left of ";
                    cout << students[r] << endl;
                }

            }
        }
    }

    return 0;
}
