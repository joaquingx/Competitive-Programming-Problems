#include <bits/stdc++.h>
#define MAXN int(1e5)
using namespace std;
int array[MAXN];
int lis[MAXN];

int LIS(int n, int m)
{
  if(lis[n] != 0)
    {
      return lis[n];
    }
  else
    {
      for(int i = m ; i >= 0 ; --i)
	{
	  LIS(i,i-1);
	  if(array[i] < array[n])
	    lis[n] = max(lis[n],lis[i]);
	}
      lis[n]+=1;
    }
  return lis[n];
}


int main()
{
  int n; cin >> n;
  memset(lis,0,sizeof lis);
  for(int i = 0 ; i < n ; ++i	)
    cin >> array[i];
  lis[0] = 1;
  LIS(n-1,n-2);
  for(int  i =0 ; i < n ; ++i)
    cout << lis[i] << "\n";
  return 0;
}
