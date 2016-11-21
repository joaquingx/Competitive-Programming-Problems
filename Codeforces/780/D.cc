#include <bits/stdc++.h>
using namespace std;


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  vector<int> ans;
  int n,a,b,k; cin >> n >> a >> b >> k;
  --a;
  string pat; cin >> pat;
  pat+='1';
  int cur =0,cnt=0;
  for(int i = 0 ;i <= n ; ++i)
    {
      if(pat[i] == '1')
	{
	  cnt += cur/b;
	  cur=0;
	}
      else ++cur;
    }
  // cout << cnt << "\n";
  cur = 0;
  for(int i = 0 ;i <= n ; ++i)
    {
      if(pat[i] == '1')
	{
	  int how = cur/b;
	  if(how > 0)
	    {
	      // cout << cnt << " "<< how << "\n";
	      if(cnt - how <= a)
		{
		  // cout << "entre\n";
		  int gg = (cnt-a)*b;
		  // cout << gg << "\n";
		  for(int j = b ; j <= gg ; j+=b)
		    ans.push_back(i-j);
		}
	      else
		{
		  for(int j = b ; j <= cur ; j+=b)
		    ans.push_back(i-j);
		}
	      cnt -= how;
	    }
	  cur=0;
	}
      else ++cur;
    }
  cout << ans.size() << "\n";
  for(int i= 0 ;i < ans.size() ; ++i)
    cout << ans[i]+1 << " ";
  cout << "\n";
  return 0;
}

