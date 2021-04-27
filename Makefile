all: rastreador hora

rastreador:
	gcc main.c -o rastreador

hora:
	gcc hora.c -o hora

clean:
	rm -f rastreador hora
