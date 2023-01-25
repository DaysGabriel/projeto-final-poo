#include "Cd.hpp"
#include "Dvd.hpp"
#include "Midia.hpp"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//imprime espaço
void flush()
{
  cout <<endl << endl << endl << endl;
}

void adicionarCD(vector<Cd *> &meusCDs) {
  //variáveis relativas à midia.hpp
  string artista, titulo, genero, faixa, keyword;
  int lancamento;
  vector<string> faixas;
  vector<string> keywords;
  vector <int> lancamentos;
  //variáveis relativas à CD.hpp
  int duracao;
  float volume;
  bool coletanea;

  cin.ignore();
  
  cout << "Insira o nome do artista" << endl;
  getline(cin, artista);
  cout << endl;

  cout << "Insira o título" << endl;
  getline(cin, titulo);
  cout << endl;

  cout << "Insira o gênero das músicas" << endl;
  getline(cin, genero);
  cout << endl;

  cout << "Insira as faixas do album, quando acabar insira '.'" << endl;

  //Insere as faixas
  int ln = 1;
  while (1==1) {
    cout << ln << ".";
    getline(cin,faixa);
    if (faixa == ".") {
      break;
    }
    faixas.push_back(faixa);
    ln++;
  }

  cout << endl;

  //Insere os anos de lançamento
  cout << "Insira o ano de lancamento de cada faixa" << endl; 
  for (int i=0; i < (int) faixas.size(); i++){
    cin >> lancamento;
    lancamentos.push_back(lancamento);
  }

  cout << endl;

  //insere as keywords
  cout << "Insira as keywords. Quando acabar, insira '.'" << endl;

  while (1==1)
  {
    getline(cin,keyword);
    if (keyword == ".") {
      break;
    }
    keywords.push_back(keyword);
    ln++;
  }

  cout << endl;

  //Insire a duração
  cout << "Insira a duração total em minutos" <<endl;
  cin >> duracao;
  cout << endl;

  //Insere o volume
  cout << "Insira o volume" << endl;
  cin >> volume;
  cout << endl;

  //Insere a coletânea
  cout << "As músicas que você inseriu são uma coletânea[0/1] ?" << endl;
  cin >> coletanea;
  cout << endl;

  ////salva os dados registrados pelo usuário
  Cd *meuCD = new Cd(duracao, volume, coletanea);
  meuCD->setArtista(artista);
  meuCD->setTitulo(titulo);
  for (string elem : faixas) {
    meuCD->setFaixas(elem);
  }
  meuCD->setLancamentos(lancamentos);
  meuCD->setGenero(genero);
  for (string elem : keywords) {
    meuCD->setKeywords(elem);
  }
  meusCDs.push_back(meuCD);
}

