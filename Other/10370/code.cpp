#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, students, i, above;
    int grades[1000];
    double average;

    cin >> cases;
    for(c = 0; c < cases; c++){
        cin >> students;
        average = 0;
        above = 0;

        for(i = 0; i < students; i++){
            cin >> grades[i];
            average += grades[i];
        }
        average /= students;

        for(i = 0; i < students; i++){
            if(grades[i] > average) above++;
        }

        printf("%.3f%%\n", 100.0*above/students);
    }

    return 0;
}
