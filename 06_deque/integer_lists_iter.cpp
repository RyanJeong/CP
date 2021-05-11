// http://icpc.me/5430
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int T, n;
deque<int> d;

void func(string &command) {
	// 역순 여부
	bool isReversed = false;
	for (int i = 0; i < command.size(); i++) {
		switch (command[i]) {
			case 'R':
				isReversed = !isReversed;
				break;
			case 'D':
				// 더 이상 진행할 수 없을 경우
				if (d.empty()) {
					cout << "error" << endl;
					return;
				}
				if (isReversed)
					d.pop_back();
				else
					d.pop_front();
				break;
		}
	}

	// 출력 시작 (덱이 비어있을 경우에는 패스한다)
	cout << "[";
	if (!d.empty()) {
		// 정방향일 경우에는 std::iterator를 사용한다.
		if (!isReversed) {
			auto it = d.begin();
			cout << *it;

			while (++it != d.end()) 
				cout << "," << *it;
		}

		// 역방향일 경우에는 std::reverse_iterator를 사용한다.
		else {
			auto it = d.rbegin();
			cout << *it;

			while (++it != d.rend()) 
				cout << "," << *it;			
		}
	}
	// 덱을 반드시 클리어 하여야 한다. 
	d.clear();
	cout << "]" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_case;
	cin >> test_case;

	while (test_case--) {
		string command;
		cin >> command;

		int numOfArr;
		cin >> numOfArr;

		// 더미 입력. '[', ',', ']' 따위의 입력을 무시하도록 한다.
		// 리눅스에서 /dev/null 같은 기능을 담당한다.

		char dummy;
		if (!numOfArr) {
			cin >> dummy >> dummy;
		}

		else {
			cin >> dummy;
			for (int i = 0; i < numOfArr; i++) {
				int num;
				cin >> num
					>> dummy;

				d.push_back(num);
			}
		}

		func(command);
	}
}