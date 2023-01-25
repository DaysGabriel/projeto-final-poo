#ifndef CD_HPP
#define CD_HPP

#include "Midia.hpp"

using namespace std;

class Cd : public Midia
{
private :
    int duracao;
    float volume;
    bool coletanea;
public :
    Cd(int, float, bool);
    void setDuracao(int);
    int getDuracao();

    void setVolume(float); 
    float getVolume();

    void setColetanea(bool); 
    bool getColetanea();
};
#endif