#include "Cd.hpp"
using namespace std;

Cd::Cd (int _duracao, float _volume, bool _coletanea) :Midia(getArtista(), getTitulo(), getFaixas(), getLancamentos(), getGenero(), getKeyWords())
{
  duracao = _duracao;
  volume = _volume;
  coletanea = _coletanea;
}

void Cd::setDuracao(int duracao) { this->duracao = duracao; } 
int Cd::getDuracao() { return this->duracao; }

void Cd::setVolume(float volume) { this->volume = volume; } 
float Cd::getVolume() { return this->volume; }

void Cd::setColetanea(bool coletanea) { this->coletanea = coletanea; } 
bool Cd::getColetanea() { return this->coletanea; }