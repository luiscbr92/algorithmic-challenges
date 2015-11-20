#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    string l1 = "\\ /  o          _o_ \\o/ \\o_ \\o/      o  ";
    string l2 = " |  /|\\          |   |  \\|  \\|/  __o( ) ";
    string l3 = "/o\\ / \\ __\\o\\_\\o/ \\ / \\  |      /  |/ \\ ";

    string output1;
    string output2;
    string output3;

    string line;
    int cases, x, length, i;
    //bool is_first;

    //if(l1.size() == l2.size() && l1.size() == l3.size()) cout << "OK" << endl;
    cin >> cases;
    cin.ignore();
    while(cases--){
        output1 = "";
        output2 = "";
        output3 = "";
        getline(cin, line);
        length = line.size();

        for(i = 0; i < length; i++){
            x = line[i] - '0';
            if(i != 0){
                output1 += " ";
                output2 += " ";
                output3 += " ";
            }
            output1 += l1.substr(x*4, 4);
            output2 += l2.substr(x*4, 4);
            output3 += l3.substr(x*4, 4);
        }

        cout << output1 << endl << output2 << endl << output3 << endl << endl;
    }



    return 0;
}
