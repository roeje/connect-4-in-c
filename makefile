CC = gcc
CFLAGS = -g

mainFileDriver = driver.c
mainFileTest = c4_engine_test.c CuTest.c CuTest.h connect4_engine.c

main : $(mainFileDriver)
	$(CC) $(CFLAGS) $(mainFileDriver) -o main.exe

tester : $(mainFileTest)
	$(CC) $(CFLAGS) $(mainFileTest) -o tester.exe	