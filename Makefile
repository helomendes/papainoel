parametrosCompilacao=-Wall #-Wsahdow
nomePrograma=exec

all: $(nomePrograma)

$(nomePrograma): main.o presentes.o
	gcc -o $(nomePrograma) main.o presentes.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

presentes.o: presentes.h presentes.c
	gcc -c presentes.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
