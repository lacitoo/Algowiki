    #include <iostream>
     
    long find_pile(long worm, long piles[], long sz)
    {
      long attempt = sz / 2;
      long delta = sz / 4;
     
      while(true) {
     
        if(worm < piles[attempt]) {
          attempt -= delta;
          delta /= 2;
          if(delta == 0) delta = 1;
          continue;
        }
     
        if(worm >= piles[attempt + 1]) {
          attempt += delta;
          delta /= 2;
          if(delta == 0) delta = 1;
          continue;
        }
        
        return attempt;
      }
    }
     
    int main() 
    {
      long pile_count;
      std::cin >> pile_count;
     
      long worms[100001];
      worms[0] = 0;
      for(long i = 1; i <= pile_count; i++)
      {
        std::cin >> worms[i];
        if(i > 0) {
          worms[i] += worms[i - 1];
        }
      }
     
      long queries;
      std::cin >> queries;
     
      for(long i = 0; i < queries; i++)
      {
        long worm;
        std::cin >> worm;
        worm--;
        std::cout 
          << (find_pile(worm, worms, pile_count) + 1)
          << std::endl;
      }
     
      return 0;
    }
