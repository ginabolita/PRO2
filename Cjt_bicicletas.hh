/** @file Cjt_bicicletas.hh
    @brief Especificación de la classe Cjt_bicicletas
*/

#ifndef _CJT_BICIS_HH_
#define _CJT_BICIS_HH_

#ifndef NO_DIAGRAM

#include <iostream>
#include <map>
#include <string>

using namespace std;

#endif

#include "Bicicleta.hh"

/** @class Cjt_bicicletas
    @brief Representa un conjunto de bicicletas
*/
class Cjt_bicicletas {
 private:
  map<string, Bicicleta> bicicletas;

 public:
  ////////////// Constructoras //////////////

  /** @brief Creadora por defecto

      \pre <em>cierto</em>
      \post El resultado es un conjunto de bicicletas no inicializado
  */
  Cjt_bicicletas();

  ////////////// Modificadoras //////////////

  /** @brief Modificadora del atributo bicicletas

      \pre <em>cierto</em>
      \post El parámetro implícito pasa a tener bicicletas más "bici"
  */
  void agregar_bicicleta(const Bicicleta &bici);

  /** @brief Modificadora del atributo bicicletas

      \pre <em>cierto</em>
      \post El parámetro implícito pasa a tener bicicletas menos la bicicleta
     con "id"
  */
  void eliminar_bicicleta(const string &id);

  /** @brief Modificadora del atributo bicicletas

      \pre <em>cierto</em>
      \post El parámetro implícito con "id_bici" pasa a tener "est_origen" a
     "est_dest".
  */
  void modificar_bicicleta(const string &id_bici, const string &est_origen,
                           const string &est_dest, bool anadir);

  ////////////// Consultoras //////////////

  /** @brief Existe bicicleta

      \pre <em>cierto</em>
      \post Devuelve <em>cierto</em> si la bicicleta con "id" existe y
     <em>falso</em> sino.
  */
  bool existe_bicicleta(const string &id);

  /** @brief Consultar bicicleta

      \pre  <em>cierto</em>
      \post Devuelve la Bicicleta con ese "id"
  */
  Bicicleta consultar_bicicleta(const string &id);
};

#endif