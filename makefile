# Pair Programming Equitable Participation & Honesty Affidavit
# We the undersigned promise that we have in good faith attempted to follow the principles of pair programming. 
# Although we were free to discuss ideas with others, the implementation is our own. 
# We have shared a common workspace and taken turns at the keyboard for the majority of the work that we are submitting. 
#Furthermore, any non programming portions of the assignment were done independently. 
#We recognize that should this not be the case, we will be subject to penalties as outlined in the course syllabus.


# Darren Ferrer
# Pair Programmer 1

# Ethan Ha
# Pair Programmer 2

myls: myls.o
	g++ myls.o -o myls

myls.o: myls.cpp
	g++ -c myls.cpp

clean:
	rm *.o myls