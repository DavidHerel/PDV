// V teto domaci uloze se Vas budeme snazit presvedcit, ze vykon vasi implementace zavisi do znacne miry na podobe
// vstupnich dat. Pri navrhu efektivnich algoritmu byste se tedy meli rozhodovat i na zaklade datove sady.
//
// Vasim ukolem je doimplementovat 4 ruzne metody na pocitani sumy kazdeho vstupniho vektoru ("data").
// V kazde metode budete pouzitivat OpenMP, ale pokazde trochu jinym zpusobem. Rychlost vypoctu Vasi implementace
// budeme porovnavat s nasi referencni implementaci. Vychazet muzete z metody sumsOfVectors_sequential implementovane
// v _executor/Executor.cpp.

//data shared??

#include <iostream>
#include <numeric>
#include <algorithm>
#include "SumsOfVectors.h"

void
sumsOfVectors_omp_per_vector(const vector<vector<int8_t>> &data, vector<long> &solution, unsigned long minVectorSize) {

    //for cyklus na počítání toho vektoru -> 2 loopy nejdřív jedupřes vektory
    //a druhý for mi sčítá ty hodnoty ve vektorech

    for (unsigned long i = 0; i < data.size(); i++) {
        long sum = 0;
        //chci aby kazde vlakno počítalo svojí část
        //mám totiž velké  vektory ale je jich málo
        //chci to nějak rozdělit - jako na cviku
        //kazdy vlakno bude mit stejnou cast -> takze static
        #pragma omp parallel for reduction(+: sum) schedule(static) shared(data)
        for (unsigned long j = 0; j < data[i].size(); j++) {
            sum += data[i][j];
        }

        solution[i] = sum;
    }

    // V teto metode si vyzkousite paralelizaci na urovni vektoru. Naimplementujte paralelni pristup
    // k vypocteni sum jednotlivych vektoru (sumu vektoru data[i] ulozte do solution[i]). V teto
    // funkci zpracovavejte jednotlive vektory sekvencne a paralelizujte nalezeni sumy v jednom
    // konkretnim vektoru. Tento pristup by mel byt zejmena vhodny, pokud mate maly pocet vektoru
    // velke delky.
}

void sumsOfVectors_omp_static(const vector<vector<int8_t>> &data, vector<long> &solution,
                              unsigned long minVectorSize) {

//ted uz paralelizuji, ze kazde vlakno ma vlastni vektor a spocita si vlastni sumu
//protoze jsou kratke
//takze pak ulozi..memusi se resit zamky protoze se neprepisi -> je tam static
//kazda ma svoji vlastni cast
//chyba asi v druhém for cyklu?
//jo jasný musím sharovat i solution aby k němo každé vlákno mělo přistup
// kravina...nechapu proc to neprochazi..
    #pragma omp parallel for schedule(static) shared(data, solution)
    for (unsigned long i = 0; i < data.size(); i++) {
        long sum = 0;

        for (const int8_t &j : data[i]) {
            sum += j;
        }
        solution[i] = sum;
    }
    // Pokud vektory, ktere zpracovavame nejsou prilis dlouhe, ale naopak jich musime zpracovat
    // velky pocet, muzeme zparalelizovat vnejsi for smycku, ktera prochazi pres jednotlive
    // vektory. Vyuzijte paralelizaci pres #pragma omp parallel for se statickym schedulingem.
}

void sumsOfVectors_omp_dynamic(const vector<vector<int8_t>> &data, vector<long> &solution,
                               unsigned long minVectorSize)
                               {
//nyni jsou ty vektory random, takze potrebuje dynamic..neni vhodne aby kazdy mel stejnou cast
//kdyz je vlakno volne musi hned pocitat..
//a u static by byl problem, prvni vlakno by spocitalo svoji cast a cekalo na ostatni
//takhle kazde vlakno by melo byt stejne
    #pragma omp parallel for schedule(dynamic)
    for (unsigned long i = 0; i < data.size(); i++) {
        long sum = 0;


        for (const int8_t &j : data[i]) {
            sum += j;
        }

        solution[i] = sum;
    }
    // Na cviceni jsme si ukazali, ze staticky scheduling je nevhodny, pokud praci mezi
    // jednotliva vlakna nedokaze rozdelit rovnomerne. V teto situaci muze byt vhodnym
    // resenim pouzitim dynamickeho schedulingu. Ten je rovnez vhodny v situacich, kdy
    // nevime predem, jak dlouho budou jednotlive vypocty trvat. Dani za to je vyssi
    // rezie pri zjistovani indexu 'i', ktery ma vlakno v dane chvili zpracovavat.
}


//Tenhle pitomy shuffle mi to nici
void sumsOfVectors_omp_shuffle(const vector<vector<int8_t>> &data, vector<long> &solution,
                               unsigned long minVectorSize) {

    vector<int> indexes(data.size());
    //musim shufflit jenom pointery

    std::iota(indexes.begin(), indexes.end(), 0);
    std::random_shuffle(indexes.begin(), indexes.end());
    //vyshufflim pointery


    #pragma omp parallel for schedule(static) shared(data, solution, indexes)
    for (unsigned long i = 0; i < data.size(); i++) {
        long sum = 0;
        //najdu ty random pointery
        //a ten tam pasnu..nebudu tedy shufflit ty vektory ale jen pointery
        int index = indexes[i];

        for (const int8_t &j : data[index]) {
            sum += j;
        }
        solution[index] = sum;
    }
    // Dalsi moznosti, jak se vyhnout problemum pri pouziti statickeho schedulingu (tj.,
    // zejmena nevyvazenemu rozdeleni prace) je predzpracovani dat. V teto funkci zkuste
    // data pred zparalelizovanim vnejsi for smycky (se statickym schedulingem) nejprve
    // prohazet. To samozrejme predpoklada, ze cas potrebny na predzpracovani je radove
    // mensi, nez zisk, ktery ziskame nahrazenim dynamickeho schedulingu za staticky.
    //
    // Tip: Abyste se vyhnuli kopirovani vektoru pri "prohazovani" (ktere muze byt velmi
    // drahe!), muzete prohazovat pouze pointery na vektory. Alternativou je vytvorit si
    // nejprve pole nahodne serazenych indexu a ty pak pouzit pro pristup k poli.
    // Uzitecnymi metodami mohou byt metody std::iota(...) (ktera Vam vygeneruje posloupnost
    // indexu) a std::random_shuffle(...), ktera zajisti nahodne prohazeni prvku.
}
