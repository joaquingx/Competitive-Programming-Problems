#include <bits/stdc++.h>
#define MAXN 2 // E = alphabet size
#define BITS 30
using namespace std;
typedef long long ll;

struct Trie
{
    struct Node
    {
      Node * childs[MAXN];
      ll cnt;
      Node(){
	for(int i = 0 ; i < MAXN ; ++i)
	  childs[i] = NULL;
	cnt= 0;
      }
    };
  Node * root;
  Trie()  { root = new Node(); }
  void insert(string st)
  {
    Node * cur  = root;
    for(char c : st)
      {
	if( !cur->childs[cnvt(c)] ) // The son is not here
	  cur->childs[cnvt(c)] = new Node();
	cur = cur->childs[cnvt(c)];
	++cur->cnt;
      }
    // ++cur->cnt;
    // ++cur->cnt;
  }

  ll query(string st, string k)
  {
    ll sum = 0;
    Node * cur  = root;
    for(int i = 0 ; i < st.size() ; ++i)
      {
	Node *cpy = cur;
	if(k[i] == '0' )
	  {
	    if(st[i] == '0')
	      {
		if( cur->childs[ cnvt('0') ] )
		  cur = cur->childs[cnvt('0')];
		else
		  break;
	      }
	    else
	      {
		if( cur->childs[ cnvt('1') ] )
		  cur = cur->childs[cnvt('1')];
		else
		  break;
	      }

	  }
	else
	  {
	    if(st[i] == '0')
	      {
		if( cur->childs[ cnvt('0') ] )
		  sum += cur->childs[cnvt('0')]->cnt;
		if( cur->childs[ cnvt('1') ] )
		  {
		    cur = cur->childs[cnvt('1')];
		  }
	      }
	    else
	      {
		if( cur->childs[ cnvt('1') ] )
		  sum += cur->childs[cnvt('1')]->cnt;
		if( cur->childs[ cnvt('0') ] )
		  cur = cur->childs[ cnvt('0') ];
	      }
	  }
	if(cpy == cur)
	  break;
      }
    return sum;
  }

  char cnvt(char c) // function that converts
  {
    return c - '0';
  }

};

inline string tobinary(ll a)
{
  string ans;
  ll aux = a;
  while(aux > 0)
    {
      ll ac = aux  % 2;
      aux /= 2;
      ans += ( ac == 1 ? '1' : '0');
    }
  int tam = ans.size();
  for(int i  = 0 ; i < BITS-tam; ++i)
    ans += '0';
  reverse(ans.begin(),ans.end());
  return ans;
}

inline ll todecimal(string bin)
{
  ll acum=0,pot=1;
  for(int i = bin.size()-1 ; i >=0 ; --i)
    {
      acum += (bin[i] == '1' ? 1 : 0 ) * pot;
      pot *= 2;
    }
  return acum;
}


int main()
{
  ios_base::sync_with_stdio(0);
  int t; scanf("%d",&t);
  string rpta;
  int n,k;ll value;
  ll acum,ans;
  string zeros="",kbin;for(int i = 0 ; i < BITS ; ++i)zeros+='0';
  for(int i = 0 ; i < t ; ++i)
    {
      acum = ans = 0;
      Trie * tree = new Trie();
      scanf("%d ",&n);
      scanf("%d",&k);
      kbin = tobinary(k);
      tree->insert(zeros);
      for(int j = 0 ; j < n ; ++j)
	{
	  scanf("%lld",&value);
	  acum  ^= value;
	  rpta = tobinary(acum);
	  // cout << rpta << "\n";
	  ans += tree->query(rpta,kbin);
	  // cout << "en el1 " << j << " tengo: " << ans << "\n";
	  tree->insert(rpta);

	}
      printf("%lld\n",ans);
      // if(i < t-1)
      // cout << ans << " ";
      // else
      // cout << ans;
    }
  // cout << "\n";
  return 0;
}
