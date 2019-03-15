#include <bits/stdc++.h>
using namespace std;

#include "quickSort.hpp"

// fast io courtesy of codeforces and alfredan
unsigned int baseTwoDigits(unsigned int x) {
	return x ? 32 - __builtin_clz(x) : 0;
}

unsigned int tenToThe[] = {
		1,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
		1000000000,
};

unsigned int baseTenDigits(unsigned int x) {
	unsigned int guess[33] = {
			0, 0, 0, 0, 1, 1, 1, 2, 2, 2,
			3, 3, 3, 3, 4, 4, 4, 5, 5, 5,
			6, 6, 6, 6, 7, 7, 7, 8, 8, 8,
			9, 9, 9
	};
	unsigned int digits = guess[baseTwoDigits(x)];
	return digits + (x >= tenToThe[digits]);
}

int main() {
	int n;
	cin >> n;

	if (n == 0) return 0;

	ios_base::sync_with_stdio(false);

	int* a = new int[n];

	char buf[16384 + 16];
	int* p = a;
	int* hi = a + n;

	uint32_t cur = 0; // unsigned to prevent UB from overflow
	int sgn = 1;
	int rem = n;

	// skip newline
	while (fread(buf, 1, 1, stdin) == 0) {}

	while (true) {
		int read = fread(buf, 1, 16384, stdin);

		for (int i = 0; i < read; i++) {
			char c = buf[i];

			switch (c) {
				case ' ':
				case '\n':
					*p = (int)(cur * sgn);
					*p++;

					if (p == hi) {
						goto inputFinished;
					}

					sgn = 1;
					cur = 0;
					break;
				case '-':
					sgn = -1;
					break;
				default:
					cur = cur * 10 + (c - '0');
					break;
			}
		}
	}
	inputFinished:

	init();
	qs(a, n);

	// reusing the buf from the input code
	char* mid = buf + 16384;
	char* ptr = buf;
	for (int* i = a; i < a+n; i++) {
		if (ptr >= mid) {
			fwrite(buf, 1, (ptr - buf), stdout);
			ptr = buf;
		}

		int cur = *i;
		int digits;

		if (cur < 0) {
			*(ptr++) = '-';
			if (cur == -2147483648) {
				*(ptr++) = '2';
				*(ptr++) = '1';
				*(ptr++) = '4';
				*(ptr++) = '7';
				*(ptr++) = '4';
				*(ptr++) = '8';
				*(ptr++) = '3';
				*(ptr++) = '6';
				*(ptr++) = '4';
				*(ptr++) = '8';
				goto loopEnd;
			}

			cur = -cur;
		}

		digits = baseTenDigits(cur);
		switch (digits) {
			case 10:
				*(ptr++) = '0' + cur / 1000000000;
			case 9:
				*(ptr++) = '0' + (cur / 100000000) % 10;
			case 8:
				*(ptr++) = '0' + (cur / 10000000) % 10;
			case 7:
				*(ptr++) = '0' + (cur / 1000000) % 10;
			case 6:
				*(ptr++) = '0' + (cur / 100000) % 10;
			case 5:
				*(ptr++) = '0' + (cur / 10000) % 10;
			case 4:
				*(ptr++) = '0' + (cur / 1000) % 10;
			case 3:
				*(ptr++) = '0' + (cur / 100) % 10;
			case 2:
				*(ptr++) = '0' + (cur / 10) % 10;
			case 1:
				*(ptr++) = '0' + cur % 10;
				break;
			case 0:
				*(ptr++) = '0';
				break;
		}

		loopEnd:
		*(ptr++) = ' ';
	}

	if (ptr > buf) {
		*(ptr-1) = '\n'; // replace last space with a newline
		fwrite(buf, 1, (ptr - buf), stdout);
	}
}
