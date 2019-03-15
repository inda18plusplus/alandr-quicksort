#include <cstdio>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

#include "quickSort.hpp"

namespace cr = std::chrono;
using namespace std::chrono_literals;

int main(int argc, char** argv) {

	if(argc < 3)
		return 1;

	long size = strtol(argv[1], nullptr, 10);
	long iterations = strtol(argv[2], nullptr, 10);

	std::random_device rd;
	std::mt19937 g(rd());
	std::uniform_int_distribution<int> dist(0, 1000000);

	std::vector<int> arr(size, 0);
	for (int& i : arr) {
		i = dist(g);
	}

	cr::nanoseconds timeElapsed = 0ns;

	for (int i = 0; i < iterations; ++i) {
		std::shuffle(arr.begin(), arr.end(), g);

		auto start = cr::high_resolution_clock::now();
		qs(arr.data(), arr.size());
		auto end = cr::high_resolution_clock::now();

		timeElapsed += end - start;
	}

	printf("Took %fs\nAverage %fµs per operation\n",
			cr::duration_cast<cr::duration<double>>            (timeElapsed).count(),
			cr::duration_cast<cr::duration<double, std::micro>>(timeElapsed).count() / iterations);

}