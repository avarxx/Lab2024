CC = gcc
CFLAGS = -Wall

all: avl_tree search_tree skip_list splay_tree
# cartesian_tree
avl_tree:
	$(CC) $(CFLAGS) -o avlTree/avlTest avlTree/avlTest.c avlTree/avlTree.c
	./avlTree/avlTest

# cartesian_tree:
# 	$(CC) $(CFLAGS) -o cartesianTree/cartesianTest cartesianTree/cartesianTest.c cartesianTree/cartesianTree.c
# 	./cartesianTree/cartesianTest

search_tree:
	$(CC) $(CFLAGS) -o searchTree/searchTest searchTree/searchTest.c searchTree/searchTree.c
	./searchTree/searchTest

skip_list:
	$(CC) $(CFLAGS) -o skipList/skipListTest skipList/skipListTest.c skipList/skipList.c
	./skipList/skipListTest

splay_tree:
	$(CC) $(CFLAGS) -o splayTree/splayTest splayTree/splayTest.c splayTree/splayTree.c
	./splayTree/splayTest

.PHONY: clean
clean:
	rm -f avlTree/avlTest searchTree/searchTest skipList/slipListTest splayTree/splayTest
# cartesianTree/cartesianTest