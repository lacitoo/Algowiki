using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ELTE_Gyakorlas
{
    public class Program
    {
        private class Pile
        {
            public bool[] SizePresent;
            public LinkedList<int> Sizes;
            public int Height;
            public int HeightLimit;


            public Pile(int limit)
            {
                SizePresent = new bool[limit + 1];
                Sizes = new LinkedList<int>();
                Height = 0;
                HeightLimit = limit;
            }


            public bool Add(int size)
            {
                int height = Height + size;
                if (SizePresent[size] || height > HeightLimit)
                    return false;

                SizePresent[size] = true;
                Sizes.AddLast(size);
                Height = height;
                return true;
            }

            public void Clear()
            {
                foreach (int size in Sizes)
                    SizePresent[size] = false;
                Sizes.Clear();
                Height = 0;
            }
        }


        private static int[] ReadInts(string s, int n)
        {
            int index = 0;
            int i = 0;
            int[] values = new int[n];
            while (true)
            {
                int next = s.IndexOf(' ', index);
                if (next == -1)
                {
                    values[i] = int.Parse(s.Substring(index));
                    break;
                }
                else
                {
                    values[i++] = int.Parse(s.Substring(index, next - index));
                    index = next + 1;
                }
            }
            return values;
        }

        public static void Main()
        {
            int[] options = ReadInts(Console.ReadLine(), 2);
            int[] sizes = ReadInts(Console.ReadLine(), options[0]);// iterates over all 1 000 000 sizes one more time than needed

            int freed = 0;
            Pile p = new Pile(options[1]);
            int last = sizes[0];
            p.Add(last);
            bool increasing = true;
            for (int i = 1; i < sizes.Length; ++i)
            {
                bool inc = last < sizes[i];
                if (sizes[i] != last && (increasing || !inc) && p.Add(sizes[i]))
                {
                    ++freed;
                    increasing = inc;
                }
                else
                {
                    p.Clear();
                    p.Add(sizes[i]);
                    increasing = true;
                }
                last = sizes[i];
            }
            Console.WriteLine(freed);
        }
    }
}
