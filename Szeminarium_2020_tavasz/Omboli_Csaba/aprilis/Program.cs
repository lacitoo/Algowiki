using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nt1_nyaralás
{
    class Program
    {
        static void Main(string[] args)
        {
            int penzunk;
            string [] seged=  Console.ReadLine().Split(' ');
            penzunk = int.Parse(seged[0]);
            int[] napok = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
           
            bool van = false;
            int mego=0;
            int i = 0;
            while (i < napok.Length && !van)
            {
                int j = 0;
                while (j < i && !van)
                {
                    int osszeg = 0;
                    for (int k = j; k < j + (napok.Length - i) + 1; k++)
                    {
                        osszeg += napok[k];
                    }
                    mego = napok.Length - i + 1;
                    van = osszeg < penzunk || osszeg==penzunk;
                    j++;
                }

                i++;
            }
            
            Console.WriteLine(mego);
            
            Console.ReadKey();
        }
    }
}
