#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void buildSegTree(int*, int*, int, int, int);

int main(void)
{
  int n;
  cin >> n;

  int input[n];
  for (int i = 0; i < n; i++)
    cin >> input[i];


  // allocate space for the seg tree
  int x =  (int)(ceil(log2(n)));
  int max_size = 2 * (int)pow(2,x) - 1;

  int* seg_tree = new int[max_size];
  memset(seg_tree, 0, max_size * sizeof(int));

  buildSegTree(seg_tree, input, 0, 0, n);

  for (int i = 0; i < max_size; i++) {
    cout << seg_tree[i] << " ";
  }
  cout << endl;
  return 0;
}

void buildSegTree(int* seg_tree, int* input, int seg_node, int i_start, int i_end)
{
  if (i_start == i_end)
  {
    // a leaf node
    seg_tree[seg_node] = input[i_start];
  }
  else
  {
    int mid = (i_start + i_end) / 2;

    // recurse on the left child
    buildSegTree(seg_tree, input, seg_node*2, i_start, mid);
    // recurse on the right child
    buildSegTree(seg_tree, input, seg_node*2 + 1, mid + 1, i_end);

    // all the leaf nodes have been filled
    seg_tree[seg_node] = seg_tree[2*seg_node] + seg_tree[2*seg_node + 1];
  }
}
