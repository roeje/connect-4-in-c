CC = gcc
CFLAGS = -g

mainFileDriver = driver.o connect4_engine.o connect4_engine.o
mainFileTest = c4_engine_test.o CuTest.o

main.exe : $(mainFileDriver)
	$(CC) $(CFLAGS) $(mainFileDriver) -o main.exe

tester.exe : $(mainFileTest)
	$(CC) $(CFLAGS) $(mainFileTest) -o tester.exe	

%.o : %.c
	$(CC) $(CFLAGS) -c $<


# CC = clang
# CFLAGS = -g -Wall

# c4_objects = connect4.o connect4_engine.o
# c4: $(c4_objects)
# 	clang $(CFLAGS) $(c4_objects) -o $@

# c4_test_objects = connect4_engine.o CuTest.o c4_engine_test.o
# c4_test: $(c4_test_objects)
# 	clang $(CFLAGS) $(c4_test_objects) -o $@
