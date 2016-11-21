#include <bits/stdtr1c++.h>
#define MAXN int(1e5+10)
using namespace std;
int block_size,n,m,pos[MAXN],v[MAXN],cur=0,posi,l,r,ans[MAXN];
pair<int,int> q[MAXN];
unordered_map<int,int> mapa;

namespace fastio{
    int ptr, ye;
    char temp[25], str[32333667], out[15333667];

    void init(){
        ptr = 0, ye = 0;
        fread(str, 1, 32333667, stdin);
    }

    inline int number(){
        int i, j, val = 0;

        while (str[ptr] < 45 || str[ptr] > 57) ptr++;
        while (str[ptr] > 47 && str[ptr] < 58) val = (val * 10) + (str[ptr++] - 48);
        return val;
    }

    inline void convert(int x){
        int i, d = 0;
        if (x < 0) x = -x, out[ye++] = 45;

        for (; ;){
            temp[++d] = (x % 10) + 48;
            x /= 10;
            if (!x) break;
        }
        for (i = d; i; i--) out[ye++] = temp[i];
        out[ye++] = 10;
    }

    inline void print(){
        fwrite(out, 1, ye, stdout);
    }
}


inline bool comp(int i ,int j)
{
  if(q[i].first/block_size != q[j].first/block_size)
    return q[i].first/block_size < q[j].second/block_size;
  return q[i].second < q[j].second;
}

int main()
{
  ios_base::sync_with_stdio(0);
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(0);
  scanf("%d %d",&n,&m);
  // printf("%d",n);
  for(int i = 0 ;i < n ; ++i)
    scanf("%d",&v[i]);
    // cin >> v[i];
  // cout << "algo";
  for(int i = 0 ; i < m ; ++i)
    {
      scanf("%d %d",&q[i].first,&q[i].second);
      --q[i].first;--q[i].second;
      pos[i] = i;
    }
  block_size = int(n  / sqrt(n));
  sort(pos, pos + m , comp);
  int mor = -1,mol=0;
  for(int i = 0 ; i < m ; ++i)
    {
      posi = pos[i];
      l = q[posi].first ; r = q[posi].second;
      while(mol < l)
	{
	  // if(mapa.find())
	  if(mapa[v[mol]] == v[mol])
	    --cur;
	  --mapa[v[mol]];
	  ++mol;
	}
      while(mol > l )
	{
	  --mol;
	  ++mapa[v[mol]];
	  if(mapa[v[mol]] == v[mol])
	    ++cur;
	}
      while(mor > r)
	{
	  if(mapa[v[mor]] == v[mor])
	    --cur;
	  --mor;
	  --mapa[v[mor]];
	}
      while(mor < r)
	{
	  ++mor;
	  ++mapa[v[mor]];
	  if(mapa[v[mor]] == v[mor])
	    ++cur;
	}
      ans[posi] = cur;
    }
  for(int i = 0 ;i < m ; ++i)
    cout << ans[i] << "\n";
  return 0;
}
