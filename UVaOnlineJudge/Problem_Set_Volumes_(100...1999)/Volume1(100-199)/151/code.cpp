#include <iostream>
#include <vector>

using namespace std;

vector<int> make_vector(int n){
    vector<int> my_vector;
    for(int i = 1; i <= n; i++) my_vector.push_back(i);
    return my_vector;
}

int main(){
    ios_base::sync_with_stdio (false);

    int number_of_regions, index, jump;
    vector<int> regions;

    while(cin >> number_of_regions && number_of_regions != 0){
        regions = make_vector(number_of_regions);
        jump = 1;
        index = 0;
        regions.erase(regions.begin());

        while( !(regions.size() == 1 && regions[0] == 13) ){
            index = (index + jump -1) % regions.size();
            if(regions[index] != 13){
                regions.erase(regions.begin() + index);
            }
            else{
                regions = make_vector(number_of_regions);
                jump++;
                index = 0;
                regions.erase(regions.begin());
            }
        }
        cout << jump << "\n";
    }

    return 0;
}