void adicionarDVD(vector<Dvd *> &meusDVDs) {
  //variáveis relativas à Midia
  string artistaDvd, tituloDvd, generoDvd, faixaDvd, keywordDvd;
  vector<string> faixasDvd;
  vector<string> keywordsDvd;
  vector <int> lancamentosDvds;
  int lancamentoDvd;
  //variáveis relativas à Dvd
  vector<string> formatoAudios;
  vector<string> formatoTelas;
  vector<string> legendas;
  string formatoAudio;
  string formatoTela;
  string legenda;
  
  cin.ignore();

  cout << "Insira o nome do artista" << endl;
  getline(cin, artistaDvd);
  cout << endl;

  cout << "Insira o título" << endl;
  getline(cin, tituloDvd);
  cout << endl;

  cout << "Insira o gênero das músicas" << endl;
  getline(cin, generoDvd);
  cout << endl;

  //Insere as faixas e os dados relativos à ela
  int ln = 1;
  while (1==1) {
    cout << "Insira a " << ln <<"° música. Caso queira parar, insira um '.'" <<endl;
    cout << ln << ".";
    getline(cin,faixaDvd);

    if (faixaDvd == ".")
    {
      break;
    }
    else
    {
      faixasDvd.push_back(faixaDvd);
    }

    //cout << endl;

    cout << "    Insira o formato de aúdio. Caso não queira, insira '.'" << endl;
    getline(cin,formatoAudio);
    
    if (formatoAudio == "."){
      formatoAudios.push_back("~");
    }
    else
    {
      formatoAudios.push_back(formatoAudio);
    }

    //cout << endl;

    cout << "    Insira o formato de tela. Caso não queira, insira '.'" << endl;
    getline(cin,formatoTela);

    if (formatoTela == "."){
      formatoTelas.push_back("~");
    }
    else
    {
      formatoTelas.push_back(formatoTela);
    }


    cout << "    Insira a legenda. Caso não queira, insira '.' "<<endl;
    getline(cin, legenda);
  
    if (legenda == "."){
      legendas.push_back("~");
      break;
    }
    else
    {
      legendas.push_back(legenda);
    }
    ln++;

    cout << endl << endl;
  }

  cout << endl;

  //insere as datas de lancamento de cada faixa
  cout << "Insira o ano de lançamento de cada faixa" << endl;
  for (int i=0; i < (int) faixasDvd.size(); i++){
    cin >> lancamentoDvd;
    lancamentosDvds.push_back(lancamentoDvd);
  }
  
  cout << endl;
  
  cout << "Insira as keywords. Quando acabar, insira '.'" << endl;

  //insere as keywords
  
  while (1==1) {
    getline(cin,keywordDvd);
    if (keywordDvd == ".") {
      break;
    }
    keywordsDvd.push_back(keywordDvd);
    ln++;
  }
  
  //salva os dados registrados pelo usuário
  Dvd *meuDvd = new Dvd(formatoAudios, formatoTelas, legendas);
  meuDvd->setArtista(artistaDvd);
  meuDvd->setTitulo(tituloDvd);
  for (string elem : faixasDvd) {
    meuDvd->setFaixas(elem);
  }
  meuDvd->setLancamentos(lancamentosDvds);
  meuDvd->setGenero(generoDvd);
  for (string elem : keywordsDvd) {
    meuDvd->setKeywords(elem);
  }

  meusDVDs.push_back(meuDvd);
  
}

void exibirCDs(vector <Cd*> &meusCDs, string ArtistaProcura)
{

  int index =0;
  bool encontrado=0; //sinaliza se o artista foi encontrado
  //encontra o artista
  for (int i = 0; i < (int) meusCDs.size(); i++)
  {
    if (meusCDs[i]->getArtista() == ArtistaProcura)
    {
      index = i;
      encontrado =1;
      break;
    }
  }

  cout << endl;

  //Caso ele foi encontrado
  if (encontrado == 1)
  {
    cout << "Título : " << meusCDs[index]->getTitulo() << endl;
    cout << "Genero : " << meusCDs[index]->getGenero() << endl;
  
    cout << "Faixas : "; 
    for (int i =0; i < (int) meusCDs[index]->getFaixas().size(); i++)
    {
      cout << endl;
      cout <<"    "<< meusCDs[index]->getFaixas()[i] << "-";
      cout << meusCDs[index]->getLancamentos()[i];
    }

    cout << endl;

    cout << "Duracao total em minutos: " << meusCDs[index]->getDuracao() << endl;
    cout << "Volume : " << meusCDs[index]->getVolume() << endl; 
  
    if (meusCDs[index]->getColetanea() != 0)
    {
      cout << "Estas musicas são uma coletânea\n" << endl; 
    }
    else
    {
      cout << "estas músicas não são uma coletânea \n" << endl;
    }
  }
  //Caso não tenha sido encontrado
  else
  {
    cout << "Nenhum Cd de " << ArtistaProcura <<" foi encontrado\n" << endl;
  }
}

