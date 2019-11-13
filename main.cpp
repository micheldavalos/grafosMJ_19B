#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
//    pair<size_t, size_t> punto(1, 2);
//    punto.first = 1;
//    punto.second = 2;

//    cout << "(" << punto.first << ", " <<
//            punto.second << ")" << endl;

//    vector<pair<size_t, size_t>> puntos;
//    string op;

//    while (true) {
//        cout << "1) Agregar Punto" << endl;
//        cout << "2) Mostrar Puntos" << endl;
//        cout << "3) Ordenar" << endl;
//        cout << "0) Salir" << endl;
//        getline(cin, op);

//        if (op == "1") {
//            size_t x, y;

//            cout << "x: ";
//            cin >> x;

//            cout << "y: ";
//            cin >> y; cin.ignore();

//            pair<size_t, size_t> punto(x, y);

//            puntos.push_back(punto);
//        }
//        else if (op == "2") {
//            cout << "[";
//            for (auto &punto: puntos) {
//                cout << "(" << punto.first <<
//                        ", " << punto.second <<
//                        "), ";
//            }
//            cout << "\b\b]" << endl;
//        }
//        else if (op == "3") {
//            sort(puntos.begin(), puntos.end(),
//                 []
//                 (const pair<size_t, size_t> &p1,
//                  const pair<size_t, size_t> &p2)
//                {
//                return p1.first < p2.first;
//                });
//        }
//        else if (op == "0") {
//            break;
//        }

//    }

//    map<string, vector<string> > grafo;

//    grafo["A"] = {"B", "C", "Z"};
//    grafo["C"] = {"A", "B"};
//    grafo["B"] = {"A", "C"};
//    grafo["Z"] = {"A"};

//    for (auto it = grafo.begin();
//         it != grafo.end(); it++) {
//        cout << (*it).first << "->";
//        cout << "[";
//        for(auto &ady: (*it).second) {
//            cout << ady << ", ";
//        }
//        cout << "\b\b]" << endl;
//    }

    map<string, vector<string> > grafo;
    string op;

    while (true) {
        cout << "1) Agregar Arista" << endl;
        cout << "2) Mostrar Grafo" << endl;
        cout << "3) Eliminar Arista" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
         string origen, destino;

         cout << "origen: ";
         getline(cin, origen);

         cout << "destino: ";
         getline(cin, destino);

         if (grafo.count(origen)) {
//            vector<string> &ady = grafo[origen];
//             auto &ady = grafo[origen];
             grafo[origen].push_back(destino);

         }
         else {
             grafo[origen] = {destino};
         }

         if (grafo.count(destino)) {
             grafo[destino].push_back(origen);
         }
         else {
             grafo[destino] = {origen};
         }


        }
        else if (op == "2") {
            for (auto it = grafo.begin();
                 it != grafo.end(); it++) {
                cout << (*it).first << "->";
                cout << "[";
                for(auto &ady: (*it).second) {
                    cout << ady << ", ";
                }
                cout << "\b\b]" << endl;
            }
        }
        else if (op == "3") {
            string origen, destino;

            cout << "origen: ";
            getline(cin, origen);

            cout << "destino: ";
            getline(cin, destino);

            if (grafo.count(origen) &&
                    grafo.count(destino)    ) {
                auto &ady_origen = grafo[origen];
                auto &ady_destino = grafo[destino];

                auto it1 = find(ady_origen.begin(),
                     ady_origen.end(), destino);
                auto it2 = find(ady_destino.begin(),
                     ady_destino.end(), origen);

                if (it1 != ady_origen.end() &&
                        it2 != ady_destino.end()) {
                    ady_origen.erase(it1);
                    ady_destino.erase(it2);

                    if (grafo[origen].size() == 0) {
                        grafo.erase(origen);
                    }
                    if (grafo[destino].size() == 0) {
                        grafo.erase(destino);
                    }
                }


            }
            else {
                cout << "No existe la arista";
            }
        }
        else if (op == "0") {
            break;
        }



    }

    return 0;
}
