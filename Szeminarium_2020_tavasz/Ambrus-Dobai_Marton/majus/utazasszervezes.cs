using System;
using System.Collections.Generic;

namespace utazas
{
    class Program
    {
        static List<int> setup(ref int n, ref int k, ref int m, ref int c)
        {
            string[] s = Console.ReadLine().Split();
            n = int.Parse(s[0]);
            k = int.Parse(s[1]);
            m = int.Parse(s[2]);
            c = int.Parse(s[3]);
            List<int> intervallum = new List<int>();
            s = Console.ReadLine().Split();
            foreach (string item in s)
            {
                intervallum.Add(int.Parse(item));
            }
            return intervallum;
        }

        static void Main(string[] args)
        {
            int n=0, k=0, m=0, c=0, sum=0;
            List<int> intervallum = setup(ref n, ref k, ref m, ref c);
            for (int i = 0; i < n; i++)
            {
                int csoport_db = 0;
                int veg = 0;
                for (int j = 0; j < c; j++)
                {
                    if (intervallum[j] > veg)
                    {
                        veg = intervallum[j] + m-1;
                        intervallum[j]=0;
                        csoport_db++;
                    }
                }
                sum += csoport_db;
            }
            Console.WriteLine(sum);
        }
    }
}