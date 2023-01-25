#ifndef DVD_HPP
#define DVD_HPP

#include <string>
#include <vector>
#include "Midia.hpp"

using namespace std;

class Dvd : public Midia
{
private :
    vector<string>formatoAudio;
    vector<string>formatoTela;
    vector<string>legendas;
public :
    //construtor
    Dvd(vector<string>, vector<string>, vector<string>);
    //getters and setters
    void setFormatoAudio(vector<string>); //C
    vector <string> getFormatoAudio();//C

    void setFormatoTela(vector<string>);
    vector <string> getFormatoTela();
    
    void setLegendas(vector<string>);
    vector <string> getLegendas();//C

    
    //how am going to retrun via void get if the element is a vector ?
};
#endif