void exibirDVDs(vector <Dvd *> &meusDVDs, string ArtistaProcura)
{

  int index =0;
  int encontrado; //sinaliza se o artista foi encontrado
  //procura o artista
  for (int i = 0; i < (int) meusDVDs.size(); i++)
  {
    if (meusDVDs[i]->getArtista() == ArtistaProcura)
    {
      index = i;
      encontrado =1;
      break;
    }
  }

  cout << endl;

  //caso o artista tenha sido encontrado
  if (encontrado == 1)
  {
    cout << "Título : " << meusDVDs[index]->getTitulo() << endl;
    cout << "Genero : " << meusDVDs[index]->getGenero() << endl;
    cout << "Faixas : ";

  
    for (int i =0; i < (int) meusDVDs[index]->getFaixas().size(); i++)
    {
      cout << endl;
      cout << "    " << meusDVDs[index]->getFaixas()[i] << "-" << meusDVDs[index]->getLancamentos()[i] << "\n        ";
      cout << meusDVDs[index]->getFormatoAudio()[i] << "\n        ";
      cout << meusDVDs[index]->getFormatoTela()[i] << "\n        ";
      cout << meusDVDs[index]->getLegendas()[i];
    }
    cout << endl;
  }
  //caso o artista não tenha sido encontrado
  else
  {
    cout << "Nenhum Dvd de " << ArtistaProcura <<" foi encontrado\n" << endl;
  }
}

void exibirMidias(vector <Cd*> meusCDs, vector <Dvd*> meusDVDs, string ArtistaProcura)
{

  cout << "-=-=-=-=-=-=-=-=-=-=-=Dados do CD-=-=-=-=-=-=-=-=-=-=-=" << endl;
  exibirCDs(meusCDs, ArtistaProcura);
  
  cout << "-=-=-=-=-=-=-=-=-=-=-=Dados do DVD-=-=-=-=-=-=-=-=-=-=-=" << endl;
  exibirDVDs(meusDVDs, ArtistaProcura);
  cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

}

void exibirMusicasAno(vector <Cd*> meusCDs, vector <Dvd*> meusDVDs, int AnoProcura)
{
  bool encontrado = 0; //sinaliza se existe alguma faixa lançada nesse ano
  bool vazioCD = 0; //sinaliza se o vetor dos CDs está vazio
  //imprime os CDs de um dado ano
  if (meusCDs.size()==0)
  {
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "Nenhum CD foi cadastrado ainda" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    vazioCD =1;
  }
  else
  {
    cout << "-=-=-=-=-=-CD's do ano de " << AnoProcura << " -=-=-=-=-=-"<< endl;
    for (int i =0; i < (int) meusCDs.size(); i++)
    {
      for (int j =0; j < (int) meusCDs[i]->getLancamentos().size(); j++)
      {
        if (meusCDs[i]->getLancamentos()[j] ==AnoProcura)
        {
          cout << meusCDs[i]->getFaixas()[j] << endl;
          encontrado =1;
        }
      }
    }
  }
  if ((encontrado ==0) and (vazioCD == 0))
  {
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=" << endl;
    cout << "nenhuma faixa de CD foi lançada nesse ano\n" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=" << endl;
  }


  cout << endl;

  encontrado =0;
  bool vazioDVD = 0;

  //checa se o vetor está vazio
  if (meusDVDs.size()==0)
  {
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "Nenhum DVD foi cadastrado ainda" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    vazioDVD = 1;
  }
  else
  {
    cout << "-=-=-=-=-=-Lancamentos de DVD's no ano de " << AnoProcura << "-=-=-=-=-=-"<< endl;
    for (int i =0; i < (int) meusDVDs.size(); i++)
    {
      for (int j =0; j < (int) meusDVDs[i]->getLancamentos().size(); j++)
      {
        if (meusDVDs[i]->getLancamentos()[j] ==AnoProcura)
        {
          cout << meusDVDs[i]->getFaixas()[j] << endl;
          encontrado =1;
        }
      }
    }
  }
  if ((encontrado ==0) and (vazioDVD == 0))
  {
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=" << endl;
    cout << "nenhuma faixa de DVD foi lançada nesse ano\n" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=" << endl;
  }

  cout << endl;
}

