all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all test-a test-b test-c test-d test-e

test-a:
	bin/gauss dane/A dane/b

test-b:
	bin/gauss dane/A1 dane/b1
	
test-c:
	bin/gauss dane/A2 dane/b2

test-d:
	bin/gauss dane/A3 dane/b3

test-e:
	bin/gauss dane/A4 dane/b4