#include "Dvd.hpp"

Dvd::Dvd(vector<string> _formatoAudio, vector<string> _formatoTela, vector<string> _legendas): Midia(getArtista(), getTitulo(), getFaixas(), getLancamentos(),
            getGenero(), getKeyWords()) {
  for (string elem : _formatoAudio) {
    formatoAudio.push_back(elem);
  }
  ///////////////////////////////
  for (string elem : _formatoTela) {
    formatoTela.push_back(elem);
  }
  //////////////////////////////
  for (string elem : _legendas) {
    legendas.push_back(elem);
  }
}

void Dvd::setFormatoAudio(vector<string> _formatoAudios) {
  for (string elem : _formatoAudios) {
    formatoAudio.push_back(elem);
  }
}

void Dvd::setFormatoTela(vector<string> _formatoTelas) {
  for (string elem : _formatoTelas) {
    formatoTela.push_back(elem);
  }
}

void Dvd::setLegendas(vector<string> _legendas) {
  for (string elem : _legendas) {
    legendas.push_back(elem);
  }
}

vector<string> Dvd ::getFormatoAudio() { return formatoAudio; }

vector<string> Dvd ::getFormatoTela() { return formatoTela; }

vector<string> Dvd::getLegendas() { return legendas; }