void exibirMusicasGenero(vector <Cd*> meusCDs, vector <Dvd*> meusDVDs, string GeneroProcura)
{
  bool encontrado=0; //sinaliza se o gênero foi encontrado

  //imprime todos os CD's do gênero selecionado
  cout << "-=-=-=-=-=-=-=-CD's do gênero-=-=-=-=-=-=-=-" << endl;
  for (int i =0; i< (int) meusCDs.size(); i++)
  {
    if (meusCDs[i]->getGenero() == GeneroProcura)
    {
      exibirCDs(meusCDs, meusCDs[i]->getArtista());
      encontrado =1;
    }
  }
  if (encontrado == 0)
  {
    cout << "Não existe nenhum CD deste gênero\n" << endl;
  }

  encontrado=0;
  //imprime todos os DVD's do gênero selecionado
  cout << "-=-=-=-=-=-=-=-DVD's do gênero-=-=-=-=-=-=-=-" << endl;
  for (int i =0; i< (int)meusDVDs.size(); i++)
  {
    if (meusDVDs[i]->getGenero() == GeneroProcura)
    {
      exibirDVDs(meusDVDs, meusDVDs[i]->getArtista());
      encontrado =1;
    }
  }
  if (encontrado == 0)
  {
    cout << "Não existe nenhum DVD deste gênero\n" << endl;
  }
}

