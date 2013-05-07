all:
	g++ --std=c++11 -Wall -O3 dlghash.cpp -o bin/dlghash
	chmod +x bin/dlghash
install:
	cp bin/dlghash /usr/local/bin/dlghash
remove:
	rm /usr/local/bin/dlghash