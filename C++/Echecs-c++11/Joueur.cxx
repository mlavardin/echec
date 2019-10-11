/**
 * Mise en oeuvre de Joueur.h
 *
 * @file Joueur.cxx
 */

#include <iostream>
#include <assert.h>
#include "Joueur.h"

using namespace std;

Joueur::Joueur(const Color &white)
{
  m_pieces.push_back(shared_ptr<Piece>( (Piece *)(new Roi( white )) ));
  m_pieces.push_back(shared_ptr<Piece>( (Piece *)(new Reine( white )) ));
  m_pieces.push_back(shared_ptr<Piece>( (Piece *)(new Fou( white, true )) ));
  m_pieces.push_back(shared_ptr<Piece>( (Piece *)(new Fou( white, false )) ));
  m_pieces.push_back(shared_ptr<Piece>( (Piece *)(new Cavalier( white, true )) ));
  m_pieces.push_back(shared_ptr<Piece>( (Piece *)(new Cavalier( white, false )) ));
  m_pieces.push_back(shared_ptr<Piece>( (Piece *)(new Tour( white, true )) ));
  m_pieces.push_back(shared_ptr<Piece>( (Piece *)(new Tour( white, false )) ));
  for (int x = 1; x <= 8; x++)
    m_pieces.push_back(shared_ptr<Piece>( (Piece *)(new Pion( white, x )) ));
  cout << "Constructeur Joueur specialise" << endl;
}

JoueurBlanc::JoueurBlanc() : Joueur(Color::colorWhite)
{
  cout << "Constructeur JoueurBlanc" << endl;
}

JoueurNoir::JoueurNoir() : Joueur(Color::colorBlack)
{
  cout << "Constructeur JoueurNoir" << endl;
}

Joueur::~Joueur()
{
  /*
  vector<Piece*>::iterator p=m_pieces.begin();
  while (p!=m_pieces.end())
    {
      delete *p;
      p++;
      }
  */
  // for (Piece* &p : m_pieces) // boucle C++11
  /*
  for (auto p : m_pieces) // boucle C++11
    delete p;
  */
  // destruction automatique des Pieces grace aux shared pointeurs
  cout << "Destructeur Joueur" << endl;
}

/*
bool
Joueur::isWhite()
{
  return m_pieces[0].isWhite();
}
*/

bool JoueurBlanc::isWhite()
{
  return true;
}

bool JoueurNoir::isWhite()
{
  return false;
}

void Joueur::affiche() const
{
  /*
  for (int i=0; i<16; i++)
    m_pieces[i]->affiche();
  */
  // for (Piece* &p : m_pieces) // boucle C++11
  for (auto &p : m_pieces) // boucle C++11
    p->affiche();
}

void Joueur::placerPieces(Echiquier &e)
{
  /*
  for (int i=0; i<16; i++)
    {
      int ok;
      ok=e.placer(m_pieces[i]);
      assert(ok);
    }
  */
  // for (Piece* &p : m_pieces) // boucle C++11
  for (auto &p : m_pieces) // boucle C++11
  {
    int ok;
    ok = e.placer(p);
    assert(ok);
  }
}
