#include<bits/stdc++.h>
using namespace std;
 
char s[29], ans[29];
int cmp['Z'+5]['Z'+5];
int cnt = 0, QQ = 1;
 
bool cmp_user(const char a, const char b) {
	char cp;
	if(cmp[a][b]==-1) {
		printf("? %c %c\n", a, b);
		fflush(stdout);
		scanf(" %c", &cp);
		if(cp=='>') {
			cmp[a][b] = true;
			cmp[b][a] = false;
			return true;
		}
		else {
			cmp[a][b] = false;
			cmp[b][a] = true;
			return false;
		}
	}
	else return cmp[a][b];
}
 
void ins2(char c) {
	if(cmp_user(c, s[1])) {
		if(cmp_user(c, s[2])) s[3] = c;
		else s[3] = s[2], s[2] = c;
	} else {
		if(cmp_user(c, s[0])) {
			s[3] = s[2];
			s[2] = s[1];
			s[1] = c;
		} else {
			s[3] = s[2];
			s[2] = s[1];
			s[1] = s[0];
			s[0] = c;
		}
	}
}
 
void ins(char c) {
	int l = 0, r = cnt;
	while(l<r) {
		int mid = l+r>>1;
		if(cmp_user(c, ans[mid])) l = mid+1;
		else r = mid;
	}
	cnt ++;
	if(cmp_user(c, ans[r])) r ++;
	for(int i=cnt; i>=r+1; i--) ans[i] = ans[i-1];
	ans[r] = c;
}
 
int main() {
	int N, Q;
	scanf("%d%d", &N, &Q);
	
	for(int i=0; i<26; i++) s[i] = (char)(i+'A');
	s[N] = '\0';
	
	if(N==26) {
		memset(cmp, -1, sizeof(cmp));
		cnt = 0;
		ans[0] = s[0];
		ans[N] = '\0';
		for(int i=1; i<N; i++) ins(s[i]);
		
		printf("! %s\n", ans);
	} else {
		memset(cmp, -1, sizeof(cmp));
		if(cmp_user(s[0], s[1])) swap(s[0], s[1]);
		if(cmp_user(s[2], s[3])) swap(s[2], s[3]);
		if(cmp_user(s[1], s[3])) {
			swap(s[0], s[2]);
			swap(s[1], s[3]);
		}
		char x = s[2];
		if(cmp_user(s[4], s[1])) {
			if(cmp_user(s[4], s[3])) {
				s[2] = s[3];
				ins2(x);
			} else {
				s[2] = s[4];
				s[4] = s[3];
				ins2(x);
			}
		} else {
			if(cmp_user(s[4], s[0])) {
				s[2] = s[1];
				s[1] = s[4];
				s[4] = s[3];
				ins2(x);
			} else {
				s[2] = s[1];
				s[1] = s[0];
				s[0] = s[4];
				s[4] = s[3];
				ins2(x);
			}
		}
		printf("! %s\n", s);
	}
	return 0;
}