#include <fstream>
#include <iostream>

#include "../btree_map.h"

//#define TEST

const char input_file[1024]="../testcase/1.in";
const char info_file[1024]="leaf_info_debug.txt";

int main(){
    std::ifstream fin(input_file);
    freopen(info_file,"w",stdout);
    int n, m;
    fin >> n >>m;
    tlx::btree_map<int, int> nmap;
    bool flag=false;
    for(int i=1; i<=30; i++){
        int key, value;
        fin >> key >>value;
        nmap.insert(std::make_pair(key,value));
        if (i ==31){
            nmap.getTree().printLeafSlotuse();
            std::cerr << (nmap.find(2060954865) != nmap.end())<<std::endl;
        }
    }
    for(int i=31; i<=n; i++){
        int key, value;
        fin >> key >>value;
        nmap.insert(std::make_pair(key,value));
        if (i ==31){
            nmap.getTree().printLeafSlotuse();
            std::cerr << (nmap.find(2060954865) != nmap.end())<<std::endl;
        }
    }
}
    
            
        /*
        if (flag == false){
            auto tree=nmap.getTree();
            for (auto itr=tree.begin();itr!=tree.end();itr++){
                if (itr->first == 1679455307){
                    std::cout << "31 appeared at" << i <<std::endl;
                    auto it=itr;
                    ++it;
                    std::cout << (it == tree.end()) <<std::endl;
                    flag = true;
                    break;
                }
            }
        }
        */
        
    //fclose(stdout);