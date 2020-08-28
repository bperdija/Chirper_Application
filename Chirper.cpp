#include "Chirper.h"

using namespace std;

int main()
{
  Chirp ch;
  ch.setup_account();
  ch.menu();
  cout << "See you next time\n";
  return 0;
}
