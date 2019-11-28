#include <iostream>
#include <cmath>


int main (){
    
double tmax=6.0;
double deltax = 0.01;
double deltat = 0.01;
int nt = tmax/deltat;
double L = 1.0;
int nx=L/deltax;
double cpri = deltax/deltat ;
double C[nx+1][nt+1];
double x=0.0;
double c=0.5;
    

for(int i=0; i < nx ; i++)
{                           
    x=i*deltax;
    C[i][0]=sin(M_PI*(x/L));
}
    
//C[0][1]=0.0;
//C[nx-1][1]=0.0;
    
for(int i = 1; i < nx; i++)
{
       C[i][1] = C[i][0] + ((c*c/(2*(cpri*cpri)))*((C[i+1][0]) + (C[i-1][0])  - 2.0*(C[i][0])));
}                        

for(int j = 1; j< nt; j++ )
{
 for(int i = 1; i < nx; i++)
 {
    C[i][j+1] = 2*C[i][j] - C[i][j-1] + ((c*c/(cpri*cpri))*((C[i+1][j]) + (C[i-1][j])  - 2.0*(C[i][j])));   
 }
}
    
    
for(int j=0; j<nt; j++)
{
  for(int i=0; i<nx; i++)
  {
      
      std::cout<<C[i][j];
  }
   std::cout<<std::endl; 
}
    
return 0;

}