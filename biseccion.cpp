#include<iostream>
#include<vector>
#include <math.h>
#include <string>
using namespace std;

vector<double>Coeficientes(0);
vector<double>Evalua(0);
vector<string>Variables(0);
vector<char>Signo(0);

void llenarFuncion( int );
void MostrarFuncion();
double Evaluar(double);
double HallarXr(double,double);

int main(){
    int n;
    int num;
    double Xi;
    double Xu;
    double Xr;
    double x,xa=0;
    double error, e;
    bool seg = true;


    cout << "\nIngrese el Numero de terminos de la ecuacion :";
    cin  >> n;
    num  = (n < 0 ? n*-1 : n);

    llenarFuncion(num);
    MostrarFuncion();
    cout << "\nResultado :" << Evaluar(3) <<endl;
    cout <<"\nIngrese el porcentaje de error : ";
    cin >> e;

while(seg == true){
    
    cout << "\nIngresar X1 :";
    cin  >> Xi;
    cout << "\nIngresar Xu :";
    cin  >> Xu;  
    

    if( Evaluar(Xi) * Evaluar(Xu) > 0){
        cout << "\nEn este intervalo no se encuentran raices ";
    }
    else{  
           do{
               Xr = HallarXr(Xi,Xu); 
               x = Evaluar(Xi) * Evaluar(Xr);
               if ( x > 0){
                    Xi = Xr;
                }
                else{
                  Xu = Xr;
                }
            error = ( (Xr -xa)/Xr )*100;
            if(error < 0){
                error = error * -1;
            }
            xa = Xr;
           
           } while (error > e);
            seg = false; 
        }
}

cout <<"\n Raiz : " << Xr <<endl;
 return 0;
 }
    


void llenarFuncion(int num){
    char res = 'n';
    Coeficientes.resize(num);
    Variables.resize(num);
    Signo.resize(num);

    for(int i=0; i<num; i++){
        cout << "\nIngresar coeficiente ["<<i+1<<"] : ";
        cin  >>  Coeficientes[i];
        cout << "El coeficiente ("<<Coeficientes[i] <<") tiene alguna variable ? (s/n) :";
        cin  >> res;
        
        if(res == 's'){
            cout << "Ingresar variable (x,x1,x2,x3 ...): ";
            cin  >> Variables[i];
        }
        else{
            Variables[i] = "0";
        }
        
        cout << "Digitar signo (+ - * ) : ";
        if(i == num-1){
            Signo[i] = ' ';
        }
        else{
            cin  >> Signo[i];
        }
    }
    cout <<"\n\n";
}


void MostrarFuncion(){
    cout << "\n---------------- Funcion Ingresada ----------------- : "<<endl;
    
    for(int i=0; i<Coeficientes.size(); i++){
        if( Variables[i] == "0"){
            cout << Coeficientes[i] <<" "<< Signo[i];
        }
        else{
            cout << Coeficientes[i] << Variables[i] <<" "<< Signo[i]<<" " ;
        }  
    }
    cout<<"\n-------------------------------------------------------------";
    cout <<endl;
}

double Evaluar(double Xr){

double valor;
Evalua.resize(Coeficientes.size());

    for(int i=0; i<Coeficientes.size(); i++){
        
        if( Variables[i] == "0"){
            Evalua[i] = Coeficientes[i];                       
        }
        
        
        else{
             string var, var2;
             var = Variables[i];
             int exponente;

             if( var.length() == 1){
                Evalua[i] = Coeficientes[i] * Xr;
             }
             
             else{
                 for(int i=0; i<var.length(); i++){
                     var2[i] = var[i+1];
                 }
                 exponente = atoi( var2.c_str() );
                 
                 Evalua[i] = Coeficientes[i] * pow(Xr,exponente);

             }
             
        }  
    }// fin 1er ciclo for
    valor = Evalua[0];
    for(int i=0; i<Signo.size();i++){
        
        if(Signo[i] == '+'){
            valor += Evalua[i+1];
        }
        else{
              if(Signo[i] == '-'){
                 valor -= Evalua[i+1];
                }
              else{
                    if(Signo[i] == '*'){
                        valor *= Evalua[i+1];
                    }
                  }          
            }
     }
     return valor;
}//cierre de la funcion 

double HallarXr(double xi, double xu){
return (xi + xu)/2;
}