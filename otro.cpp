#include <iostream>
#include <cmath>

//Modificado de: https://www.dreamincode.net/forums/topic/125770-simulating-diffusion-equation/
//Guiado de: https://github.com/vostertag/solving-the-heat-equation/blob/master/computationalMethods/FTCS.cpp
//Guiado de: https://warwick.ac.uk/fac/cross_fac/complexity/study/msc_and_phd/co906/co906online/lecturenotes_2009/chap3.pdf

FILE *output;
int main (){
    int nx=30;
    double D=1.0;
	int nt=100;
	double deltax=1.0/nx;
    double deltat=deltax*deltax/2*D;
    double C[nx][nt];
	double x=0.0;
    int i=0;
	int j=0;
	double L=1.0;
	double ten = 40;
    double rho = 0.01;
	double cpri = sqrt(ten/rho);
	double c= deltax/deltat;
	
    
    output=fopen("Ejer.dat", "w");

    for(i=0; i < nx; i++){                           
        x=i*deltax;
        C[i][0]=0.0001*sin(2*M_PI*(x/L));
		
    }
    C[0][0]=0.0;
    C[nx-1][0]=0.0;
                                           
    for(j = 0; j < nt - 1; j++){
        for(i=1; i<nx-1; i++){
            x=i*deltax;
            C[i][j+1] = 2*C[i][j] - C[i][j-1] + (((c*c)/(cpri*cpri))*((C[i+1][j]) + (C[i-1][j])  - 2.0*(C[i][j])));
        }                                             
        C[0][j+1]=0.0;                                      
        C[nx-1][j+1]=0.0;                          

    }

    for (i = 0; i < nx; ++i)
    {
        x = i * deltax;
        fprintf(output, "%e\t", x);
        for (j = 0; j < nt; ++j)
        {
            fprintf(output, "%e\t", C[i][j]);
            
        }
        fprintf(output, "\n");
    }                                             

    fflush(output);
    fclose(output);
	
 return 0;
 
}