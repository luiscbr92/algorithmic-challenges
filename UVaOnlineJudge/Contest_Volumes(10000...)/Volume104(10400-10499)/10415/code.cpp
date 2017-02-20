#include <iostream>
#include <vector>
#include <map>
#include <utility>

#define endl '\n'

using namespace std;

int main(){

  map<char, vector<bool>> notes;
  vector<bool> p = {0,1,1,1,0,0,1,1,1,1};
  notes.insert(make_pair('c',p));
  p = {0,1,1,1,0,0,1,1,1,0};
  notes.insert(make_pair('d',p));
  p = {0,1,1,1,0,0,1,1,0,0};
  notes.insert(make_pair('e',p));
  p = {0,1,1,1,0,0,1,0,0,0};
  notes.insert(make_pair('f',p));
  p = {0,1,1,1,0,0,0,0,0,0};
  notes.insert(make_pair('g',p));
  p = {0,1,1,0,0,0,0,0,0,0};
  notes.insert(make_pair('a',p));
  p = {0,1,0,0,0,0,0,0,0,0};
  notes.insert(make_pair('b',p));

  p = {0,0,1,0,0,0,0,0,0,0};
  notes.insert(make_pair('C',p));
  p = {1,1,1,1,0,0,1,1,1,0};
  notes.insert(make_pair('D',p));
  p = {1,1,1,1,0,0,1,1,0,0};
  notes.insert(make_pair('E',p));
  p = {1,1,1,1,0,0,1,0,0,0};
  notes.insert(make_pair('F',p));
  p = {1,1,1,1,0,0,0,0,0,0};
  notes.insert(make_pair('G',p));
  p = {1,1,1,0,0,0,0,0,0,0};
  notes.insert(make_pair('A',p));
  p = {1,1,0,0,0,0,0,0,0,0};
  notes.insert(make_pair('B',p));

  int cases;
  string song;
  char note;

  cin >> cases;
  cin.ignore();
  while(cases--){
    getline(cin, song);
    vector<int> pulsations (10, 0);
    vector<bool> pressed (10, false);

    for(int i = 0; i < song.size(); i++){
      note = song[i];
      for(int j = 0; j < 10; j++){
        if(!pressed[j] && notes[note][j])
          pulsations[j]++;
        pressed[j] = notes[note][j];
      }
    }

    cout << pulsations[0] << ' ' << pulsations[1] << ' ' << pulsations[2] << ' ' << pulsations[3] << ' ' << pulsations[4] << ' ' << pulsations[5] << ' ' << pulsations[6] << ' ' << pulsations[7] << ' ' << pulsations[8] << ' ' << pulsations[9] << endl;
  }

  return 0;
}
