CXX = g++

slm: src/main.cpp src/k_gram_map.h src/generator.h
	$(CXX) src/main.cpp -o slm

clean:
	rm -f slm