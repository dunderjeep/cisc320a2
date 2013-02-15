fraction : FractionTest.o fraction_8cc17.o
	g++ -Wall -g FractionTest.o fraction_8cc17.o -o fraction

FractionTest.o : FractionTest.cpp fraction_8cc17.h 
	g++ -Wall -c FractionTest.cpp -o FractionTest.o

fraction_8cc17.o : fraction_8cc17.cpp fraction_8cc17.h 
	g++ -Wall -c fraction_8cc17.cpp -o fraction_8cc17.o

clean:
	\rm *.o *~ fraction
