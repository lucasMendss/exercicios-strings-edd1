#include<iostream>
#include <algorithm>
#include <locale.h>

using namespace std;

void isPalindrome(string word)
{
	cout << " " << endl;
	
	// deixando todas as letras minúsculas
	string wordToLower = "";
	for(char c : word){
		wordToLower += tolower(c);	
	}
	
	// removendo espaços
	char charToRemove = ' ';
	wordToLower.erase(remove(wordToLower.begin(), wordToLower.end(), charToRemove), wordToLower.end());
	
	// invertendo palavra e verificando
	string reversedWord = "";
	int ri = 0;
	int wordSize = wordToLower.size();
	for(int ii = wordSize-1; ii >= 0; ii--){
		   reversedWord += wordToLower[ii];
		   ri++;	   	
	}
	
	cout << "Palavra: " << wordToLower << endl;
	cout << "Palavra invertida: " << reversedWord << endl;
	if (wordToLower.compare(reversedWord) == 0){
		cout << "É um palíndromo" << endl;
	}
	else{
		cout << "Não é um palíndromo" << endl;
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	string word = "";
	cout << "Digite uma palavra: ";
	getline(cin, word);
	
	isPalindrome(word);
	return 0;
}
