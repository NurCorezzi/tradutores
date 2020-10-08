prog_name=tradutor.out
input_default=input.txt

all:
	bison -d -Wempty-rule -Wconflicts-sr --verbose gramatica.y
	flex definicao.l
	gcc -g -Wall lex.yy.c gramatica.tab.c -o ${prog_name}

r:
	./${prog_name} < ${input_default}
check:
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./${prog_name} < ${input_default}

c1:
	./${prog_name} < ./test/lexico/correto1.txt
c2:
	./${prog_name} < ./test/lexico/correto2.txt
e1:
	./${prog_name} < ./test/lexico/errado1.txt
e2: 
	./${prog_name} < ./test/lexico/errado2.txt

clean:
	rm ./${prog_name} lex.yy.c
