#include <bits/stdc++.h>
#define MAXN 501
using namespace std;
typedef long long ll;
ll d[MAXN][MAXN],n,bucket[MAXN];
vector<ll> vec,res;

void floyd()
{
  for(int l = 0 ; l < vec.size() ; ++l)
    {
      int k = vec[l]-1;
      bucket[k] = 1;
      for(int i = 0 ; i < n ; ++i)
	for(int j = 0 ; j < n ; ++j)
	  d[i][j] = min( d[i][j] , d[i][k] + d[k][j]);
      ll ans = 0;
      for(int i = 0 ; i < n ; ++i)
	for(int j = 0 ; j < n ; ++j)
	  {
	    if(bucket[i] and bucket[j])
	      ans+= d[i][j];
	  }
      res.push_back(ans);
    }
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  memset(bucket,0,sizeof bucket);
  cin >> n;
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n ; ++j)
      cin >> d[i][j];
  vec.resize(n);
  for(int i =  0; i < n ; ++i)
    {
      cin >> vec[i];
    }
  reverse(vec.begin() , vec.end());
  floyd();
  for(int i = n-1 ; i>= 0 ; --i)
    cout << res[i] << " ";
  cout << "\n";
  return 0;
}
