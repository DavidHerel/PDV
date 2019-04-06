#ifndef SORTING_COUNTINGSORT_H
#define SORTING_COUNTINGSORT_H

#include <vector>
#include <limits>
#include <cstdlib>
#include <chrono>
#include <omp.h>
#include "../_prefixsum/prefixsum.h"

template <typename elem_t>
void counting_sequential(std::vector<elem_t> & data) {
    elem_t minElement = std::numeric_limits<elem_t>::max();
    elem_t maxElement = std::numeric_limits<elem_t>::min();

    for(auto && el : data) {
        if(el < minElement) minElement = el;
        if(el > maxElement) maxElement = el;
    }

    const size_t range = maxElement - minElement + 1;
    std::vector<unsigned int> counts(range);

    for(auto && el : data) {
        ++counts[el-minElement];
    }

    unsigned int idx = 0;
    for(unsigned int i = 0 ; i < range ; i++) {
        unsigned int count = counts[i];
        unsigned int number = minElement + i;
        for(unsigned int k = 0 ; k < count ; k++) {
            data[idx++] = number;
        }
    }
}

template <typename elem_t>
void counting_parallel(std::vector<elem_t> & data) {
    // Naimplementujte paralelni verzi counting-sortu. Zamyslete se nad tim,
    // jak muzete paralelizovat:
    //   1) Nalezeni rozsahu hodnot v poli
    //   2) Napocitani "histogramu"
    //   3) "Vypsani" histogramu do pole 'data'
    // Inspirovat se muzete sekvencni implementaci

    elem_t minElement = std::numeric_limits<elem_t>::max();
    elem_t maxElement = std::numeric_limits<elem_t>::min();
    int size = data.size();
#pragma omp parallel for reduction(min:minElement) reduction(max:maxElement)
    for(int i = 0; i < size; i++) {
        int el = data[i];
        if(el < minElement) minElement = el;
        if(el > maxElement) maxElement = el;
    }

    const size_t range = maxElement - minElement + 1;
    std::vector<unsigned int> counts(range);
//
//#pragma omp parallel for
//    for(int i = 0; i < size; i++) {
//        int el = data[i];
//#pragma omp atomic
//        ++counts[el-minElement];
//    }
//ctrl+/
    int num_threads = omp_get_max_threads();
    std::vector<std::vector<unsigned int>> threads_counts(num_threads);
    for (int i = 0; i < num_threads; i++){
        threads_counts[i].resize(range);
    }
#pragma omp parallel
    {
        auto & my_counts = threads_counts[omp_get_thread_num()];
#pragma omp for
        for(int i = 0; i < size; i++) {
            int el = data[i];
            ++my_counts[el-minElement];
        }
#pragma omp for
        for(int i = 0; i<range; i++){
            for(int j = 0; j < num_threads; j++){
                counts[i] += threads_counts[j][i];
            }
        }

    };
    unsigned int idx = 0;
    for(unsigned int i = 0 ; i < range ; i++) {
        unsigned int count = counts[i];
        unsigned int number = minElement + i;
        for(unsigned int k = 0 ; k < count ; k++) {
            data[idx++] = number;
        }
    }
}

#endif //SORTING_COUNTINGSORT_H
