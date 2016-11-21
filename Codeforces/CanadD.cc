#include <bits/stdc++.h>
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
    return sum(r) - sum(l-1);
  }
  void init(vector<int> a) {
    init(a.size());
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }
};


int main()
{
  FenwickTree acum,acum2;
  int n;
  scanf("%d",&n);
  for(int i = 0 ;i < n; ++i)
    {
      scanf("%lld %lld",&a[i].first , &a[i].second);
      dif[i] = a[i].second - a[i].first;
    }
  sort(a.begin() , a.end() , greater< pair<int , int > () );
  sort(dif.begin() , dif.end());
  acum.init(vector<int>(n,0));
  acum2.init(vector<int>(n,0));
  for(int i = 0 ; i < n; ++i)
    {
      
    }
}
