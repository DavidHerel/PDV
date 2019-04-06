#include <functional>
#include "bst_tree.h"

void bst_tree::insert(long long data) {
    node * new_node = new node(data);
    node * temp_node = root;
    //lets look on root
    while(true){

        //if null
        if (root == nullptr) {
            root = new_node;
            return;

        //lower
        }else if (new_node->data < temp_node->data){
            node *temp_next = temp_node->left;
            //jestli temp_node->right bude temp_next ulozi se mi do nej new_node
            if (temp_node->left == nullptr && temp_node->left.compare_exchange_strong(temp_next ,new_node)){
                //temp_node->left = new_node;
                return;
            } else{
                temp_node = temp_node->left;
            }
            //higher
        } else if (new_node->data > temp_node->data){
            node *temp_next = temp_node->right;
            //jestli temp_node->right bude temp_next ulozi se mi do nej new_node
            if (temp_node->right == nullptr && temp_node->right.compare_exchange_strong(temp_next ,new_node)){
             //   temp_node->right = new_node;
                return;
            } else{
                temp_node = temp_node->right;
            }
        }
    }
    // Naimplementujte zde vlaknove-bezpecne vlozeni do binarniho vyhledavaciho stromu
}

bst_tree::~bst_tree() {
    // Rekurzivni funkce pro pruchod stromu a dealokaci pameti prirazene jednotlivym
    // uzlum
    std::function<void(node*)> cleanup = [&](node * n) {
        if(n != nullptr) {
            cleanup(n->left);
            cleanup(n->right);

            delete n;
        }
    };
    cleanup(root);
}
