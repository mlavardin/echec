#include <iostream>
#include <assert.h>
#include "Joueur.h"

using namespace std;

Joueur::Joueur(bool white)
{
    m_pieces.push_back( new Roi(white) );
    m_pieces.push_back( new Reine(white) );
    m_pieces.push_back( new Fou(white,true) );
    m_pieces.push_back( new Fou(white,false) );
    m_pieces.push_back( new Cavalier(white,true) );
    m_pieces.push_back( new Cavalier(white,false) );
    m_pieces.push_back( new Tour(white,true) );
    m_pieces.push_back( new Tour(white,false) );
    for ( int i = 1; i<= 8; i++)
        m_pieces.push_back( new Pion(white,i) );
    cout << "Un Joueur cree" << endl;
}

Joueur::~Joueur()
{
    vector<Piece *>::iterator p = m_pieces.begin();
    while (p!=m_pieces.end())
    {
        delete *p;
        p++;
    }
}

JoueurBlanc::JoueurBlanc() : Joueur(true)
{
    cout << "Un Joueur Blanc cree" << endl;
}

JoueurNoir::JoueurNoir() : Joueur(false)
{
    cout << "Un Joueur Noir cree" << endl;
}

void
Joueur::affiche()
{
    vector<Piece *>::iterator p = m_pieces.begin();
    while (p!=m_pieces.end())
    {
        ( *p )->affiche();
        p++;
    }
    /*
    for ( int i = 0; i < 16; i++ )
        m_pieces[i]->affiche();
    */
}

/* methode virtuelle pure
bool
Joueur::isWhite()
{
    return m_pieces[0].isWhite();
}
*/

bool
JoueurBlanc::isWhite()
{
    return true;
}

bool
JoueurNoir::isWhite()
{
    return false;
}

void
Joueur::placerPieces(Echiquier & e)
{
    vector<Piece *>::iterator p = m_pieces.begin();
    while (p!=m_pieces.end())
    {
        e.placer(*p);
        p++;
    }
    /*
    for (int i=0; i<16; i++)
        e.placer(m_pieces[i]);
    */
}