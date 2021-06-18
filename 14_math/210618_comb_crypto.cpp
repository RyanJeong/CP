// http://icpc.me/1759
// combination
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int l, c;
	cin>>l>>c;
	vector<char> v_list;
	for (int i = 1; i<=c; ++i) {
		char temp;
		cin>>temp;

		v_list.push_back(temp);
	}
	sort(v_list.begin(),v_list.end());

	// nCm
	// 0: select, 1: skip
	vector<bool> is_skipped;
	for (int i = 0; i<l; ++i) {
		is_skipped.push_back(false);
	}
	for (int i = l; i<c; ++i) {
		is_skipped.push_back(true);
	}
	do {
		int n_consonant = 0;
		int n_vowel = 0;
		string temp;

		for (int i = 0; i<c; ++i) {
			if (!is_skipped[i]) {
				char ch = v_list[i];

				temp.push_back(ch);
				switch (ch) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					++n_vowel;
					break;
				default:
					++n_consonant;	
					break;
				}
			}
		}
		if (n_vowel>=1 && n_consonant>=2) {
			cout << temp << '\n';
		}
	} while (next_permutation(is_skipped.begin(),is_skipped.end()));

	return 0;
}