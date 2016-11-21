#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
int v[MAXN],l[MAXN];

int main()
{
  int T; cin >> T;
  while(T--)
    {
      int n,w; cin >> n;
      cin >> w;
      int rpta ;
      int ans = -1;
      for(int i = 0 ;i < n-1 ; ++i)
	cin >> v[i];
      for(int i = 0 ;i < n  ; ++i)
	cin >> l[i];
      sort(v , v + n - 1);
      sort(l, l +n);
      rpta = w*l[n-1];
      for(int i = 0 ; i < n - 1 ; ++i)
	{
	  // cout << v[i] * l[n-i-2] << "\n";
	  ans = max(ans,v[i] * l[n-i-2]);
	}
      if(ans < rpta)
	cout << "YES\n";
      else
	cout << "NO\n";
    }  
  return 0;
}
