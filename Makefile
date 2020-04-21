#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: uklad_rownan
	./uklad_rownan

uklad_rownan: obj/main.o obj/LZespolona.o obj/Wektor.o obj/Macierz.o 
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/LZespolona.o obj/Wektor.o obj/Macierz.o 

obj/main.o: src/main.cpp src/WektorC.cpp src/LZespolona.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

#obj/UkladRownanLiniowych.o: src/UkladRownanLiniowych.cpp inc/UkladRownanLiniowych.hh
#	g++ ${CPPFLAGS} -o obj/UkladRownanLiniowych.o src/UkladRownanLiniowych.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh 
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/Macierz.o: src/Macierz.cpp src/MacierzC.cpp inc/Macierz.hh 
	g++ ${CPPFLAGS} -o obj/Macierz.o src/MacierzC.cpp

obj/Wektor.o: src/Wektor.cpp src/WektorC.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/WektorC.cpp

clean:
	rm -f obj/*.o uklad_rownan
