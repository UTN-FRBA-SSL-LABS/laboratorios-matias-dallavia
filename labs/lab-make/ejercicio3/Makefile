# Nombre del ejecutable final
PROGRAMA := calc3

# Compilador
CC := gcc

# Regla principal
all: $(PROGRAMA)

# Regla para construir la calculadora a partir del parser y el scanner
# Bison genera: parser3.tab.c y parser3.tab.h
# Flex genera:  lex.yy.c
$(PROGRAMA): parser3.tab.c lex.yy.c
	$(CC) -Wall $^ -o $(PROGRAMA)

parser3.tab.c: parser3.y
	bison -d $<

lex.yy.c: scanner3.l
	flex $<

# Regla para limpiar todos los archivos generados
clean:
	rm -f parser3.tab.c  parser3.tab.h lex.yy.c

.PHONY: all clean
