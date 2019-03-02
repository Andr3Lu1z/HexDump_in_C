all:
	gcc -shared -fPIC -o libhex.so ./src/libhex.c
	gcc -o hex_dump main.c -L ./src/ -l hex
clean:
	rm -f libhex.so

install:
	install -m 0644 libhex.so /usr/lib/libhex.so

uninstall:
	rm -f /usr/lib/libhex.so''
