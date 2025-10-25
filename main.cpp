#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

map<string,map<char,int>> k_gram_map(int k, string &input) {
    map<string, map<char,int>> mp;
    for(int i=0; i<input.size();i++) { // check k_gram and next char for each i
        string current_kgram = input.substr(i,k); // slice from start i to len k
        char next_char = input[i+k];
        mp [current_kgram] [next_char]++;
    }
    return mp;
}

vector<string> get_outer_keys(map<string,map<char,int>> const &input_map) {
    vector<string> keys;
    for(auto const &element:input_map){
        keys.push_back(element.first);
    }
    return keys;
}

vector<char> get_inner_keys(map<char,int> const &input_map) {
    vector<char> keys;
    for(auto const &element:input_map){
        keys.push_back(element.first);
    }
    return keys;
}


int main(int argc, char* argv[]) {
    /* if(argc!=4){
        cerr << "Usage: <size of chunks> <input.txt> <size of output>"<< endl;
        exit(1);
    } */
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

    map<string, map<char,int>> mp = k_gram_map(k,input);

    vector<string> outer_keys = get_outer_keys(mp);
    vector<char> inner_keys = get_inner_keys(mp[outer_keys[n]]);
    int value = mp [outer_keys[n]] [inner_keys[m]];
    cout << n<< "th outer Key: " << outer_keys[n] << endl;
    cout << m<< "th inner Key: " << inner_keys[m] << endl;
    cout << "Value: " << value << endl;

    return 0;
}