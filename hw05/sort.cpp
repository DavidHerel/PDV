#include "sort.h"
#include <iostream>


// implementace vaseho radiciho algoritmu. Detalnejsi popis zadani najdete v "sort.h"
void radix_par(std::vector<std::string *> &vector_to_sort, const MappingFunction &mappingFunction,
               unsigned long alphabet_size, unsigned long string_lengths) {


    //if it is 0 kill it
    if (string_lengths == 0){
        return;
    }
    auto size = 0;
    auto actual_length = vector_to_sort[0]->size();
    std::vector<std::string *> buckets[alphabet_size];
    //fill the buckets
    //#pragma omp parallel for
    for (auto i = 0; i < vector_to_sort.size(); i++) {
        //we need to calculate index where are we
        size = actual_length-string_lengths;
        //get the number of current letter in word
        auto alphaNumber = mappingFunction((*vector_to_sort[i])[size]);
        //push there current word
        buckets[alphaNumber].push_back(vector_to_sort[i]);
    }

    //sort every bucket
#pragma omp parallel for
    for (int i = 0; i< alphabet_size; i++){
        //recursivery sort every bucket
        radix_par(buckets[i], mappingFunction, alphabet_size, string_lengths-1);
    }

    int iter = 0;
    //put it into an original array
    //pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < alphabet_size; i++) {
         for (auto j = 0; j < buckets[i].size(); j++){
            vector_to_sort[iter]=buckets[i][j];
            iter++;
            }

    }

}
