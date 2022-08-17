/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/#ifndef CPP_CODE_PRIME_H
#define CPP_CODE_PRIME_H

#include <string>
#include <sstream>


struct WeightedEdge {
    int v;
    int w;
    int weight;

    WeightedEdge(int v, int w, int weight): v(v), w(w), weight(weight) {}

    std:: string toString() {
        std::stringstream fmt;
        fmt << "WeightedEdge{ v = " << std::to_string(v) << ", w=" << std::to_string(w);
        fmt << ", weight=" << std::to_string(weight) << "}";
        return fmt.str();
    }
};

static bool compareWeightedEdge(WeightedEdge o1, WeightedEdge o2) {
    if (o1.weight > o2.weight) {
        return true;
    }
    return false;
}

#endif //CPP_CODE_PRIME_H
