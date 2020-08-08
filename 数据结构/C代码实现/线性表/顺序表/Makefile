SqListTest:SqListTest.o SqList.o
	gcc SqListTest.o SqList.o -o SqListTest
SqListTest.o:SqListTest.c
	gcc -c SqListTest.c
SqList.o:SqList.c
	gcc -c SqList.c

.PHONY:clean
clean:
	@echo "=======clean project========="
	rm -f *.o
	@echo "=======clean completed========="