/* FELADAT:

Egy társasház közös költségének egy adott évben történt befizetéseit egy szöveges
állományban tároljuk. Minden lakás minden befizetése egy-egy sor az állományban,
amelyik tartalmazza a lakás azonosítóját (sztring), a befizetés dátumát (EEEE.HH.NN
formájú sztring) és összegét (természetes szám). Egy soron belül az adatokat
elválasztójelek (szóközök, tabulátor jelek) határolják egymástól. A sorok a
lakásazonosítók szerint, azon belül a befizetési dátumok időrendje szerint rendezettek.

Példa néhány egymást követő sorra:

    *   IV.ép.I.lh.8.em.12. 2014.01.05 23000
    *   IV.ép.I.lh.8.em.12. 2014.02.06 24500
    *   IV.ép.I.lh.9.em.1. 2014.02.06 27500

Megfelelt szintű (közepes) a munkája akkor, ha
    *   kilistázza a képernyőre, hogy az egyes lakások mennyit fizettek be eddig,
    *   keres olyan lakást, amelyik sosem fizetett egymást követően ugyanakkora összeget.

Ezeken kívül a programja kielégíti az alábbi követelményeket:

    *   nemcsak az érvényes tesztesetekre működik helyesen a programja (itt felteheti,
    hogy a lakás azonosítója egyetlen, elválasztójeleket nem tartalmazó sztring, és
    az állomány minden sora a megadott módon van kitöltve), hanem a nem létező fájl
    esetét is lekezeli.
    *   a program ciklusai tanult programozási tételekből származnak;
    *   egy osztályt készít a szöveges állomány olvasásához;
    *   a szöveges állományt csak egyszer nyitja meg olvasásra és nem használ a szöveges
    állomány sorainak számától függő méretű változót.

Kiválóan megfelelt szintű a munkája akkor, ha a megfelelt szinten túl:

    *   a befizetések két, a fent megadott formájú szöveges állományban helyezkednek el,
    *   egy tanuló neve tetszőleges számú tagból, szóközökkel és/vagy tabulátor jelekkel
    elválasztott részekből állhat.
*/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
Az enumot a hibakezelésre alkalmazzuk. az "enum" parancs létrehoz egy egy új típust (mint
az int stb), melynek minden lehetséges értékét mi adjuk meg. A feladat azt kéri, hogy az
üres fájlt és a rosszul megadot fájlnevet us tudjuk kezelni, így ezeket rakom bele a típusomba,
melynek az Exception nevet adom.
*/

enum Exception {WRONG_INPUT, NEGATIVE_COUNT, EMPTY_FILE};

/*
A Flat osztály fog felelni a fájlből beolvasott sorok tárolásáért. A feladat szerint lesz:

    *   lakás azonosítója (sztring)
    *   befizetés dátuma (EEEE.HH.NN formájú sztring) <--- ami nekünk fontos az az hogy string.
    *   és összege (természetes szám)

Ezek az adatok nekünk nagyon fontosak, annyira, hogy meg is akarjuk védeni őket, ezért
PRIVÁTTÁ tesszük őket a "private:" paranccsal.
    ---> minden adattag és tagfüggvény privát, ami a private: után van írva.
Azon adattagokhoz, melyek privátak, csak maga az osztály tagfüggvényei / adattagjai férhetnek
hozzá.
    ---> ha "tmp" egy "Flat" típusú változó, akkor közvetlenül nem tudjuk tmp.flatID-t megvál-
    toztatni.
Mivel értelmetlen lenne teljesen elvágnunk magunkat ezektől az adatoktól, így biztosítunk egy
alternatív utat ahhoz, hogy ezekhez hozzáférhessük:

    *   "friend" függvényekkel (vagy osztályokkal, de itt ilyet nem alkalmaztunk)
    *   publikus tagfüggvényekkel.

Hogy kényelmesen tudjunk beolvasni, a beolvasóoperátorunkat (ld. lejjebb) friend-é tesszük.
Ezáltal ez a függvény hozzá fog tudni férni a privát adattagjainkhoz is.
Továbbá létrehozunk un. get/set függvényeket is, melyeket publikussá teszünk.
    ---> minden adattag és tagfüggvény publikus, mely public: után van írva.

--->a class közel ugyanaz mint a struct, csak ez utóbbinak minden adattagja alapértelmezetten
publikus, míg a classnak alapértelmezetten mindenadattagja privát.
*/
class Flat
{
private:
    string flatID;
    string date;
    int input;

public:
    //set függvények
    void set_flatID (const string tmp)
    {
        flatID = tmp;
    }
    void set_date (const string tmp)
    {
        date = tmp;
    }
    void set_input (const int tmp)
    {
        input = tmp;
    }

