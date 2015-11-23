#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string line;
    vector<char> a;
    vector<char> b;
    char tmp;
    int i, j, start_pointer;

    while(getline(cin, line)){
        a.clear();
        b.clear();

        for(i = 0; i < line.size(); i++) a.push_back(line[i]);
        getline(cin,line);
        for(i = 0; i < line.size(); i++) b.push_back(line[i]);

        // Insertion sort (vector a)
        for(i = 1; i < a.size(); i++){
            tmp = a[i];
            j = i-1;
            while(j >= 0 && a[j] > tmp){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = tmp;
        }

        // Insertion sort (vector b)
        for(i = 1; i < b.size(); i++){
            tmp = b[i];
            j = i-1;
            while(j >= 0 && b[j] > tmp){
                b[j+1] = b[j];
                j--;
            }
            b[j+1] = tmp;
        }

        start_pointer = 0;
        for(i = 0; i < a.size(); i++){
            j = start_pointer;
            while(j < b.size() && a[i] != b[j]) j++;
            if(j < b.size() && a[i] == b[j]){
                start_pointer = j+1;
                cout << a[i];
            }
        }
        cout << endl;
    }

    return 0;
}
