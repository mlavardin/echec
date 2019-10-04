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

Reine::Reine(bool white) : Piece(4, white?1:8, white)
{
    cout << "Une Reine construite" << endl;
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
Reine::mouvementValide(Echiquier &e, int x, int y)
{
    cout << "mouvementValide de Reine" << endl;
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
Reine::codechar() const
{
    return m_white ? 'Q' : 'q';
}