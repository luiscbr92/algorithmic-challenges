#include <iostream>

using namespace std;

int main(){
    int cases, students, required_speed, speed;
    int i, j;

    cin >> cases;

    for(i = 1; i <= cases; i++){
        cin >> students;
        required_speed = 0;

        for(j = 0; j < students; j++){
            cin >> speed;
            if (required_speed < speed) required_speed = speed;
        }

        cout << "Case " << i << ": " << required_speed << "\n";
    }
}
