#include <iostream>
#include <fstream>
#include <cstdio>

#ifdef TEST
const char input_file[1024]="testcase/1.in";
const char out_std_file[1024]="testcase/1.out";
const char out_file[1024]="testcase/leaf_info_simple.txt";

void checker(){
    std::string t,ans,ans2;
	int i;
	freopen(out_file,"r",stdin);
	char c;
	while(scanf("%c",&c)!=EOF) ans+=c;
	fclose(stdin);
	freopen(out_std_file,"r",stdin);
	while(scanf("%c",&c)!=EOF) ans2+=c;;
    //freopen("/dev/console", "r", stdin);
    freopen("testcase/result.txt", "w", stdout);
	fclose(stdin);
	if(ans.size()!=ans2.size()){std::cout<<"NO\n";return ;}
	for(i=0;i<ans.size();i++)
		if(ans[i]!=ans2[i]){std::cout<<"NO\n";return ;}
	std::cout<<"YES\n";
}
#endif //TEST

#include "btree_map.h"


int main(){
#ifdef TEST
    freopen(out_file, "w", stdout);
    freopen(input_file,"r", stdin);
#endif
    //part2
    int n, m;
    std::scanf("%d", &n);
    std::scanf("%d", &m);
    tlx::btree_map<int, int> nmap;
    for(int i=1; i<=n; i++){
        int key, value;
        std::scanf("%d", &key);
        std::scanf("%d", &value);
        nmap.insert(std::make_pair(key,value));
    }
    //nmap.getTree().printLeafSlotuse();
    std::cerr << (nmap.find(2060954865) != nmap.end())<<std::endl;

   /* 
    for (int i=1; i<=9512; i++){
        int lvalue, rvalue;
        std::scanf("%d", &lvalue);
        std::scanf("%d", &rvalue);
        std::printf("%d\n", nmap.rangeQuery(lvalue, rvalue));
    }
    for (int i=9513; i<=m; i++){
        int lvalue, rvalue;
        std::scanf("%d", &lvalue);
        std::scanf("%d", &rvalue);
        std::printf("%d\n", nmap.rangeQuery(lvalue, rvalue));
    }
    */
    

        /*
        int count=0;
        if(lvalue <= rvalue){
            auto itr_begin=nmap.lower_bound(lvalue);
            auto itr_end=nmap.lower_bound(rvalue);
            for(auto it=itr_begin;it!=itr_end;it++){
                count++;
            }
            std::printf("%d\n", count);
        }
        else{
            std::printf("%d\n", 0);
        }
        */
    

#ifdef TEST
    //freopen("/dev/console", "r", stdin);
    fclose(stdin);
    fclose(stdout);
    //checker();
#endif

    return 0;
}