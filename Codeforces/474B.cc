#include <bits/stdc++.h>
#define MAXN int(1e5+1)
using namespace std;
int v[MAXN];

int bs(int left , int right, int k)
{
  while( right - left > 0)
    {
      int med = (right + left)/2;
      if(v[med] < k)
	left = med+1;
      else
	right = med;
    }
  // cout << left << " " << right << "\n";
  // if(v[left] < k)
  //   return right;
  // if(abs(v[left]-k) < abs(v[right] - k))
  //   return left;
  return right;
}



int main()
{
  int n,m; cin >> n;
  for(int i =0  ;i < n; ++i)
    {
      cin >> v[i];
    }
  for(int i = 1 ; i < n ; ++i)
    {
      v[i] += v[i-1];
      // cout << v[i] << " ";
    }
  // cout << "\n";
  cin >> m;
  for(int i =0 ; i < m ; ++i)
    {
      int x; cin >> x;
      cout << bs(0,n,x)+1 <<"\n";
    }
  return 0;
}
