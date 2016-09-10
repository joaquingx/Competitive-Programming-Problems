#include <bits/stdc++.h>
using namespace std;
vector<int> vec,bb;
int n;

int initbb(int v)
{
  bb.clear();
  int cnt =0;
  for(int i= 0 ; i < n ; ++i)
    {
      if(i >= 1 and  vec[i] == vec[i-1]) ++cnt;
      else cnt = 1;
      if(cnt <= v )
	{
	  bb.push_back(vec[i]);
	  // cout << bb.back() << "\n";
	}
	
    }
}
int main()
{
   cin >> n;
  for(int i = 0 ; i < n ; ++i)
    {
      int k; cin >> k;
      vec.push_back(k);
    }
  sort(vec.begin() , vec.end());
  int l = 0, r = n;
  while(r - l > 1)
    {
      int med = (r + l) /2 ;
      initbb(med);
      if(bb.size() >= med * 3) l = med;
      else
	r = med;
    }
  cout << l << "\n";
  initbb(l);
  for(int i= 0 ; i < l ; ++i)
    {
      cout << bb[2*l+i] << " " << bb[l + i] << " " <<bb[i] << "\n";
    }
  return 0;
}
