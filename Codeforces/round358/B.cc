#include <bits/stdc++.h>
#define MAXN int(1e6+10)
using namespace std;

int main()
{
  int n; cin >> n;
  int v[MAXN],cnt;
  for(int i  = 0; i < n; ++i)
    cin >> v[i];
  sort(v, v+n);
  cnt = 1;
  for(int i = 0 ; i < n; ++i )
    {
      if(v[i] >= cnt)
	cnt++;
    }
  cout << cnt << "\n";
  return 0;
}
