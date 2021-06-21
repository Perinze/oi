#include <bits/stdc++.h>
using namespace std;

namespace solve {

string input;
int sq, sqlen, sqcnt;
#define invaild(c) (c >= 'a' && c <= 'z' || c > 'F' && c <= 'Z')
#define vaild(c) (c >= '0' && c <= '9' || c >= 'A' && c <= 'F')
#define hex_char(c) (c >= 'A' && c <= 'F')
#define front() (input[sq])
#define pop() (sq++, sqlen--)
#define push() (sqlen++)
#define empty() (!sqlen)
#define blank() (!num_len)
#define clear() (sq += sqlen, sqlen = 0, sqcnt = 0)

int ans_id = 0;
void print()
{
	string buf;
	while (input[sq] == '0' && input[sq + 1] != '.') sq++, sqlen--;
	int dot_cnt = 0;
	for (int i = 0; i < sqlen; i++) {
		if (input[sq + i] == '.') dot_cnt++;
		if (dot_cnt < 3 && input[sq + i - 1] == '.' && input[sq + i] == '0' && input[sq + i + 1] != '.') return;
		if (dot_cnt == 3 && input[sq + i - 1] == '.' && input[sq + i] == '0') {
			buf.push_back('0');
			break;
		}
		buf.push_back(input[sq + i]);
	}
	++ans_id;
	printf("%s\n", buf.c_str());
}

void pop_num()
{
	while (front() != '.') pop();
	pop();
	sqcnt--;
}

int dec;
int hex;
int hex_only;
int num_len;
#define reset() (dec = 0, hex = 0, hex_only = 0)

void solve()
{
	int p;
	dec = 0, hex = 0;
	hex_only = 0;
	for (p = 0; p < input.length(); p++) {
		char c = input[p];
		if (invaild(c)) {
			num_len = 0;
			if (sqcnt == 4)
				print();
			push();
			clear();
			reset();
			continue;
		}
		if (c == '.') {
			reset();
			if (blank()) {
				push();
				clear();
				num_len = 0;
				continue;
			}
			num_len = 0;
			if (sqcnt == 4) {
				print();
				pop_num();
				push();
				continue;
			}
			push();
		}
		if (vaild(c)) {
			if (blank())
				sqcnt++;
			num_len++;
			if (hex_char(c))
				hex_only = 3;
			else
				if (hex_only) hex_only--;
			dec = (hex_char(c) ? 0 : dec * 10 + c - '0');
			hex = hex * 16 + (hex_char(c) ? c - 'A' + 10 : c - '0');
			if (hex > 255) {
				if (hex_only && sqcnt == 4)
					print();
				push();
				hex %= 256;
				while (sqlen > 2) pop();
				num_len = 2;
				sqcnt = 1;
			} else if (dec > 255) {
				if (!hex_only && sqcnt == 4)
					print();
				push();
				dec %= 100;
				while (sqlen > 2) pop();
				num_len = 2;
				sqcnt = 1;
			} else {
				push();
			}
		}
	}
	if (sqcnt == 4)
		print();
}

};

int main()
{
	while (cin >> solve::input)
		solve::solve();
	return 0;
}