#include <bits/stdc++.h>
#define MAXN 2 // E = alphabet size
#define BITS 32
using namespace std;
typedef long long ll;

struct Trie
{
  struct Node
  {
    Node * childs[MAXN];
    int words,prefix;
    Node(){
      for(int i = 0 ; i < MAXN ; ++i)
	childs[i] = NULL;
      words = prefix = 0;
    }
  };
  Node * root;
  Trie()  { root = new Node(); }
  void insert(string st)
  {
    Node * cur  = root;
    for(char c : st)
      {
	++cur->prefix;
	if( !cur->childs[cnvt(c)] ) // The son is not here
	  cur->childs[cnvt(c)] = new Node();
	cur = cur->childs[cnvt(c)];
      }
    ++cur->words;
  }

  string maximun(string st)
  {
    string nw = "";
    Node * cur  = root;
    for(char c : st)
    {
      if(c == '1')
	{
	  if( !cur->childs[cnvt('0')] )
	    {
	      nw += '0';
	      cur = cur->childs[cnvt('1')];
	    }
	  else
	    {
	      cur = cur->childs[cnvt('0')];
	      nw += '1';
	    }
	}
      else
	{
	  if( !cur->childs[cnvt('1')] )
	    {
	      nw += '0';
	      cur = cur->childs[cnvt('0')];
	    }
	  else
	    {
	      nw += '1';
	      cur = cur->childs[cnvt('1')];
	    }
	}
    }
    return nw;    
  }
  
  
  int findWords(string st, bool word) // return prefix or words.
  {
    Node * cur  = root;
    for(char c : st)
      {
	// cout << cur->prefix << "\n";
	if( !( cur->childs[cnvt(c)] ) )
	  return 0;
	cur = cur->childs[cnvt(c)];
      }
    if(word)
      return cur->words;
    return cur->prefix;
  }

  char cnvt(char c) // function that converts
  {
    return c-'0';
  }
  
};

string tobinary(int a)
{
  string ans;
  int aux = a;
  while(aux > 0)
    {
      int ac = aux  % 2;
      aux /= 2;
      ans += ( ac == 1 ? '1' : '0');
    }
  int tam = ans.size();
  for(int i  = 0 ; i < BITS-tam; ++i)
    ans += '0';
  reverse(ans.begin(),ans.end());
  return ans;
}

int todecimal(string bin)
{
  int acum=0,pot=1;
  for(int i = bin.size()-1 ; i >=0 ; --i)
    {
      acum += (bin[i] == '1' ? 1 : 0 ) * pot;
      pot *= 2;
    }
  return acum;
}


int main()
{
  int t; cin >> t;
  for(int i = 0 ; i < t ; ++i)
    {
      int n;
      Trie tree;
      int acum=0;
      int ans = 0;
      tree.insert("00000000000000000000000000000000");
      cin >>n;
      for(int j = 0 ; j < n ; ++j)
	{
	  int k; cin >> k;
	  acum  ^= k;
	  string rpta = tobinary(acum);
	  tree.insert(rpta);
	  // cout << rpta << "\n";
	  // cout << todecimal(tree.maximun(rpta)) << "\n";
	  ans = max(ans, todecimal(tree.maximun(rpta)) );
	}
      cout << ans << "\n";
    }
  return 0;
}
