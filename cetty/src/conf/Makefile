all: ../log/log.h ../type/type.h  conf.h conf.cpp 
	g++ -c ../log/log.h ../type/type.h  conf.h ../log/log.c conf.cpp
test: ../log/log.h ../type/type.h  conf.h conf.cpp conf_t.cpp 
	g++ -g -o conf_t ../log/log.h ../type/type.h  conf.h ../log/log.c conf.cpp conf_t.cpp
clean:
	rm -rf conf_t *.o *.gch
