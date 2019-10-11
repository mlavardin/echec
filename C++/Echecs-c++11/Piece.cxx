/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Piece.h"

using namespace std;

Piece::Piece() : m_c(Coordinate(0, 0)), m_white(Color::colorNone)
{
  // ne fait rien => objet instancie mais non validee.
  cout << "Construction Piece par defaut" << endl;
}

Roi::Roi(const Color &white) : Piece(Coordinate(5, (white == Color::colorWhite) ? 1 : 8), white)
{
  cout << "Constructeur Roi" << endl;
}

Pion::Pion(const Color &white, const int pos) : Piece(Coordinate(pos, (white == Color::colorWhite) ? 2 : 7), white)
{
  cout << "Constructeur Pion " << pos << endl;
}

Cavalier::Cavalier(const Color &white, const bool left) : Piece(Coordinate(left ? 2 : 7, (white == Color::colorWhite) ? 1 : 8), white)
{
  cout << "Constructeur Cavalier" << endl;
}

Fou::Fou(const Color &white, const bool left) : Piece(Coordinate(left ? 3 : 6, (white == Color::colorWhite) ? 1 : 8), white)
{
  cout << "Constructeur Fou" << endl;
}

Tour::Tour(const Color &white, const bool left) : Piece(Coordinate(left ? 1 : 8, (white == Color::colorWhite) ? 1 : 8), white)
{
  cout << "Constructeur Tour" << endl;
}

Reine::Reine(const Color &white) : Fou(white, true), Tour(white, true),
                                   Piece(Coordinate(4, (white == Color::colorWhite) ? 1 : 8), white)
{
  cout << "Constructeur Reine" << endl;
}

Piece::~Piece()
{
  cout << "Destructeur Piece" << endl;
}

/*
Piece::Piece(const Piece & autre)
{
  m_c=autre.m_c;
  m_white=autre.m_white;
  cout << "Constructeur Piece par copie" << endl;
}

Piece &
Piece::operator=(const Piece & autre)
{
  m_c=autre.m_c;
  m_white=autre.m_white;
  cout << "Affectation Piece" << endl;
  return *this;
}
*/

Piece::Piece(const Coordinate &c, const Color &white) : m_c(c), m_white(white)
{
  cout << "Construction Piece specialisee" << endl;
}

void Piece::move(const Coordinate &c)
{
  m_c = c;
}

Coordinate
Piece::c() const
{
  return m_c;
}

bool Piece::isWhite() const
{
  return m_white == Color::colorWhite;
}

bool Piece::isBlack() const
{
  return m_white == Color::colorBlack;
}

void Piece::affiche() const
{
  cout << "Piece: x=" << m_c.x() << " y=" << m_c.y() << " "
       << ((m_white == Color::colorWhite) ? "blanche" : "noire") << endl;
}

/*
bool
Piece::mouvementValide(const Echiquier &e, const Coordinate &c)
{
  cout << "mouvementValide Piece" << endl;
}
*/

bool Roi::mouvementValide(const Echiquier &e, const Coordinate &c)
{
  cout << "mouvementValide Roi" << endl;
}

bool Pion::mouvementValide(const Echiquier &e, const Coordinate &c)
{
  cout << "mouvementValide Pion" << endl;
}

bool Cavalier::mouvementValide(const Echiquier &e, const Coordinate &c)
{
  cout << "mouvementValide Cavalier" << endl;
}

bool Fou::mouvementValide(const Echiquier &e, const Coordinate &c)
{
  cout << "mouvementValide Fou" << endl;
}

bool Tour::mouvementValide(const Echiquier &e, const Coordinate &c)
{
  cout << "mouvementValide Tour" << endl;
}

bool Reine::mouvementValide(const Echiquier &e, const Coordinate &c)
{
  //cout << "mouvementValide Reine" << endl;
  return Fou::mouvementValide(e, c) || Tour::mouvementValide(e, c);
}

char Piece::getChar() const
{
  return (m_white == Color::colorWhite) ? 'B' : 'N';
}

char Roi::getChar() const
{
  return (m_white == Color::colorWhite) ? 'R' : 'r';
}

char Pion::getChar() const
{
  return (m_white == Color::colorWhite) ? 'P' : 'p';
}

char Cavalier::getChar() const
{
  return (m_white == Color::colorWhite) ? 'C' : 'c';
}

char Fou::getChar() const
{
  return (m_white == Color::colorWhite) ? 'F' : 'f';
}

char Tour::getChar() const
{
  return (m_white == Color::colorWhite) ? 'T' : 't';
}

char Reine::getChar() const
{
  return (m_white == Color::colorWhite) ? 'Q' : 'q';
}

void Roi::roque()
{
  cout << "roque de Roi" << endl;
}
