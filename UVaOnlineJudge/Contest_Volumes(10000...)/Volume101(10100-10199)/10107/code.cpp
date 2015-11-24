#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    vector<long> data;
    vector<long>::iterator it;
    long input;
    int index = 0;
    string result = "";

    while(cin >> input){
        it = data.begin();
        while(it != data.end() && *it < input) it++;
        data.insert(it, input);

        if(data.size() % 2 == 0){
            result += to_string((data[index]+data[index+1])/2) + "\n";
            index++;
        }
        else{
            result += to_string(data[index]) + "\n";
        }
    }

    cout << result;

    return 0;
}
