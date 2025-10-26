CXX = g++

slm: main.cpp k_gram_map.h generator.h
	$(CXX) main.cpp -o slm

clean:
	rm -f slm