#include <iostream>

using namespace std;

int main(){
    int well_height, distance_day, distance_night, fatigue, day;
    double height, distance_up;

    cin >> well_height >> distance_day >> distance_night >> fatigue;

    while(well_height != 0){
        height = 0;
        day = 0;

        while(height >= 0 && height <= well_height){
            day = day + 1;

            distance_up = distance_day - (day-1) * (distance_day * fatigue /100.0);
            if(distance_up < 0) distance_up = 0;
            height = height + distance_up;

            if(height <= well_height) height = height - distance_night;
        }

        if(height > well_height)    cout << "success";
        else                        cout << "failure";

        cout << " on day " << day << "\n";

        cin >> well_height >> distance_day >> distance_night >> fatigue;
    }

}
