#include <fstream>
#include <iostream>

#include "btree_map.h"

//#define TEST

const char input_file[1024]="testcase/1.in";
const char info_file[1024]="testcase/leaf_info_simple2.txt";

int main(){
    std::ifstream fin(input_file);
    std::ofstream fout(info_file);
    int n, m;
    fin >> n >>m;
    tlx::btree_map<int, int> nmap;
    for(int i=1; i<=n; i++){
        int key, value;
        fin >> key >>value;
        nmap.insertRewrite(std::make_pair(key,value));
    }
    auto tree=nmap.getTree();
    for (auto itr=tree.begin();itr!=tree.end();itr++){
        fout << itr->first <<std::endl;
    }
}