#ifndef LOCKBASED_H
#define LOCKBASED_H

#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>

#include "spin.h"

class Concurrent {
public:
    class Node {
    public:
        long long value;
        Node * next = nullptr;
        spin_mutex m;

        Node(long long value) : value(value) {}
    };

    Node * head = new Node(-999999999999L);

    // Naimplementujte vlaknove-bezpecne vkladani do konkurentniho spojoveho seznamu.
    // Pro popis struktury spojoveho seznamu se podivejte do souboru 'sequential.h',
    // kde naleznete i implementaci vkladani do spojoveho seznamu, ktera neni vlaknove
    // bezpecna (tj., muze ji provadet pouze jedno vlakno).
    //
    // Vsimnete si, ze trida Node reprezentujici uzel spojoveho seznamu obsahuje svuj
    // vlastni mutex 'm'.
    void insert(long long value) {
        Node * node = new Node(value);   // Novy uzel seznamu, ktery budeme vkladat

        // Nulty prvek je vzdy v seznamu pritomny a nikdy ho nebudeme muset
        // "posunout" dale v seznamu. Vzdy budeme vkladat az za nej.
        Node * current = head;

        // Toto neni nejelegantnejsi implementace vkladani do seznamu, ale doufame,
        // ze Vam poslouzi lepe pri psani konkurentni verze:
        while(true) {
            Node * next = current->next; // Naslednik aktualniho prvku

            if(next == nullptr || next->value > value) {
        //TADY MOHLO JINE VLAKNO MODIFIKOVAT current->next

                current->m.lock();

                if(next == current->next){
                    node->next = next;
                    current->next = node;
                    current->m.unlock();
                    return;
                } else{
                    current->m.unlock();
                }

            } else {
                // V opacnem pripade bude spravne misto pro vlozeni lezet dale
                // v seznamu a musime ho najit. Posuneme se na dalsi prvek a
                // vratime se na zacatek while smycky.
                current = next;

            }
        }

    }

    // Pokud byste si chteli vyzkouset slozitejsi operaci se spojovym seznamem, muzete
    // si zkusit naimplementovat metodu pro odebrani prvku ze seznamu. Vzpomente si,
    // ze na prednasce jsme si rikali, ze mazani prvku probiha dvoufazove.
    //   1) Nejprve prvek oznacim za smazany. Tim zabranim ostatnim vlaknu vkladat za
    //      nej nove prvky.
    //   2) Pote ho vypojim ze seznamu
    //
    // Oznaceni prvku za smazany muzete provest pomoci atomickych operaci tak, ze ukazatel
    // na naslednika oznacite bitovym priznakem (schematicky napr., current->next | 1ULL).
    //
    // Pro jednoduchost nemusite resit dealokaci pameti po odebrani prvku.
    void remove(long long value) {
    }
};

#endif