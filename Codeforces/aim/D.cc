#include <bits/stdc++.h>
using namespace std;

void init()
{
  int k =2;
  for(int i = 1 ; i <=INF; i += k)
    {
      s.insert(i);
      ++k;
    }
}


int main()
{
  init();
  int a,b,c,d; cin >> a>> b >> c>>> d;
  if(s.find(a) == s.end() or s.find(d) == s.end())
    {
      cout << "Impossible\n";
      return 0;
    }
  for(int )  
  return 0;
}
