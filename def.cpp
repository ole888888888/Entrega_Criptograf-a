/*Programa de encriptado RSA, usaremos la lbrería GMP, una librería de C que permite hacer cálculos con precisión arbitraria*/

#include <iomanip>
#include <iostream>
#include <gmpxx.h>
#include <sstream>
using namespace std;

/*Esto es una función que transforma un entero a una cadena de caracteres*/
string intastr(mpz_class t){
	/*Comenzamos con un string vacío*/
        string resultado = "";

	/*Transformamos el entero a hexadecimal,de hexadecimal a enteros de dos en dos y de allí a char*/
        string hexStr = t.get_str(16);

        for (size_t i = 0; i < hexStr.length(); i += 2) {
                string byte = hexStr.substr(i, 2);
                resultado += (char)stoul(byte, nullptr, 16);
        }

        return resultado;
}

int main(){
	/*Definimos las variables*/
        string entrada;
        mpz_class n,phi,p,q,e,c,m,M,NUM,f;

	cout << "Introduzca un número para calcular dos primos se calculará el próximo y el anterior: ";
	cin >> NUM;
	cin.ignore();

	mpz_nextprime(p.get_mpz_t(),NUM.get_mpz_t());

	mpz_prevprime(q.get_mpz_t(),NUM.get_mpz_t());

	cout << "Los primos que van a formar n son: " << p << " " << q << endl;

        n = p*q;
        phi = (q-1)*(p-1);
        cout << "Introduzca el texto que quieras encriptar (cuidado con la longitud): ";

	/*Entrada y transformación a Hexadecimal*/
	getline(cin,entrada);
        stringstream ss;
        for(char c : entrada) ss << hex <<setw(2) << setfill('0') << (int)c;
        m.set_str(ss.str(), 16);

	e = 65537; /*El quinto número de Fermat, último primo de nº de fermat, permite computación fácil*/
	mpz_class mcd;

	/*Buscamos un número e de manera que mcd(e,phi)=1*/
	mpz_gcd(mcd.get_mpz_t(),e.get_mpz_t(),phi.get_mpz_t());
	while( mcd != 1 ){
		mpz_gcd(mcd.get_mpz_t(),e.get_mpz_t(),phi.get_mpz_t());
		e++;
	}

	/*Calculamos el inverso de e con respecto a phi, esta es la clave privada*/
        mpz_invert(f.get_mpz_t(),e.get_mpz_t(),phi.get_mpz_t());

	/*Encriptamos el mensaje*/
        mpz_powm(c.get_mpz_t(), m.get_mpz_t(),e.get_mpz_t(),n.get_mpz_t());
        cout << "El mensaje encriptado es: " << c << endl;
        string encriptado = intastr(c);
        cout << "Con texto: " << encriptado << endl;

	/*Desencriptamos el mensaje*/
        mpz_powm(M.get_mpz_t(),c.get_mpz_t(),f.get_mpz_t(),n.get_mpz_t());
        cout << "El mensaje vuelto a desencriptar es: " << M.get_str(10) << endl;
        string resultado = intastr(M);
        cout << "El texto es: " << resultado << endl;
}

