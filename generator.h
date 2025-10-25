#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <numeric>
#include "k_gram_map.h"
using namespace std;

class Generator {
public:
    int output_length;
    KGramMap MP;
    Generator(string input, int k, int out_length): MP(input,k),output_length(out_length) {

    }
};