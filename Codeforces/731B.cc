#include <bits/stdc++.h>
#define MAXN int(1e5*2+100)
using namespace std;
int a[MAXN];

int main()
{
  int n; cin >> n;
  for(int i =0 ; i < n ; ++i)
    cin >> a[i];
  int c = a[0];
  for(int i = 1 ; i < n ; ++i)
    {
      int ad = a[i];
      if(ad == 0 and c % 2 == 1)
	{ cout << "NO\n";  return 0;
	}
      if(ad % 2  == 0 and c % 2 ==0)
	c = 0 ;
      else
	if(ad % 2 == 0 and c % 2 != 0)
	    c = 1;
	else
	  if(ad % 2 != 0 and c % 2 != 0)
	    c = 0;
	  else
	    c = 1;
    }
  if(c % 2 !=0)
    cout << "NO";
  else
    cout << "YES";
  cout << "\n";
  return 0;
}
