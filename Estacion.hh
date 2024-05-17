/** @file Estacion.hh
    @brief Especificación de la classe Estacion
*/

#ifndef _EST_HH_
#define _EST_HH_

#ifndef NO_DIAGRAM

#include <iostream>
#include <set>
#include <string>

using namespace std;

#endif

/** @class Estacion
    @brief Representa una estación con atributos identificador, capacidad y un mapa de identificadores de bicicletas
*/
class Estacion {
 private:
  string id;
  int nmax;  // número máximo de bicicletes en el conjunto
  set<string> IDbicis;

 public:
  ////////////// Constructoras //////////////

  /** @brief Creadora por defecto.

      \pre <em>cierto</em>
      \post El resultado es una estación no inicializada
  */
  Estacion();

  /** @brief Creadora con valores concretos

      \pre <em>cierto</em>
      \post El parámetro implícito es una estación con id "id" y nmax "nmax"
  */
  Estacion(const string& id, int nmax);

  ////////////// Modificadoras //////////////

  /** @brief Modificadora del atributo IDbicis

        \pre <em>El P.I. tiene capacidad máxima, 0 <= num. bicis <= nmax</em>
        \post  El parámetro implícito pasa a tener IDbicis más "bici"
  */
  void agregar_IDbici(const string& bici);

  /** @brief Modificadora del atributo IDbicis

        \pre <em>cierto</em>
        \post El parámetro implícito pasa a tener IDbicis menos "bici"
  */
  void eliminar_IDbici(const string& bici);

  /** @brief Modificadora del atributo nmax

        \pre <em>cierto</em>
        \post El parámetro implícito pasa a tener nmax "n"
  */
  void modificar_capacidad(int n);

  ////////////// Consultoras //////////////

  /** @brief Consultora del identificador de la estación

      \pre <em>cierto</em>
      \post El resultado es el identificador del parámetro implícito
  */
  string consultar_id() const;

  /** @brief Consultora de las plazas libres en la estación

      \pre <em>cierto</em>
      \post El resultado es el número de plazas libres del parámetro implícito
  */
  int consultar_plazas() const;

  /** @brief Consultora de la capacidad máxima de la estación

      \pre <em>cierto</em>
      \post El resultado es la capacidad máxima del parámetro implícito
  */
  int capacidad_maxima();

  /** @brief Consultora de la cantidad de bicis que hay en la estación

      \pre <em>cierto</em>
      \post El resultado es el número de bicis del parámetro implícito
  */
  int consultar_nbicis() const;

  /** @brief Consultora de la bicicleta con menor id en la estación

      \pre <em>cierto</em>
      \post El resultado es la bicicleta con menor id del parámetro implícito
  */
  string menor_id();

  // Operación de lectura
  /** @brief Operación de lectura

      \pre <em>cierto</em>
      \post El contenido de la entrada es guardado en el parámetro implícito
  */
  void leer();

  // Operación de escritura
  /** @brief Operación de escritura

      \pre  La estación existe
      \post Escribe el contenido del parámetro implícito por el canal estándar
     de salida.
  */
  void escribir() const;
};

#endif
