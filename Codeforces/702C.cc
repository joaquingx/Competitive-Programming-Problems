#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define NEG -ll(4*1e10+10)
vector<ll> v1,v2;

int bs1(ll key)
{
  int ini = 0, fin = v1.size(),med;
  while(fin > ini)
    {
      med = (ini + fin)/2;
      if(v1[med] > key)
	fin = med - 1;
      if(v1[med] < key)
	ini = med + 1;
      if(v1[med] == key)
	return med;
    }
  return ini;
}


int bs2(ll key)
{
  int ini = 0, fin = v1.size(),med;
  while(fin > ini)
    {
      med = (ini + fin)/2;
      if(v1[med] > key)
	fin = med - 1;
      if(v1[med] < key)
	ini = med + 1;
      if(v1[med] == key)
	return med;
    }
  return fin;
}

int main()
{
  ios_base::sync_with_stdio(0);
  ll n,m; cin >> n >> m;
  for(int i = 0 ; i < n; ++i)
    {
      ll k; cin >> k;
      v1.push_back(k);
    }
  v2.push_back(NEG);
  for(int i =0 ;i < m ; ++i)
    {
      ll k ; cin >> k;
      v2.push_back(k);
    }
  v2.push_back(-NEG);
  ll ans=-1;
  for(int i = 1 ; i < v2.size() ; ++i)
    {
      ll diff = abs(v2[i] - v2[i-1]);
      // cout << "la diff  = " << diff << "\n";
      ll alc = diff/2+1;
      // cout << v2[i] - alc << "\n";
      ll low =  bs2(v2[i-1]+alc);
      ll up = bs1(v2[i]-alc);
      if(low < 0 ) low= 0;
      if(up < 0 ) up = 0 ;
      if(low == v1.size()) --low;
      if(up == v1.size()) --up;
      // cout << low << "  " << up <<  "\n";
      if(v2[i] < v1[low] or v2[i] < v1[up] or v2[i-1] > v1[up] or  v2[i-1] > v1[low])
	{
	  continue;
	}
      // cout << "pasemdf\n";
      ans = max(ans, min
		( max( abs(v1[low]-v2[i-1]) , abs(v1[up]- v2[i-1]) ) ,max( abs(v2[i]-v1[low]) , abs(v2[i] - v1[up]))
		  ));
      // ans = max(ans, min(abs(v1[up]-v2[i-1]),abs(v2[i]-v1[up]) )  );
    }
  cout << ans << "\n";
  return 0;
}
