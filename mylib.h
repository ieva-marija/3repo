#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

class StudentasRanka {
   private:
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    float vidurkis, mediana, rezultatasv, rezultatasm;

    public:
        StudentasRanka() : egzaminas(0), vidurkis(0), mediana(0), rezultatasv(0), rezultatasm(0) {}

    std::string& getVardas()  {
        return vardas;
    }
    std::string& getPavarde() {
        return pavarde;
    }
    std::vector<int>& getPazymiai()  {
        return pazymiai;
    }
    int getEgzaminas()  {
        return egzaminas;
    }
    float getRezultatasV()  {
        return rezultatasv;
    }
    float getRezultatasM() {
        return rezultatasm;
    }

    void setVardas( std::string& vardas) {
        this->vardas = vardas;
    }
    void setPavarde( std::string& pavarde) {
        this->pavarde = pavarde;
    }
    void setPazymiai( std::vector<int>& pazymiai) {
        this->pazymiai = pazymiai;
    }
    void setEgzaminas(int egzaminas) {
        this->egzaminas = egzaminas;
    }
    void setVidurkis(float vidurkis) {
        this->vidurkis = vidurkis;
    }
    void setMediana(float mediana) {
        this->mediana = mediana;
    }
    void setRezultatasV(float rezultatasv) {
        this->rezultatasv = rezultatasv;
    }
    void setRezultatasM(float rezultatasm) {
        this->rezultatasm = rezultatasm;
    }

private:
    float galutinisVidVectorRanka();
    float galutinisMedVectorRanka();
};

class Studentas {
    private:
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    float vidurkis, mediana, rezultatasv, rezultatasm;

    public:
        Studentas() : egzaminas(0), vidurkis(0), mediana(0), rezultatasv(0), rezultatasm(0) {}

    public:
    Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& pazymiai, int egzaminas)
    : vardas(vardas), pavarde(pavarde), pazymiai(pazymiai), egzaminas(egzaminas),
      rezultatasv(galutinisVidVector()), rezultatasm(galutinisMedVector())
 {
        this->vardas = vardas;
        this->pavarde = pavarde;
        this->pazymiai = pazymiai;
        this->egzaminas = egzaminas;
        this->rezultatasv = galutinisVidVector();
        this->rezultatasm = galutinisMedVector();
}
    const std::string& getVardas() const {
        return vardas;
    }
    const std::string& getPavarde() const {
        return pavarde;
    }
    const std::vector<int>& getPazymiai() const {
        return pazymiai;
    }
    int getEgzaminas() const {
        return egzaminas;
    }
    float getRezultatasV()  const {
        return rezultatasv;
    }
    float getRezultatasM() const {
        return rezultatasm;
    }

    void setVardas(const std::string& vardas) {
        this->vardas = vardas;
    }
    void setPavarde(const std::string& pavarde) {
        this->pavarde = pavarde;
    }
    void setPazymiai(const std::vector<int>& pazymiai) {
        this->pazymiai = pazymiai;
    }
    void setEgzaminas(int egzaminas) {
        this->egzaminas = egzaminas;
    }
    void setVidurkis(float vidurkis) {
        this->vidurkis = vidurkis;
    }
    void setMediana(float mediana) {
        this->mediana = mediana;
    }
    void setRezultatasV(float rezultatasv) {
        this->rezultatasv = rezultatasv;
    }
    void setRezultatasM(float rezultatasm) {
        this->rezultatasm = rezultatasm;
    }

private:
    float galutinisVidVector() const;
    float galutinisMedVector() const;
};

class Studentas2 {
    private:
    std::string vardas, pavarde;
    std::list<int> pazymiai;
    int egzaminas;
    float vidurkis, mediana, rezultatasv, rezultatasm;

    public:
        Studentas2() : egzaminas(0), vidurkis(0), mediana(0), rezultatasv(0), rezultatasm(0) {}


    public:
    Studentas2(const std::string& vardas, const std::string& pavarde, const std::list<int>& pazymiai, int egzaminas)
    : vardas(vardas), pavarde(pavarde), pazymiai(pazymiai), egzaminas(egzaminas),
      rezultatasv(galutinisVidList()), rezultatasm(galutinisMedList())
 {
        this->vardas = vardas;
        this->pavarde = pavarde;
        this->pazymiai = pazymiai;
        this->egzaminas = egzaminas;
        this->rezultatasv = galutinisVidList();
        this->rezultatasm = galutinisMedList();
}
    const std::string& getVardas() const {
        return vardas;
    }
    const std::string& getPavarde() const {
        return pavarde;
    }
    const std::list<int>& getPazymiai() const {
        return pazymiai;
    }
    int getEgzaminas() const {
        return egzaminas;
    }
    float getRezultatasV()  const {
        return rezultatasv;
    }
    float getRezultatasM() const {
        return rezultatasm;
    }

    void setVardas(const std::string& vardas) {
        this->vardas = vardas;
    }
    void setPavarde(const std::string& pavarde) {
        this->pavarde = pavarde;
    }
    void setPazymiai(const std::list<int>& pazymiai) {
        this->pazymiai = pazymiai;
    }
    void setEgzaminas(int egzaminas) {
        this->egzaminas = egzaminas;
    }
    void setVidurkis(float vidurkis) {
        this->vidurkis = vidurkis;
    }
    void setMediana(float mediana) {
        this->mediana = mediana;
    }
    void setRezultatasV(float rezultatasv) {
        this->rezultatasv = rezultatasv;
    }
    void setRezultatasM(float rezultatasm) {
        this->rezultatasm = rezultatasm;
    }

private:
    float galutinisVidList() const;
    float galutinisMedList() const;
};

#endif // MYLIB_H
