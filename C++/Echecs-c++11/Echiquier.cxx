/**
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */

#include <iostream>
#include <assert.h>
// A besoin de la declaration de la classe
#include "Echiquier.h"

using namespace std;

/**
 * Constructeur par defaut.
 * Initialise a vide l'echiquier.
 */
Echiquier::Echiquier()
{
  // static_assert(extent<decltype(m_cases)>::value == 64); // ok if built-in array : Piece* m_case[64];
  for (int i = 0; i < m_max * m_max; i++)
    m_cases[i] = nullptr; // C++11
}

/**
 * Recupere la piece situee sur une case.
 *
 * @param c une coordonnee
 *
 * @return nullptr si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
shared_ptr<Piece>
Echiquier::getPiece(const Coordinate &c) const
{
  assert(c.isValid());
  return m_cases[toIndex(c)];
}

/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool Echiquier::placer(shared_ptr<Piece> p)
{
  if (p != nullptr)
  {
    assert(p->c().isValid());
    if (m_cases[toIndex(p->c())] == nullptr)
    {
      m_cases[toIndex(p->c())] = p;
      return true;
    }
  }
  return false;
}

/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y.
 *
 * @param p un pointeur vers une piece
 * @param c une coordonnee
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */
bool Echiquier::deplacer(shared_ptr<Piece> p, const Coordinate &c)
{
}

/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param c une coordonnee
 *
 * @return nullptr si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
shared_ptr<Piece>
Echiquier::enleverPiece(const Coordinate &c)
{
  shared_ptr<Piece> tmp;
  assert(c.isValid());
  tmp = m_cases[toIndex(c)];
  m_cases[toIndex(c)] = nullptr;
  return tmp;
}

/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void Echiquier::affiche() const
{
  cout << endl
       << "  12345678" << endl;
  for (int y = m_min; y <= m_max; ++y)
  {
    cout << y << " ";
    for (int x = m_min; x <= m_max; ++x)
    {
      char c;
      Coordinate pos(x, y);
      shared_ptr<Piece> p = getPiece(pos);
      if (p == nullptr)
        c = ((x + y) % 2) == 0 ? '#' : '.';
      else
        c = p->getChar(); // p->isWhite() ? 'B' : 'N';
      cout << c;
    }
    cout << " " << y << endl;
  }
  cout << "  12345678" << endl;
}
