#include <iostream>
#include <assert.h>
#include "Joueur.h"

using namespace std;

Joueur::Joueur(bool white)
{
    int p=0;
    int y=(white?1:8);
    for (int x=1;x<=8;x++)
        m_pieces[p++].init(x,y,white);
    y=(white?2:7);
    for (int x=1;x<=8;x++)
    {
        m_pieces[p].init(x,y,white);
        p=p+1;
    }
    assert(p==16);
    cout << "Un Joueur cree" << endl;
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
    for (int i=0; i<16; i++)
        m_pieces[i].affiche();
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
    for (int i=0; i<16; i++)
        e.placer(m_pieces+i /*&(m_pieces[i])*/);
}