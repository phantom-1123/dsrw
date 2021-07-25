#include <iostream>

#ifdef TEST
#include <fstream>
#define IN fin
#define OUT fout
#else
#define IN std::cin
#define OUT std::cout
#endif //TEST

#include "btree_map.h"

void run_part1 (std::istream & input, std::ostream &output){
    tlx::btree_map<int, int> nmap;
    int n, m, p, q;
    input >> n >>m >>p >>q;
    for (int i=1;i<=n;i++){
        int key, value;
        input >> key >> value;
        nmap.insert(std::make_pair(key,value));
    }

    for (int i=1;i<=m;i++){
        int key;
        input >> key;
        auto itr = nmap.find(key);
        if (itr!=nmap.end())
            output << itr->second << std::endl;
        else
            output << "NOT FOUND" << std::endl;
    }

    for (int i=1;i<=p;i++){
        int key,value;
        input >> key >> value;
        nmap.erase(key);
        nmap.insert(std::make_pair(key,value));
    }

    for (int i=1;i<=q;i++){
        int lvalue,rvalue;
        input >> lvalue >> rvalue;
        int count=0;
        auto itr_end=nmap.end();
        for (int k=lvalue; k<rvalue;k++){
            if (itr_end!=nmap.find(k))
                count++;
        }
        output<<count<<std::endl;
    }
}

int main(){
    //part1
    #ifdef TEST
        std::ifstream fin("test.in");
        std::ofstream fout("test_ans.out");
    #endif //TEST

    run_part1(IN,OUT);
    
    #ifdef TEST
        fout.close();
    #endif //TEST

    return 0;
}