    //get függvények
    string get_flatID () const  //  a függvény paraméterei után írt const kulcsszóval mi
    {                           //  ígéretet teszünk a fordítónak, hogy az adott függvénnyel
        return flatID;          //  nem fogjuk megváltoztatni az osztály adattagjait.
    }                           //  ez különösen const Flat változóknál lenne fontos.
    string get_date () const
    {
        return date;
    }
    int get_input () const
    {
        return input;
    }

    friend istream& operator>>(istream& in, Flat& o);
};

/*
A FlatGroupedByFlatID osztály, nevéből adódóan fog felelni azért, hogy csoportosítani tudjuk
az azonos lakáshoz tartozó bemeneteket. Feladatleírás alapján két adatot kell majd megállapítani:
    *   az adott lakás neve (string)
    *   az általa befizetett pénz szummája (int)
*/

class FlatGroupedByFlatID
{
private:
    string flatID;
    int sum;

public:
/*
Ez egy un. konstruktor. Minden típusnak létezik konstruktora, és minden osztálynak is, még ha
mi magunk is hozzuk létre: ha nem írjuk meg, akkor a fordító teszi meg nekünk. konstruktort csak
egyféleképp definiálhatunk: (ami a mi szempontunkból fontos)

    <osztály neve>( <paraméterek> ) : <inicializációs lista> {<egyéb mókák>}

Az inicializációs lista mondja meg, hogy az adott adattagokat milyen értékkel inicializáljuk.
Az inicializációs listát használni nem kötelező, de célszerű, mert nélküle először létrehozzuk az
adattagot, és utána adnánk neki értéket. Így egyből létrehozáskor az adott értéket kapja.
Nem kell minden tagra írni valamit, a fordító elvégzi ezt a munkát helyettünk!
    !!!INICIALIZÁCIÓS LISTÁBAN TARTANI KELL AZ ADATTAGOK SORRENDJÉT!!!

class X
{
    int x;
    int y;
public:
    X(int a, int b) : y(a) x(y) {}
};

Ekkor x memóriaszemetet kapna, mert y még nem volt inicializálva. Minden adattag sorrend szerint lesz
létrehozva.
*/
    FlatGroupedByFlatID() : sum(0){}

    //set függvények
    void set_flatID (const string tmp)
    {
        flatID = tmp;
    }
    void add_sum (const int tmp)
    {
        sum += tmp;
    }
    void reset()
    {
        sum=0;
    }

    //get függvények
    string get_flatID () const
    {
        return flatID;
    }
    int get_sum () const
    {
        return sum;
    }

    friend ostream& operator<<(ostream& out, const FlatGroupedByFlatID& o);
};

