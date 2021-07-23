#include <iostream>

#include "btree_map.h"

int main(){
    //part1
    tlx::btree_map<int, int> nmap;
    int n, m, p, q;
    std::cin >> n >>m >>p >>q;
    for (int i=1;i<=n;i++){
        int key, value;
        std::cin >> key >> value;
        nmap.insert(std::make_pair(key,value));
    }

    for (int i=1;i<=m;i++){
        int key;
        std::cin >> key;
        auto itr = nmap.find(key);
        if (itr!=nmap.end())
            std::cout << itr->second << std::endl;
        else
            std::cout << "NOT FOUND" << std::endl;
    }

    for (int i=1;i<=p;i++){
        int key,value;
        std::cin >> key >> value;
        nmap.erase(key);
        nmap.insert(std::make_pair(key,value));
    }

    for (int i=1;i<=q;i++){
        int lvalue,rvalue;
        std::cin >> lvalue >> rvalue;
        int count=0;
        auto itr_end=nmap.end();
        for (int k=lvalue; k<rvalue;k++){
            if (itr_end!=nmap.find(k))
                count++;
        }
        std::cout<<count<<std::endl;
    }
    


    return 0;
}