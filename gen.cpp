#include "mylib.h"
#include "mylib2.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

Studentas::~Studentas(){}

void generavimasVector(vector<Studentas>& studentai, int count, const string& failas)
{
    studentai.clear();
    for (int i = 1; i < count +1; i++) {
        Studentas studentas;
        studentas.setVardas("Vardas" + to_string(i));
        studentas.setPavarde("Pavarde" + to_string(i));
        for (int j = 0; j < 15; j++) {
            studentas.setPazymiai({rand() % 10 + 1});
            }
        studentas.setEgzaminas(rand() % 10 + 1);
        studentas.setRezultatasV(galutinisVidVector(studentas));
        studentas.setRezultatasM(galutinisMedVector(studentas));
        studentai.push_back(studentas);
    }
    rusiavimasVector(studentai);
    saugojimasVector(failas, studentai);
}

void saugojimasVector(const string& failas, const vector<Studentas>& studentai)
{
    ofstream F(failas);
    if (!F) {
        cerr << "Nepavyko atidaryti failo " << failas << endl;
        return;
    }

    F << left << setw(15) << "Vardas" << setw(15) << " Pavarde" << setw(15) << "Galutinis (Vid.) " << setw(15) << "Galutinis (Med.)" << endl;
  
    for (const Studentas& studentas : studentai) {
        F << setw(15) << studentas.getVardas() << " " << setw(15) << studentas.getPavarde();
        F << " " << fixed << setprecision(2) << setw(16) << studentas.getRezultatasV() << " " << fixed << setprecision(2) << studentas.getRezultatasM() << endl;
    }
    F.close();
}

void skaityti2Vector(vector<Studentas>& studentai, const string& pav) {
    ifstream F(pav);

   try {
   if (!F) {
        throw runtime_error("nera tokio failo: " + pav);
    }

    string line;
    bool firstLine = true;
    while (getline(F, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }
        istringstream iss(line);
        Studentas studentas;
        string vardas, pavarde;
        float rezultatasv, rezultatasm;

        if (iss >> vardas >> pavarde >> rezultatasv >> rezultatasm) {
                studentas.setVardas(vardas);
                studentas.setPavarde(pavarde);
                studentas.setRezultatasV(rezultatasv);
                studentas.setRezultatasM(rezultatasm);

                studentai.push_back(studentas);
            }
            else {
                cout << "Klaida skaityti2vector eilutej: " << line << endl;
            }
    }
    F.close();
   }
    catch (const exception& e) {
        cerr << "neperskaito...:" << e.what() << endl;
    }
};

void rusiavimas2Vector(vector<Studentas>& studentai, vector<Studentas>& vargsiukai)
{
    vargsiukai.clear();

    std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(vargsiukai), [](const Studentas& studentas) {
        return studentas.getRezultatasV() >= 5;
    });

    studentai.erase(std::remove_if(studentai.begin(), studentai.end(), [](const Studentas& studentas) {
        return studentas.getRezultatasV() < 5;
    }), studentai.end());
}
void isvedimasVVector(const string& failas_vargsiukai, const vector<Studentas>& vargsiukai)
{
    saugojimasVector(failas_vargsiukai, vargsiukai);
}

void isvedimasKVector(const string& failas_kietiakai, const vector<Studentas>& studentai)
{
    saugojimasVector(failas_kietiakai, studentai);
}

void generavimoLVector(vector<Studentas>& studentai, int skaicius, const string& failas) {
    auto start = std::chrono::high_resolution_clock::now();
    generavimasVector(studentai, skaicius, failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << skaicius << " irasu failo generavimas uztruko: " << duration.count() << endl;
}

void skaitymoLVector(vector<Studentas>& studentai, int skaicius, const string& failas) {
    auto start = std::chrono::high_resolution_clock::now();
    skaityti2Vector(studentai, failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}

void rusiavimoLVector(vector<Studentas>& studentai, int skaicius, vector<Studentas>& vargsiukai) {
    auto start = std::chrono::high_resolution_clock::now();
    rusiavimas2Vector(studentai, vargsiukai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}

void isvedimoVLVector(const string& failas_vargsiukai, int skaicius, const vector<Studentas>& vargsiukai) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasVVector(failas_vargsiukai, vargsiukai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}

void isvedimoKLVector(const string& failas_kietiakai, int skaicius, const vector<Studentas>& studentai) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasKVector(failas_kietiakai, studentai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
