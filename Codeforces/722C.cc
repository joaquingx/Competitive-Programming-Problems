#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> sum,a,d;
vector<int> p,rating;

void dsuCreate(int u,ll suma)
{
  p[u] = u;
  rating[u] = 0;
  sum[u] = suma;
}

int dsuFind(int v)
{
  return (v == p[v] ? v : p[v] = (dsuFind(p[v]) ) );
}

void dsuUnion(int u , int v)
{
  u = dsuFind(u);
  v = dsuFind(v);
  if(rand() & 1)
    swap(u,v);
  p[u] = v;
  sum[v] += sum[u];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n; cin >> n;
  a.resize(n);sum.resize(n);d.resize(n);p.resize(n,-1);rating.resize(n);
  for(int i = 0 ;i < n; ++i)
    cin >> a[i];
  for(int i = 0 ;i < n ; ++i)
    {
      cin >> d[i];
      --d[i];
    }
  ll ans = -1;
  vector<ll> rpta;
  for(int i = n - 1 ; i>= 1 ; --i)
    {
      if(p[d[i]] == -1)
	dsuCreate(d[i],a[d[i]]);
      if( (d[i]-1) >= 0 and p[d[i]-1] != -1)
	dsuUnion(d[i],d[i]-1);
      if( (d[i]+1) < n and p[d[i]+1] != -1   )
	dsuUnion(d[i],d[i]+1);
      ans = max(ans,sum[ dsuFind(d[i]) ]   );
      rpta.push_back(ans);
    }
  for(int i = rpta.size() -1 ;i  >= 0 ; --i)
    cout << rpta[i] << "\n";
  cout << 0 << "\n";
  return 0;
}
