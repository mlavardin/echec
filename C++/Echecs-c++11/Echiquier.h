/**
 * Header de Echiquier.cxx
 *
 * @file Echiquier.h
 */

#if !defined Echiquier_h
#define Echiquier_h

#include <array>
#include <memory>
#include "Piece.h"

using namespace std;

/**
 * Declaration d'une classe modelisant une piece de jeu d'echec.
 */
class Echiquier : public NonCopyable
{
private:
  /**
   * Les cases de l'echiquier
   */
  //Piece* m_cases[ 64 ];
  array<shared_ptr<Piece>, m_max * m_max> m_cases;

public:
  /**
   * Constructeur par defaut.
   * Initialise a vide l'echiquier.
   */
  Echiquier();

  /**
   * Recupere la piece situee sur une case.
   *
   * @param c une coordonnee
   *
   * @return nullptr si aucune piece n'est sur cette case et un pointeur
   * vers une piece sinon.
   */
  shared_ptr<Piece> getPiece(const Coordinate &c) const;

  /**
   * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
   *
   * @param p un pointeur vers une piece
   *
   * @return 'true' si le placement s'est bien passe, 'false' sinon
   * (case occupee, coordonnees invalides, piece vide )
   */
  bool placer(shared_ptr<Piece> p);

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
  bool deplacer(shared_ptr<Piece> p, const Coordinate &c);

  /**
   * Enleve la piece situee sur une case (qui devient vide).
   *
   * @param c une coordonnee
   *
   * @return nullptr si aucune piece n'est sur cette case et le pointeur
   * vers la piece enlevee sinon.
   */
  shared_ptr<Piece> enleverPiece(const Coordinate &c);

  /**
   * Affiche l'echiquier avec des # pour les cases noires et . pour
   * les blanches si elles sont vides, et avec B pour les pieces
   * blanches et N pour les pieces noires.
   */
  void affiche() const;
};

#endif // !defined Echiquier_h
