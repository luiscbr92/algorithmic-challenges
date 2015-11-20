#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string line;
    float hour_hand, minute_hand, degrees;
    int hour, minute, length;

    while(getline(cin, line) && line != "0:00"){
        length = line.size();
        minute = ((int)line[length-2]-48) *10 + ((int)line[length-1]-48);
        hour = ((int)line[length-4]-48);
        if(length == 5){
            hour += ((int)line[0]-48) *10;
            if(hour == 12) hour = 0;
        }

        minute_hand = 6.0 * minute;
        hour_hand = 30.0 * hour + 0.5 * minute;

        degrees = hour_hand - minute_hand;

        if(degrees < 0)     degrees += 360;
        if(degrees > 180)   degrees = 360 - degrees;

        printf("%.3f\n", degrees);
    }

    return 0;
}
