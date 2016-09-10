#include <bits/stdc++.h>
using namespace std;
struct triplet {
  int x,y,z;
  triplet(int nx, int ny , int nz)
  {
    x = nx ; y = ny ; z = nz;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  int n; cin >> n;
  multiset<int> p;
  vector<triplet> ans;
  for(int i = 0 ; i < n ;++i)
    {
      int k ; cin >> k;
      p.insert(k);
    }
   for(auto it = p.begin() ; it != p.end() ; it++)
    {
      int first = (*it);
      auto i1 = p.lower_bound(first+1);
      int dist = distance(p.begin() , i1);
      if(dist < p.size())
      	{
      	  int second = (*i1);
      	  auto i2 = p.lower_bound(second+1);
      	  int dist2 = distance(p.begin() , i2);
      	  if(dist2 < p.size())
      	    {
      	      int third =  (*i2);
      	      ans.push_back(triplet(third,second,first));
      	      p.erase(i1);
      	      p.erase(i2);
      	    }
      	}
    }
  cout << ans.size()  << "\n"; 
  for(int i  = 0 ; i < ans.size() ; ++i)
    {
      cout << ans[i].x << " "<< ans[i].y << " "<< ans[i].z << "\n";
    }
  return 0;
}


  // for(int i = 0 ; i < n; ++i)
  //   {
  //     int k ;cin >> k;
  //     p.insert(k);
  //   }
  // for(auto it = p.begin() ; it != p.end() ; it++)
  //   {
  //     cout << (*it) << " ";
  //   }
  // cout << "NUMERO DE BUSQUEDAS : \n";
  // cin >> n;
  // for(int i = 0 ; i < n ; ++i)
  //   {
  //     int k ; cin >> k;
  //     auto ii = p.lower_bound(k);
  //     cout << distance(p.begin(),ii) << "\n";
  //     // auto ii = p.find(k);
  //     // p.erase(ii);
  //     // for(auto it = p.begin() ; it != p.end() ; it++)
  //     // 	{
  //     // 	  cout << (*it) << " ";
  //     // 	}
  //   }
  // cout << "\n";
