base/NumberConverter: base/number_converter.o base/converters.o
						g++ -o NumberConverter build/converters.o build/number_converter.o

base/converters.o: src/Converters.cpp src/Converters.h
				   g++ src/Converters.cpp -c -o build/converters.o

base/number_converter.o: src/NumberConverter.cpp
						g++ src/NumberConverter.cpp -c -o build/number_converter.o
 
clean:
		rm -r build/