#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
typedef long long ll;
vector<int>  smash;
ll acum[MAXN];
ll v1[MAXN],v2[MAXN];
set<int> joshi;

vector<int> Z (string &p)
{
  vector<int> Z(p.size()); Z[0] = 0;
  for(int i = 1, l  = 0 , r = 0 ; i < p.size(); ++i)
    {
      if(i <= r)
	Z[i] = min(r-i+1 , Z[i-l]);
      while( Z[i] < p.size() && p[Z[i]] == p[i+Z[i]] )
	++Z[i];
      if(i+Z[i]-1 > r)
	l = i , r = i+Z[i]-1;
    }
  return Z;
}

int main()
{
  ios::sync_with_stdio(false);
  ll carry=0;
  string pat ; cin >> pat;
  int n=(int)pat.size(),j=0 ; smash.resize(n);
  memset(acum,0,sizeof acum);
  smash = Z(pat);
  // for(int i = 0 ; i < n ; ++i)
  //   cout << smash[i] << " ";
  // cout << "\n";
  for(int i = 0 ; i < n ;++i)
    {
      acum[smash[i]]++;
      if(n-i == smash[i])
	{
	  // cout << "me imprimi : " << pat[i] << " " << i << " "  << "\n";
	  joshi.insert(smash[i]);
	}
    }
  cout << joshi.size()+1 << endl;
  for(int i = MAXN-1 ; i >= 1 ;--i)
    {
      carry += acum[i];
      if(joshi.find(i) != joshi.end()) //existen
	{
	  v1[j] = i;
	  v2[j] = carry+1;
	  j++;
	}
    }
  for(int i  = j-1 ; i >= 0 ;--i )
    {
      cout << v1[i] << " " << v2[i] << endl;
    }
  cout << pat.size() << " " << 1 << endl;
  return 0;
}
