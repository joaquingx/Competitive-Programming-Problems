#include <bits/stdc++.h>
typedef long long ll;
#define MAXN int(5*1e5+10)
#define INF int(1e9+10)
using namespace std;
int n;
ll v[MAXN],s1,s2,s3;
vector<int> idx,idy;

inline ll range(int a, int b)
{
  return v[b] - v[a-1];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n;
  s1 = s2 = s3 = 0;
  v[0]= v[n+1] = 0;
  for(int i = 1 ; i <= n ; ++i)
    cin >> v[i];
  for(int i = 2 ; i <= n ; ++i)
    v[i] += v[i-1];
  if(v[n] % 3 != 0)
    {
      cout << "0" << "\n";
      return 0;
    }
  ll s = v[n]/3;ll s2 = s*2;
  for(int i = 1 ; i < n ; ++i)
    {
      if(v[i] == s) idx.push_back(i);
      if(v[i] == s2) idy.push_back(i);
    }
  ll ans=0;
  int a,b; a = b = 0;
  while(b < idy.size())
    {
      // cout << a << " " << b << "\n";
      // cout << idx[a] << " " << idy[b] << "\n";
      if(a < idx.size() and idx[a] < idy[b])
	++a;
      else
	{
	  ans += a;
	  ++b;
	}	
    }
  cout << ans << "\n";
  return 0;
}
