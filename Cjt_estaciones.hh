/** @file Cjt_estaciones.hh
    @brief Especificación de la classe Cjt_estaciones
*/

#ifndef _CJT_EST_HH_
#define _CJT_EST_HH_

#ifndef NO_DIAGRAM

#include <iostream>
#include <map>
#include <string>

using namespace std;

#include "BinTree.hh"

#endif

#include "Cjt_bicicletas.hh"
#include "Estacion.hh"

/** @class Cjt_estaciones
    @brief Representa un conjunto de estaciones
*/
class Cjt_estaciones {
 private:
  map<string, Estacion> estaciones;
  BinTree<string> arbolID;
  int espacio_libre;

 public:
  ////////////// Constructoras //////////////

  /** @brief Creadora por defecto

      \pre <em>cierto</em>
      \post El resultado es un conjunto de estaciones no inicializado
  */
  Cjt_estaciones();

  /** @brief Creadora con valores concretos

      \pre <em>cierto</em>
      \post El parámetro implícito es un Cjt_estaciones con arbolID "a" y
     estaciones "b"
  */
  void construir_cjt(const BinTree<string>& a, const map<string, Estacion>& b);

  ////////////// Modificadoras //////////////

  /** @brief Modificadora del atributo estaciones y arbolID

      \pre <em>cierto</em>
      \post El parámetro implícito pasa a tener en la estación de "bici" el id
     de bicicleta "bici" y se actualiza también en el cjt_bicicletas
  */
  void agregar(const Bicicleta& bici, Cjt_bicicletas& c_bici);

  /** @brief Modificadora del atributo estaciones y arbolID

      \pre <em>cierto</em>
      \post El parámetro implícito, en la estación de "bici" se elimina el id de
     bicicleta "bici" y se actualiza también en el cjt_bicicletas
  */
  void eliminar_bici_cjt(const string& id_bici, Cjt_bicicletas& c_bici);

  /** @brief Modificadora del atributo estaciones

      \pre <em>cierto</em>
      \post El parametro implícito modifica la ubicación de la bicicleta con id
     "id_bici" de su ubi a "est_dest". Se acutaliza también el cjt_bicicletas
  */
  void modificar_estacion(const string& id_bici, const string& est_dest,
                          Cjt_bicicletas& c_bici);

  /** @brief Modificadora del atributo estaciones

      \pre <em>cierto</em>
      \post El parámetro implícito con id "id" pasa a tener nmax "n"
  */
  void modificar_capacidad(const string& id, int n);

  /** @brief Modificadora del atributo estaciones

      \pre <em>cierto</em>
      \post Cambia de ubicación una bicicleta. Se actualiza el destino y el
     cjt_bicicletas
  */
  void autocompletar_bicis(Estacion& nexo, Estacion& e, Cjt_bicicletas& c_bici);

  /** @brief Modificadora del atributo estaciones

      \pre <em>cierto</em>
      \post <em>cierto</em>

    * Función auxiliar para subir bicis
  */
  void completar_aux(const BinTree<string>& t, Cjt_bicicletas& c_bici);

  /** @brief Modificadora del atributo estaciones

      \pre <em>cierto</em>
      \post <em>cierto</em>

    * Se actualiza el conjunto de bicicletas
  */
  void completar(Cjt_bicicletas& c_bici);

  /** @brief Modificadora del atributo estaciones

      \pre <em>cierto</em>
      \post <em>cierto</em>

    * Función recursiva para asignar la estación adecuada
  */
  void asignar_est_aux(const BinTree<string>& t, double& pl, int& c,
                       pair<double, string>& est);

  /** @brief Modificadora del atributo estaciones

      \pre <em>cierto</em>
      \post Devuelve el identficador de la estación elegida
  */
  string asignar_est();

  ////////////// Consultoras //////////////

  /** @brief Existe estación
      \pre <em>cierto</em>
      \post Devuelve <em>true</em> si la estación existe sino devuelve
     <em>false</em>
  */
  bool existe_estacion(const string& id);

  /** @brief Se devuelve el estado de la bicicleta y/o estación
      \pre <em>cierto</em>
      \post Devuelve -1 si la bici existe, -2 si la estación no existe, 0 sino.
  */
  int estado_bici_est(const Bicicleta& bici, Cjt_bicicletas& c_bici);

  /** @brief Consultora de estación

      \pre  <em>cierto</em>
      \post Devuelve la Estación con "id"
  */
  Estacion consultar_estacion(const string& id);

  /** @brief Consultora de las plazas libres totales

      \pre <em>cierto</em>
      \post Devuelve "espacio_libre"
  */
  int consultar_plazas() const;

  // Operación de lectura
  /** @brief Operación de lectura

      \pre <em>cierto</em>
      \post El contenido de la entrada es guardado en el parámetro implícito
  */
  void leer(BinTree<string>& a, map<string, Estacion>& b);
};

#endif