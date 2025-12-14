bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp
bin/testHashTable: testHashTable.cpp HashTable.h Dict.h TableEntry.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp

bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h
	g++ -o bin/testBSTree testBSTree.cpp

bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h BSTree.h Dict.h BSNode.h TableEntry.h
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp
	

clean:
	rm -rf *.o *.gch bin
