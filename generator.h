#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <numeric>
#include "k_gram_map.h"
#include <random>
using namespace std;

class Generator {
public:
    int output_length;
    KGramMap MP;
    mt19937 rng;
    string output;

    Generator(string input, int k, int out_length): MP(input,k),output_length(out_length) {
        random_device rd;
        rng.seed(rd());
        output = choose_start();
    }

    string choose_start(){
        vector<float> weights = MP.vfrequencies();
        discrete_distribution<int> dist(weights.begin(),weights.end());
        int index = dist(rng);
        return MP.outer_keys[index];
    }
    



};