#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

map<string,map<char,int>> k_gram_map(int k, string &input) {
    map<string, map<char,int>> mp;
    for(int i; i<input.size();i++) { // check k_gram and next char for each i
        string current_kgram = input.substr(i,k); // slice from start i to len k
        char next_char = input[i+k];
        mp [current_kgram] [next_char]++;

    }
    return mp;
}


int main(int argc, char* argv[]) {
    if(argc!=4){
        cerr << "Usage: <size of chunks> <input.txt> <size of output>"<< endl;
        exit(1);
    }
    int k;
    string input_file = argv[2];
    int output_n;
    string input;
    
    ifstream f;
    f.open(input_file);
    string line;
    while(getline(f,line)){
        input+=line;
    }
    cout << input[15] << endl;

    return 0;
}