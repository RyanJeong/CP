# Fast IO
* [[BOJ] 0.1](https://www.acmicpc.net/problem/11921)
```c++
#include <bits/stdc++.h>

using namespace std;

const int size = 1<<18;
char buf[size];

inline char get_char(void)
{
    static int idx = size;

    if (idx==size) {
        fread(buf,1,sizeof buf,stdin);
        idx=0;
    }

    return buf[idx++];
}

inline void get_int(int& n)
{
    int c;
    n=0;
    while ((c=get_char())!='\n') {
        n=n*10+c-'0';
    }

    return;
}

int main(void)
{
    int n;
    get_int(n);
    printf("%d\n",n);

    int tmp;
    long long sum = 0;
    while (n--) {
        get_int(tmp);
        sum+=tmp;
    }
    printf("%lld",sum);

    return 0;
}
```

* 아래 코드를 사용하면 속도를 더욱 향상시킬 수 있음:
    * [Fast I/O 구현 코드](https://www.acmicpc.net/blog/view/105)
```c++
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-04-16
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout. (mmap ver.)
 */
constexpr int INPUT_SZ = 45000000;
constexpr int OUTPUT_SZ = 1 << 20;

class INPUT {
private:
	char* p;
	bool __END_FLAG__, __GETLINE_FLAG__;
public:
	explicit operator bool() { return !__END_FLAG__; }
    INPUT() { p = (char*)mmap(0, INPUT_SZ, PROT_READ, MAP_SHARED, 0, 0); }
	bool is_blank(char c) { return c == ' ' || c == '\n'; }
	bool is_end(char c) { return c == '\0'; }
	char _readChar() { return *p++; }
	char readChar() {
		char ret = _readChar();
		while (is_blank(ret)) ret = _readChar();
		return ret;
	}
	template<typename T> T readInt() {
		T ret = 0; char cur = _readChar(); bool flag = 0;
		while (is_blank(cur)) cur = _readChar();
		if (cur == '-') flag = 1, cur = _readChar();
		while (!is_blank(cur) && !is_end(cur)) ret = 10 * ret + cur - '0', cur = _readChar();
		if (is_end(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	string readString() {
		string ret; char cur = _readChar();
		while (is_blank(cur)) cur = _readChar();
		while (!is_blank(cur) && !is_end(cur)) ret.push_back(cur), cur = _readChar();
		if (is_end(cur)) __END_FLAG__ = 1;
		return ret;
	}
	double readDouble() {
		string ret = readString();
		return stod(ret);
	}
	string getline() {
		string ret; char cur = _readChar();
		while (cur != '\n' && !is_end(cur)) ret.push_back(cur), cur = _readChar();
		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
		if (is_end(cur)) __GETLINE_FLAG__ = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char write_buf[OUTPUT_SZ];
	int write_idx;
public:
	~OUTPUT() { bflush(); }
	void bflush() {
		fwrite(write_buf, sizeof(char), write_idx, stdout);
		write_idx = 0;
	}
	void writeChar(char c) {
		if (write_idx == OUTPUT_SZ) bflush();
		write_buf[write_idx++] = c;
	}
	template<typename T> int getSize(T n) {
		int ret = 1;
		if (n < 0) n = -n;
		while (n >= 10) ret++, n /= 10;
		return ret;
	}
	template<typename T> void writeInt(T n) {
		int sz = getSize(n);
		if (write_idx + sz >= OUTPUT_SZ) bflush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz - 1; i >= 0; i--) write_buf[write_idx + i] = n % 10 + '0', n /= 10;
		write_idx += sz;
	}
	void writeString(string s) { for (auto& c : s) writeChar(c); }
	void writeDouble(double d) { writeString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.readChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.readString(); return in; }
template<typename T, typename std::enable_if_t<is_integral_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) { i = in.readInt<T>(); return in; }
template<typename T, typename std::enable_if_t<is_floating_point_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) { i = in.readDouble(); return in; }
OUTPUT& operator<< (OUTPUT& out, char i) { out.writeChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.writeString(i); return out; }
template<typename T, typename std::enable_if_t<is_integral_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) { out.writeInt<T>(i); return out; }
template<typename T, typename std::enable_if_t<is_floating_point_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) { out.writeDouble(i); return out; }

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////

using ull = unsigned long long;

int main() {
	fastio;
    ull n, t, sum = 0; cin >> n;
    for (int i = 0; i < n; i++) cin >> t, sum += t;
    cout << n << '\n' << sum << '\n';
}
```

* [[BOJ] 그대로 출력하기](https://www.acmicpc.net/problem/11718)
```c++
__libc_start_main() {
    char r[1 << 16], *p = r; read(0, r, 1 << 16);
    for (; *++p;);
    write(1, r, p - r); _exit(0);
} main;
```