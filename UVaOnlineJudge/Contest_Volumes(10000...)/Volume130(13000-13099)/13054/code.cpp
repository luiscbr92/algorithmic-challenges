#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    vector<int> hippos;
    int cases, c, number_of_hippos, heigth_gate, time_single, time_double, time_spent, i, tmp, front_index, back_index;

    cin >> cases;
    for(c = 1; c <= cases; c++){
        hippos.clear();
        time_spent = 0;
        cin >> number_of_hippos >> heigth_gate >> time_single >> time_double;
        for(i = 0; i < number_of_hippos; i++){
            cin >> tmp;
            hippos.push_back(tmp);
        }

        if(time_double < 2*time_single){
            sort(hippos.begin(), hippos.end());
            front_index = 0;
            back_index = number_of_hippos -1;

            while(front_index < back_index){
                    if(hippos[front_index] + hippos[back_index] < heigth_gate){
                        time_spent += time_double;
                        front_index++;
                        back_index--;
                    }
                    else{
                        time_spent += time_single;
                        back_index--;
                    }
            }
            if(back_index == front_index) time_spent += time_single;

            cout << "Case " << c << ": " << time_spent << "\n";
        }
        else cout << "Case " << c << ": " << time_single*number_of_hippos << "\n";

    }

    return 0;
}
