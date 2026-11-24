CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
courier: main.cpp queue.cpp graph.cpp courier.cpp queue.h graph.h courier.h
	$(CXX) $(CXXFLAGS) main.cpp queue.cpp graph.cpp courier.cpp -o courier

test: courier
	python3 tests/test_cli.py

clean:
	rm -f courier
.PHONY: test clean
