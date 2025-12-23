/*Programa de encriptado RSA,usaremos la lbrería GMP, una librería de C que permite hacer cálculos con precisión arbitraria*/
/*Funciona únicamente con entradas numéricas*/

#include <iostream>
#include <gmpxx.h>
using namespace std;

int main(){
	/*Definimos las variables*/
        mpz_class n,phi,p,q,e,c,m,M,NUM,f;

	cout << "Introduzca un número para calcular dos primos (DNI): ";
	cin >> NUM;

	mpz_nextprime(p.get_mpz_t(),NUM.get_mpz_t());

	mpz_prevprime(q.get_mpz_t(),NUM.get_mpz_t());

	cout << "Los primos que van a formar n son: " << p << " " << q << endl;

        n = p*q;
        phi = (q-1)*(p-1);
        cout << "Introduzca el texto que quieras encriptar (10000): ";
	cin >> m;

	e = 65537; /*El quinto número de Fermat, último primo de nº de fermat, permite computación fácil*/
	mpz_class mcd;

	/*Buscamos un número e de manera que mcd(e,phi)=1*/
	mpz_gcd(mcd.get_mpz_t(),e.get_mpz_t(),phi.get_mpz_t());
	while( mcd != 1 ){
		mpz_gcd(mcd.get_mpz_t(),e.get_mpz_t(),phi.get_mpz_t());
		e++;
	}
	cout << e;
	/*Calculamos el inverso de e con respecto a phi, esta es la clave privada*/
        mpz_invert(f.get_mpz_t(),e.get_mpz_t(),phi.get_mpz_t());
	cout << f;

	/*Encriptamos el número*/
        mpz_powm(c.get_mpz_t(),m.get_mpz_t(),e.get_mpz_t(),n.get_mpz_t());
        cout << "El mensaje encriptado es: " << c << endl;

	/*Lo volvemos a desencriptar*/
        mpz_powm(M.get_mpz_t(),c.get_mpz_t(),f.get_mpz_t(),n.get_mpz_t());
        cout << "El mensaje vuelto a desencriptar es: " << M << endl;
}

