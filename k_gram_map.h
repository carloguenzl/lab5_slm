#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

class KGramMap {
public:
    string input;
    int k;
    map<string,map<char,int>> mp;
    vector<string> outer_keys;

    KGramMap(const string &inp,int n): input(inp),k(n) {
        for(int i=0; i+k<input.size();i++) {
            string current_kgram = input.substr(i,k);
            char next_char = input[i+k];
            mp [current_kgram] [next_char]++;
        }

        for(auto const &element:mp){
            outer_keys.push_back(element.first);
        }
    }

    vector<char> get_inner_keys(string const outer_key) {
        vector<char> keys;
        for(auto const &element:mp[outer_key]){
            keys.push_back(element.first);
        }
        return keys;
    }
};