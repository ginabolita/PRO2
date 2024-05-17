#include "Cjt_estaciones.hh"

Cjt_estaciones::Cjt_estaciones() { espacio_libre = 0; }

void Cjt_estaciones::construir_cjt(const BinTree<string>& a,
                                   const map<string, Estacion>& b) {
  estaciones = b;
  arbolID = a;
}

void Cjt_estaciones::agregar(const Bicicleta& bici, Cjt_bicicletas& c_bici) {
  --espacio_libre;

  c_bici.agregar_bicicleta(bici);
  map<string, Estacion>::iterator it = estaciones.find(bici.consultar_ubi());
  it->second.agregar_IDbici(bici.consultar_id());
}

void Cjt_estaciones::eliminar_bici_cjt(const string& id_bici,
                                       Cjt_bicicletas& c_bici) {
  ++espacio_libre;

  Bicicleta b = c_bici.consultar_bicicleta(id_bici);
  string id_est = b.consultar_ubi();
  c_bici.eliminar_bicicleta(id_bici);
  map<string, Estacion>::iterator it = estaciones.find(id_est);
  it->second.eliminar_IDbici(id_bici);
}

void Cjt_estaciones::modificar_estacion(const string& id_bici,
                                        const string& est_dest,
                                        Cjt_bicicletas& c_bici) {
  map<string, Estacion>::iterator it = estaciones.find(est_dest);
  it->second.agregar_IDbici(id_bici);
  string est_origen = c_bici.consultar_bicicleta(id_bici).consultar_ubi();
  it = estaciones.find(est_origen);
  it->second.eliminar_IDbici(id_bici);
  c_bici.modificar_bicicleta(id_bici, est_origen, est_dest, true);
}

void Cjt_estaciones::modificar_capacidad(const string& id, int n) {
  int max = estaciones[id].capacidad_maxima();
  espacio_libre += (n - max);
  estaciones[id].modificar_capacidad(n);
}

void Cjt_estaciones::autocompletar_bicis(Estacion& nexo, Estacion& e,
                                         Cjt_bicicletas& c_bici) {
  string s = e.menor_id();
  nexo.agregar_IDbici(s);
  e.eliminar_IDbici(s);
  string est_origen = e.consultar_id();
  string est_dest = nexo.consultar_id();
  c_bici.modificar_bicicleta(s, est_origen, est_dest, false);
}

void Cjt_estaciones::completar_aux(const BinTree<string>& t,
                                   Cjt_bicicletas& c_bici) {
  map<string, Estacion>::iterator it = estaciones.find(t.value());
  int missing = it->second.consultar_plazas();
  if (not t.empty()) {
    if (not t.left().empty()) {
      map<string, Estacion>::iterator itleft =
          estaciones.find(t.left().value());
      int nleft = itleft->second.consultar_nbicis();
      map<string, Estacion>::iterator itright =
          estaciones.find(t.right().value());
      int nright = itright->second.consultar_nbicis();

      int i = 0;
      while ((nleft != 0 or nright != 0) and i < missing) {
        if (nleft > nright) {
          autocompletar_bicis(it->second, itleft->second, c_bici);
          --nleft;
        } else if (nleft < nright) {
          autocompletar_bicis(it->second, itright->second, c_bici);
          --nright;
        } else if (nleft == nright) {
          string id_esq = itleft->second.menor_id();
          string id_dre = itright->second.menor_id();

          if (id_esq < id_dre) {
            autocompletar_bicis(it->second, itleft->second, c_bici);
            --nleft;
          } else {
            autocompletar_bicis(it->second, itright->second, c_bici);
            --nright;
          }
        }
        ++i;
      }
      completar_aux(t.left(), c_bici);
      completar_aux(t.right(), c_bici);
    }
  }
}

void Cjt_estaciones::completar(Cjt_bicicletas& c_bici) {
  completar_aux(arbolID, c_bici);
}

void Cjt_estaciones::asignar_est_aux(const BinTree<string>& t, double& pl,
                                     int& c, pair<double, string>& est) {
  if (t.left().empty() and t.right().empty()) {
    double plazas = estaciones[t.value()].consultar_plazas();
    pl += plazas;
    ++c;
    if (plazas > est.first) {
      est.first = plazas;
      est.second = t.value();
    } else if (plazas == est.first) {
      if (t.value() < est.second) est.second = t.value();
    }
  } else {
    double pl_left, pl_right;
    int c_left, c_right;
    pl_left = pl_right = c_left = c_right = 0;
    asignar_est_aux(t.left(), pl_left, c_left, est);
    asignar_est_aux(t.right(), pl_right, c_right, est);

    c = c_left + c_right + 1;
    pl = estaciones[t.value()].consultar_plazas() + pl_left + pl_right;
    double plazas = pl / c;

    if (plazas > est.first) {
      est.first = plazas;
      est.second = t.value();
    } else if (plazas == est.first) {
      if (t.value() < est.second) est.second = t.value();
    }
  }
}

string Cjt_estaciones::asignar_est() {
  pair<double, string> est;
  double pl = 0;
  int c = 0;
  asignar_est_aux(arbolID, pl, c, est);

  return est.second;
}

bool Cjt_estaciones::existe_estacion(const string& id) {
  map<string, Estacion>::iterator it = estaciones.find(id);
  if (it == estaciones.end()) {
    return false;
  } else
    return true;
}

int Cjt_estaciones::estado_bici_est(const Bicicleta& bici,
                                    Cjt_bicicletas& c_bici) {
  if (c_bici.existe_bicicleta(bici.consultar_id()))
    return -1;  // ya existe
  else {
    string est = bici.consultar_ubi();
    map<string, Estacion>::iterator it = estaciones.find(est);
    if (it != estaciones.end()) {
      return 0;  // existe
    } else
      return -2;  // no existe
  }
}

Estacion Cjt_estaciones::consultar_estacion(const string& id) {
  map<string, Estacion>::iterator it = estaciones.find(id);
  return it->second;
}

int Cjt_estaciones::consultar_plazas() const {
  if (espacio_libre > 0)
    return espacio_libre;
  else
    return 0;
}

void Cjt_estaciones::leer(BinTree<string>& a, map<string, Estacion>& b) {
  string id;
  cin >> id;
  if (id != "#") {
    int c;
    cin >> c;
    espacio_libre += c;
    Estacion est(id, c);
    b.insert(pair<string, Estacion>(id, est));
    BinTree<string> ai;
    leer(ai, b);
    BinTree<string> ad;
    leer(ad, b);
    a = BinTree<string>(id, ai, ad);
  }
}
