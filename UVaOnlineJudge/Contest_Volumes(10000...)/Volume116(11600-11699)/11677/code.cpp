#include <iostream>

using namespace std;

int main(){

  int curr_hour, curr_minute, alarm_hour, alarm_minute, sleep_minutes;

  while(cin >> curr_hour >> curr_minute >> alarm_hour >> alarm_minute &&
        curr_hour || curr_minute || alarm_hour || alarm_minute) {

    sleep_minutes = alarm_hour * 60 - curr_hour * 60 + alarm_minute - curr_minute +
                    (curr_hour > alarm_hour || curr_hour == alarm_hour && curr_minute > alarm_minute) * 24 * 60;

    cout << sleep_minutes << endl;
  }

  return 0;
}
