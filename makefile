Ejer.png : Ejer.dat Ejercicio32.py
	python Ejercicio32.py


Ejer.dat  : Ejer.x
	./Ejer.x > Ejer.dat


Ejer.x : otro.cpp
	c++ otro.cpp -o Ejer.x
	
clean:
	rm -r *.x *.dat *.png
