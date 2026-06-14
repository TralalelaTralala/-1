#include <iostream>
#include <iomanip>
#include <list>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n) || n <= 0) {
        return 0;
    }

    std::list<double> values;
    values.resize(n);

    auto it = values.begin();
    for (int i = 0; i < n; ++i, ++it) {
        std::cin >> *it;
    }

    bool hasLessThanMinusThree = false;
    for (double x : values) {
        if (x < -3.0) {
            hasLessThanMinusThree = true;
            break;
        }
    }

    if (hasLessThanMinusThree) {
        for (double &x : values) {
            if (x < -3.0) {
                x = x * x;
            }
        }
    } else {
        for (double &x : values) {
            x = x * 0.1;
        }
    }

    std::cout << std::fixed << std::setprecision(6);
    for (auto it = values.rbegin(); it != values.rend(); ++it) {
        std::cout << *it;
        if (std::next(it) != values.rend()) {
            std::cout << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
