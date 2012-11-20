make:
	@g++ -g -std=c++0x -Wall julian.cpp gregorian.cpp -c 
kattis:
	@g++ -g -std=c++0x -Wall cprog09lab22a.cpp julian.cpp gregorian.cpp kattistime.cpp -o cprog09lab22a.out
test:
	@g++ -g -std=c++0x -Wall datetest.cpp julian.cpp gregorian.cpp kattistime.cpp -o datetest.out
	./datetest.out
testv:
	@g++ -g -std=c++0x -Wall datetest.cpp julian.cpp gregorian.cpp kattistime.cpp -o datetest.out
	valgrind --tool=memcheck --leak-check=yes ./datetest.out
clean:
	@rm -rf *.out *.o
submission1: clean
	python submit.py -f -p oldkattis:cprog09lab22a date.h julian.h julian.cpp gregorian.h gregorian.cpp kattistime.h kattistime.cpp cprog09lab22a.cpp vector.h
	
submission2: clean
	python submit.py -f -p oldkattis:cprog09lab22b date.h gregorian.h gregorian.cpp kattistime.h kattistime.cpp cprog09lab22b.cpp vector.h
	
submission3: clean
	python submit.py -f -p oldkattis:cprog09lab22c date.h julian.h julian.cpp gregorian.h gregorian.cpp kattistime.h kattistime.cpp cprog09lab22c.cpp vector.h
	
	
submission4: clean
	python submit.py -f -p oldkattis:cprog09lab23 date.h julian.h julian.cpp gregorian.h gregorian.cpp kattistime.h kattistime.cpp cprog09lab22c.cpp vector.h calendar.h
	
	
