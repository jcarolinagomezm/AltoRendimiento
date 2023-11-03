GCC = gcc
FLAG = -Wall
PROGS = principalv1
principalv1:
	$(GCC) $(FLAG) $@.c modulo.c -o $@

clean:
	$(RM) $(PROGS) *.o
