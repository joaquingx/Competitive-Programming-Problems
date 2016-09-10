#include <bits/stdc++.h>
using namespace std;

int main()
{
  int cnt = 0;
  int n,c; cin >> n >> c;
  if(n <= 1 and c <= 1)
    {
      cout << "0";
      return 0;
    }
  while(n > 0 and c > 0)
    {
      int aux = n;
      n = max(n,c);
      c = min(aux,c);
      n -= 2;
      c += 1;
      ++cnt;
    }
  cout << cnt << "\n";
  return  0;
}
