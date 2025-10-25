# Small Language Model
Goal of this exercise was to implement a rudimentary algorithm to generate text from "training data".
It works by segmenting a text file into packets of k charakters (k-grams) and predicting the next character.
This version of the SLM contains of two objects:

## KGramMap
The header file k_gram_map.h contains the object that evaluates the input. That is, it counts the number of occurances of each k-gram and stores next valid characters. At its heart lies a "map of maps" that we can use to efficiently store the needed data. 
We translate some of the needed data into vectors, mainly the probability-vector (how likely a character after a k-gram is) and the frequency-vector (how frequent a k-gram occurs), so we can handle the calculations for text generation easier.

## Generator
generator.h handles the text generation. Using a random-number-generator, we choose a starting k-gram from the KGramMap. With its probability-vector as the distribution, we then choose the following character, which then makes up the next k-gram, append it to the result-string and we start again. When the result-string has reached a predetermined length, the loop exits and the string is given as the result.

## Usage
To compile, use: `make`
To run, use: `./main <size of k-grams> <input_file.txt> <number of characters in output>`
Example: `./main 5 idiot.txt 100`

## Continuation
- The generated text always begins and ends abruptly due to the nature of k-grams and the hard character limit
- The current algorithm chooses a random k-gram to continue, if the generated one is not in the KGramMap. A more elegant solution would be some kind of similarity-search through the outer_keys of mp to find a natural succession if the generated k-gram cant be found.
- if the k-gram size is too big, this algorithm will just copy the given text. are dynamic k~grams a thing?
- natural succession would be to swich from k-grams to tokens. The same math could maybe be applied but would probably need way more "training" texts

