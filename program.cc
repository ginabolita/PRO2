/** @mainpage

    Laboratorio de PRO2. Ejercicio 'Bicing bifurcado'. 2023

*/


/** @file program.cc

    @brief Programa principal para la gestión de bicicletas y estaciones.

    Este programa facilita la ejecución de diversas operaciones vinculadas a
    bicicletas y estaciones, incluyendo la creación de una bicicleta, su
    eliminación, la consulta de su ubicación, la realización de viajes en bicicleta,
    y la transferencia de bicicletas entre estaciones, entre otras funcionalidades.

*/

#ifndef NO_DIAGRAM

#include <iostream>
#include <string>

using namespace std;

#endif

#include "Cjt_bicicletas.hh"
#include "Cjt_estaciones.hh"


int main() {
  Cjt_bicicletas c_bici;
  Cjt_estaciones c_est;
  BinTree<string> a;
  map<string, Estacion> b;

  c_est.leer(a, b);
  c_est.construir_cjt(a, b);

  string op;
  cin >> op;
  while (op != "fin") {
    string id_est, id_bici;
    if (op == "alta_bici" or op == "ab") {
      cin >> id_bici >> id_est;
      cout << "#ab " << id_bici << ' ' << id_est << endl;
      Bicicleta b(id_bici, id_est);
      int y = c_est.estado_bici_est(b, c_bici);
      if (y == -1) {
        cout << "error: la bici ya existe" << endl;
      } else {
        if (y == -2) {
          cout << "error: la estacion no existe" << endl;
        } else {
          Estacion e = c_est.consultar_estacion(id_est);
          if (e.consultar_plazas() != 0)
            c_est.agregar(b, c_bici);
          else
            cout << "error: la bici no cabe" << endl;
        }
      }
    }
    if (op == "baja_bici" or op == "bb") {
      cin >> id_bici;
      cout << "#bb " << id_bici << endl;
      if (c_bici.existe_bicicleta(id_bici)) {
        c_est.eliminar_bici_cjt(id_bici, c_bici);

      } else
        cout << "error: la bici no existe" << endl;
    }
    if (op == "estacion_bici" or op == "eb") {
      cin >> id_bici;
      cout << "#eb " << id_bici << endl;
      if (c_bici.existe_bicicleta(id_bici)) {
        Bicicleta b = c_bici.consultar_bicicleta(id_bici);
        cout << b.consultar_ubi() << endl;
      } else
        cout << "error: la bici no existe" << endl;
    }
    if (op == "viajes_bici" or op == "vb") {
      cin >> id_bici;
      cout << "#vb " << id_bici << endl;
      if (c_bici.existe_bicicleta(id_bici)) {
        Bicicleta b = c_bici.consultar_bicicleta(id_bici);
        b.escribir();
      } else
        cout << "error: la bici no existe" << endl;
    }
    if (op == "mover_bici" or op == "mb") {
      string est_dest;
      cin >> id_bici >> est_dest;
      cout << "#mb " << id_bici << ' ' << est_dest << endl;
      if (c_bici.existe_bicicleta(id_bici)) {
        Bicicleta b = c_bici.consultar_bicicleta(id_bici);
        if (c_est.existe_estacion(est_dest)) {
          Estacion e = c_est.consultar_estacion(est_dest);
          if (b.consultar_ubi() != est_dest) {
            if (e.consultar_plazas() != 0) {
              c_est.modificar_estacion(id_bici, est_dest, c_bici);
            } else
              cout << "error: la bici no cabe" << endl;
          } else
            cout << "error: la bici ya esta en el sitio" << endl;
        } else
          cout << "error: la estacion no existe" << endl;

      } else
        cout << "error: la bici no existe" << endl;
    }
    if (op == "bicis_estacion" or op == "be") {
      cin >> id_est;
      cout << "#be " << id_est << endl;
      if (c_est.existe_estacion(id_est)) {
        Estacion e = c_est.consultar_estacion(id_est);
        e.escribir();
      } else
        cout << "error: la estacion no existe" << endl;
    }
    if (op == "modificar_capacidad" or op == "mc") {
      int n;
      cin >> id_est >> n;
      cout << "#mc " << id_est << ' ' << n << endl;
      if (c_est.existe_estacion(id_est)) {
        int max = c_est.consultar_estacion(id_est).consultar_nbicis();
        if (n >= max) {
          c_est.modificar_capacidad(id_est, n);
        } else
          cout << "error: capacidad insuficiente" << endl;
      } else
        cout << "error: la estacion no existe" << endl;
    }
    if (op == "plazas_libres" or op == "pl") {
      cout << "#pl" << endl;
      cout << c_est.consultar_plazas() << endl;
    }
    if (op == "subir_bicis" or op == "sb") {
      cout << "#sb" << endl;
      c_est.completar(c_bici);
    }
    if (op == "asignar_estacion" or op == "ae") {
      cin >> id_bici;
      cout << "#ae " << id_bici << endl;
      if (not c_bici.existe_bicicleta(id_bici)) {
        if (c_est.consultar_plazas() != 0) {
          string est = c_est.asignar_est();
          Bicicleta b(id_bici, est);
          c_est.agregar(b, c_bici);
          cout << est << endl;
        } else
          cout << "error: no hay plazas libres" << endl;
      } else
        cout << "error: la bici ya existe" << endl;
    }

    cin >> op;
  }
}
