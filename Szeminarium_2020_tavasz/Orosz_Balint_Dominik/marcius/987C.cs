using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace displays
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 0;
            n = Convert.ToInt32(Console.ReadLine());
 
            int[] s = new int[n];
            int[] c = new int[n];
 
            string[] sor = Console.ReadLine().Split(' ');
 
            for (int i = 0; i < n; i++)
            {
                s[i] = Convert.ToInt32(sor[i]);
            }
            sor = Console.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                c[i] = Convert.ToInt32(sor[i]);
            }
 
            List<int> jok = new List<int>();
 
            for (int i = 0; i < n; i++)
            {
                int m = int.MaxValue;
                for (int j = i + 1; j < n; j++)
                {
                    if (s[i] < s[j] && c[j] < m)
                    {
                        m = c[j];
                    }
                }
                jok.Add(m);
            }
 
 
            int min = int.MaxValue;
 
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (s[i] < s[j] && jok[j] != int.MaxValue)
                    {
                        int value = c[i] + c[j] + jok[j];
                        if (value < min)
                        {
                            min = value;
                        }
                    }
                }
            }
 
            if(min == int.MaxValue)
            {
                Console.WriteLine(-1);
            }
            else
            {
                Console.WriteLine(min);
            }
 
            Console.ReadLine();
        }
    }
}