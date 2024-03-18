#ifndef JOGODAVIDA_HPP
#define JOGODAVIDA_HPP
#include <string>
#include <fstream>
#include <vector>
#include <iostream>



using namespace std;

class JogoDaVida{

    public:
    
    
    void le_matriz(ifstream& arq,int **&matriz_original, int linhas, int colunas);

    int conta_vizinhos(int **matriz_original,int pos_linha, int pos_coluna,int linhas, int colunas);

    void processa_matriz(int **matriz_original,int **&matriz_copia,int linhas,int colunas);

    void copia_matriz(int **&matriz_original,int **matriz_copia, int linhas, int colunas);

    void escreve_matriz(ofstream& arq, int **matriz, int linhas, int colunas, string titulo, int num_geracao);

    bool verifica_zerou(int **matriz_copia,int linhas, int colunas);

 
};


#endif

