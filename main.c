#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct node
{
  int pos;
  int depth;
  int frequency;
  int l;
  int r;
  friend bool operator<(struct node n1,struct node n2){
    return n1.frequency > n2.frequency;
  };
}data[10000];

typedef struct node Node;

priority_queue<Node> record;

int rp = 0, bt = 0;

Node* buildTree(int rp);

void travelTree(Node* root);

int main(){
  int n = 0;
  cin >> n;
  char c;
  rp = n;
  for (int i = 0; i < n; i++){
    cin >> c >> data[i].frequency;
    data[i].pos = i;
    data[i].l = -1;
    record.push(data[i]);
  }
  Node* root = buildTree(n);
  root->depth = 0;
  travelTree(root);
  cout << bt << endl;
  return 0;
}

Node* buildTree(int rp){
  if (record.size()<=2)
    {
      data[rp].pos = rp;
      data[rp].l = record.top().pos;
      record.pop();
      data[rp].r = record.top().pos;
      record.pop();
      return &data[rp];
    }
  else
    {
      data[rp].pos = rp;
      data[rp].l = record.top().pos;
      record.pop();
      data[rp].r = record.top().pos;
      record.pop();
      data[rp].frequency = data[data[rp].l].frequency + data[data[rp].r].frequency;
      record.push(data[rp]);
      return buildTree(rp+1);
    }
}

void travelTree(Node* root){
  if (root->l==-1)
    {
      bt += root->frequency*root->depth;
    }
  else
    {
      data[root->l].depth = root->depth + 1;
      data[root->r].depth = root->depth + 1;
      travelTree(&data[root->l]);
      travelTree(&data[root->r]);
    }
}                                 
