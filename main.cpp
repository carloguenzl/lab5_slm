#include <iostream>
#include "generator.h"
using namespace std;

int main(int argc, char* argv[]) {
    if(argc!=4){
        cerr << "Usage: <size of chunks> <input.txt> <size of output>"<< endl;
        exit(1);
    } 
    
    int k = atoi(argv[1]);
    string input_file = argv[2];
    int output_n = atoi(argv[3]);
    string input;
    
    ifstream f;
    f.open(input_file);
    string line;
    while(getline(f,line)){
        input+=line;
    }
    Generator Gen(input,k,output_n);
    Gen.generate();
    cout << Gen.output << endl;
    return 0;
}