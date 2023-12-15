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

class Zmogus {
public:
    virtual ~Zmogus() = default;

    virtual std::string getVardas() const = 0;
    virtual std::string getPavarde() const = 0;
};

class StudentasRanka {
   private:
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    float vidurkis, mediana, rezultatasv, rezultatasm;

    public:
       StudentasRanka() : egzaminas(0), vidurkis(0), mediana(0), rezultatasv(0), rezultatasm(0) {}

       StudentasRanka(const StudentasRanka& other)
           : vardas(other.vardas), pavarde(other.pavarde), pazymiai(other.pazymiai), egzaminas(other.egzaminas),
             vidurkis(other.vidurkis), mediana(other.mediana), rezultatasv(other.rezultatasv), rezultatasm(other.rezultatasm) {
             std::cout << "Kopijavimo konstruktorius iskviestas " << vardas << " " << pavarde << "\n"; }
   
       StudentasRanka& operator=(const StudentasRanka& other) {
           if (this != &other) {
               vardas = other.vardas;
               pavarde = other.pavarde;
               pazymiai = other.pazymiai;
               egzaminas = other.egzaminas;
               vidurkis = other.vidurkis;
               mediana = other.mediana;
               rezultatasv = other.rezultatasv;
               rezultatasm = other.rezultatasm;
           }
           std::cout<<"Kopijavimo priskirties operatorius iskviestas " << vardas << " " << pavarde << "\n";
           return *this;
       }
   
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
   
    ~StudentasRanka(){
                        std::cout<<"Iskviestas destruktorius " << vardas << " " << pavarde << "\n";
                        pazymiai.clear();};
       friend std::ostream& operator<<(std::ostream& os, StudentasRanka& student);
       friend std::istream& operator>>(std::istream& is, StudentasRanka& student);

private:
    float galutinisVidVectorRanka();
    float galutinisMedVectorRanka();
};

class Studentas : public Zmogus {
    private:
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    float vidurkis, mediana, rezultatasv, rezultatasm;

    public:
    Studentas(const std::string& vardas ="", const std::string& pavarde = "", const std::vector<int>& pazymiai = {}, int egzaminas = 0)
    : vardas(vardas), pavarde(pavarde), pazymiai(pazymiai), egzaminas(egzaminas),
      rezultatasv(galutinisVidVector()), rezultatasm(galutinisMedVector())
 {
        std::cout << "Parametrizuotas konstruktorius iskviestas\n";
}

    Studentas(const Studentas& other)
        : vardas(other.vardas), pavarde(other.pavarde), pazymiai(other.pazymiai), egzaminas(other.egzaminas),
          vidurkis(other.vidurkis), mediana(other.mediana), rezultatasv(other.rezultatasv), rezultatasm(other.rezultatasm) {
          std::cout << "Kopijavimo konstruktorius iskviestas " << vardas << " " << pavarde << "\n"; }

    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            pazymiai = other.pazymiai;
            egzaminas = other.egzaminas;
            vidurkis = other.vidurkis;
            mediana = other.mediana;
            rezultatasv = other.rezultatasv;
            rezultatasm = other.rezultatasm;
        }
        std::cout<<"Kopijavimo priskirties operatorius iskviestas " << vardas << " " << pavarde << "\n";
        return *this;
    }

    std::string getVardas() const override {
        return vardas;
    }
    std::string getPavarde() const override {
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

    ~Studentas(){
                    std::cout<<"Iskviestas destruktorius " << vardas << " " << pavarde << "\n";
                    pazymiai.clear(); };

private:
    float galutinisVidVector() const {return 0; };
    float galutinisMedVector() const {return 0; };
};

class Studentas2 : public Zmogus {
    private:
    std::string vardas, pavarde;
    std::list<int> pazymiai;
    int egzaminas;
    float vidurkis, mediana, rezultatasv, rezultatasm;

    public:
    Studentas2(const std::string& vardas ="", const std::string& pavarde = "", const std::list<int>& pazymiai = {}, int egzaminas = 0)
    : vardas(vardas), pavarde(pavarde), pazymiai(pazymiai), egzaminas(egzaminas),
      rezultatasv(galutinisVidList()), rezultatasm(galutinisMedList())
 {
}
    Studentas2(const Studentas2& other)
        : vardas(other.vardas), pavarde(other.pavarde), pazymiai(other.pazymiai), egzaminas(other.egzaminas),
          vidurkis(other.vidurkis), mediana(other.mediana), rezultatasv(other.rezultatasv), rezultatasm(other.rezultatasm) {
          std::cout << "Kopijavimo konstruktorius iskviestas " << vardas << " " << pavarde << "\n"; }

    Studentas2& operator=(const Studentas2& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            pazymiai = other.pazymiai;
            egzaminas = other.egzaminas;
            vidurkis = other.vidurkis;
            mediana = other.mediana;
            rezultatasv = other.rezultatasv;
            rezultatasm = other.rezultatasm;
        }
        std::cout<<"Kopijavimo priskirties operatorius iskviestas " << vardas << " " << pavarde << "\n";
        return *this;
    }

    std::string getVardas() const override {
        return vardas;
    }
    std::string getPavarde() const override {
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

    ~Studentas2(){
                    std::cout<<"Iskviestas destruktorius " << vardas << " " << pavarde << "\n";
                    pazymiai.clear();};


private:
    float galutinisVidList() const{return 0; };
    float galutinisMedList() const{return 0; };
};

#endif // MYLIB_H