void CompararMidias(vector<Cd*>&meusCDs, vector<Dvd*>&meusDVDs, string tituloCD, string tituloDVD)
{
    cout << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    
    int CDindex = 0;
    bool CDnulo=0; //sinaliza se o vetor de CDs está vazio
    //verifico se o vetor é nulo
    if (meusCDs.size() ==0)
    {
      cout << "Não existe nenhum CD cadastrado" << endl;
      CDnulo =1;
    }
    //encontro o index do CD
    else
    {
      for (int i =0; i < (int) meusCDs.size(); i++ )
      {
          if (meusCDs[i]->getTitulo() == tituloCD)
          {
              CDindex = i;
              break;
          }
      }
    }
    //encontro o index do DVD
    int DVDindex = 0;
    bool DVDnulo =0;
    //verifico se o vetor é nulo
    if (meusDVDs.size() ==0 )
    {
      cout << "Não existe nenhum DVD cadastrado" << endl;
      DVDnulo =1;
    }
    else 
    {
      for (int i =0; i < (int) meusDVDs.size(); i++ )
      {
        if (meusDVDs[i]->getTitulo() == tituloDVD)
        {
          DVDindex = i;
          break;
        }
      }
    }

    vector <string> faixasComuns;
    vector <string> faixasExclusivasCD;
    vector <string> faixasExclusivasDVD;

    //verifico se o vetor de CDs ou o vetor de DVDs está vazio
    if ((CDnulo == 1) or (DVDnulo ==1))
    {
      cout << "Não é possível prosseguir com a comparação sem haver mídias cadastradas" << endl << endl;
    }
    else
    {
      //Procuro as diferencas e as igualdades entre CD e DVD    
      for (int i =0; i < (int) meusCDs[CDindex]->getFaixas().size(); i++)
      {
        for (int j =0; j < (int) meusDVDs[DVDindex]->getFaixas().size(); j++)
        {
          //se a faixa do CD for igual ao do DVD
          if (meusCDs[CDindex]->getFaixas()[i] == meusDVDs[DVDindex]->getFaixas()[j])
          {
            faixasComuns.push_back(meusDVDs[DVDindex]->getFaixas()[j]);
            break;
          }
          //se não for igual e a iteração tiver acabado
          else if ((meusCDs[CDindex]->getFaixas()[i] != meusDVDs[DVDindex]->getFaixas()[j]) and (j == (int) (meusDVDs[DVDindex]->getFaixas().size()-1)))
          {
            faixasExclusivasCD.push_back(meusCDs[CDindex]->getFaixas()[i]) ;   
          }
          }
      }
      for (int i =0; i < (int) meusDVDs[DVDindex]->getFaixas().size(); i++)
      {
        for (int j =0; j < (int) meusCDs[CDindex]->getFaixas().size(); j++)
        {
          if ((meusCDs[CDindex]->getFaixas()[j] != meusDVDs[DVDindex]->getFaixas()[i]) and (j == (int) (meusDVDs[DVDindex]->getFaixas().size()-1)))
          {                                                                                                                                              
            faixasExclusivasDVD.push_back(meusDVDs[DVDindex]->getFaixas()[j]) ;   
          }
        }
      }
    }
    //verifica-se se o vetor de faixas comuns está vazio
    int ln =1;
    if ((faixasComuns.size()==0) and (CDnulo == 0) and (DVDnulo ==0))
    {
      cout << "Não existem faixas comuns ao CD e ao DVD" << endl <<endl;
    }
    else if (faixasComuns.size()!=0)
    {
      //imprimo as faixas comuns
      cout << "Faixas presentes tanto no CD, quanto no DVD : " << endl << endl;
      ln =1;
      for (string elem : faixasComuns)
      {
        cout << ln << ".";
        cout << elem << endl;
        ln++;   
      }
      cout << endl;
    }
    //verifica-se se o vetor das faixas exclusivas do CD está vazio
    if ((faixasExclusivasCD.size() == 0) and ((CDnulo == 0) and (DVDnulo ==0)))
    {
      cout << "Não existem faixas exclusivas do CD" << endl<<endl;
    }
    else if (faixasComuns.size()!=0)
    {
      //imprimo as faixas exclusivas de CD
      cout << "Faixas exclusivas do CD : " << endl;
      ln =1;
      for (string elem : faixasExclusivasCD)
      {
        cout << ln << ".";
        cout << elem << endl;
        ln++;  
      }
      cout << endl;
    }
    //verifica-se se o vetor das faixas exclusivas do DVD está vazio
    if ((faixasExclusivasDVD.size() == 0) and ((CDnulo == 0) and (DVDnulo ==0)))
    {
      cout << "Não existem faixas exclusivas do DVD" << endl<<endl;
    }
    else if (faixasComuns.size()!=0)
    {
      //imprimo as faixas exclusivas de DVD
      cout << "Faixas exclusivas do DVD" << endl;
      ln =1;
      for (string elem : faixasExclusivasDVD)
      {
        cout << ln << ".";
        cout << elem << endl;
        ln++;
      }
      cout << endl;
    }
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}

void ImprimirKeywords(vector<Cd*> &meusCDs, vector<Dvd*> &meusDVDs)
{
    //copio todas as keywords para este vetor auxiliar
    vector <string> MinhasKeywords;
    if (meusCDs.size() != 0)
    {
      for (int i =0; i < (int) meusCDs.size();i++)
      {
          for (int j = 0; j < (int) meusCDs[i]->getKeyWords().size(); j++)
          {
              MinhasKeywords.push_back(meusCDs[i]->getKeyWords()[j]);   
          }
      }
    }
    if (meusDVDs.size() != 0)
    {
      for (int i =0; i < (int) meusDVDs.size();i++)
      {
        for (int j = 0; j < (int) meusDVDs[i]->getKeyWords().size(); j++)
        {
          MinhasKeywords.push_back(meusDVDs[i]->getKeyWords()[j]);   
        }
      }
    }
    //imprimo as keywords
    if (MinhasKeywords.size() != 0)
    {
      for (auto elem : MinhasKeywords)
      {
        cout << elem << endl;
      }
    }
    else
    {
      cout << "Nenhum tipo de Mídia foi cadastrada ainda" << endl;
    }
}

