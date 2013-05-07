all:
	g++ --std=c++11 -Wall -O3 dlghash.cpp -o bin/dlghash
	chmod +x bin/dlghash
install:
	cp bin/dlghash /usr/bin/dlghash
remove:
	rm /usr/bin/dlghash