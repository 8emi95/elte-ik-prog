using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace progtetel_fels
{
    class Program
    {
        static void Main(string[] args)
        {
            //tomb
            int[] t = { 1, 3, 5, 3, 6, 2, 7 };
            
            //lista
            List<int> l = new List<int>();
            l.Add(4);
            l.Add(-5);
            l.Add(2);
            l.Add(4);
            l.Add(-3);

            //asszociativ tomb
            Dictionary<int, String> d = new Dictionary<int, string>();
            d[1] = "egy";
            d[3] = "harom";
            d[2] = "ketto";
            d[5] = "ot";

            System.Console.WriteLine("--== KIÍRÁS ==--");
            System.Console.WriteLine("t tömb:");
            foreach (int i in t)
                System.Console.Write(i + " ");
            System.Console.WriteLine();

            System.Console.WriteLine("l lista:");
            foreach (int i in l)
                System.Console.Write(i + " ");
            System.Console.WriteLine();

            System.Console.WriteLine("d dictionary (kulcsok):");
            foreach (int i in d.Keys)
                System.Console.Write(i + " ");
            System.Console.WriteLine();

            System.Console.WriteLine("d dictionary (értékek):");
            foreach (String s in d.Values)
                System.Console.Write(s + " ");
            System.Console.WriteLine();

            System.Console.WriteLine("d dictionary (kulcs-érték párok):");
            foreach (KeyValuePair<int, String> e in d)
                System.Console.Write(e + " ");
            System.Console.WriteLine();

            System.Console.WriteLine("--== ÖSSZEGZÉS TÉTEL ==--");
            System.Console.WriteLine("aggregálok egy függvényt:");
            System.Console.WriteLine(t.Aggregate(0, (s, e) => s + e, e => "A t tömb elemeinek összege: " + e + "."));
            System.Console.WriteLine(d.Aggregate("", (s, e) => s + e.Value, e => "A d dictionary értékeinek összefűzése: " + e + "."));
            System.Console.WriteLine("összegzek:");
            System.Console.WriteLine("Az l lista elemeinek abszolútértékösszege: " + l.Sum(e => Math.Abs(e)) + ".");

            System.Console.WriteLine("--== SZÁMLÁLÁS TÉTEL ==--");
            System.Console.WriteLine("összegzéssel:");
            System.Console.WriteLine("Az l lista pozitív elemeinek száma: " + l.Sum(e => e > 0 ? 1 : 0) + ".");
            System.Console.WriteLine("számlálok:");
            System.Console.WriteLine("Az l lista pozitív elemeinek száma: " + l.Count(e => e > 0) + ".");

            System.Console.WriteLine("--== RENDEZÉS ==--");
            l = l.OrderBy(e => e).ToList();
            System.Console.WriteLine("l lista rendezve:");
            foreach (int i in l)
                System.Console.Write(i + " ");
            System.Console.WriteLine();

            System.Console.WriteLine("--== Egy tulajdonságig eldobok... LINKER FÉLESÉG ==--");
            l.TakeWhile(e => e < 0).ToList(); //nem adtam végül l-nek értékül.
            System.Console.WriteLine("--== KÜLÖNBSÉG ==--");
            l = l.Except(l.TakeWhile(e => e < 0)).ToList();
            System.Console.WriteLine("l lista csak pozitívan:");    //ez most halmazos except volt, nyilván megoldható hogy mindkét 4-es megmaradjon
            foreach (int i in l)
                System.Console.Write(i + " ");
            System.Console.WriteLine();

            System.Console.WriteLine("--== MAXKIV ==--");
            System.Console.WriteLine("A d dictionary értékei közötti leghosszabb szó hossza: " + d.Max(e => e.Value.Length) + ".");

            System.Console.WriteLine("--== LINKER ==--");
            System.Console.WriteLine("A d dictionary 2 kulcsú elemének értéke: " + d.First(e => e.Key == 2).Value + ".");
            System.Console.WriteLine("A d dictionary 4 kulcsú eleme: " + d.FirstOrDefault(e => e.Key == 4) + "."); //First exceptiont dobna

            System.Console.WriteLine("--== KIVÁLOGATÁS ==--");
            int[] ps = l.Where(e => e % 2 == 0).ToArray();
            System.Console.WriteLine("Az l lista páros elemeinek tömbje:");
            foreach (int i in ps)
                System.Console.Write(i + " ");
            System.Console.WriteLine();

            System.Console.ReadKey(true);
        }
    }
}
