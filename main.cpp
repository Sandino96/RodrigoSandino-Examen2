#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char*argv[]){
	int opcion = 0;
	while(opcion != 4){
		cout << "1.- Encriptar en Ceasar Cipher" << endl;
		cout << "2.- Desencriptar en Ceasar Cipher" << endl;
		cout << "3.- Verifique su tarjeta de crédito" << endl;
		cout << "4.- Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		if (opcion == 1){
			string texto;
			cout << "\tIngrese su frase a encriptar (No ingrese numeros ni caracteres especiales ni letras mayúsculas :D ): ";
			cin.ignore();
			getline(cin,texto);
			char* convertido = new char[texto.length() + 1];
			char* encriptado = new char[texto.length() + 1];
			strcpy(convertido,texto.c_str());
			for (int i = 0; i < texto.length(); i++){
				int codigo = 0;
				if(convertido[i] == '0' || convertido[i] == '1' || convertido[i] == '2' || convertido[i] == '3' || convertido[i] == '4' 
				|| convertido[i] == '5' || convertido[i] == '6' || convertido[i] == '7' || convertido[i] == '8' || convertido[i] == '9'){
					cout << "\tNo puede ingresar numeros\n" << endl;
				} else {
					if (convertido[i] != ' '){
						if(convertido[i] >= 96 && convertido[i] < 120){
							codigo = convertido[i] + 3;
							encriptado[i] = codigo;
						} else {
							codigo = convertido[i] - 3;
							encriptado[i] = codigo;
						}
					} else {
						encriptado[i] = ' ';
					}
				}
			}
			cout << "\t" <<encriptado << "\n" << endl;
			delete[] convertido;
			delete[] encriptado;
		} else if (opcion == 2){
			string texto;
			cout << "\tIngrese su frase para desencriptar (No ingrese numeros ni caracteres especiales ni letras mayúsculas :D ): ";
			cin.ignore();
			getline(cin,texto);
			char* convertido = new char[texto.length() + 1];
			char* desencriptado = new char[texto.length() + 1];
			strcpy(convertido,texto.c_str());
			for (int i = 0; i < texto.length(); i++){
				int codigo = 0;
				if(convertido[i] == '0' || convertido[i] == '1' || convertido[i] == '2' || convertido[i] == '3' || convertido[i] == '4' 
				|| convertido[i] == '5' || convertido[i] == '6' || convertido[i] == '7' || convertido[i] == '8' || convertido[i] == '9'){
					cout << "\tNo puede ingresar numeros\n" << endl;
				} else {
					if (convertido[i] != ' '){
						if(convertido[i] >= 99 && convertido[i] < 123){
							codigo = convertido[i] - 3;
							desencriptado[i] = codigo;
						} else {
							codigo = convertido[i] + 3;
							desencriptado[i] = codigo;
						}
					} else {
						desencriptado[i] = ' ';
					}
				}
			}
			cout << "\t" << desencriptado << "\n" << endl;
			delete[] convertido;
			delete[] desencriptado;
		} else if (opcion == 3){
			string tarjetaCredito;
			cout << "\tIngrese su numero de tarjeta de crédito (con confianza y solo números, ejemplo 0000111122223333):";
			cin.ignore();
			getline(cin,tarjetaCredito);
			char* convertido = new char[tarjetaCredito.length() + 1];
			strcpy(convertido,tarjetaCredito.c_str());
			int size = strlen(convertido);
			if(size == 16){
				int variable = 0;
				for (int i = 0; i < size; i++){
					stringstream ss;
					ss << convertido[i];
					int suma = 0;
					ss >> suma;
					if (i % 2 == 0){
						if (suma == 0 || suma == 1 || suma == 2 || suma == 3 || suma == 4)
							variable += suma*2;
						else
							variable += (suma*2) - 9;
					}else
						variable += suma;
				}
				if (variable % 10 == 0)
					cout << "\tSu tarjeta es valida :3\n" << endl;
				else 
					cout << "\tSu tarjeta es invalida :(\n" << endl;
			} else
				cout << "\tA ingresado su tarjeta de credito mal :(\n" << endl;
			delete[] convertido;
		} else if (opcion == 4){
			cout << "Gracias por usarme :3" << endl;
			exit(0);
		} else {
			cout << "Número no válido, ingrese un número dentro del rango\n" << endl;
		}
	}
}

