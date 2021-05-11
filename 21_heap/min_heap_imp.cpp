// http://icpc.me/1927
#include <bits/stdc++.h>
using namespace std;
int heap[100005];
int sz = 0; // heap size
void add(int x){
  sz++;
  heap[sz] = x;
  int idx = sz;
  while(idx != 1){
    int par = idx/2;
    if(heap[par] < heap[idx]) break;
    swap(heap[par], heap[idx]);
    idx = par;
  }
}
int top(){
  if(sz == 0) return 0;
  return heap[1];
}
void pop(){
  if(sz==0) return;
  swap(heap[1], heap[sz]);
  sz--;
  int idx = 1;
  while(2*idx <= sz){ // 왼쪽 자식의 index(=2*idx)가 size보다 크면 idx가 leaf라는 의미이다.
    int min_child;
    if(heap[2*idx] < heap[2*idx+1] or 2*idx+1 > sz) min_child = 2*idx;
    else min_child = 2*idx+1;
    if(heap[idx] < heap[min_child]) break;
    swap(heap[idx],heap[min_child]);
    idx = min_child;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    if(x == 0){
      cout << top() << '\n';
      pop();
    }
    else{
      add(x);
    }
  }  
}
