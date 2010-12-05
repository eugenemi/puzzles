#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// print longest increasing subsequence (lis) in x in O(n log(n))
void print_longest_increasing_subsequence(vector<int> &x)
{
  int l = 0;// length of lis so far; m,mi are valid in range [0..l-1]
  vector<int> 
    m,      // m[i] is the smallest value in x[k] processed so far s.t.
            // there is a subsequence of length i ending at x[k]
    mi,     // mi[i] is index of x[k]
    p;      // p[i] - index in x of the predecessor in the lis ending at x[i]

  for (int i = 0; i < x.size(); ++i) {
    vector<int>::iterator ub = upper_bound(m.begin(), m.end(), x[i]);

    /*
    cout << "m ";
    for (int j = 0; j<m.size();++j) { cout << " " << m[j]; }
    cout <<endl;

    cout << "i " << i << " x[i] " << x[i] << " l " << l;
    if (ub == m.end()) {
      cout << " ub is end ";
    } else {
      int t = (int)(ub - m.begin());
      cout << " ub is " <<*ub << " offset " << t;
    }
    cout <<endl<<endl;
    */

    if (ub == m.end()) { 
      // new max len sen subsequence
      m.push_back(x[i]);
      mi.push_back(i);
      p.push_back((l==0?-1:mi[l-1]));
      ++l;
    } else { 
      // *ub > x[i]
      int t = (int)(ub - m.begin());

      // if x[i]  is same as m[t-1], we do not update m,mi,p[t] as
      // sequence should be stricly increasing
      if (t > 0 && m[t-1] == x[i]) { 
        p.push_back(p[mi[t-1]]);  // same predecessor as the equal entry in m
        continue;
      }
      m[t] = x[i];
      mi[t] = i;
      if (t > 0) {
        p.push_back(mi[t-1]);
      } else {
        p.push_back(-1);
      }
    }
  }

  stack<int> s;
  for (int i = 0, j = mi[l-1]; i < l; ++i) {
    s.push(x[j]);
    j = p[j];
  }
  while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout <<endl;

  for (int i = 0; i < x.size(); ++i) { cout <<x[i]<< " "; } 
  cout <<endl<<endl;;
}

#define RUN_TEST vector<int> x(myints,myints+sizeof(myints)/(sizeof(int))); print_longest_increasing_subsequence(x);
int main(int argc, char *argv[])
{
  { int myints[] = {1}; RUN_TEST; }
  { int myints[] = {1,2}; RUN_TEST; }
  { int myints[] = {2,1}; RUN_TEST; }
  { int myints[] = {1,2,3,4}; RUN_TEST; }
  { int myints[] = {3,9,14,10,2,12,4,8,11}; RUN_TEST; }
  { int myints[] = {1,2,3,8,10,5,6,7,12,2,4,0}; RUN_TEST; }
  { int myints[] = {12,13,15,16,1,8,3,5,7,9,19, 0, 4 , 2}; RUN_TEST; }
  { int myints[] = {12,13,15,16,1,6,8,2,3,4,5,7,9,19,10,11,17}; RUN_TEST; }
  { int myints[] = {2,3,2}; RUN_TEST; }
  return 0;
}
