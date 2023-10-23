#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

class Node {
    public:
    Node *children[26];
    bool isEndOfWord = false;
    bool hasChild(char ch) {
        return (children[ch - 'a'] != NULL);  
    }
    void setChild(char ch, Node *node) {
        children[ch - 'a'] = node;    
    }
    Node *getChild(char ch) {
        return children[ch - 'a'];   
    }
    
    bool isEnd() {
        return isEndOfWord;  
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        
        root = new Node();
    }

    void insert(string word) {
        
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->hasChild(word[i])) {
                node->setChild(word[i], new Node());
            }
            
            node = node->getChild(word[i]);
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->hasChild(word[i])) {
                return false;
            }
            node = node->getChild(word[i]);
        }
        return node->isEnd();
    }

    bool prefix(string s) {
        Node* node = root;
        for (int i = 0; i < s.size(); i++) {
            if (!node->hasChild(s[i])) {
                return false;
            }
            node = node->getChild(s[i]);
        }
        return true;
    }

    vector<int> suffices(string s)
    {
        vector<int>ans;
        Node *node=root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->hasChild(s[i]))
            return ans;

            node=node->getChild(s[i]);
            if(node->isEnd())
            ans.push_back(i+1);
        }

        return ans;
    }
};

int main()
{
    auto start= chrono::steady_clock::now();
    vector<string> inputWords;

    #ifndef ONLINE_JUDGE    
         freopen("Input_02.txt", "r", stdin);
         freopen("output_02.txt", "w", stdout);
    #endif

    string word;
    while(cin>>word){
        inputWords.push_back(word);
    }
    Trie trie;
    for(int i=0;i<inputWords.size();i++)
    {
        trie.insert(inputWords[i]);
    }

       queue<pair<string,string>> q;
      for(int i=0;i<inputWords.size();i++)
      {
          string word=inputWords[i];
          vector<int> suffix=trie.suffices(word);

          for(auto j:suffix)
          {
              if(j>=word.size())
              break;

              string temp=word.substr(j);
              q.push({word,temp});
          }
      }

      int max_len=0;
      string longestCompound="";
      string secondLongestCompound="";


      while(!q.empty())
      {
          auto pair=q.front();
          q.pop();
          string original=pair.first;
          string suff=pair.second;

          vector<int>index=trie.suffices(suff);

          if(index.size()==0)
          continue;

          for(auto j:index)
          {
              if(j>suff.size())
              break;

              if(j==suff.size())
              {
                  if(original.size()>max_len)
                  {
                      max_len=original.size();
                      secondLongestCompound=longestCompound;
                      longestCompound=original;
                  }
              }

              else
              {
                   string temp=suff.substr(j);
                   q.push({original,temp});
              }
          }
      }

      auto end= chrono::steady_clock::now();
      auto duration = duration_cast<milliseconds>(end-start);
      cout<<"Longest Compound Word is "<<longestCompound<<endl;
      cout<<"Second Longest Compound Word is "<<secondLongestCompound<<endl;
      cout<<"Time taken to process the given file "<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" milliseconds";

    return 0;
}