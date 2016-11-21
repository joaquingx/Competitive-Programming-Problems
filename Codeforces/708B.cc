#include <bits/stdc++.h>
#define MAXN int(1e9+1000)
#define MAXI int(1e5+100)
using namespace std;
vector<int> pos(MAXI);
void init()
{
  // pos.resize;
  pos[0] = 0;
  pos[1] = 0;
  int k=1;
  for(int i = 2; pos[i] <= MAXN ; ++i)
    {
      pos[i] = pos[i-1] + k;
      k = k + 1;	
    }
}

void impossible()
{
  cout << "Impossible\n";
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  init();
  int c0,c1;
  int a[2][2];
  for(int i=0 ; i < 2 ; ++i)
    for(int j = 0 ; j < 2 ; ++j)
      cin >> a[i][j];
  c0 = find(pos.begin() , pos.end() , a[0][0]) - pos.begin();
  c1 = find(pos.begin(), pos.end(), a[1][1]) - pos.begin();
  if(a[0][0] == 1000000000  and a[0][1] == 0 and a[1][0] == 0 and a[1][1]== 0)
    {
      impossible();
    }
  if(a[0][0] == 0  and a[0][1] == 0 and a[1][0] == 0 and a[1][1] == 10000000000)
    {
      impossible();
    }
  if(a[0][0]+ a[1][0] + a[0][1] + a[1][1] == 0)
    {
      cout << 0 << "\n";
      return 0;
    }
  if (a[0][0] == 0 || a[1][1] == 0) {
    if(!a[0][0]) c0 = 1;
    if(!a[1][1]) c1 = 1;
    if (a[0][1] + a[1][0] == 0) {
      if (c0 == 1) c0 = 0;
      if (c1 == 1) c1 = 0;
      cout << string(c0, '0') << string(c1, '1');
      return 0;
    }
  }
  if(c0 >= pos.size() or c1 >= pos.size()) {
    // cout << c0 << " " << c1 << "\n";
    impossible();
  }
  // cout << c1* c0 << "\n";
  // cout << "algo\n";
  if(a[0][1] + a[1][0] != c1*c0) impossible();
  int req = a[1][0],n = c0 + c1;
  a[0][1] = c1*c0;
  a[1][0] = 0;
  string ans = string(n, '0');
  // cout << c1 << c0 <<"\n";
  for(int i = 0 ; i < n ; ++i)
    {
      // cout << c1 << c0 <<"\n";
      // cout << c0 << "\n";
      if(!c0 or ( (a[1][0] + c0 ) <= req ))
	{
	  ans[i] = '1';
	  a[1][0] += c0;
	  --c1;
	}
      else
	{
	  --c0;
	}
    }
  cout << ans << "\n";
  return 0;
}
