# Define the C++ compiler tool options
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wno-sign-compare

TARGET = compiler

all: $(TARGET)

$(TARGET): src/lexer/lex.yy.c src/parser/parser.tab.c src/ast/ast.cpp src/symbol_table/symbol_table.cpp src/semantic/semantic.cpp src/main.cpp
	$(CXX) $(CXXFLAGS) -Isrc/parser src/lexer/lex.yy.c src/parser/parser.tab.c src/ast/ast.cpp src/symbol_table/symbol_table.cpp src/semantic/semantic.cpp src/main.cpp -o $(TARGET)

src/parser/parser.tab.c: src/parser/parser.y
	bison -d -o src/parser/parser.tab.c src/parser/parser.y

src/lexer/lex.yy.c: src/lexer/lexer.l src/parser/parser.tab.c
	flex -o src/lexer/lex.yy.c src/lexer/lexer.l

clean:
ifeq ($(OS),Windows_NT)
	del /f /q src\lexer\lex.yy.c src\parser\parser.tab.c src\parser\parser.tab.h $(TARGET).exe 2>nul || exit 0
else
	rm -f src/lexer/lex.yy.c src/parser/parser.tab.c src/parser/parser.tab.h $(TARGET)
endif

test:
	@for file in tests/*.txt; do \
		echo "=============================="; \
		echo "Running $$file"; \
		echo "=============================="; \
		./$(TARGET) < $$file; \
		echo ""; \
	done