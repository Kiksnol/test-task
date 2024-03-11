#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

std::list<int> func(std::vector<int> v, std::list<int> l) {
    std::list<int> vec_cpy;

    for (size_t i = 0; i < v.size(); ++i) {
        vec_cpy.push_back(v[i]);
    }

    for (size_t i = 0; i < l.size(); ++i) {

        std::list<int>::iterator it = l.begin();
        std::advance(it, i);
        if (std::find(vec_cpy.begin(), vec_cpy.end(), *it) != vec_cpy.end()) {
            vec_cpy.push_back(*it);
        }
    }

    std::sort(vec_cpy.begin(), vec_cpy.end());

    return vec_cpy;
}