#include <bits/stdc++.h>

#define ALPHABET 26

using namespace std;

struct trieNode
{
  struct trieNode* child[ALPHABET];
  bool wordEnding;
  int prio;
};

void insertNode(struct trieNode* root, string key, int prio);
struct trieNode* createNode(void);
int anotherSearch(struct trieNode* root, string key);

vector<string> matching;
int maxPrio;

int main(void)
{
  int n, q;
  cin >> n >> q;

  struct trieNode *root = createNode();
  unordered_map<string, int> db;

  for (int i = 0; i < n; i++)
  {
    string s;
    int p;
    cin >> s >> p;

    db[s] = p;

    insertNode(root, s, p);
  }

  for (int i = 0; i < q; i++)
  {
    // vector<string> temp;
    // matching = temp;
    maxPrio = 0;
    string qe;
    cin >> qe;

    // moddedSearch(root, qe);
    int retVal = anotherSearch(root, qe);

    // for (auto s : matching)
      // if (db[s] > retVal)
        // retVal = db[s];

    // if (maxPrio != 0)
      // cout << maxPrio << endl;
    // else
      // cout << "-1" << endl;
    if (retVal == 0)
      cout << "-1" << endl;
    else
      cout << retVal << endl;
  }

  return 0;
}

void insertNode(struct trieNode* root, string key, int prio)
{
  struct trieNode* temp = root;

  for (int i = 0; i < key.size(); i++)
  {
    int index = key[i] - 'a';

    if (!temp -> child[index])
      temp -> child[index] = createNode();


    temp = temp -> child[index];
    if (temp -> prio < prio)
      temp -> prio = prio;
  }

  temp -> wordEnding = true;
  temp -> prio = prio;
}

struct trieNode* createNode(void)
{
  struct trieNode* hello = new trieNode;
  hello -> wordEnding = false;
  hello -> prio = 0;

  for (int j = 0; j < ALPHABET; j++)
    hello -> child[j] = NULL;

  return hello;
}

int anotherSearch(struct trieNode* root, string key)
{
  struct trieNode* temp = root;

  int max_prio_seen = 0;
  for (int i = 0; i < key.length(); i++)
  {
    int index = key[i] - 'a';
    if (!temp -> child[index])
    {
      max_prio_seen = 0;
      return max_prio_seen;
    }
    else
      temp = temp -> child[index];
    max_prio_seen = temp -> prio;
  }
  return max_prio_seen;
}
