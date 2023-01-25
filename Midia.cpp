//#include <iostream>
#include "Midia.hpp"
//#include <vector>
using namespace std;

Midia::Midia(string _artista, string _titulo, vector<string> _faixas,
vector <int> _lancamentos, string _genero, vector<string> _keywords) {

  artista = _artista;
  titulo = _titulo;
  // inicialização de faixas
  for (string elem : _faixas) {
    faixas.push_back(elem);
  }
  // fim da inicialização do vetor
  for (int elem : _lancamentos) {
    lancamentos.push_back(elem);
  }
  genero = _genero;
  // inicialização de keywords
  for (string elem : _keywords) {
    keywords.push_back(elem);
  }
}

void Midia::setArtista(string artista) { this->artista = artista; }
string Midia::getArtista() { return this->artista; }

void Midia::setTitulo(string titulo) { this->titulo = titulo; }
string Midia::getTitulo() { return this->titulo; }

// Início
void Midia::setFaixas(string _faixas) { faixas.push_back(_faixas); }

vector<string> Midia::getFaixas() { return faixas; }
// Fim

void Midia::setLancamentos(vector <int> _lancamentos) 
{ 
  for (int elem : _lancamentos)
  {
    lancamentos.push_back(elem);
  } 
}
vector<int> Midia::getLancamentos() { return lancamentos; }

void Midia::setGenero(string genero) { this->genero = genero; }
string Midia::getGenero() { return this->genero; }

// Início
void Midia::setKeywords(string _keyWords) {
  keywords.push_back(_keyWords);
} //<-------------------------------

vector<string> Midia::getKeyWords() { return keywords; }
// Fim
