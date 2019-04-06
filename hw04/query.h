#ifndef DATABASEQUERIES_QUERY_H
#define DATABASEQUERIES_QUERY_H

#include <vector>
#include <functional>
#include <atomic>

template<typename row_t>
using predicate_t = std::function<bool(const row_t &)>;



template<typename row_t>
bool is_satisfied_for_all(std::vector<predicate_t<row_t>> predicates, std::vector<row_t> data_table);

template<typename row_t>
bool is_satisfied_for_any(std::vector<predicate_t<row_t>> predicates, std::vector<row_t> data_table);



template<typename row_t>
bool is_satisfied_for_all(std::vector<predicate_t<row_t>> predicates, std::vector<row_t> data_table) {
    // Doimplementujte telo funkce, ktera rozhodne, zda pro VSECHNY dilci dotazy (obsazene ve
    // vektoru 'predicates') existuje alespon jeden zaznam v tabulce (reprezentovane vektorem
    // 'data_table'), pro ktery je dany predikat splneny.

    // Pro inspiraci si prostudujte kod, kterym muzete zjistit, zda prvni dilci dotaz plati,
    // tj., zda existuje alespon jeden radek v tabulce, pro ktery predikat reprezentovany
    // funkci predicates[i] plati:


            // Funkce reprezentujici predikat prvniho poddotazu

    unsigned int row_count = data_table.size();    // Kazdy radek tabulky je reprezentovany jednim prvkem
                                                   // vektoru 'data_table'. Velikost vektoru tedy odpovida
                                                   // poctu zaznamu
    std::atomic<bool> jump_out{false};

    #pragma omp parallel for shared(jump_out)
    for (unsigned int j = 0; j < predicates.size(); j++) {
        //skip everything
        if (jump_out){
            continue;
        }
        bool is_true_all=false;
        auto &first_predicate = predicates[j];

        for (unsigned int i = 0; i < row_count; i++) {
            auto &row = data_table[i];                // i-ty radek tabulky ...
            bool is_satisfied = first_predicate(row);  // ... splnuje prvni predikat, pokud funkce first_predicate
            //     vrati true

            if (is_satisfied) {
                // Nalezli jsme radek, pro ktery je predikat splneny.
                // Dilci poddotaz tedy plati
                is_true_all = true;
                break;
            } else {
                is_true_all = false;
                // V opacnem pripade hledame dal - stale muzeme najit radek, pro ktery predikat plati
            }
        }
        if (is_true_all == false) {
            jump_out = true;
        }
    }
    if(jump_out){
        return false;
    }
    // Radek, pro ktery by prvni predikat platil, jsme nenasli. Prvni dilci dotaz je tedy
    // nepravdivy
    return true;
}

template<typename row_t>
bool is_satisfied_for_any(std::vector<predicate_t<row_t>> predicates, std::vector<row_t> data_table) {
    // Doimplementujte telo funkce, ktera rozhodne, zda je ALESPON JEDEN dilci dotaz pravdivy.
    // To znamena, ze mate zjistit, zda existuje alespon jeden predikat 'p' a jeden zaznam
    // v tabulce 'r' takovy, ze p(r) vraci true.

    // Zamyslete se nad tim, pro ktery druh dotazu je vhodny jaky druh paralelizace. Vas
    // kod optimalizujte na situaci, kdy si myslite, ze navratova hodnota funkce bude true.
    // Je pro Vas dulezitejsi rychle najit splnujici radek pro jeden vybrany predikat, nebo
    // je dulezitejsi zkouset najit takovy radek pro vice predikatu paralelne?

    unsigned int row_count = data_table.size();    // Kazdy radek tabulky je reprezentovany jednim prvkem
    // vektoru 'data_table'. Velikost vektoru tedy odpovida
    // poctu zaznamu
    std::atomic<bool> is_true_all{false};


    for (unsigned int j = 0; j < predicates.size(); j++) {
        //lets skip all things if it is true
        if (is_true_all){
            return is_true_all;
        }
        auto &first_predicate = predicates[j];
            #pragma omp parallel for shared(is_true_all) schedule(static)
            for (unsigned int i = 0; i < row_count; i++) {
                if (is_true_all){
                    continue;
                }
                auto &row = data_table[i];                // i-ty radek tabulky ...
                bool is_satisfied = first_predicate(
                        row);  // ... splnuje prvni predikat, pokud funkce first_predicate
                //     vrati true

                if (is_satisfied) {
                    // Nalezli jsme radek, pro ktery je predikat splneny.
                    // Dilci poddotaz tedy plati
                    is_true_all = true;
                } else {
                    // is_true_all = false;
                    // V opacnem pripade hledame dal - stale muzeme najit radek, pro ktery predikat plati
                }
            }
        if (is_true_all){
            return is_true_all;
        }


    }
    if (is_true_all){
        return is_true_all;
    }


    // Radek, pro ktery by prvni predikat platil, jsme nenasli. Prvni dilci dotaz je tedy
    // nepravdivy
    return false;
}


#endif //DATABASEQUERIES_QUERY_H
