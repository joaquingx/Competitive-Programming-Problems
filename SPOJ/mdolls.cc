#include <bits/stdc++.h>
using namespace std;
#define MAXN int(1e6+10)
vector< pair<int,int> > dolls;
int arr[MAXN],fi[MAXN];

int binary_search(int l , int r, int key)
{
  int m;
  while(r-l > 1)
    {
      m = l+(r-l)/2;
      if(arr[fi[m]] >= key)
	r = m;
      else
	l = m;
    }
  return r;
}

int lis(int n)
{
  int len = 0,where;
  fi[0]  = 0 ;
  memset(fi,0,sizeof fi);
  for(int i = 1 ; i < n ; ++i)
    {
      if(arr[i] < arr[fi[0]]) // less than 0
	fi[0] = i;
      else if(arr[i] > arr[fi[len]])
	{
	  ++len;
	  fi[len] = i;
	}
      else
	{
	  where = binary_search(-1,len,arr[i]);
	  fi[where] = i;
	}
    }
  return len+1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t,n; cin >> t;
  while(t--)
    {
      cin >> n;
      dolls.clear();
      dolls.resize(n);
      for(int i = 0 ; i < n ; ++i)
	{
	  int l,k; cin >> l >> k;
	  dolls[i] = {l,k};
	}
      sort(dolls.begin(),dolls.end());
      for(int  i = 0 ; i <  n ; ++i)
      	{
      	  cout << dolls[i].first << dolls[i].second << "\n" ; 
      	}
    }
  // for(int i  = 0 ; i < n ; ++i)
  //   cin >> arr[i];
  // cout << lis(n)  << "\n";
  return 0;
}
