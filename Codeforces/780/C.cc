#include <bits/stdc++.h>
using namespace std;
int n , a , b , k ;
vector<int> par;
vector< pair<int , int > > arr;

bool doing(int j)
{
  int time = 0;
  for(int i = 1 ; i  <= a+1 ; ++i)
    {
      // cout << par[i] << " ";
      int act = par[i] - par[i-1],gasto;
      if(act <= arr[j].first)
	{
	  gasto = act * 2;
	  gasto -= min((arr[j].first - act),act);
	}
      else
	{
	  return 0;
	}
      time += gasto;
      // cout << time << "\n";
    }
  // cout << " termine\n";
  if(time <= k)
    return 1;
  return 0;    
}

/* n is the size of the int[] array A. */
int lower_bound(int n)
{
    int l = 0;
    int r = n;
    while (l < r)
    {
        int m = (l+r)/2;     /* Rounds toward zero. */
	if(!doing(m))
            l = m+1;
        else
            r = m;
    }
    return l;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> a >> b >> k;
  arr.resize(n);
  for(int i= 0 ;i < n ; ++i)
    {
      cin >> arr[i].first >> arr[i].second;
      swap(arr[i].first , arr[i].second);
    }
  sort(arr.begin() ,  arr.end());
  par.resize(a+2);
  for(int i = 0 ; i < a ; ++i)
    cin >> par[i];
  par[a] = 0;
  par[a+1] = b;
  sort(par.begin() , par.end());
  int low = lower_bound(n),rpta=2000000000;
  // cout << low << "\n";
  for(int i= low ; i < n ; ++i)
    rpta = min(arr[i].second,rpta);
  if(rpta == 2000000000)
    cout << -1 << "\n";
  else cout << rpta << "\n";
  return 0;
}
