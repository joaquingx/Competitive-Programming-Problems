#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 100;
int n,q,v[MAXN],acum[MAXN],ans[MAXN],pos[MAXN];
map<int,int> last;
pair<int,int> seg[MAXN];

struct FenwickTree {
  vector<int> bit; // binary indexed tree
  int n;

  void init(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r+1)) - 1) // saltando hacia atras entre rangos
      {
	// cout << "r : "<<r << "\n";
	ret = ret ^ bit[r];
      }
    return ret;
  }
  void add(int idx, int delta) { // saltando hacia adelante(no necesariamente entre rangos!).
    for (; idx < n; idx = idx | (idx+1))
      bit[idx] =  bit[idx] ^ delta;
  }
  int sum(int l, int r) {
    if(l == 0)
      return sum(r);
    return sum(r) ^ sum(l-1);
  }
  void init(vector<int> a) {
    init(a.size());
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }
};

FenwickTree cnt;

void init()
{
  acum[0] = v[0];
  for(int i=  1; i < n ; ++i)
    acum[i] = acum[i-1] ^ v[i];
}

int query(int l , int r)
{
  if(l == 0)
    return acum[r];
  return acum[r] ^ acum[l-1];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for(int i = 0;i < n ; ++i)
    cin >> v[i];
  cin >> q;
  for(int i= 0 ;i < q ; ++i)
    {
      cin >> seg[i].first >> seg[i].second;
      --seg[i].first;--seg[i].second;
      pos[i] = i;
    }
  sort(pos , pos+q , [&] (int i , int j) {return seg[i].second < seg[j].second ; }   );
  init();
  cnt.init(n);
  int idx=0,posi = pos[idx] ,act = seg[posi].second;
  for(int i = 0 ;i < n ; ++i)
    {
      if(last.find(v[i]) != last.end())
	cnt.add(  last[v[i]] , v[i]    );
      cnt.add(  i , v[i]);
      last[v[i]] = i;//dsadsad
      
      while(idx < q and i == act)
	{
	  int l = seg[posi].first , r = seg[posi].second;
	  ans[posi] = query(l,r) ^ cnt.sum(l,r);
	  posi = pos[++idx];
	  act = seg[posi].second;
	}
    }
  for(int i = 0 ;i < q ; ++i)
    cout << ans[i] << "\n";
}

