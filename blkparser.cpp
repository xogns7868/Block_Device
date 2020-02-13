#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    ifstream inFile("blktrace.output");
    string buffer;
    string lba = "";
    int r_lba = 0;
    vector<int> v_lba;
    while(!inFile.eof()){
        getline(inFile, buffer);
        if(buffer[4] == 'R'){
            for(int i = 12; i<20; i++){
                lba += buffer[i];
            }
            r_lba = atoi(lba.c_str());
            v_lba.push_back(r_lba);
            lba = "";
        }
    }
    int flag = 0;
    for(int i = 0; i < v_lba.size(); i++){
        if(v_lba[i+1] - v_lba[i] > 1){
            cout<<flag * 512<<" "<<v_lba[flag]<<" "<<v_lba[i]<<" "<<v_lba[i] - v_lba[flag] + 1<<endl;
            flag = i + 1;
        }
    }
}