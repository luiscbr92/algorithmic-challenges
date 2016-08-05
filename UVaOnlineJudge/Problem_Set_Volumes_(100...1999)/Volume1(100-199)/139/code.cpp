#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool by_size(string a, string b){
  return a.size() > b.size();
}

int to_decimal_size(int n){
  if(n == -100)
    return 5;
  if(n < 1000)
    return 4;
  if(n < 10000)
    return 5;
  return 6;
}

int main(){

  string idd_row, code, locality_name, str_price_in_cents;
  int space_index, dollar_index, price_in_cents, i;
  vector<string> code_list;
  map<string, string> locality_names;
  map<string, int> rates_in_cents;

  while(getline(cin, idd_row) && idd_row != "000000"){
    space_index = idd_row.find(' ');
    dollar_index = idd_row.rfind('$');

    code = idd_row.substr(0, space_index);
    locality_name = idd_row.substr(space_index+1, dollar_index - space_index -1);
    str_price_in_cents = idd_row.substr(dollar_index+1);

    price_in_cents = 0;
    for(i = 0; i < str_price_in_cents.size(); i++){
      price_in_cents *= 10;
      price_in_cents += str_price_in_cents[i] - '0';
    }

    code_list.push_back(code);
    locality_names.insert(pair<string, string>(code, locality_name));
    rates_in_cents.insert(pair<string, int>(code, price_in_cents));
  }

  sort(code_list.begin(), code_list.end(), by_size);

  string call_row, number, str_duration, subscribers_number;
  int duration, cost_in_cents, rate_in_cents;
  bool found;

  cout << fixed;
  while(cin >> number >> str_duration && number != "#"){
    duration = 0;
    for(i = 0; i < str_duration.size(); i++){
      duration *= 10;
      duration += str_duration[i] - '0';
    }

    if(number[0] == '0'){
      found = false;
      i = 0;
      while(i < code_list.size() && !found){
        if(i < code_list.size() && number.size() > code_list[i].size() && code_list[i] == number.substr(0, code_list[i].size())){
          subscribers_number = number.substr(code_list[i].size());
          if(number[1] == '0' && subscribers_number.size() > 3 && subscribers_number.size() < 11){
            found = true;
            code = code_list[i];
          }
          else if(number[1] != '0' && subscribers_number.size() > 3 && subscribers_number.size() < 8){
            found = true;
            code = code_list[i];
          }
        }
        i++;
      }

      if(found){
        locality_name = locality_names[code];
        rate_in_cents = rates_in_cents[code];
        cost_in_cents = rates_in_cents[code] * duration;
      }
      else{
        subscribers_number = "";
        locality_name = "Unknown";
        rate_in_cents = -100;
        cost_in_cents = -100;
      }
    }
    else{
      subscribers_number = number;
      locality_name = "Local";
      rate_in_cents = 0;
      cost_in_cents = 0;
    }

    cout << number;
    for(i = number.size(); i < 16; i++)
      cout << ' ';

    cout << locality_name;
    for(i = 0; i < 35 - locality_name.size() - subscribers_number.size(); i++)
      cout << ' ';
    cout << subscribers_number;

    for(i = 0; i < 5 - str_duration.size(); i++)
      cout << ' ';
    cout << str_duration;

    if(rate_in_cents == -100)
      cout << "      ";
    else{
      for(i = 0; i < 6 - to_decimal_size(rate_in_cents); i++)
        cout << ' ';
      cout << setprecision(2) << rate_in_cents/100.0;
    }

    for(i = 0; i < 7 - to_decimal_size(cost_in_cents); i++)
      cout << ' ';
    cout << setprecision(2) << cost_in_cents/100.0 << '\n';
  }

  return 0;
}
