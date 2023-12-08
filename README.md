# Ieva-MarijaDM2-1.1 1.0
Vartotojui yra pateikiamas pasirinkimas - surašyti duomenis rankiniu būdu arba nuskaityti duomenis iš failo:
1) Pasirinkus ranka: įvedamas norimas studentų kiekis ir tada, naudojantis įvesties metodu (anksčiau visa tai atlikdavo funkcija ivesk()), tiek kartų atitinkamai programa prašys vartotojo įvesti šiuos duomenis apie studentą: vardą pavardę, duos pasirinkimą suvesti studento pažymius bei egzamino rezultatą pačiam arba juos leisti sugeneruoti programai. Tada programa apskaičiuos kiekvieno studento galutinį balą pagal vidurkį bei pagal medianą. Rezultatai rūšiuojami pagal studentų pavardes. Paskui su išvesties metodo pagalba mes į konsolę išvedame lentelę su surašytų studentų šiais duomenimis: kur saugoma ši informacija (adresas), studento vardas, pavardė, galutinis balas pagal vidurkį bei medianą.
2) Pasirinkus nuskaityti: Programa duoda pasirinkimą: nuskaityti iš anksto paruoštus failus ar sugeneruoti juos šią akimirką. Pasirinkus generavimą duodamas list arba vector konteinerių pasirinkimas ir tada programa sukuria atitinkamai su pasirinktu konteineriu 5 skirtingus failus, kuriems sugeneruoja atitinkamai 1000, 10000, 100000, 1000000 ir 10000000 įrašų. Tada kiekvieną iš šių failų ji surūšiuoja pagal esančias pavardes didėjimo tvarka. Visi šie įrašai yra išsaugomi failuose s_1000.txt, s_10000.txt, ... .(*) Tai atlikusi programa imasi duomenų išskaidymo į dar du failus: lygina stulpelyje "galutinis(vid.)" esančius duomenis ir juos išskaido į "vargšiukus" arba "kietiakius", priklausomai nuo galutinio balo dydžio - vargšiukai yra tie, kurių g.b. yra mažesnis nei 5, o kietiakai yra tie, kuriu g.b. yra didesnis arba lygus 5. Šie procesai taikomi atitinkamai kiekvienam sugeneruotam failui. Galiausiai mes skaičiuojame programos veikimo laiką - kiek užtrunka mus dominanti funkcija. Sukame ciklą - leidžiame funkcijas 5 kartus ir jų veikimo laiką imame vidurkį šių 5kartų, kad duomenys būtų tikslesni. Pasirinkus iš anksto sugeneruotus failus, programa atlieka darbą nuo ( *).
3) Programa optimizuota naudojantis 3 strategija - ši strategija yra sparčiausia. Šioje strategijoje rūšiavimo principas yra kaip ir 2-oje strategijoje: vargšiukai išskirstomi į naują vektorių, o kietiakai pasilieka studentų vektoriuje.
4) Gauti duomenys yra saugomi atitinkamose class'ėse. Įvesti ranka duomenys klasėje StudentasRanka, vector tipo duomenys - Studentas, list - Studentas2.
5) Kiekvienoje iš šių klasių matome destruktorių, kopijavimo konstruktorių, kopijavimo priskirties operatorių. Kiekvieną sykį, kai yra iškviesti šie metodai - konsolėje matome atitinkamai frazes: Iskviestas destruktorius <studento vardas pavarde>, kopijavimo konstruktorius iskviestas <studento vardas pavarde>, kopijavimo priskirties operatorius iskviestas <studento vardas pavarde>.
6) Rankiniu būdu įvedus duomenis:
    ![naujas](https://github.com/ieva-marija/Ieva-MarijaDM2-1.2/assets/144428382/a8514c0a-d407-4c57-aaa4-3575c7644f13)
7) Pasirinkus nuskaityti duomenis iš failo:
   a) pirmieji duomenys:![sdsa](https://github.com/ieva-marija/Ieva-MarijaDM2-1.2/assets/144428382/229996b9-3033-409d-834e-922c6d7208f3)

   b) laiko išmatavimas su 1000 studentų duomenimis: ![scs](https://github.com/ieva-marija/Ieva-MarijaDM2-1.2/assets/144428382/2fa59445-9080-464d-b1ed-030c099fe263)






Testavimo sistemos parametrai: Procesorius: 4CPUs, ~2.5GHz, Atmintis: 8192MB RAM (7568 naudojama), SSD 
