/**
 * Header de Commun.cxx
 *
 * @file Commun.h
 */

#if !defined Commun_h
#define Commun_h

#include <tuple>
using namespace std;

enum class Color
{
  colorNone,  // Represente l’absence de couleur
  colorWhite, // Represente la couleur blanche
  colorBlack, // Represente la couleur noire
  colorMax    // Valeur maximale a ne jamais atteindre
};

static const int m_max = 8;
static const int m_min = 1;

class Coordinate
{
public:
  Coordinate() : m_c(m_max, m_max) {}
  Coordinate(const int x, const int y) : m_c(x, y) {}
  int x() const { return get<0>(m_c); }
  int y() const { return get<1>(m_c); }
  bool isValid() const { return this->x() <= m_max && this->y() <= m_max && this->x() >= m_min && this->y() >= m_min; }

private:
  tuple<int, int> m_c;
};

inline bool operator==(Coordinate const &first,
                       Coordinate const &second)
{
  if (!first.isValid())
    return !second.isValid();
  return first.x() == second.x() && first.y() == second.y();
}
inline int toIndex(const int x, const int y) { return (x - 1) + m_max * (y - 1); }
inline int toIndex(const Coordinate &c) { return (c.x() - 1) + m_max * (c.y() - 1); }
inline Coordinate toCoordinate(const int index)
{
  Coordinate c(index % m_max, index / m_max);
  return c;
}

class NonCopyable
{
public:
  NonCopyable(NonCopyable const &) = delete;
  NonCopyable &operator=(NonCopyable const &) = delete;

protected:
  // protege car utilisable uniquement par les classes derivees
  NonCopyable() {}
  ~NonCopyable() {}
};

#endif
