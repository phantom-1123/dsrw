#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

const char input_file[1024]="../testcase/1.in";
const char output_file[1024]="testcase/brute_solve1.out";
const char info_file[1024]="info_31.txt";

int main(){
    std::ifstream fin(input_file);
    //std::ofstream fout(output_file);
    std::ofstream fout(info_file);
    int n,m;
    fin >>n >>m;
    std::vector<int> keys(31);
    for (int i=0;i<=30;i++){
        int key, value;
        fin >> key >>value;
        keys[i]=key;
    }
    std::sort(keys.begin(),keys.end());
    std::vector<int> new_keys;
    new_keys.push_back(keys[0]);
    for (int i=1; i< keys.size(); i++){
        if (keys[i] != keys[i-1]){
            new_keys.push_back(keys[i]);
        }
    }
    std::cout<< new_keys.size() <<std::endl;
    for (int i=0;i<new_keys.size();i++){
        fout << new_keys[i] << std::endl;
    }
}