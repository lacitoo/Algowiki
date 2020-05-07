using System;
using System.Collections.Generic;

namespace ELTE_CSharp
{
    public class Program
    {
        private class Node
        {
            public char[] String;
            public int Level;


            public Node(char[] s, int level)
            {
                String = s;
                Level = level;
            }


            public Node Invert(int start, int end)
            {
                int length = end + 1 - start;
                char[] c = new char[String.Length];
                for (int i = 0; i < start; ++i)
                    c[i] = String[i];

                for (int i = 0; i < length; ++i)
                {
                    int l = start + i;
                    int r = end - i;
                    c[l] = String[r];
                }

                for (int i = end + 1; i < String.Length; ++i)
                    c[i] = String[i];

                return new Node(c, Level + 1);
            }
        }


        public static long GetHash(char[] s)
        {
            long l = 0;
            for (int i = 0; i < s.Length; ++i)
                l = 10 * l + (s[i] - 'a');
            return l;
        }

        public static void Main(string[] args)
        {
            string canon = "abcdefghij";
            int combscount = 1;
            for (int i = 2; i <= canon.Length; ++i)
                combscount *= i;

            Node root = new Node(canon.ToCharArray(), 0);
            Dictionary<long, int> d = new Dictionary<long, int>(combscount);
            d.Add(GetHash(root.String), root.Level);

            Queue<Node> q = new Queue<Node>(combscount);
            q.Enqueue(root);
            while (q.Count != 0)
            {
                Node n = q.Dequeue();
                for (int i = 0; i < n.String.Length; ++i)
                {
                    for (int j = i + 1; j < n.String.Length; ++j)
                    {
                        Node n_ = n.Invert(i, j);
                        long hash = GetHash(n_.String);
                        if (!d.ContainsKey(hash))
                        {
                            d.Add(hash, n_.Level);
                            q.Enqueue(n_);
                        }
                    }
                }
            }

            string line;
            char[] trans = new char[canon.Length];
            char[] key = new char[canon.Length];
            while ((line = Console.ReadLine()) != "* *")
            {
                string src = line.Substring(0, 10);
                string dst = line.Substring(11);
                for (int i = 0; i < src.Length; ++i)
                    trans[src[i] - 'a'] = canon[i];
                for (int i = 0; i < dst.Length; ++i)
                    key[i] = trans[dst[i] - 'a'];
                Console.WriteLine(d[GetHash(key)]);
            }
        }
    }
}
