build:
	gcc -o typewriter typewriter.c

install:
	make build
	cp typewriter /usr/bin/
	mkdir -p /etc/typewriter
	cp *.mp3 /etc/typewriter

uninstall:
	rm /usr/bin/typewriter
	rm -rf /etc/typewriter/

run:
	make build
	./typewriter

kill:
	killall typewriter

clean:
	-rm typewriter
