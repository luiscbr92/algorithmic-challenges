#include <iostream>
#include <vector>

#define MILLION   1000000
#define MMILION   1000000000000
#define endl      '\n'

using namespace std;

bool is_prime(int n) {
  if (n<2) return false;
  if (n<=3) return true;
  if (!(n%2) || !(n%3)) return false;
  for (int i=5;i*i<=n;i+=6)
    if (!(n%i) || !(n%(i+2))) return false;
  return true;
}

int main(){

  vector<long> almost_prime;

  for(long i = 2; i < MILLION; i++)
    if(is_prime(i))
      for(long power = i*i; power < MMILION; power *= i)
        almost_prime.push_back(power);

  int cases, n;
  long low, high;
  cin >> cases;

  while(cases--){
    cin >> low >> high;
    n = 0;
    for(long i = 0; i <= almost_prime.size(); i++)
      if(low <= almost_prime[i] && high >= almost_prime[i])
        n++;
    cout << n << endl;
  }

  return 0;
}
