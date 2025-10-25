#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <numeric>
#include "k_gram_map.h"
#include <random>
#include <algorithm>
using namespace std;

class Generator {
public:
    int output_length;
    KGramMap MP;
    mt19937 rng;
    string current_gram;
    string output;


    Generator(string input, int k, int out_length): MP(input,k),output_length(out_length) {
        random_device rd;
        rng.seed(rd());
        current_gram = choose_start();
        output = "";
    }

    string choose_start(){
        vector<float> weights = MP.vfrequencies();
        discrete_distribution<int> dist(weights.begin(),weights.end());
        int index = dist(rng);
        return MP.outer_keys[index];
    }

    char choose_next_character(){
        auto it = find(MP.outer_keys.begin(), MP.outer_keys.end(), current_gram); //check if current_gram is in the map 
        if(it!=MP.outer_keys.end()){
            vector<char> chars = MP.get_inner_keys(current_gram);
            vector<float> weights = MP.vprobabilities(current_gram);
            discrete_distribution<int> dist(weights.begin(),weights.end());
            int index = dist(rng);
            cout << chars[index] << endl;
            return chars[index]
        }
        else{
            current_kgram = choose_start();
            choose_next_character();
        }
    }

    void generate(){
        for(int i=0;i<=output_length;i++){
            output+=choose_next_character();
        }
    }