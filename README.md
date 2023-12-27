# Ieva-MarijaDM2-1.1 1.1
Vartotojui yra pateikiamas pasirinkimas - surašyti duomenis rankiniu būdu arba nuskaityti duomenis iš failo:
1) Pasirinkus ranka: įvedamas norimas studentų kiekis ir tada tiek kartų atitinkamai programa prašys vartotojo įvesti šiuos duomenis apie studentą: vardą pavardę, duos pasirinkimą suvesti studento pažymius bei egzamino rezultatą pačiam arba juos leisti sugeneruoti programai. Tada programa apskaičiuos kiekvieno studento galutinį balą pagal vidurkį bei pagal medianą. Rezultatai rūšiuojami pagal studentų pavardes.
2) Pasirinkus nuskaityti: Programa duoda pasirinkimą: nuskaityti iš anksto paruoštus failus ar sugeneruoti juos šią akimirką. Pasirinkus generavimą duodamas list arba vector konteinerių pasirinkimas ir tada programa sukuria atitinkamai su pasirinktu konteineriu 5 skirtingus failus, kuriems sugeneruoja atitinkamai 1000, 10000, 100000, 1000000 ir 10000000 įrašų. Tada duodamas rūšiavimo pasirinkimas 0 - rūšiavimas pagal vardą, 1 - rūšiavimas pagal pavardę ir 2 - rūšiavimas pagal galutinį balą, pasirinkus norimą skaičių, programa atitinkamai kiekvieną iš šių failų surūšiuoja pagal pasirinktą parametrą. Šie įrašai yra išsaugomi failuose s_1000.txt, s_10000.txt, ..., o pradiniai duomenų variantai (t.y. kiekvieni sugeneruoti namų darbai bei sugeneruotas egzaminas) išsaugomi s0_1000.txt, s0_10000.txt ir t.t. .(*) Tai atlikusi programa imasi duomenų išskaidymo į dar du failus: lygina stulpelyje "galutinis(vid.)" esančius duomenis ir juos išskaido į "vargšiukus" arba "kietiakius", priklausomai nuo galutinio balo dydžio - vargšiukai yra tie, kurių g.b. yra mažesnis nei 5, o kietiakai yra tie, kuriu g.b. yra didesnis arba lygus 5. Šie procesai taikomi atitinkamai kiekvienam sugeneruotam failui. Galiausiai mes skaičiuojame programos veikimo laiką - kiek užtrunka mus dominanti funkcija. Sukame ciklą - leidžiame funkcijas 5 kartus ir jų veikimo laiką imame vidurkį šių 5kartų, kad duomenys būtų tikslesni. Pasirinkus iš anksto sugeneruotus failus, programa atlieka darbą nuo ( *).
3) Programa optimizuota naudojantis 3 strategija - ši strategija yra sparčiausia. Šioje strategijoje rūšiavimo principas yra kaip ir 2-oje strategijoje: vargšiukai išskirstomi į naują vektorių, o kietiakai pasilieka studentų vektoriuje.
4) Gauti duomenys yra saugomi atitinkamose class'ėse. Įvesti ranka duomenys klasėje StudentasRanka, vector tipo duomenys - Studentas, list - Studentas2.
5) Struct ar Class?
   1. Kai programoje naudojome 'struct', vektoriaus tipą ir 100000 bei 1000000 apimties duomenis, programos laikas: ![3strategijoskonsole](https://github.com/ieva-marija/Ieva-MarijaDM2-1.2/assets/144428382/4cfc8f73-b203-40d3-879d-6cfa00d01dbb)
   2. Kai programoje naudojome 'class', vektoriaus tipą ir 100000 bei 1000000 apimties duomenis, programos laikas: ![class](https://github.com/ieva-marija/Ieva-MarijaDM2-1.2/assets/144428382/76f978de-e100-4541-a2a9-7a0d125f749a)
  
Matome, kad naudojant 'class' programos veikimo laikas buvo nežymiai ilgesnis nei naudojant 'struct'. 
  
6) Eksperimentinė analizė priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3. Naudojome vector tipą ir 100000 bei 1000000 apimties duomenis.
   1. o1: ![o1flagas](https://github.com/ieva-marija/Ieva-MarijaDM2-1.2/assets/144428382/fa571401-c6f9-4070-b036-fbaef67b632e) exe failo dydis: 120KB
   2. o2: ![o2flagas](https://github.com/ieva-marija/Ieva-MarijaDM2-1.2/assets/144428382/7a89654a-d3c7-487d-8b41-e99c4baba118) exe failo dydis: 119KB
   3. o3: ![o3flagas](https://github.com/ieva-marija/Ieva-MarijaDM2-1.2/assets/144428382/1f198b17-4b5b-461e-8aa8-ca4c31510f3d) exe failo dydis: 119KB
   
  o2 flag'as iš testuotų, buvo lėčiausias, o3 ir o1 buvo spartesni, o3 nežymiai spartesnis už o1. exe failų dydžiai o2 ir o3 vienodi, o1 nežymiai didesnis. 





Testavimo sistemos parametrai: Procesorius: 4CPUs, ~2.5GHz, Atmintis: 8192MB RAM (7568 naudojama), SSD 
