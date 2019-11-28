Ejer.png : Ejer.dat Ejercicio27.py
	python Ejercicio27.py


Ejer.dat  : Ejer.x
	./Ejer.x > Ejer.dat


Ejer.x : Ejercicio32.cpp
	c++ Ejercicio32.cpp -o Ejer.x
	

clean:
	rm -r *.x *.dat *.png
