#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;

int answa(int n)
{
  int a = 1 , b = 1 ,cnt=0;
  while(n > 0)
    {
      n-=a;
      int aux = a;
      a = a + b;
      b = aux;
      ++cnt;
    }
  return cnt;
}


int main()
{
  int n;
  while(cin >> n)
    {
      cout << answa(n) << "\n";
    }
  return 0;
}
