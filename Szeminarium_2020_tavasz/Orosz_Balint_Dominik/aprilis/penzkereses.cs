using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace penzkereses
{
    class Program
    {
        static void Main(string[] args)
        {
            int N, P;
            string[] sor = Console.ReadLine().Split(' ');
            N = Convert.ToInt32(sor[0]);
            P = Convert.ToInt32(sor[1]);

            List<int> szamok = new List<int>();
            sor = Console.ReadLine().Split(' ');
            for (int i = 0; i < sor.Length; i++)
            {
                szamok.Add(Convert.ToInt32(sor[i]));
            }

            int min = int.MaxValue;

            int current = P;
            int first = 0;

            List<int> values = new List<int>();

            for (int i = 0; i < szamok.Count; i++)
            {
                current -= szamok[i];

                if (current <= 0)
                {
                    int napok = i - first + 1;
                    values.Add(napok);

                    if (napok < min)
                    {
                        min = napok;
                    }

                    while (current <= 0 && first < szamok.Count)
                    {
                        current += szamok[first];
                        first++;
                    }

                    int j = i + 1;

                    while (current <= 0)
                    {
                        current -= szamok[j];
                        j++;
                    }
                    napok = j - first + 1;
                    values.Add(napok);

                    if (napok < min)
                    {
                        min = napok;
                    }
                }
            }

            Console.WriteLine(min);
        }
    }
}
