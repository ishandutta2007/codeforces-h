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

template<class T>
struct BinTree1 {
    size_t size;
    std::vector<T> t;

    BinTree1(size_t N) :
        size(N),
        t(2 * N) { }

    BinTree1(const std::vector<T>& other) :
        size(other.size()),
        t(2 * other.size()) {
        std::copy(other.begin(), other.end(), t.begin() + size);
        for (size_t i = size; i-- > 1;) {
            t[i] = combine(t[2 * i], t[2 * i + 1]);
        }
    }

    T get(size_t p) {
        return t[p + size];
    }

    void modify(size_t p, T value) {
        p += size;
        t[p] = value;
        while (p > 1) {
            p = p / 2;
            t[p] = combine(t[2 * p], t[2 * p + 1]);
        }
    }

    T query(size_t l, size_t r) {
        l += size;
        r += size;
        T left = init();
        T right = init();
        while (l < r) {
            if (l & 1) {
                left = combine(left, t[l]);
                l++;
            }
            if (r & 1) {
                r--;
                right = combine(t[r], right);
            }
            l = l / 2;
            r = r / 2;
        }
        return combine(left, right);
    }

  private:
    T combine(T left, T right) {
        return left + right;
    }

    T init() {
        return T();
    }
};

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    int diagonal = 0;
    for (int i = 0; i < n; i++) {
        if (as[i] > i) {
            diagonal++;
        }
    }
    BinTree1<int> tree(std::vector<int>(n, 1));
    std::vector<std::vector<int>> mods(n);
    for (int i = 0; i < n; i++) {
        if (as[i] < n) {
            mods[as[i]].push_back(i);
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        for (int mod : mods[i]) {
            tree.modify(mod, 0);
        }
        ans += tree.query(0, std::min(n, as[i]));
    }
    ans = (ans - diagonal) / 2;
    out << ans << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}