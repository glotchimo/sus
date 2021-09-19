ODIR = obj
SDIR = src

HEADERS = $(SDIR)/token.h $(SDIR)/lexer.h
LIBS = $(ODIR)/token.o $(ODIR)/lexer.o $(ODIR)/stmt.o $(ODIR)/expr.o $(ODIR)/ast.o $(ODIR)/parser.o
FLAGS = -Wall -g

sus : $(SDIR)/sus.c $(LIBS) $(HEADERS)
	@echo 'Compiling [sus.c]'
	@clang $(SDIR)/sus.c -o sus $(LIBS) $(FLAGS)

$(ODIR)/token.o : $(SDIR)/token.c $(SDIR)/token.h
	@echo 'Compiling [token.c]'
	@cd $(SDIR) && clang token.c -c $(FLAGS) -o ../obj/token.o && cd ..

$(ODIR)/lexer.o : $(SDIR)/lexer.c $(SDIR)/lexer.h $(SDIR)/token.h
	@echo 'Compiling [lexer.c]'
	@cd $(SDIR) && clang lexer.c -c $(FLAGS) -o ../obj/lexer.o && cd ..

$(ODIR)/stmt.o : $(SDIR)/stmt.c $(SDIR)/stmt.h $(SDIR)/token.h
	@echo 'Compiling [stmt.c]'
	@cd $(SDIR) && clang stmt.c -c $(FLAGS) -o ../obj/stmt.o && cd ..

$(ODIR)/expr.o : $(SDIR)/expr.c $(SDIR)/expr.h $(SDIR)/token.h
	@echo 'Compiling [expr.c]'
	@cd $(SDIR) && clang expr.c -c $(FLAGS) -o ../obj/expr.o && cd ..

$(ODIR)/ast.o : $(SDIR)/ast.c $(SDIR)/ast.h $(SDIR)/token.h
	@echo 'Compiling [ast.c]'
	@cd $(SDIR) && clang ast.c -c $(FLAGS) -o ../obj/ast.o && cd ..

$(ODIR)/parser.o : $(SDIR)/parser.c $(SDIR)/parser.h $(SDIR)/token.h
	@echo 'Compiling [parser.c]'
	@cd $(SDIR) && clang parser.c -c $(FLAGS) -o ../obj/parser.o && cd ..

clean :
	@echo 'Removing executable and object files'
	@rm -f sus obj/*.o
