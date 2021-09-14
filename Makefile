ODIR = obj
SDIR = src

HEADERS = $(SDIR)/token.h $(SDIR)/lexer.h
LIBS = $(ODIR)/token.o $(ODIR)/lexer.o
FLAGS = -Wall -g

monkey : $(SDIR)/monkey.c $(LIBS) $(HEADERS)
	@echo 'Compiling [monkey.c]'
	@clang $(SDIR)/monkey.c -o monkey $(LIBS) $(FLAGS)

$(ODIR)/token.o : $(SDIR)/token.c $(SDIR)/token.h
	@echo 'Compiling [token.c]'
	@cd $(SDIR) && clang token.c -c $(FLAGS) -o ../obj/token.o && cd ..

$(ODIR)/lexer.o : $(SDIR)/lexer.c $(SDIR)/lexer.h $(SDIR)/token.h
	@echo 'Compiling [lexer.c]'
	@cd $(SDIR) && clang lexer.c -c $(FLAGS) -o ../obj/lexer.o && cd ..

clean :
	@echo 'Removing executable and object files'
	@rm -f monkey obj/*.o
