#include <bits/stdc++.h>
#define MAXN 30050
#define Q 200010
using namespace std;

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
	ret += bit[r];
      }
    return ret;
  }
  void add(int idx, int delta) { // saltando hacia adelante(no necesariamente entre rangos!).
    for (; idx < n; idx = idx | (idx+1))
      bit[idx] += delta;
  }
  int sum(int l, int r) {
    int ll = l-1;
    if(ll < 0)
      return sum(r);
    return sum(r) - sum(ll);
  }
  void init(vector<int> a) {
    init(a.size());
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }
};

FenwickTree tree;
int p[MAXN],a[MAXN],ans[Q],rpta[Q];
vector<int> ini;
pair< int, pair<int , int > > orden[Q];

int main()
{
  int n,q,l,r,k ; scanf("%d",&n);
  for(int i = 0 ;i < n ; ++i)
    {
      scanf("%d",&a[i]);
      p[i] = i;
    }
  scanf("%d",&q);
  for(int i =0 ;i < q ; ++i)
    {
      scanf("%d %d %d",&l,&r,&k);
      orden[i] = {k, {l,r}} ;
      ans[i] = i;
    }
  sort(p, p + n, [&] (int i , int j) { return a[i] < a[j] ; }   );
  sort(ans, ans + q , [&](int i , int j) {return orden[i].first < orden[j].first ;} );
  ini.assign(n,1);
  tree.init(ini);
  int ptr = 0,kact,left,right,idxact,idx;
  for(int i = 0; i < q ; ++i)
    {
      idx = ans[i];
      kact = orden[idx].first;
      left = orden[idx].second.first; right = orden[idx].second.second;
      while(ptr < n && a[p[ptr]] <= kact)
	tree.add(p[ptr++],-1);
      rpta[ans[i]] = tree.sum(left-1,right-1);
    }

  for(int i = 0 ; i < q ; ++i)
    printf("%d\n",rpta[i]);
  return 0;
}
