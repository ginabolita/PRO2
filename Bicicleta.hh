/** @file Bicicleta.hh
    @brief Especificación de la clase Bicicleta
*/

#ifndef _BICI_HH_
#define _BICI_HH_

#ifndef NO_DIAGRAM

#include <iostream>
#include <list>
#include <string>

using namespace std;

#endif

/** @class Bicicleta
    @brief Representa una bicicleta con atributos identificador, ubicación y
   una lista de viajes

    Todas las operaciones son de <b>coste constante</b>
*/
class Bicicleta {
 private:
  string id;   // identificador de bicicleta
  string ubi;  // estacion ubicada
  list<pair<string, string> > viajes;

 public:
  ////////////// Constructoras //////////////

  /** @brief Creadora por defecto.

      \pre <em>cierto</em>
      \post El resultado es una bicicleta no inicializada
  */
  Bicicleta();

  /** @brief Creadora con valores concretos

      \pre <em>cierto</em>
      \post El parámetro implícito es una bicicleta con id "id" y ubi "ubi"
  */
  Bicicleta(const string id, const string ubi);

  ////////////// Modificadoras //////////////

  /** @brief Modificadora del atributo ubi
      \pre <em>cierto</em>
      \post El parámetro implícito pasa a tener ubi "nueva_ubi"
  */
  void modificar_ubi(string nueva_ubi);

  /** @brief Modificadora del atributo viajes
      \pre <em>cierto</em>
      \post El parámetro implícito pasa a tener viajes más el pari<string,
     string>(est_origen, id_est)
  */
  void anadir_viaje(const string& est_origen, const string& id_est);

  ////////////// Consultoras //////////////

  /** @brief Consultora de ubicación de la bicicleta
      \pre <em>cierto</em>
      \post El resultado es la ubicación del parámetro implícito
  */
  string consultar_ubi() const;

  /** @brief Consultora del identificador de la bicicleta
      \pre <em>cierto</em>
      \post El resultado es el identificador del parámetro implícito
  */
  string consultar_id() const;

  // Operación de lectura
  /** @brief Operación de lectura

      \pre <em>cierto</em>
      \post El contenido de la entrada es guardado en el parámetro implícito
  */
  void leer();

  // Operación de escritura
  /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito los atributos de viajes del parámetro implícito en el
     canal standard de salida.
  */
  void escribir();
};

#endif