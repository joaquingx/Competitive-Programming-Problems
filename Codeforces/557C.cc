#include <bits/stdc++.h>
#define MAXN int(1e5+100)
using namespace std;
typedef long long ll;
ll sum[MAXN],v1[MAXN],v2[MAXN];
vector< vector<int> > cnt;

vector< pair<ll,ll> > v;

bool cmp( pair<ll,ll> a , pair<ll,ll> b)
{
  if(a.first == b.first)
    return a.second <= b.second;
  return a.first < b.first;
}

void init()
{
  cnt.resize(210);
  for(int i = 0 ; i < 210 ; ++i)
    {
      cnt[i].resize(MAXN,0);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  init();
  memset(sum,0,sizeof sum);
  int n; cin>> n;
  for(int i= 0 ; i < n ; ++i)
    cin >> v1[i];
  for(int i = 0 ; i< n ; ++i)
    cin >> v2[i];
  v.resize(n);
  for(int i = 0 ; i < n ; ++i)
    {
      v[i] = {v1[i],v2[i]};
      ++cnt[v2[i]][v1[i]];
    }
  sort(v.begin(),v.end(),cmp);
  // for(int i = 0 ; i < n ; ++i)
  //   {
  //     cout << v[i].first << " "<< v[i].second << "\n";
  //   }
  for(int i = 1 ; i <= 200 ; ++i)
    {
      for(int j = 1; j < cnt[i].size() ; ++j)
	{
	  cnt[i][j] += cnt[i][j-1];
	}
    }
  sum[0] = v[0].second;
  for(int i = 1 ; i < n; ++i)
    {
      sum[i] = v[i].second +  sum[i-1];
    }
  ll ans=10000000000000;
  int state = v[0].first,contador=0;
  ll mine = 0;
  v.push_back({1000000000,100000000});
  for(int i = 1 ; i < n+1 ; ++i)
    {
      if(state != v[i].first)
	{
	  // cout << "v[i] : "<< state << "\n";
	  // if(contador*2-1 < i)
	  //   {
	      mine += sum[n-1] - sum[i-1];
	      // cout << "premine: "<< mine << "\n";
	      ll cc = n-(n-i);
	      // cout << "elementos : " << cc << "\n";
	      // cout << "contador : "  << contador << "\n";
	      if(cc > contador*2-1)
		{
		  for(int j = 1 ; j <= 200 ; ++j)
		    {
		      // cout << "contador : "<<contador << "\n";
		      if( cc-(contador*2-1) <= cnt[j][state-1])
			{
			  mine += (cc-(contador*2-1)) * j;
			  break;
			}
		      mine += cnt[j][state-1]*j;
		      cc -= cnt[j][state-1];
		    }
		}
	    // }
	  // cout << mine << "\n";
	  ans = min(ans,mine);
	  mine = 0;
	  contador = 0 ;
	  state = v[i].first;
	}
      ++contador;
    }
  
  cout << ans << "\n";
  return 0;
}
