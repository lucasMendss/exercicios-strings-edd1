#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

string paraMaiusculo(string s) {
    string resultado = s;
    for (size_t i = 0; i < resultado.length(); i++) {
        resultado[i] = (char)toupper(resultado[i]);
    }
    return resultado;
}

string formatarCitacao(string nomeCompleto) {
    if (nomeCompleto.empty()) return "";

    stringstream ss(nomeCompleto);
    string palavra;
    vector<string> partes;

    while (ss >> palavra) {
        partes.push_back(palavra);
    }

    if (partes.empty()) return "";

    string sobrenome = paraMaiusculo(partes[partes.size() - 1]);
    
    string primeiroNome = partes[0];
    
    string citacao = sobrenome + ", " + primeiroNome;

    for (size_t i = 1; i < partes.size() - 1; i++) {
        string parte = partes[i];
        string pMinuscula = parte;
        for(size_t j=0; j<pMinuscula.length(); j++) pMinuscula[j] = tolower(pMinuscula[j]);
        
        if (pMinuscula != "de" && pMinuscula != "da" && pMinuscula != "do" && 
            pMinuscula != "das" && pMinuscula != "dos" && pMinuscula != "e") {
            citacao += " " + parte.substr(0, 1) + ".";
        }
    }

    return citacao;
}

int main() {
    string nomeArquivo = "nomes.txt";
    ifstream arquivoEntrada(nomeArquivo.c_str());

    if (!arquivoEntrada.is_open()) {
        cout << "Erro: Nao foi possivel abrir o arquivo '" << nomeArquivo << "\'." << endl;
    } else {
        cout << "--- FORMATO DE CITACAO BIBLIOGRAFICA ---" << endl << endl;
        
        string linha;
        while (getline(arquivoEntrada, linha)) {

            if (!linha.empty() && linha[linha.length()-1] == '\r') {
                linha.erase(linha.length()-1);
            }
            
            if (!linha.empty()) {
                string resultado = formatarCitacao(linha);
                cout << "Original: " << linha << endl;
                cout << "Citacao:  " << resultado << endl;
                cout << "---------------------------------------" << endl;
            }
        }
        arquivoEntrada.close();
    }

    cout << "\nPressione Enter para sair...";
    cin.get();

    return 0;
}
