#include "integrate.h"

#include <omp.h>
#include <cmath>

double
integrate_sequential(std::function<double(double)> integrand, double a, double step_size, int step_count) {

    // Promenna kumulujici obsahy jednotlivych obdelniku
    double acc = 0.0;

    for (int i = 0; i < step_count; i++){
        double xc = a+i*step_size+step_size/2;
        acc += integrand(xc) * step_size;
    }
    
    // Celkovy obsah aproximuje hodnotu integralu funkce
    return acc;
}

double
integrate_omp_critical(std::function<double(double)> integrand, double a, double step_size, int step_count) {
    double acc = 0.0;
    throw "not now";
    //TODO
    // Rozdelte celkovy interval na podintervaly prislusici jednotlivym vlaknum
    // Identifikujte kritickou sekci, kde musi dojit k zajisteni konzistence mezi vlakny

    #pragma omp parallel
    {

        int num_threads = omp_get_num_threads();
        int chunks = (step_count/num_threads) + 1;
        int thread_id = omp_get_thread_num();

        int begin = thread_id*chunks;;
        int end = (thread_id+1)*chunks;

        if (end > step_count){
            end = step_count;
        }

        for (int i = begin; i < end; i++){
            double xc = a+i*step_size+step_size/2;

            #pragma omp critical
            {
                acc += integrand(xc) * step_size;

            };
        }
    };

    return acc;
}

double
integrate_omp_atomic(std::function<double(double)> integrand, double a, double step_size, int step_count) {
    double acc = 0.0;
    throw "not now";
    //TODO
    // Rozdelte celkovy interval na podintervaly prislusici jednotlivym vlaknum
    // Identifikujte kritickou sekci, kde musi dojit k zajisteni konzistence mezi vlakny

#pragma omp parallel
    {

        int num_threads = omp_get_num_threads();
        int chunks = (step_count/num_threads) + 1;
        int thread_id = omp_get_thread_num();

        int begin = thread_id*chunks;;
        int end = (thread_id+1)*chunks;

        if (end > step_count){
            end = step_count;
        }

        for (int i = begin; i < end; i++){
            double xc = a+i*step_size+step_size/2;

                #pragma omp atomic
                acc += integrand(xc) * step_size;

        }
    };

    return acc;
}

double integrate_omp_reduction(std::function<double(double)> integrand, double a, double step_size, int step_count) {
    double acc = 0.0;

    //TODO
    // Rozdelte celkovy interval na podintervaly prislusici jednotlivym vlaknum
    // Identifikujte kritickou sekci, kde musi dojit k zajisteni konzistence mezi vlakny

#pragma omp parallel reduction(+: acc)
    {

        int num_threads = omp_get_num_threads();
        int chunks = (step_count/num_threads) + 1;
        int thread_id = omp_get_thread_num();

        int begin = thread_id*chunks;;
        int end = (thread_id+1)*chunks;

        if (end > step_count){
            end = step_count;
        }

        for (int i = begin; i < end; i++){
            double xc = a+i*step_size+step_size/2;


                acc += integrand(xc) * step_size;

        }
    };

    return acc;
}

double integrate_omp_for_static(std::function<double(double)> integrand, double a, double step_size, int step_count) {
    // Promenna kumulujici obsahy jednotlivych obdelniku
    double acc = 0.0;

    //TODO
    //rozsirte integrate_omp_reduction o staticke rozvrhovani

    #pragma omp parallel for reduction(+: acc) schedule(static)
    for (int i = 0; i < step_count; i++){
        double xc = a+i*step_size+step_size/2;
        acc += integrand(xc) * step_size;
    }
    
    // Celkovy obsah aproximuje hodnotu integralu funkce
    return acc;
}

double integrate_omp_for_dynamic(std::function<double(double)> integrand, double a, double step_size, int step_count) {
    // Promenna kumulujici obsahy jednotlivych obdelniku
    double acc = 0.0;

    //TODO
    //rozsirte integrate_omp_reduction o dynamicke rozvrhovani

#pragma omp parallel for reduction(+: acc) schedule(dynamic)
    for (int i = 0; i < step_count; i++){
        double xc = a+i*step_size+step_size/2;
        acc += integrand(xc) * step_size;
    }
    
    // Celkovy obsah aproximuje hodnotu integralu funkce
    return acc;
}
