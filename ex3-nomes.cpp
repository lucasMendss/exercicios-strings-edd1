#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <locale.h>

using namespace std;


/* Exercício 3 - À partir de uma lista de nomes disponível em um arquivo TXT,
transforma-los em nomes no formato agenda telefônica */

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");

	ifstream arq("nomes.txt");

	if (arq.is_open())
	{
		string linha;
		cout << "Lista Telefônica: " << endl;
		while (getline(arq, linha))
		{

			stringstream ss(linha);
			vector<string> partes;
			string primeiroNome;
			string palavra;

			// enquanto ainda houver palavras para ler...
			while (ss >> palavra)
			{
				partes.push_back(palavra);
			}

			string sobrenome = partes.back();

			for (int i = 0; i < partes.size() - 1; i++)
			{
				primeiroNome += partes[i] + " ";
			}

			cout << sobrenome << ", " << primeiroNome << endl << endl;
		}
		arq.close();
	}
	else
	{
		cout << "Erro ao abrir o arquivo com nomes.";
	}

	return 0;
}
