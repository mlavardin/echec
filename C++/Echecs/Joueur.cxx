#include <assert.h>
#include "Joueur.h"

Joueur::Joueur(bool white)
{
    int p=0;
    int x=(white?1:8);
    for (int y=1;y<=8;y++)
        m_pieces[p++].init(x,y,white);
    x=(white?2:7);
    for (int y=1;y<=8;y++)
    {
        m_pieces[p].init(x,y,white);
        p=p+1;
    }
    assert(p==16);
}

void
Joueur::affiche()
{
    for (int i=0; i<16; i++)
        m_pieces[i].affiche();
}

bool
Joueur::isWhite()
{
    return m_pieces[0].isWhite();
}