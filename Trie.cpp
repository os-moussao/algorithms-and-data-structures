// source: https://gist.github.com/hrsvrdhn/1ae71c25ef1c620c022a544d52df8928
struct Trie
{
  map<char,Trie*> children;
  int prefixes;
  bool endofword;
  Trie() {
    prefixes=0;
    endofword=false;
  }
  void insert(string word)
  {
    Trie *current=this;
    for(int i=0;i<word.size();i++)
    {
      char ch=word[i];
      Trie *node=current->children[ch];
      if(!node)
      {
        node=new Trie();
        current->children[word[i]]=node;
      }
      current=node;
      current->prefixes++;
    }
    current->endofword=true;
  }
  bool search(string word)
  {
    Trie *current=this;
    for(int i=0;i<word.size();i++)
    {
      char ch=word[i];
      Trie *node=current->children[ch];
      if(!node)
        return false;
      current=node;
    }
    return current->endofword;
  }
  int countPrefix(string word)
  {
    Trie *current=this;
    for(int i=0;i<word.size();i++)
    {
      char ch=word[i];
      Trie *node=current->children[ch];
      if(!node)
      {
        return 0;
      }
      current=node;
    }
    return current->prefixes;
  }
};
