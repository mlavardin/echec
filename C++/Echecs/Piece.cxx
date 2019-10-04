/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

#include <iostream>
#include <assert.h>
// A besoin de la declaration de la classe
#include "Piece.h"

using namespace std;

Piece::Piece()
{
    // ne fait rien => objet instancie mais non valide.
    cout << "Une Piece construite par defaut" << endl;
}

Piece::Piece( const Piece &autre )
{
    m_x     = autre.m_x;
    m_y     = autre.m_y;
    m_white = autre.m_white;
    // autre.m_x = 1; // const protected !
    cout << "Une Piece construite par copie" << endl;
}

Roi::Roi(bool white) : Piece()
{
    m_x = 5;
    m_y = white ? 1 : 8;
    m_white = white;
    cout << "Un Roi construit" << endl;
}

Fou::Fou(bool white, bool left) : Piece(left?3:6, white?1:8, white)
{
    cout << "Un Fou construit" << endl;
}

Tour::Tour(bool white, bool left) : Piece(left?1:8, white?1:8, white)
{
    cout << "Une Tour construite" << endl;
}

Reine::Reine(bool white) : Piece(4, white?1:8, white),
    Fou(white,true), Tour(white,true)
{
    cout << "Une Reine construite" << endl;
}

Cavalier::Cavalier(bool white, bool left) : Piece(left?2:7, white?1:8, white)
{
    cout << "Un Cavalier construit" << endl;
}

Pion::Pion(bool white, int place) : Piece(place, white?2:7, white)
{
    cout << "Un Pion construit" << endl;
}

Piece &
Piece::operator=( const Piece &autre )
{
    m_x     = autre.m_x;
    m_y     = autre.m_y;
    m_white = autre.m_white;
    cout << "Une Piece affectee" << endl;
    return *this;
}

bool
Piece::mouvementValide(Echiquier &e, int x, int y)
{
    // on ne devrait pas passer ici
    cout << "mouvementValide de Piece" << endl;
    return false;
}

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
    cout << "mouvementValide de Roi" << endl;
    return false;
}

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
    cout << "mouvementValide de Fou" << endl;
    return false;
}

bool
Tour::mouvementValide(Echiquier &e, int x, int y)
{
    cout << "mouvementValide de Tour" << endl;
    return false;
}

bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
    cout << "mouvementValide de Reine" << endl;
    return Fou::mouvementValide( e, x, y ) || Tour::mouvementValide( e, x, y );
}

bool
Cavalier::mouvementValide(Echiquier &e, int x, int y)
{
    cout << "mouvementValide de Cavalier" << endl;
    return false;
}

bool
Pion::mouvementValide(Echiquier &e, int x, int y)
{
    cout << "mouvementValide de Pion" << endl;
    return false;
}

Piece::~Piece()
{
    cout << "Une Piece detruite" << endl;
}

Piece::Piece( int x, int y, bool white )
{
    m_x     = x;
    m_y     = y;
    m_white = white;
    cout << "Une Piece construite" << endl;
}

void
Piece::init( int x, int y, bool white )
{
    m_x     = x;
    m_y     = y;
    m_white = white;
}

void
Piece::move( int x, int y )
{
    m_x = x;
    m_y = y;
}

int
Piece::x() const
{
    return m_x;
}

int
Piece::y() const
{
    return m_y;
}

bool
Piece::isWhite() const
{
    return m_white;
}

bool
Piece::isBlack() const
{
    return !m_white;
}

void
Piece::affiche() const
{
    cout << "Piece: x=" << m_x << " y=" << m_y << " " << ( m_white ? "blanche" : "noire" ) << endl;
}

char
Piece::codechar() const
{
    return m_white ? 'B' : 'N';
}

char
Roi::codechar() const
{
    return m_white ? 'R' : 'r';
}

char
Fou::codechar() const
{
    return m_white ? 'F' : 'f';
}

char
Tour::codechar() const
{
    return m_white ? 'T' : 't';
}

char
Reine::codechar() const
{
    return m_white ? 'Q' : 'q';
}

char
Cavalier::codechar() const
{
    return m_white ? 'C' : 'c';
}

char
Pion::codechar() const
{
    return m_white ? 'P' : 'p';
}
