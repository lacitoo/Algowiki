using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace komb
{
    class Program
    {
        static bool hatar(int[] array, int[] prev, int[] next, int n, int m)
        {
            bool max = true;
            bool min = true;
            int[] first = new int[m];
            int[] last = new int[m];
            for (int i = 0; i < m; i++)
            {
                first[i] = i + 1;
                last[i] = n - m + i + 1;
                min = min && array[i] == first[i];
                max=max && array[i] == last[i];
            }
            for (int i = 0; i < m; i++)
            {
                if (max)
                {
                    next[i] = first[i];
                }
                if (min)
                {
                    prev[i] = last[i];
                }
            }
            
            return min || max;
        }
        static void step(int[] array, int stp, int ind, int n, int m)
        {
            int maybe = array[ind] + stp;
            if (((ind > 0 && maybe > array[ind - 1]) || (ind == 0 && maybe >= 1)) && maybe <= n - (m - ind) + 1)//n-m+ind+1
            {
                array[ind] = maybe;
            }
            else
            {
                if (ind > 0)
                {
                    step(array, stp, ind - 1, n, m);
                    if(stp>0)
                        array[ind] = array[ind - 1] + 1;
                    if (stp < 0)
                        array[ind] = n - m + ind + 1;
                }
                else
                {
                    ;
                }
            }
        }
        static void print(int[] array, int m)
        {
            for (int i = 0; i < m; i++)
            {
                Console.Write(array[i] + " ");
            }
            Console.WriteLine();
        }

        static void Main(string[] args)
        {
            int n, m;
            string[] s = Console.ReadLine().Split();
            n = int.Parse(s[0]);
            m = int.Parse(s[1]);
            int[] x = new int[m];
            int[] prev = new int[m];
            int[] next = new int[m];
            s = Console.ReadLine().Split();
            for (int i = 0; i < m; i++)
            {
                x[i] = int.Parse(s[i]);
                prev[i] = int.Parse(s[i]);
                next[i] = int.Parse(s[i]);
            }

            step(prev, -1, m - 1, n, m);
            step(next, +1, m - 1, n, m);
            hatar(x, prev, next, n, m);
            print(prev,m);
            print(next,m);
            Console.ReadLine();
        }
    }
}
//2.bead 41/60 rekurzív megoldás, lefele lépésnél hiba
//3.bead 54/60 előző javítva, határokon hiba
//4.bead 60/60 előző javítva