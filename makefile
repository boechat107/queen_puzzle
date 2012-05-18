# Andre Ambrosio Boechat

COMP = g++ -ansi -pedantic

ARQS =		Main.o\
		Queen.o\
		
	
EXE = queen

all:	$(ARQS)
	$(COMP) $(ARQS) -o $(EXE)
	
run:
	./$(EXE)
	
clean:
	rm -f $(EXE) *.o
	
cleanall:
	rm -f $(EXE) *.o *~
	
mem:
	valgrind --leak-check=yes --show-reachable=yes ./$(EXE)
