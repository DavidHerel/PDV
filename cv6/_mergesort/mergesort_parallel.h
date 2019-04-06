#ifndef SORTING_MERGESORT_PARALLEL_H
#define SORTING_MERGESORT_PARALLEL_H

#include "mergesort.h"
#include "mergesort_sequential.h"

template <typename elem_t>
void mergesort_parallel_worker(elem_t *data, unsigned long size, elem_t *tmp);


template <typename elem_t>
void mergesort_parallel(std::vector<elem_t> & data) {

    // Doimplementujte paralelni verzi algoritmu mergesort za pouziti 'task'
    // v OpenMP. Muzete se inspirovat sekvencni verzi algoritmu v souboru
    // 'mergesort_sequential.h' a muzete take pouzit sekvencni metody 'merge'
    // pro sliti dvou serazenych poli do jednoho (implementovanou v souboru
    // 'mergesort.h'). Pravdepodobne si budete potrebovat vytvorit pomocnou
    // funkci. Tu uvodte pomoci 'template <typename elem_t>', abyste meli
    // pristup k typu 'elem_t'.

    // Vytvorime si pomocne pole, do ktereho budeme provadet operaci 'merge'
    const size_t size = data.size();
    std::unique_ptr<elem_t> tmp(new elem_t[size]);
#pragma omp parallel
#pragma omp single
    mergesort_parallel_worker(&data[0], size, tmp.get());
}

template <typename elem_t>
void mergesort_parallel_worker(elem_t *data, unsigned long size, elem_t *tmp){

    // Pole velikosti mensi nez 1 je serazene
    if (size <= 1) {
    return;
    }

    size_t h_size = size / 2;

    // Nejprve si pole rozdelime na dve casti [a .. b-1] a [b .. end-1]
    elem_t *a = data;             // Pointer na zacatek segmentu
    elem_t *b = data + h_size;    // Pointer doprostred segmentu (konec leve poloviny)
    elem_t *end = data + size;    // Konec segmentu (konec prave poloviny)

    // Stejnym zpusobem si rozdelime i pomocne pole
    elem_t *tmp_a = tmp;
    elem_t *tmp_b = tmp + h_size;

    // Zavolame rekurzivni volani na levou a pravou polovinu
    if (size < 512){
        mergesort_parallel_worker(a, h_size, tmp_a
        );
        mergesort_parallel_worker(b, size
                                     - h_size, tmp_b);
        merge(a, b, end, tmp
        );

    }else {
#pragma omp task
        mergesort_parallel_worker(a, h_size, tmp_a
        );
#pragma omp task
        mergesort_parallel_worker(b, size
                                     - h_size, tmp_b);
#pragma omp taskwait
        // A vysledky nakonec slijeme pomoci operace merge
        merge(a, b, end, tmp
        );
    }

}

#endif //SORTING_MERGESORT_PARALLEL_H
