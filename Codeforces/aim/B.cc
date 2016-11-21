#include <bits/stdc++.h>
#define INF int(1e9)
#define MAXN int(1e5+10)
using namespace std;

bool isinterval(int a, int b , int key)
{
  if(key >=  a and key <= b)
    return 1;
  return 0;
}


int main()
{
  int v[MAXN];
  int n,m; cin >> n >> m;
  for(int i = 0 ;i < n ; ++i)
    {
      cin >> v[i];
    }
  int ans = INF;
  sort(v, v+ n);
  // for(int i = 0 ; i < n; ++i)
  //   cout << v[i] << " ";
  // cout << "\n";
  pair<int,int> p1(v[0],v[n-2]) , p2(v[1],v[n-1]);
  
  int first;
  if(n==2) first = v[n-2];
  else first = v[n-2]-v[0];
  int second;
  if(n==2)second = v[n-1];
  else  second = v[n-1] - v[1];
  if(n == 1)
    {
      cout << 0 << "\n";
      return 0;
    }
  if(n==2)
    {
      ans = min(abs(m-first),abs(m-second));
      cout << ans << "\n";
      return 0;
    }
  if(m < p1.first)
    {
      // cout << "si nos organizamos cojemos todos!\n";
      cout << abs(v[n-2] - m) << "\n";
      return 0;
    }
  if(m > p2.second)
    {
      cout <<abs( m - v[1]) << "\n";
      return 0;
    }
  int cercano=INF;
  cercano = min(cercano , abs(m - v[0]));
  cercano = min(cercano,abs(v[n-2] - m));
  ans = min(ans, abs(cercano) + abs(first));
  cercano = INF;
  cercano = min(cercano , abs(m - v[1]));
  cercano = min(cercano,abs(v[n-1] - m));
  ans = min(ans, abs(cercano)+ abs(second));
      
  cout << ans << "\n";
  return 0;
}
