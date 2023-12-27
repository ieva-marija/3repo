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

void generavimasVector(vector<Studentas>& studentai, int count, const string& failas, const string& failas0, int skaicius)
{
    studentai.clear();
    for (int i = 1; i < count +1; i++) {
        Studentas studentas;
        studentas.setVardas("Vardas" + to_string(i));
        studentas.setPavarde("Pavarde" + to_string(i));

        vector <int> pazymiai;
        for (int j = 0; j < 15; j++) {
                pazymiai.push_back(rand() % 10 + 1);
        }
        studentas.setPazymiai(pazymiai);
        studentas.setEgzaminas(rand() % 10 + 1);
        studentas.setRezultatasV(galutinisVidVector(studentas));
        studentas.setRezultatasM(galutinisMedVector(studentas));
        studentai.push_back(studentas);
    }
    vector<Studentas> pradinis = studentai;
    saugojimas0Vector(failas0, pradinis);
    if(skaicius==0){
        rusiavimasVector2(studentai);
    }
    else if(skaicius==1){
        rusiavimasVector(studentai);
    }
    else if (skaicius==2){
        rusiavimasVector3(studentai);
    }
    saugojimasVector(failas, studentai);
}

void saugojimas0Vector(const string& failas0, const vector<Studentas>& pradinis)
{
    ofstream F(failas0);
    if (!F) {
        cerr << "Nepavyko atidaryti failo " << failas0 << endl;
        return;
    }
    int maxNumND = 0;
    for (const Studentas& studentas : pradinis) {
        maxNumND = max(maxNumND, static_cast<int>(studentas.getPazymiai().size()));
    }
    F << left << setw(15) << "Vardas" << setw(17) << " Pavarde";
    for(int i=0; i<maxNumND; i++){
        F << setw(10) <<  "Nd." + to_string(i);
    }
    F << setw(15) << "Egzaminas " << endl;
    for (const Studentas& studentas : pradinis) {
        F << setw(15) << studentas.getVardas() << " " << setw(17) << studentas.getPavarde();
        for(int i=0; i<studentas.getPazymiai().size(); i++){
            F << setw(10) << studentas.getPazymiai()[i];
        }
        F << studentas.getEgzaminas() <<  endl;
    }
    F.close();
}
//-------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------
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

void rusiavimas2Vector(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, int skaiciux)
{
    vargsiukai.clear();

    std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(vargsiukai), [](const Studentas& studentas) {
        return studentas.getRezultatasV() >= 5;
    });

    studentai.erase(std::remove_if(studentai.begin(), studentai.end(), [](const Studentas& studentas) {
        return studentas.getRezultatasV() < 5;
    }), studentai.end());

    if(skaiciux==0){
    rusiavimasVector2(vargsiukai);
    rusiavimasVector2(studentai);
    }
    else if(skaiciux==1){
        rusiavimasVector(vargsiukai);
        rusiavimasVector(studentai);
    }
    else if(skaiciux==2){
        rusiavimasVector3(vargsiukai);
        rusiavimasVector3(studentai);
    }
}
void isvedimasVVector(const string& failas_vargsiukai, const vector<Studentas>& vargsiukai)
{
    saugojimasVector(failas_vargsiukai, vargsiukai);
}

void isvedimasKVector(const string& failas_kietiakai, const vector<Studentas>& studentai)
{
    saugojimasVector(failas_kietiakai, studentai);
}
//-------------------------------------------------------------------------------------
void generavimoLVector(vector<Studentas>& studentai, int skaicius, const string& failas, const string& failas0, int sk) {
    auto start = std::chrono::high_resolution_clock::now();
    generavimasVector(studentai, skaicius, failas, failas0, sk);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << skaicius << " irasu failo generavimas uztruko: " << duration.count() << endl;
}
//---------------------------------------------------------------------------------------------
void skaitymoLVector(vector<Studentas>& studentai, const string& failas) {
    auto start = std::chrono::high_resolution_clock::now();
    skaityti2Vector(studentai, failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
//---------------------------------------------------------------------------------------------
void rusiavimoLVector(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, int skaiciux) {
    auto start = std::chrono::high_resolution_clock::now();
    rusiavimas2Vector(studentai, vargsiukai, skaiciux);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
//---------------------------------------------------------------------------------------------
void isvedimoVLVector(const string& failas_vargsiukai, const vector<Studentas>& vargsiukai) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasVVector(failas_vargsiukai, vargsiukai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
//---------------------------------------------------------------------------------------------
void isvedimoKLVector(const string& failas_kietiakai, const vector<Studentas>& studentai) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasKVector(failas_kietiakai, studentai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
