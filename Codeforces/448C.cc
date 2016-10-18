#include <bits/stdc++.h>
#define MAXN int(5*10e4+100)
#define INF int(2*1e9)
using namespace std;
int dp[MAXN],v[MAXN];

int damelo(int i, int j)
{
  int pos = i;
  for(int k = i+1 ; k <= j ; ++k)
    if(v[pos] > v[k])
      pos = k;
  return pos;
}

int calc(int l , int r , int h)
{
  if(l>r) return 0;

  int m = damelo(l,r);
  int res = min(r-l+1, calc(l,m-1,v[m]) + calc(m+1,r,v[m]) + v[m]-h );
  return res;
}

int main()
{
  int n; cin >> n;
  for(int i= 1 ;i <= n ; ++i)
    cin >> v[i];
  cout << calc(1,n,0) << "\n";
  return 0;
}
