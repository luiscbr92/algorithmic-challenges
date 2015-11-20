#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int n_of_devices, operations, consumption_limit, current_consumption, max_consumption, device, i;
    int sequence = 1;

    cin >> n_of_devices >> operations >> consumption_limit;

    while(n_of_devices != 0 && operations != 0 && consumption_limit != 0){
        int consumption[n_of_devices];
        bool isturnedon[n_of_devices];
        current_consumption = 0;
        max_consumption = 0;

        for(i = 0; i < n_of_devices; i++){
            cin >> consumption[i];
            isturnedon[i] = false;
        }

        for(i = 0; i < operations; i++){
            cin >> device;
            if(current_consumption < consumption_limit){
                device -= 1;
                if(isturnedon[device])  current_consumption -= consumption[device];
                else{
                    current_consumption += consumption[device];
                    if(current_consumption > max_consumption) max_consumption = current_consumption;
                }
                isturnedon[device] = !isturnedon[device];
            }
        }

        cout << "Sequence " << sequence << endl;
        if(current_consumption <= consumption_limit){
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << max_consumption << " amperes." << endl;
        }
        else cout << "Fuse was blown." << endl;

        cout << endl;
        cin >> n_of_devices >> operations >> consumption_limit;
        sequence += 1;
    }


    return 0;
}
