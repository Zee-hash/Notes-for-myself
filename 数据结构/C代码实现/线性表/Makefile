test:test.o SqList.o
	gcc test.o SqList.o -o test
test.o:test.c
	gcc -c test.c
SqList.o:SqList.c
	gcc -c SqList.c

.PHONY:clean
clean:
	@echo "=======clean project========="
	rm -f *.o
	@echo "=======clean completed========="