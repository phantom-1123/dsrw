#include <iostream>

#include "btree_map.h"

#ifdef TEST
#include <string>
#include <stdio.h>
const char input_file[1024]="testcase/1/4.in";
const char out_std_file[1024]="testcase/1/4.out";
const char out_file[1024]="testcase/1/test.out";

void checker(){
    std::string t,ans,ans2;
	int i;
	freopen(out_file,"r",stdin);
	char c;
	while(scanf("%c",&c)!=EOF) ans+=c;
	fclose(stdin);
	freopen(out_std_file,"r",stdin);
	while(scanf("%c",&c)!=EOF) ans2+=c;;
    freopen("/dev/console", "r", stdin);
    freopen("testcase/1/result.txt", "w", stdout);
	fclose(stdin);
	if(ans.size()!=ans2.size()){std::cout<<"NO\n";return ;}
	for(i=0;i<ans.size();i++)
		if(ans[i]!=ans2[i]){std::cout<<"NO\n";return ;}
	std::cout<<"YES\n";
}
#endif

int main(){

#ifdef TEST
    freopen("testcase/1/test.out", "w", stdout);
    freopen(input_file,"r", stdin);
#endif
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
        auto itr_begin=nmap.lower_bound(lvalue);
        auto itr_end=nmap.lower_bound(rvalue);
        for(auto it=itr_begin;it!=itr_end;it++){
            count++;
        }
        std::cout<<count<<std::endl;
    }

#ifdef TEST
    freopen("/dev/console", "r", stdin);
    fclose(stdin);
    fclose(stdout);
    checker();
#endif


    return 0;
}