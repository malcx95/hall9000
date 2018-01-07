SOURCES=../servocontrol.hpp ../servocontrol.cpp fakeservo.hpp fakeservo.cpp \
		servocontroltests.cpp

TEST_SOURCE=unittestmain.cpp

test:
	g++ $(SOURCES) $(TEST_SOURCE) --std=c++11 -o test -Wall -g -DIS_UNITTEST 
	./test

clean:
	rm test

