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
            for(int i = 12; i<=20; i++){
                lba += buffer[i];
            }
            r_lba = atoi(lba.c_str());
            v_lba.push_back(r_lba);
            lba = "";
        }
    }
    int flag = 0;
    vector<int> c_vector;
    c_vector.push_back(v_lba[0]);
    int count = 0;
    for(int i = 0; i < v_lba.size(); i++){
        if(v_lba[i+1] - v_lba[i] > 1){
            c_vector.push_back(v_lba[i]);
            c_vector.push_back(v_lba[i+1]);
        }
        if(v_lba[i] - v_lba[i+1] > 1){
            c_vector.push_back(v_lba[i]);
            c_vector.push_back(v_lba[i+1]);
        }
    }
    int offset = 0;
    for(int i = 1; i < c_vector.size(); i++){
        int size = c_vector[i] - c_vector[i-1] + 1;
        cout<<offset * 512<<" "<<c_vector[i - 1]<<" "<<c_vector[i]<<" "<<size<<endl;
        offset += size;
        i=i+1;
    }
}
