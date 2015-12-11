#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int n, a_jump, b_jump, a_pointer, b_pointer, i;
    vector<int> dole;
    string result;
    bool is_first;

    cin >> n >> a_jump >> b_jump;
    while(n != 0 && a_jump != 0 && b_jump != 0){
        is_first = true;
        result = "";
        dole.clear();
        for(i = 1; i <= n; i++) dole.push_back(i);
        a_pointer = dole.size()-1;
        b_pointer = 0;

        while(dole.size() > 0){
            if(!is_first)   result += ",";
            else            is_first = false;

            for(i = 0; i < a_jump; i++){
                a_pointer++;
                if(a_pointer >= dole.size()) a_pointer = 0;
            }
            for(i = 0; i < b_jump; i++){
                b_pointer--;
                if(b_pointer < 0) b_pointer = dole.size() -1;
            }

            if(a_pointer < b_pointer){
                if(dole[a_pointer] > 9) result += " " + to_string(dole[a_pointer]);
                else                    result += "  "+ to_string(dole[a_pointer]);

                if(dole[b_pointer] > 9) result += " " + to_string(dole[b_pointer]);
                else                    result += "  "+ to_string(dole[b_pointer]);

                dole.erase(dole.begin()+b_pointer);
                dole.erase(dole.begin()+a_pointer);

                a_pointer--;
                if(a_pointer < 0) a_pointer = dole.size() -1;
                b_pointer--;
            }
            else if(a_pointer > b_pointer){
                if(dole[a_pointer] > 9) result += " " + to_string(dole[a_pointer]);
                else                    result += "  "+ to_string(dole[a_pointer]);

                if(dole[b_pointer] > 9) result += " " + to_string(dole[b_pointer]);
                else                    result += "  "+ to_string(dole[b_pointer]);

                dole.erase(dole.begin()+a_pointer);
                dole.erase(dole.begin()+b_pointer);

                a_pointer -=2;
                if(a_pointer < 0) a_pointer = dole.size() -1;

            }
            else{
                if(dole[a_pointer] > 9) result += " " + to_string(dole[a_pointer]);
                else                    result += "  "+ to_string(dole[a_pointer]);

                dole.erase(dole.begin()+a_pointer);

                a_pointer--;
                if(a_pointer < 0) a_pointer = dole.size() -1;
            }

        }
        cout << result << "\n";
        cin >> n >> a_jump >> b_jump;
    }

    return 0;
}
