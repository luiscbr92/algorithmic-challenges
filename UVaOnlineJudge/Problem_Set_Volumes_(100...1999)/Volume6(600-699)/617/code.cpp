#include <iostream>

#define MAX_SPEED 60
#define MIN_SPEED 30

using namespace std;

int main(){

  int number_traffic_lights, yellow, green, periods, min_interval_speed, last_accepted_speed;
  double seconds_to_arrive, second_of_period;
  bool acceptable_speed, in_interval, first_interval;
  int test_case = 1;

  while(cin >> number_traffic_lights && number_traffic_lights != -1){
    double light_position[number_traffic_lights];
    int allowed_period[number_traffic_lights];
    int red_period[number_traffic_lights];
    int cycle_length[number_traffic_lights];

    for(int i = 0; i < number_traffic_lights; i++){
      cin >> light_position[i] >> green >> yellow >> red_period[i];
      allowed_period[i] = green+yellow;
      cycle_length[i] = allowed_period[i] + red_period[i];
    }

    first_interval = true;
    in_interval = false;
    cout << "Case " << test_case << ": ";
    for(int mph = MIN_SPEED; mph <= MAX_SPEED; mph++){
      acceptable_speed = true;
      for(int i = 0; i < number_traffic_lights; i++){
        seconds_to_arrive = light_position[i] * 3600 / mph;
        periods = seconds_to_arrive / cycle_length[i];
        second_of_period = seconds_to_arrive - (cycle_length[i] * periods);
        if(second_of_period > allowed_period[i]){
          acceptable_speed = false;
          break;
        }
      }
      if(acceptable_speed){
        if(in_interval)
          last_accepted_speed = mph;
        else{
          in_interval = true;
          last_accepted_speed = mph;
          min_interval_speed = mph;
        }
      }
      else{
        if(in_interval){
          in_interval = false;
          if(last_accepted_speed == min_interval_speed){
            if(first_interval){
              cout << last_accepted_speed;
              first_interval = false;
            }
            else
              cout << ", " << last_accepted_speed;
          }
          else{
            if(first_interval){
              cout << min_interval_speed << '-' << last_accepted_speed;
              first_interval = false;
            }
            else
              cout << ", " << min_interval_speed << '-' << last_accepted_speed;
          }
        }
      }
    }

    if(in_interval){
      in_interval = false;
      if(last_accepted_speed == min_interval_speed){
        if(first_interval){
          cout << last_accepted_speed;
          first_interval = false;
        }
        else
          cout << ", " << last_accepted_speed;
      }
      else{
        if(first_interval){
          cout << min_interval_speed << '-' << last_accepted_speed;
          first_interval = false;
        }
        else
          cout << ", " << min_interval_speed << '-' << last_accepted_speed;
      }
    }
    if(first_interval)
      cout << "No acceptable speeds.";

    cout << '\n';
    test_case++;
  }

  return 0;
}
