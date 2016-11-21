#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n ; cin >> n;
  cout << (n / 5) + ( n%5 > 0 ? 1 : 0 ) << "\n";
  return 0;
}
