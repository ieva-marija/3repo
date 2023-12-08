#include "mylib.h"
#include "mylib2.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

//-------------------------------------------------------
float galutinisVidVector(const Studentas& studentas) {
    float vidurkis = 0;
    for (int pazymys : studentas.getPazymiai()) {
        vidurkis += pazymys;
    }
    vidurkis = static_cast<float>(vidurkis) / studentas.getPazymiai().size();
    return 0.4 * vidurkis + 0.6 * studentas.getEgzaminas();
};
//-------------------------------------------------------
float galutinisVidList(const Studentas2& studentas) {
    float vidurkis = 0;
    for (int pazymys : studentas.getPazymiai()) {
        vidurkis += pazymys;
    }
    vidurkis = static_cast<float>(vidurkis) / studentas.getPazymiai().size();
    return 0.4 * vidurkis + 0.6 * studentas.getEgzaminas();
};
//--------------------------------------------------------
float galutinisMedVector(const Studentas& studentas) {
    vector<int> pazymiai = studentas.getPazymiai();
    sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 == 0) {
        int vidurys = pazymiai.size() / 2;
        float mediana = static_cast<float>(pazymiai[vidurys - 1] + pazymiai[vidurys]) / 2;
        return 0.4 * mediana + 0.6 * studentas.getEgzaminas();
    } else {
        float mediana = static_cast<float>(pazymiai[pazymiai.size() / 2]);
        return 0.4 * mediana + 0.6 * studentas.getEgzaminas();
        }
};
//-------------------------------------------------------
float galutinisMedList(const Studentas2& studentas) {
    list<int> pazymiai = studentas.getPazymiai();
    pazymiai.sort();
    if (pazymiai.size() % 2 == 0) {
        auto it1 = std::next(pazymiai.begin(), pazymiai.size() / 2 - 1);
        auto it2 = std::next(pazymiai.begin(), pazymiai.size() / 2);
        float mediana = (static_cast<float>(*it1) + static_cast<float>(*it2)) / 2.0f;
        return 0.4 * mediana + 0.6 * studentas.getEgzaminas();
    }
    else {
        auto it = std::next(pazymiai.begin(), pazymiai.size() / 2);
        float mediana = static_cast<float>(*it);
        return 0.4 * mediana + 0.6 * studentas.getEgzaminas();}
};
//----------------------------------------------------------
void rusiavimasVector(vector<Studentas>& studentai) {
    std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return a.getPavarde() < b.getPavarde();
    });
};
//----------------------------------------------------------
void rusiavimasList(list<Studentas2>& studentai2) {
    studentai2.sort([](const Studentas2& a, const Studentas2& b) {
        return a.getPavarde() < b.getPavarde();
    });
};
//-------------------------------------------------------
float galutinisVidVectorRanka(StudentasRanka& studentas) {
    float vidurkis = 0;
    for (int pazymys : studentas.getPazymiai()) {
        vidurkis += pazymys;
    }
    vidurkis = static_cast<float>(vidurkis) / studentas.getPazymiai().size();
    return 0.4 * vidurkis + 0.6 * studentas.getEgzaminas();
};
float galutinisMedVectorRanka(StudentasRanka& studentas) {
    vector<int> pazymiai = studentas.getPazymiai();
    sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 == 0) {
        int vidurys = pazymiai.size() / 2;
        float mediana = static_cast<float>(pazymiai[vidurys - 1] + pazymiai[vidurys]) / 2;
        return 0.4 * mediana + 0.6 * studentas.getEgzaminas();
    } else {
        float mediana = static_cast<float>(pazymiai[pazymiai.size() / 2]);
        return 0.4 * mediana + 0.6 * studentas.getEgzaminas();
        }
};
//----------------------------------------------------------
std::ostream& operator<<(std::ostream& os, StudentasRanka& student) {
    os << "Vardas: " << student.getVardas() << "\n";
    os << "Pavarde: " << student.getPavarde() << "\n";
    os << "Pazymiai: ";
    for (const int& pazymys : student.getPazymiai()) {
        os << pazymys << " ";
    }
    os << "\nEgzaminas: " << student.getEgzaminas() << "\n";
    os << "Vidurkis: " << student.getRezultatasV() << "\n";
    os << "Mediana: " << student.getRezultatasM() << "\n";
    return os;
}
//--------------------------------------------------------------
std::istream& operator>>(std::istream& is, StudentasRanka& student) {
    std::cout << "Iveskite varda: ";
    is >> student.vardas;
    std::cout << "Iveskite pavarde: ";
    is >> student.pavarde;
    int pazymys;
    int pasirinkimas2;
    std::cout << "Ar norite, kad programa studento pazymius ir egzamino rezultata generuotu atsitiktinai?" << endl;
      cout << "5 - taip, noriu, aciu" << endl;
      cout << "9 - ne, noriu ivesti savarankiskai" << endl;
        cin >> pasirinkimas2;

        if (pasirinkimas2 == 5) {
            srand(time(0));
            int a_pazymiai_sk = rand() % 11;
            cout << "Sugeneruoti atsitiktinai pazymiai: ";
            for (int i = 0; i < a_pazymiai_sk; ++i) {
                int a_pazymys = rand() % 11 + 1;
                student.getPazymiai().push_back(a_pazymys);
                cout << a_pazymys << " ";
            }

            srand(time(0));
            student.setEgzaminas(rand() % 11 + 1);
            cout << "Sugeneruotas egzamino pazymys: "<< student.getEgzaminas() << endl;
            cout << "\n";
        }
         else if (pasirinkimas2 == 9) {
           while (true) {
                cout << "Iveskite namu darbu rezultatus (iveskite -1, kai suvedete visus norimus pazymius): ";
                if (cin >> pazymys) {
                    if (pazymys == -1) {
                        cin.clear();
                        cin.ignore(256, '\n');
                        break;
                    }
                    if (pazymys >= 0 && pazymys <= 10) {
                        student.getPazymiai().push_back(pazymys);
                    }
                    else {
                        cout << "??????????" << endl;
                        }
                }
                else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "????????????" << endl;
                    }
           }
           cout << "Iveskite egzamino pazymi: ";
           int egzaminas;
            cin >> egzaminas;
            student.setEgzaminas(egzaminas);
            while (student.getEgzaminas() > 10) {
                cout << "MELAGIS. VESK IS NAUJO";
                cin >> egzaminas;
                student.setEgzaminas(egzaminas);
            }
         }
         else {
            cout << "nu cia nei 5, nei 9........" << endl;
            return is;
         }
    student.setRezultatasV(galutinisVidVectorRanka(student));
    student.setRezultatasM(galutinisMedVectorRanka(student));
    return is;
}