void deleteCD(vector<Cd*> &meusCDs, string CDtitulo)
{
    //se o vetor não tiver elementos
    bool encontrado =0; //sinaliza se o titulo foi encontrado
    bool vazio=0; //sinaliza se a lista esta vazia
    int CDindex =0;
    if (meusCDs.size() == 0 )
    {
      cout << "Atualmente não existe nenhum CD cadastrado" << endl << endl;
      vazio =1;
    }
    //Caso o vetor não seja nulo, encontra o index do elemento a ser deletado
    else
    {
      for (int i =0; i < (int) meusCDs.size(); i++)
      {
        if (meusCDs[i]->getTitulo() == CDtitulo)
        {
          CDindex = i;
          encontrado =1;
          break;
        }
      }
      //se o CD não foi encontrado
      if ((encontrado == 0) and (vazio =0))
      {
        cout << "Não existe nenhum CD com esse título na coleção" << endl<<endl;  
      }
      //se o CD foi encontrado
      else if (encontrado == 1)
      {
        meusCDs.erase(meusCDs.begin()+CDindex);
        cout << "CD deletado com sucesso !" << endl << endl;
      }
    }
}

void deleteDVD(vector<Dvd*> &meusDVDs, string DVDtitulo)
{
    int DVDindex =0;
    bool encontrado = 0; //sinaliza se o elemento foi encontrado
    bool vazio =0; // sinaliza se o vetor está vazio
    //caso o vaetor seja vazio
    if (meusDVDs.size() ==0 )
    {
      cout << "Atualmente não existe nenhum CD cadastrado" << endl <<endl;
      vazio =1;
    }
    //Caso o vetor não seja nulo, procura-se o elemento
    else
    {
      for (int i =0; i < (int)meusDVDs.size(); i++)
      {
        if (meusDVDs[i]->getTitulo() == DVDtitulo)
        {
          DVDindex = i;
          encontrado = 1;
          cout << "DVD deletado com sucesso !" << endl << endl;
          break;
        }
      }
    }
    //se o DVD não foi encontrado
    if ((encontrado ==0) and (vazio =0))
    {
      cout << "Não existe nenhum DVD com esse título na coleção" << endl<< endl;
    }
    //Se o DVD foi encontrado
    else if (encontrado == 1)
    {
      meusDVDs.erase(meusDVDs.begin()+DVDindex);
      cout << "CD deletado com sucesso !" << endl << endl;
    }
}

void atualizarArtistaCD(vector <Cd*> &meusCDs, string antigoNome, string nomeNovo)
{
  bool encontrado =0; 
  if (meusCDs.size()==0)
  {
    cout << "Não existe nenhum CD cadastrado ainda" << endl;
  }
  else 
  {
    for (int i =0; i < (int)meusCDs.size(); i++)
    {
      if (meusCDs[i]->getArtista() == antigoNome)
      {
        meusCDs[i]->setArtista(nomeNovo);
        encontrado =1;
        cout << "Nome modificado com sucesso !" << endl;
        break;
      }
    }
  }
  if ((encontrado ==0) and (meusCDs.size() !=0))
  {
    cout << "Não existe nenhum artista com este nome" << endl;
  }
}

void atualizarGeneroCD(vector <Cd*> &meusCDs, string tituloCD, string novoGenero)
{
  bool encontrado =0;
  if (meusCDs.size() == 0)
  {
    cout << endl <<"Não existe nenhum CD cadastrado ainda" << endl <<endl;
  }
  else
  {
    for (int i =0; i <(int) meusCDs.size(); i++)
    {
      if (meusCDs[i]->getTitulo() == tituloCD) 
      {
        meusCDs[i]->setGenero(novoGenero);
        encontrado = 1;
        cout << "Gênero modificado com sucesso" << endl;
        break;
      }
    }
  }
  if ((encontrado == 0) and (meusCDs.size() !=0))
  {
    cout << "Não foi possível encontrar esse CD" << endl;
  }
}

