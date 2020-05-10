using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


//kezdes 11:20
//veg 12:50
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
            List<int> x = new List<int>();
            s = Console.ReadLine().Split();
            foreach (string item in s)
            {
                x.Add(int.Parse(item));
            }
            return x;
        }

        static void Main(string[] args)
        {
            int n=0, k=0, m=0, c=0, sum=0;
            List<int> x = setup(ref n, ref k, ref m, ref c);
            int[] vezeto = new int[n];
            for (int i = 0; i < n; i++)
            {
                int veg = 0;
                for (int j = 0; j < c; j++)
                {
                    if (x[j] > veg)
                    {
                        veg = x[j] + m-1;
                        x[j]=0;
                        vezeto[i]++;
                        //Console.Write(vezeto[i] + ":" + j+ " ");
                    }
                }
                sum += vezeto[i];
                //Console.WriteLine("sum: "+sum);
            }
            Console.WriteLine(sum);
            //Console.ReadLine();
        }
    }
}
/*
 * hibás beadás: vég nem kezdet+m hanem kezdet+m-1 -- 1.beadás : 4 pont
 * helyes beadás: -- 3.beadás : 85 pont
 */