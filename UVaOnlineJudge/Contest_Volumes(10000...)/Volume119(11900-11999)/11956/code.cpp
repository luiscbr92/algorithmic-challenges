#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, i, pointer;
    int memory[100];
    char instruction;
    string line;

    cin >> cases;
    cin.ignore();
    for(c = 1; c <= cases; c++){
        getline(cin, line);
        for(i = 0; i < 100; i++) memory[i] = 0;

        pointer = 0;
        for(i = 0; i < line.size(); i++){
            instruction = line[i];
            if(instruction == '+'){
                memory[pointer]++;
                if(memory[pointer] == 256) memory[pointer] = 0;
            }
            else if(instruction == '-'){
                memory[pointer]--;
                if(memory[pointer] == -1) memory[pointer] = 255;
            }
            else if(instruction == '>'){
                pointer++;
                if(pointer == 100) pointer = 0;
            }
            else if(instruction == '<'){
                pointer--;
                if(pointer == -1) pointer = 99;
            }
        }

        printf("Case %d:", c);
        for(i = 0; i < 100; i++) printf(" %02X", memory[i]);
        printf("\n");
    }

    return 0;
}
