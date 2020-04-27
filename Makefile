#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: uklad_rownan
	./uklad_rownan < test.txt

uklad_rownan: obj/main.o obj/LZespolona.o obj/Wektor.o obj/Macierz.o obj/UkladRownanLiniowych.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/LZespolona.o obj/Wektor.o obj/Macierz.o obj/UkladRownanLiniowych.o

obj/main.o: src/main.cpp src/WektorC.cpp  src/Macierz.cpp src/UkladRownanLiniowychC.cpp src/LZespolona.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/UkladRownanLiniowych.o: src/UkladRownanLiniowych.cpp src/UkladRownanLiniowychC.cpp inc/UkladRownanLiniowych.hh
	g++ ${CPPFLAGS} -o obj/UkladRownanLiniowych.o src/UkladRownanLiniowychC.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh 
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/Macierz.o: src/Macierz.cpp src/MacierzC.cpp inc/Macierz.hh 
	g++ ${CPPFLAGS} -o obj/Macierz.o src/MacierzC.cpp

obj/Wektor.o: src/Wektor.cpp src/WektorC.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/WektorC.cpp

clean:
	rm -f obj/*.o uklad_rownan
