#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "generator.h"
using namespace std;

int main(int argc, char* argv[]) {
    /* if(argc!=4){
        cerr << "Usage: <size of chunks> <input.txt> <size of output>"<< endl;
        exit(1);
    } 
    */
    int k = atoi(argv[1]);
    string input_file = argv[2];
    int output_n = atoi(argv[3]);
    int n = atoi(argv[3]);
    int m = atoi(argv[4]);
    string input;
    
    ifstream f;
    f.open(input_file);
    string line;
    while(getline(f,line)){
        input+=line;
    }

/*     KGramMap MP(input,k);

    vector<string> outer_keys = MP.outer_keys;
    vector<char> inner_keys = MP.get_inner_keys(outer_keys[n]);
    vector<int> values = MP.get_values(outer_keys[n]);
    
    
    cout << n<< "th outer Key: " << outer_keys[n] << endl;
    cout << m<< "th inner Key: " << inner_keys[m] << endl;
    cout << "Value: " << values[m] << endl;
    cout << "key vector sizes: "<<outer_keys.size() << " " << inner_keys.size() << " " << values.size()<< endl;
    cout << "probabilitiy: " << MP.probability(outer_keys[n],inner_keys[m]) << endl;
    float freq =MP.frequency(outer_keys[n]);
    cout << "frequency: " << freq << endl; */

    Generator Gen(input,k,output_n);
    Gen.generate();
    cout << Gen.output << endl;
    return 0;
}