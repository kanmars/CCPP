log:log.h log.c
	g++ -c log.h log.c
test:log.h log.c log_t.c
	g++ -o log log.h log.c log_t.c
clean:
	rm -rf log *.o *.gch