/*
Ez egy un. overload, egészen pontosan a >> operátor overloadja. Az overload annyit tesz, hogy a
függvény neve nem változik, de mások lesznek a paraméterei, pl.

int hello (int a, int b)
{
    <minden jó>
}

int hello (string a, string b)
{
    <kibaszott progtételek>
}

Itt attól függ hogy melyik függvény hívódik meg, hogy milyen paramétereket adunk meg. A >> operátor,
melyet főleg beolvasásra használunk, többnyire 2 adatot kér be: bal oldalról egy beolvasó típusú
változót (pl. cin) és bal oldalról azt a változót, melyet be kell olvasni. Ez a beolvasó típust
függvénynél az "istream"-el kérhetünk el, ahogy lentebb is látható (melyet szokás referenciával
átvenni, így kevesebbet kell dolgoznia a programnak.

FYI:

    *   referencia szerinti átvétel: nem az adott változó ÉRTÉKÉT, hanem az ahhoz tartozó memória-
    helyet kérjük el. Ekkor ha megváltoztatjuk függvényen ennek a változónak az értékét, akkor az
    eredeti változó is új értéket kap. Gyakorlatialg olyan, mintha magát a változót vennénk át.
        ---> "&" operátorral tehetjük meg
    *   érték szerinti átvétel: magát a változót nem, csak a hozzá tartozó értéket vesszük át.
    Ekkor nem memóriahelyet, hanem értéket kapunk, amit át kell másolni. Ez gyakran kölcségesebb,
    mint a memória szerinti átvétel.

Amennyiben az az "in" zavaró, gondoljunk arra, hogy ha azt írjuk hogy

    Flat sajt;
    cin >> sajt;

minden o sajt-ra, minden in cin-re fog változni.

A végén azért kell return-ölni a beolvasó operátort, hogy az egymásba ágyazott beolvasás
(cin >> a >> b; stb) tudjon működni.
*/

istream& operator>>(istream& in, Flat& o)
{
    in >> o.flatID >> o.date >> o.input;
    if (o.input < 0)
    {
        throw NEGATIVE_COUNT; //róla majd később
    }
    return in;
}

/*
Ugyanez, csak a << operatort overloadoljuk.
*/
ostream& operator<<(ostream& out, const FlatGroupedByFlatID& o)
{
    out << "A \"" << o.flatID << "\" lakashoz tartozo befizetett osszeg: " << o.sum;
    return out;
}

/*
Ez a nevezetes felsorolónk. Adattagjaihoz kicsi magyarázat:

    *   f egy fájlbeolvasó változó. Azért érdemes adattagként eltárolni, mert ha nem tennénk,
    akkor minden alkalommal amikor be akarunk olvasni, újra definiálnunk kéne, ami túl azon
    hogy értelmetlen pazarlás, megírni is fárasztó :'(
    *   actual tárolja majd az éppen beolvasott sor adatait.
    *   grouped tárolja majd azokat az adatokat, amelyekre a main függvény kíváncsi. Ez ugye
    az adott lakás neve, és a hozzá tartozó összesen befizetett pénz.
    *   isFinished azért célszerű, mert ez egy kevésbé gyomorforgató módszere annak, hogy
    jelezzük, mikor ért véget a fájl. (GT módszeréhez képest, norm/abnorm is cancer)
*/

class Enumerator
{
    fstream f;
    Flat actual;
    FlatGroupedByFlatID grouped;
    bool isFinished;
public:

    bool isNotSame; //publikussá tettem, mert nem volt kedvem get/set fv-t írni hozzá c:

    //Figyeljük meg, hogy az inicializációs lista tartja a sorrendet!
    Enumerator(const string filename) :   f (filename.c_str()), isFinished (false), isNotSame (true)
    {
        if (f.fail())
        {
            throw WRONG_INPUT;
        }
    }

