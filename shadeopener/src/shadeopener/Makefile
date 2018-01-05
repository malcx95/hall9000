SOURCES=servocontrol.hpp servocontrol.cpp unittest/fakeservo.hpp unittest/fakeservo.cpp

TEST_SOURCE=unittest/unittest.cpp

test:
	g++ $(SOURCES) $(TEST_SOURCE) --std=c++11 -o test -Wall -g -DIS_UNITTEST 
	./test

clean:
	rm test

