#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    int k;
    in >> k;
    std::vector<int> ranks(k);
    for (int i = 0; i < k; i++) {
        in >> ranks[i];
    }
    out << std::max(0, *std::max_element(ranks.begin(), ranks.end()) - 25) << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}