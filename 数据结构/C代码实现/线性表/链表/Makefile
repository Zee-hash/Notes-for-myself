LinkListTest:LinkListTest.o LinkList.o
	gcc LinkListTest.o LinkList.o -o LinkListTest
LinkListTest.o:LinkListTest.c
	gcc -c LinkListTest.c
LinkList.o:LinkList.c
	gcc -c LinkList.c

.PHONY:clean
clean:
	@echo "=======clean project========="
	rm -f *.o
	@echo "=======clean completed========="