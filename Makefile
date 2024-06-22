output: tenser.o
	g++ test/test_tenser.cpp

tenser.o: src/tenser.cpp include.blackwall/tenser.hpp
	g++ -c src/tenser.cpp