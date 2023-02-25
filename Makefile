CC=gcc
CFLAGS=-I/usr/local/opt/openssl/include -L/usr/local/opt/openssl/lib -lssl -lcrypto
DEPS=
OBJ=main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) main
