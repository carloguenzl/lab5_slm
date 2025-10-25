CXX = g++

main: main.cpp k_gram_map.h generator.h
	$(CXX) main.cpp -o main

clean:
	rm -f main