
output: test_shopkeeper.o shopkeeper.o test_thing.o
	g++ test_shopkeeper.o shopkeeper.o test_thing.o -o output

test_shopkeeper.o: test_shopkeeper.cpp
	g++ -c test_shopkeeper.cpp

shopkeeper.o: shopkeeper.cpp shopkeeper.h
	g++ -c shopkeeper.cpp

test_thing.o: test_thing.cpp test_thing.h
	g++ -c test_thing.cpp

clean:
	rm *.o