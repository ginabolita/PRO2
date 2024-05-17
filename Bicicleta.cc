#include "Bicicleta.hh"

Bicicleta::Bicicleta() {}

Bicicleta::Bicicleta(string id, string ubi) {
  this->id = id;
  this->ubi = ubi;
}

void Bicicleta::modificar_ubi(string nueva_ubi) { ubi = nueva_ubi; }

void Bicicleta::anadir_viaje(const string& est_origen, const string& id_est) {
  viajes.push_back(pair<string, string>(est_origen, id_est));
}

string Bicicleta::consultar_ubi() const { return ubi; }

string Bicicleta::consultar_id() const { return id; }

void Bicicleta::leer() { cin >> id; }

void Bicicleta::escribir() {
  list<pair<string, string> >::iterator it = viajes.begin();
  while (it != viajes.end()) {
    cout << it->first << ' ' << it->second << endl;
    ++it;
  }
}
