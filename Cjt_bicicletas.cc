#include "Cjt_bicicletas.hh"

Cjt_bicicletas::Cjt_bicicletas() {}

void Cjt_bicicletas::agregar_bicicleta(const Bicicleta& bici) {
  bicicletas.insert(pair<string, Bicicleta>(bici.consultar_id(), bici));
}

void Cjt_bicicletas::eliminar_bicicleta(const string& id) {
  bicicletas.erase(id);
}

void Cjt_bicicletas::modificar_bicicleta(const string& id_bici,
                                         const string& est_origen,
                                         const string& est_dest, bool anadir) {
  map<string, Bicicleta>::iterator it = bicicletas.find(id_bici);
  it->second.modificar_ubi(est_dest);
  if (anadir) it->second.anadir_viaje(est_origen, est_dest);
}

bool Cjt_bicicletas::existe_bicicleta(const string& id) {
  map<string, Bicicleta>::iterator it = bicicletas.find(id);
  if (it == bicicletas.end()) {
    return false;
  } else
    return true;
}

Bicicleta Cjt_bicicletas::consultar_bicicleta(const string& id) {
  map<string, Bicicleta>::iterator it = bicicletas.find(id);
  return it->second;
}
