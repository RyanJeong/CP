#include <bits/stdc++.h>

using namespace std;

struct node {
    int from;
    int to;
    int value;
};

struct cmp_less {
    bool operator()(node s, node t){

        return s.value<t.value;
    }
};

struct cmp_greater {
    bool operator()(node s, node t){

        return s.value>t.value;
    }
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<node, vector<node>, cmp_less> max_heap;
	priority_queue<node, vector<node>, cmp_greater> min_heap;

	max_heap.push({1,1,4});
	max_heap.push({1,2,1});
	max_heap.push({2,1,3});
	max_heap.push({1,3,5});
	max_heap.push({3,3,2});
	cout << "{ " << max_heap.top().from << ", "
	     << max_heap.top().to << ", "
		 << max_heap.top().value << " }\n"; // { 1, 3, 5 }

	min_heap.push({1,1,4});
	min_heap.push({1,2,1});
	min_heap.push({2,1,3});
	min_heap.push({1,3,5});
	min_heap.push({3,3,2});
	cout << "{ " << min_heap.top().from << ", "
	     << min_heap.top().to << ", "
		 << min_heap.top().value << " }\n"; // { 1, 2, 1 }

	return 0;
}