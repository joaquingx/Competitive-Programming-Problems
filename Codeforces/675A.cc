#include <bits/stdc++.h>
#define MAXN int(1e9)
using namespace std;


int main()
{
  int a,b,c; cin >> a >> b >> c;
  // if(b < a)
  //   {
  //     cout << "NO\n";
  //     return 0;
  //   }
  if(b < a)
    {
      if(a + c > a)
	{
	  cout << "NO\n";
	  return 0;
	}
    }
  else
    {
      if(a == b)
	{
	  cout << "YES\n";
	  return 0;
	}
      if(a +c < a)
	{
	  cout << "NO\n";
	  return 0;
	}
    }
  if(c== 0)
    if(a == b)
      {
	cout << "YES\n";
	return 0;
      }
    else
      {
	cout << "NO\n";
	return 0;
      }
  int k;
  k = a - b;
  // if(a < 0 and b < 0)
  //   k = a+c;
  // else
  //   k = a-c;
  // cout << k << "\n";
  if(k% c==0)
    {
      cout << "YES\n";
      return 0;
    }
  else
    cout << "NO\n";
  return 0;
}
