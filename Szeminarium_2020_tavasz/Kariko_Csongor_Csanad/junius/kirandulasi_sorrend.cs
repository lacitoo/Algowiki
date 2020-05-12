using System;
using System.Text;
using System.IO;

class Program{
    public static void Main(){
        int n, m, l;

        string[] str = Console.ReadLine().Split();

        n = int.Parse(str[0]);
        m = int.Parse(str[1]);
        l = int.Parse(str[2]) - 1;

        int[,] tav = new int[n,n];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                tav[i,j] = int.MaxValue/2;

        for(int i = 0; i < m; ++i){
            int a, b, ido;
            str = Console.ReadLine().Split();

            a = int.Parse(str[0]) - 1;


            // A lakhely és az első város megcserélése
            if(a == l)
                a = 0;
            else if(a == 0)
                a = l;
            b = int.Parse(str[1]) - 1;
            if(b == l)
                b = 0;
            else if(b == 0)
                b = l;
            ido = int.Parse(str[2]);

            tav[a,b] = ido;
            tav[b,a] = ido;
        }


        // Floyd-Warshall algoritmus
        for(int d = 0; d < n; ++d)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    tav[i,j] = Math.Min(tav[i,j], tav[i,d]+tav[d,j]);
        

        int[] sor = new int[n-1];
        int[] megoldas = new int[n-1];
        int minTav = int.MaxValue;

        for(int i = 0; i < n-1; ++i)
            sor[i] = i+1;
        

        do{
            int osszTav = tav[sor[n-2],0];
            for(int i = 1; i < n-1; ++i)
                osszTav += tav[sor[i-1],sor[i]];
            osszTav += tav[0, sor[0]];

            if(osszTav < minTav){
                minTav = osszTav;
                sor.CopyTo(megoldas,0);
            }
        } while(KovPermutacio(sor));


        StringBuilder sb = new StringBuilder();
        sb.AppendLine(minTav.ToString());

        for(int i = 0; i < n-1; ++i){
            // Lakhely és első város visszacserélése
            if(megoldas[i] == l)
                megoldas[i] = 0;
            sb.Append(megoldas[i]+1);
            sb.Append(' ');
        }

        sb.Length --;   // utolso space torlese
        
        Console.WriteLine(sb.ToString());

        return;
    }

    static bool KovPermutacio(int[] tomb){
        int ind = tomb.Length-2;
        while(ind >= 0 && tomb[ind] > tomb[ind+1])
            --ind;
        
        if(ind == -1)
            return false;
        
        
        int bal = ind+1, jobb = tomb.Length-1, kozep;
        while(bal < jobb){
            kozep = (bal+jobb+1)/2;
            if(tomb[kozep] < tomb[ind]){
                jobb = kozep-1;
            } else {
                bal = kozep;
            }
        }

        int x = tomb[ind];
        tomb[ind] = tomb[bal];
        tomb[bal] = x;

        bal = ind+1; jobb = tomb.Length-1;
        while(bal < jobb){
            x = tomb[bal];
            tomb[bal] = tomb[jobb];
            tomb[jobb] = x;
            ++bal; --jobb;
        }
        return true;
    }

}