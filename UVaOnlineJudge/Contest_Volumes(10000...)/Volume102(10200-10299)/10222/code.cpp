#include <iostream>
#include <map>

using namespace std;

int main(){

  map<char, char> decode;
  decode[' '] = ' ';
  decode['e'] = 'q';
  decode['E'] = 'q';
  decode['r'] = 'w';
  decode['R'] = 'w';
  decode['t'] = 'e';
  decode['T'] = 'e';
  decode['y'] = 'r';
  decode['Y'] = 'r';
  decode['u'] = 't';
  decode['U'] = 't';
  decode['i'] = 'y';
  decode['I'] = 'y';
  decode['o'] = 'u';
  decode['O'] = 'u';
  decode['p'] = 'i';
  decode['P'] = 'i';
  decode['['] = 'o';
  decode[']'] = 'p';

  decode['d'] = 'a';
  decode['D'] = 'a';
  decode['f'] = 's';
  decode['F'] = 's';
  decode['g'] = 'd';
  decode['G'] = 'd';
  decode['h'] = 'f';
  decode['H'] = 'f';
  decode['j'] = 'g';
  decode['J'] = 'g';
  decode['k'] = 'h';
  decode['K'] = 'h';
  decode['l'] = 'j';
  decode['L'] = 'j';
  decode[';'] = 'k';
  decode['\''] = 'l';

  decode['c'] = 'z';
  decode['C'] = 'z';
  decode['v'] = 'x';
  decode['V'] = 'x';
  decode['b'] = 'c';
  decode['B'] = 'c';
  decode['n'] = 'v';
  decode['N'] = 'v';
  decode['m'] = 'b';
  decode['M'] = 'b';
  decode[','] = 'n';
  decode['.'] = 'm';

  string encoded;
  getline(cin, encoded);
  string message = "";

  for (int i = 0; i < encoded.size(); i++) {
    message = message + decode[encoded[i]];
  }

  cout << message << endl;

  return 0;
}