    void first()
    {
        f >> actual;
        if (f.fail())
        {
            throw EMPTY_FILE;
        }
        next();
    }
/*
Mivel a függvényünkben a while ciklus akkor áll le ha

    *   sikertelen volt a beolvasás
    VAGY
    *   újabb házhoz értünk

Le kell ellenőriznünk, hogy a beolvasáson halt-e el a dolog. Ha igen, akkor végeztünk, és a
return paranccsal ki is léphetünk a függvényből. Ha nem, akkor beállítjuk grouped-ban azt, hogy
milyen lakásnévvel fogunk foglalkozni, és mivel ezt az értékadást csak egyszer tesszük meg,
az újabb beolvasásoknál tudni fogjuk, hogyha új lakáshoz értünk el, mert össze tudjuk hasonlítani
vele.

"tmp" fog majd ügyelni azért, hogy figyeljük, volt e két azonos egymást követő befizetés.
*/
    void next()
    {
        if (f.fail())
        {
            isFinished = true;
            return;
        }

        isNotSame = true;
        int tmp = actual.get_input();

        grouped.set_flatID(actual.get_flatID());
        grouped.reset();

        while (!f.fail() && actual.get_flatID() == grouped.get_flatID())
        {
            grouped.add_sum(actual.get_input());
            f >> actual;
            if (tmp == actual.get_input() && !f.fail() && actual.get_flatID() == grouped.get_flatID())
            {                                       //ügyel arra, hogy az egyetlen befize-
                isNotSame = false;                  //téssel operáló lakások is igazak le-
            }                                       //gyenek.
            tmp = actual.get_input();
        }
    }

    bool isEnd() const
    {
        return isFinished;
    }

    FlatGroupedByFlatID current() const
    {
        return grouped;
    }
};

/*
Ide elérkezvén már nagyon jó dolgunk van, a main függvényünk csak nagyon minimális információhoz
fér hozzá, és csak ennyire is van szüksége. Csupán annyit kell még megírni benne, hogy kiírasson
mindent, csináljon egy pesszimista keresést (ugye itt az isNotSame változóra vadászunk, mely igazra
lett beállítva ha NEM volt két egymást követő befizetés).

Amiről még beszélni érdemes, az a try-catch dolog. Amikor azt írjuk hogy

    try
    {
        <móka>
    }catch (<kihajított elem típusa> <változónév>)
    {
        <egyéb móka>
    }

akkor a <móka> kódrészletet nem csak lefutattjuk, hanem megpróbáljuk lefutattni: lehetőséget adunk
arra, hogy a "throw" paranccsal megszakítsuk a kód futtatását, és a kidobott elemtől függően (melyet
nevéből adódóan "catch" fog elkapni) az <egyéb móka> fut le.

Képzeljük el ezt úgy, mintha egy lasagnáról beszélnénk. Megpróbáljuk megenni a lasagna-t, és neki is
látunk. A felső réteg okénak néz ki, így annak egy részét megesszük, és azalatt mégegy réteget találunk
(ekkor létünk egy függvényből egy másik függvénybe, "egyre mélyebbre megyünk velük"), ami szintén e-
hetőnek tűnik, így eszünk abból is. Aztán találunk mégegy réteget, az is jónak tűnik, azt is elkezdjük
rágcsálni, de abba valami nem ízlik, szóval inkább kihányjuk az egészet, rá a lasagna tetejére. Itt
a lasagna teteje catch-elt.
*/

int main()
{
    try
    {
        Enumerator en("test.txt");

        bool l = false;
        for (en.first(); !en.isEnd(); en.next())
        {
            cout << en.current() << endl;
            if (l == false && en.isNotSame)
            {
                l = true;
                cout << "Ez a lakas tovabba teljesiti a feltetelt." << endl << endl;
            }
        }
    }catch (Exception e)
    {
        switch(e)
        {
        case WRONG_INPUT:
            {
                cout << "A megadott fajl nem letezik!" << endl;
                return 1;
            }
        case EMPTY_FILE:
            {
                cout << "A megadott fajl ures!" << endl;
                return 1;
            }
        case NEGATIVE_COUNT:
            {
                cout << "Negativ szam!" << endl;
                return 1;
            }
        }
    }
    return 0;
}

//NOTE: Ahova lehet const-ot írni, oda const-ot KELL írni!
