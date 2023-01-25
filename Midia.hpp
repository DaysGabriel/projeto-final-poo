#ifndef MIDIA_HPP
#define MIDIA_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//faixas e keywords são coleções

class Midia
{
private :
    string artista, titulo;
    vector <string> faixas;
    vector<int> lancamentos;
    string genero;
    vector <string> keywords;
    
public :
    //construtor
    Midia(string, string, vector<string>, vector<int>, string, vector<string>);
    //getters and setters
    void setArtista(string);
    string getArtista();

    void setTitulo(string);  
    string getTitulo();
    
    void setFaixas(string);
    vector <string> getFaixas(); //retorna uma coleção

    void setLancamentos(vector<int>);
    vector <int> getLancamentos();//C

    void setGenero(string);
    string getGenero();

    void setKeywords(string);
    vector <string> getKeyWords();

};

#endif