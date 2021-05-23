# map-editor

## Ambice
Cílem projektu bude vytvořit intiutivní nástroj pro editaci stávajících map Spellcrossu pro ostatní nadšence. Primárně by mělo jít o možnost měnit rozmístění jednotek na mapě a udělat hru trošku težší. Nedílnou součástí bude taky zdokumentování jednotlivých souborů a jejich obsahu.

Doufám že dokonce roku 2021 vznikne nějaký použitelný výsledek.

## Současný stav
* načtení obrázku s mapou
* vygenrování sítě s číslem políčka (žluté), políčko s nepřítelem (červené); síť je "plochá" a nekopíruje terénní nerovnosti
* načtení a zobrazeí skriptu mapy
* seznam všech nepřátel na mapě
* 

## Ukázka

![gui](https://github.com/spellcross/map-editor/blob/master/img/editor.png)

## Definice mapy - soubory Mxx_yyA.DEF
Ukázka souboru M02_02A.DEF
Patrné dvě části *MissionData* a *MissionParameters*. Text lze pak dohledat v adresáři *Texts*.
Textové soubory nějaké obstarožní kódování, tak tady hezky přepisuju diakritiku, ale asi se na to vykašlu a bude to po cesky.
```
MissionData {
    MissionMap(M02_02)
    AddUnit(50,37,1910,0,100,NormalUnit,-)
    AddUnit(51,37,1865,0,100,NormalUnit,-)
    AddUnit(52,37,1955,0,100,NormalUnit,-)
    AddUnit(54,38,1307,0,100,NormalUnit,-)
    AddUnit(55,38,1351,0,100,NormalUnit,-)
    AddUnit(57,37,1658,0,100,WaitForContact,-)
    AddUnit(58,37,1704,0,100,WaitForContact,-)
    AddUnit(59,37,1614,0,100,WaitForContact,-)
    AddUnit(60,48,0626,0,100,PatrolUnit,-)
    AddUnit(61,48,2192,0,100,PatrolUnit,-)
    AddUnit(62,41,1567,0,20,WaitForContact,-)
    AddUnit(63,41,1613,0,20,WaitForContact,-)
    AddUnit(64,38,1909,0,100,NormalUnit,-)
    AddMissionObjective(DestroyAllUnits,Zniční všech jednotek)
    AddStartSquare(0637,0682,0687,0726,0728,0730,0732,0771,0773,0775)
    AddStartSquare(0776,0778,0815,0817,0819,0820,0821,0823,0862,0864)
    AddStartSquare(0865,0866,0867,0906,0908,0909,0910,0911,0912,0952)
    AddStartSquare(0954,0955,0956,0957,0997,0999,1000,1001,1044,1045)
    AddStartSquare(1046,1088,1089,1090,1134,1135,1136,1179,1180,1225)
}
 
MissionParameters {
    Time(t)
    MissionText(T02_02A)
    MissionStartText(T02_02A.S)
    MissionEndOKText(T02_02A.OK)
    MissionEndBadText(T02_02A.BAD)
}
```
 

### AddUnit
```
AddUnit(51,37,1865,0,100,NormalUnit,-)
AddUnit(57,37,1002,0,100,WaitForContact,-)
AddUnit(58,48,2142,0,100,PatrolUnit,-)
AddUnit(50,55,3291,0,10,ToughDefence,-)

AddUnit(50,68,0913,8,1,,Tronndor)
AddUnit(76,38,1885,10,100,,Elitní Ka-Orkové)
AddUnit(99,43,0792,10,20,,Elitní Arachnoidi)
```
Jednotlivé parametry:
* ID jednotky na mapě (hráč čísla 1-49), nepřítel 50-99 (čekal jsem něco jako 127(8), ale víc než 99 podle mě nejde)
* typ jednotky
* políčko na mapě
* nejspíš level jednotky
* velikost jednotky (počet členů, orci 100, vlčí jezdci 20, atd.)
* chovíní jednotky (netuším budu muset nějak vyzkoušet a popíšu blíž)
* název jednotky




## Poděkování
Velký dík patří Stanislavu Mašláňovi a jeho stránkám [spellcross.kvalitne.cz](http://spellcross.kvalitne.cz/), kde má svoje prográmky na práci s datovými soubory hry.
