#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;
int v[MAXN],q[MAXN];

int bs(int left , int right, int k)
{
  while(right - left > 1)
    {
      int med =  (right + left) /2 ;
      if(v[med] > k)
	right = med;
      else
	left = med;
    }
  return left;
}


int main()
{
  int n ; cin >> n;
  for(int i =0 ; i < n ; ++i)
    {
      cin >> v[i];
    }
  int k ; cin >> k;
  sort(v,v+n);
  // for(int i =0 ; i < n ; ++i)
  //   cout << v[i];
  for(int i = 0 ; i < k; ++i)
    {
      cin >> q[i];
      int res = bs(0,n,q[i]);
      // cout << v[res] << "  adsa\n";
      if(v[res] > q[i])
	cout << 0 << "\n";
      else
	cout << res+1 << "\n";
    }
  return 0;
}
