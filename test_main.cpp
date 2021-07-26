#include <iostream>

#include "btree_map.h"

void output(const tlx::btree_map<int, int> & map){
    auto tree=map.getTree();
    std::cout <<"output() start"<<std::endl;
    for (auto itr = tree.begin(); itr != tree.end(); itr++){
        std::cout << itr->first <<" "<< itr->second << " ";
    }
    std::cout <<"output() finished"<<std::endl;
    std::cout <<tree.is_keyCounterCorrect()<<std::endl;
}

int main(){
    tlx::btree_map<int, int> nmap;
    int key[4]={1,3,2,4};
    int value[4]= {10,11,12,13};
    for (int i=0;i<4;i++){
        int k=key[i];
        int v=value[i];
        nmap.insertRewrite(std::make_pair(k,v));
        output(nmap);
    }
    nmap.insertRewrite(std::make_pair(2, 15));
    output(nmap);
    return 0;
    tlx::BTree<int,int,int> tree;
    tree.find_upper(4);
    tree.find_lower()

}