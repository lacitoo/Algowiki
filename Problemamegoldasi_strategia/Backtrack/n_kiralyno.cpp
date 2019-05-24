#include <iostream>
#include <vector>

using namespace std;

// Hány királynő legyen és hányszor hányas legyen a tábla
const int N = 8;

// Szimpla kiírás
void print(const vector< pair<int,int> >& x)
{
    cout << '[';

    for(auto& p : x)
        cout << "{" << p.first << ", " << p.second << "},";

    cout << "]\n";
}

bool knocksout(pair<int,int> x, pair<int,int> y)
{
    if(
        // Ha egy sorban / oszlopban vannak
        (x.first == y.first) ||
        (x.second == y.second) ||
        // Ha átlósan vannak
        (x.first - y.first) == (x.second - y.second)
    )
    {
        return true;
    }

    return false;
}

// Megnézi az összes lettet királynőt hogy ütik-e egymást
bool safe(vector<pair<int,int>>& board)
{
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board.size(); ++j)
        {
            if(i != j) 
            {
                if(knocksout(board[i], board[j]))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool solve(vector< pair<int,int> > board, int col)
{
    // Ha már meg van az N királynő akkor adjuk adjuk vissza a megoldást
    if(col > N)
    {
        print(board);
        return true;
    }

    // Legeneráljuk az összes lehetséges lépést
    for(int i = 1; i <= N; ++i)
    {
        // Kipróbáljuk hogy jó-e ez a lépés
        board.push_back({col, i});

        if(safe(board))
        {
            // Ha jó a lépés akkor megolpróbáljuk tovább oldani
            if(solve(board, col + 1)) 
                return true;
        }

        // Ha nem sikerült az előző lépéssel emgoldani akkor visszacsináljuk ezt a lépést
        board.pop_back();
    }

    return false;
}

int main()
{
    // Felveszünk egy üres pályát és elkezdjük rá a megoldást
    vector< pair<int,int> > x;
    solve(x, 1);

    return 0;
}