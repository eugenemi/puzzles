// interview with facebook November 2010
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
#include <cstring>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

struct BinTree
{
  int d;
  BinTree *L,*R;
  BinTree(int ind):d(ind),L(NULL),R(NULL) {}
  void print(){cout<<" "<<d;}
};

void printBinTree (BinTree *R) {
  if (R==NULL) return;
  queue<BinTree *> Q;
  Q.push(R);
  Q.push(NULL);  // terminator for a level
  while (!Q.empty()) {
    BinTree *c = Q.front();
    Q.pop();
    if (c == NULL) {
      cout << endl;
      if (!Q.empty()) {
        Q.push(NULL);
      }
    } else {
      c->print();
      if (c->L != NULL) Q.push(c->L);
      if (c->R != NULL) Q.push(c->R);
    }
  }
}
int main(int argc, char *argv[])
{
  {
    cout << "----------\n";
    BinTree t1(1), t2(2), t3(3), t4(4), t5(5);
    printBinTree(&t1);
  }
  {
    cout << "----------\n";
    BinTree t1(1), t2(2), t3(3), t4(4), t5(5);
    t1.L = &t2;
    t1.R = &t3;
    t2.L = &t4;
    t2.R = &t5;
    printBinTree(&t1);
  }
  {
    cout << "----------\n";
    BinTree t1(1), t2(2), t3(3), t4(4), t5(5);
    t1.L = &t2;
    t1.R = &t4;
    t2.L = &t3;
    printBinTree(&t1);
  }
  {
    cout << "----------\n";
    BinTree t1(1), t2(2), t3(3), t4(4), t5(5);
    t1.R = &t2;
    t1.L = &t4;
    t2.R = &t3;
    printBinTree(&t1);
  }
  return 0;
}
