#include "Estacion.hh"

Estacion::Estacion() {}

Estacion::Estacion(const string& id, int nmax) {
  this->id = id;
  this->nmax = nmax;
}

void Estacion::agregar_IDbici(const string& bici) { IDbicis.insert(bici); }

void Estacion::eliminar_IDbici(const string& bici) { IDbicis.erase(bici); }

void Estacion::modificar_capacidad(int n) { nmax = n; }

string Estacion::consultar_id() const { return id; }

int Estacion::consultar_plazas() const {
  if (IDbicis.empty())
    return nmax;
  else
    return nmax - IDbicis.size();
}

int Estacion::capacidad_maxima() { return nmax; }

int Estacion::consultar_nbicis() const {
  if (IDbicis.empty())
    return 0;
  else
    return IDbicis.size();
}

string Estacion::menor_id() {
  set<string>::iterator it = IDbicis.begin();
  return *it;
}

void Estacion::leer() { cin >> id >> nmax; }

void Estacion::escribir() const {
  for (set<string>::iterator it = IDbicis.begin(); it != IDbicis.end(); ++it) {
    cout << *it << endl;
  }
}