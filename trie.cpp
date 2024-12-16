/*
Requirement Node: (5 methods, bool flag, Node *links)
1. whether a character exists or not from the current state
2. make a 'link' to the character it doesn't exist
3. Jump to a character
4. Set the end when it is the last node of any word: this will be called whenever the word is ended from Trie function
5. Check whether any word ended here or not


Requirement Trie: (3 methods, Node *root)
1. Insert Word in the trie
2. Check whether the word exist in a trie already
3. Check whether the word is prefix of any string in the trie or not
*/
class Node{
public:
  Node *links[26];  //pointer to all the letters that can be reached by the current state of prefix
  bool flag = false;  //marks the end of the word

  bool containsKey(char x){
    return links[x-'a]!=NULL;
  }
  void put(char x, Node* node){
    links[x-'a'] = node;
  }
  Node* get(char x){
    return links[x-'a'];
  }
  void setEnd(){
    flag = true;
  }
  bool isEnd(){
    return flag;
  }
};


class Trie{
private:
  Node* root;
public:
  Trie(){
    root = new Node();  //pointer to a Node
  }

  void insert(string word){
    int n = word.size();
    Node* node = root;
    for(int i=0; i<n; i++){
      if(node->containsKey(word[i])){
        node = node->get(word[i]);
      }
      else{
        node->put(word[i], new Node());
        node = node->get(word[i]);
      }
    }
    node->setEnd();
  }

  bool search(string word){
    int n = word.size();
    Node *node = root;
    for(int i=0; i<n; i++){
      if(!node->containsKey(word[i])){
        return false;
      }
      node = node->get(word[i]);
    }
    return node->isEnd();
  }

  bool startsWith(string prefix){
    int n = word.size();
    Node *node = root;
    for(int i=0; i<n; i++){
      if(!node->containsKey(word[i])){
        return false;
      }
      node = node->get(word[i]);
    }
    return true;
  }
};