void updateCD(vector <Cd*> &meusCDs)
{
  cout << "1. Atualizar o nome do Artista" << endl;
  cout << "2. Atualizar um gênero" << endl;
  
  int opc;
  string antigoNome, tituloCD, nomeNovo, novoGenero;

  inicio :
    cin >> opc;
    switch (opc)
    {
      case 1 :
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Insira o nome antigo do artista" << endl;
        getline(cin, antigoNome);

        cout << endl;

        cout << "Insira o novo nome do Artista" << endl;
        getline(cin, nomeNovo);

        cout << endl;

        atualizarArtistaCD(meusCDs, antigoNome, nomeNovo);
        break;
      case 2 :
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Insira o titulo do CD" << endl;
        getline(cin, tituloCD);
        cout << endl;

        cout << "Insira a novo Gênero" << endl;
        getline(cin, novoGenero);

        atualizarGeneroCD(meusCDs, tituloCD, novoGenero);
        break;
      default :
        cout << "Opção inválida. Por favor, insira uma opção válida" << endl;
        goto inicio;
        break;
    }

}

void atualizarArtistaDVD(vector <Dvd*> &meusDVDs, string antigoNome, string nomeNovo)
{
  bool encontrado =0;
  if (meusDVDs.size() == 0)
  {
    cout << "Nenhum DVD foi cadastrado ainda" << endl;
  }
  else
  {
    for (int i =0; i < (int)meusDVDs.size(); i++)
    {
      if (meusDVDs[i]->getArtista() == antigoNome)
      {
        meusDVDs[i]->setArtista(nomeNovo);
        encontrado =1;
        cout << "Nome modificado com sucesso !" << endl;
        break;
      }
    }
  }
  if ((encontrado ==0) and (meusDVDs.size() !=0))
  {
    cout << "Não existe nenhum artista com este nome" << endl;
  }
}

void atualizarGeneroDVD(vector <Dvd*> &meusDVDs, string tituloDVD, string novoGenero)
{
  bool encontrado =0;
  if (meusDVDs.size() == 0)
  {
    cout << endl<< "Nenhum DVD foi cadastrado ainda" << endl << endl;
  }
  else
  {
    for (int i =0; i < (int) meusDVDs.size(); i++)
    {
      if (meusDVDs[i]->getTitulo() == tituloDVD) 
      {
        meusDVDs[i]->setGenero(novoGenero);
        encontrado = 1;
        cout << "Gênero modificado com sucesso" << endl;
        break;
      }
    }
  }
  if ((encontrado == 0) and (meusDVDs.size() != 0))
  {
    cout << "Não foi possível encontrar esse CD" << endl;
  }
}

void updateDvd(vector <Dvd*> &meusDVDs)
{
  cout << "1. Atualizar o nome do Artista" << endl;
  cout << "2. Atualizar um gênero" << endl;
  
  int opc;
  string antigoNome, tituloDvd, nomeNovo, novoGenero;

  inicio :
    cin >> opc;
    switch (opc)
    {
      case 1 :
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Insira o nome antigo do artista" << endl;
        getline(cin, antigoNome);

        cout << endl;

        cout << "Insira o novo nome do Artista" << endl;
        getline(cin, nomeNovo);

        cout << endl;

        atualizarArtistaDVD(meusDVDs, antigoNome, nomeNovo);
        break;
      case 2 :
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Insira o titulo do Dvd" << endl;
        getline(cin, tituloDvd);
        cout << endl;

        cout << "Insira o novo Gênero" << endl;
        getline(cin, novoGenero);

        atualizarGeneroDVD(meusDVDs, tituloDvd, novoGenero);
        break;
      default :
        cout << "Opção inválida. Por favor, insira uma opção válida" << endl;
        goto inicio;
        break;
    }
}

void MenuUpdate (vector<Cd *> &meusCDs, vector<Dvd *> &meusDVDs)
{
  cout << "1. Atualizar um conteúdo do CD" << endl;
  cout << "2. Atualizar um conteúdo do DVD" << endl;
  
  int opc;
  inicio :

  flush();
  cin >> opc;
  switch (opc)
  {
    case 1 :
      updateCD(meusCDs);
      break;
    case 2 :
      updateDvd(meusDVDs);
      break;
    default :
      cout << "Insira uma opção válida" << endl;
      goto inicio;
      break;
  }
}

void Menu(vector<Cd *> &meusCDs, vector<Dvd *> &meusDVDs, bool &pararMenu) {

  //cin.ignore(numeric_limits<streamsize>::max(), '\n'); //dá pau 

  int opc;
  string ArtistaProcura;
  string GeneroProcura;
  int AnoProcura;
  string tituloCD, tituloDVD;
    
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
    cout << "1. Adicionar um CD" << endl; // Create
    cout << "2. Adicionar um DVD" << endl;
    cout << "3. Atualizar um CD" << endl;
    cout << "4. Atualizar um DVD" << endl;
    cout << "5. Deletar um CD" << endl;
	  cout << "6. Deletar um DVD" << endl;
    cout << "7. Exibir CDs" << endl;
    cout << "8. Exibir DVDs" << endl; 
    cout << "9. Exibir Mídias" << endl;
    cout << "10. Exibir as músicas de um ano" << endl;
    cout << "11. Exibir as musicas de um gênero" << endl;
    cout << "12. Exibir todas as keywords" << endl;
    cout << "13. Comparar Midias" << endl;
    cout << "14. Interromper a execução" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    inicio:
    cin >> opc;
    flush();
    switch (opc) {
    case 1:
      adicionarCD(meusCDs);
      break;
    case 2:
      adicionarDVD(meusDVDs);
      break;
    case 3:
      updateCD(meusCDs);
      break;
    case 4:
      updateDvd(meusDVDs);
      break;
    case 7:
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Insira o nome do Artista" << endl;
      getline (cin, ArtistaProcura);
      exibirCDs(meusCDs, ArtistaProcura);
      break;
    case 8:
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Insira o nome do Artista" << endl;
      getline (cin, ArtistaProcura);
      exibirDVDs(meusDVDs, ArtistaProcura);
      break;
    case 9:
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Insira o nome do Artista" << endl;
      getline (cin, ArtistaProcura);
      exibirMidias(meusCDs, meusDVDs, ArtistaProcura);
      break;
    case 10 :
      cout << "Insira o ano que você deseja procurar" << endl;
      cin >> AnoProcura;
      exibirMusicasAno(meusCDs, meusDVDs, AnoProcura);
      break;
    case 11 :
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Insira o gênero que você procura" << endl;
      getline (cin, GeneroProcura);
      exibirMusicasGenero(meusCDs, meusDVDs, GeneroProcura);
      break;
    case 5	:
		  cin.ignore(numeric_limits<streamsize>::max(), '\n');
		  cout << "Insira o título do CD que você deseja deletar" << endl;
		  getline (cin, tituloCD);
		  deleteCD(meusCDs, tituloCD);
		  break;
	  case 6 :
		  cin.ignore(numeric_limits<streamsize>::max(), '\n');
		  cout << "Insira o título do DVD que você deseja deletar" << endl;
		  getline (cin, tituloDVD);
		  deleteDVD(meusDVDs, tituloDVD);
		  break;
    case 13:
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Insira o título do CD" << endl;
      getline(cin, tituloCD);
      cout << "Insira o título do DVD" << endl;
      getline(cin, tituloDVD);
      CompararMidias(meusCDs, meusDVDs, tituloCD, tituloDVD);
      break;
    case 12 :
      ImprimirKeywords(meusCDs, meusDVDs);
      break;
    case 14 :
      pararMenu =1;
      break;
    default:
      cout << "Opção inválida, por favor insira uma opção válida" << endl<<endl;
      goto inicio;
      break;
  }
}

int main() {

  vector<Cd *> meusCDsII;
  vector<Dvd *> meusDVDsII;
  bool pararMenu =0;
  
  while (!pararMenu)
  {
    Menu(meusCDsII, meusDVDsII, pararMenu);
  }

}
