#include <stdio.h>
int main()
{
  int z1;
  int z2;
  int z3;
  int id = 18 % 10 + 1;
  int count_z = 19;
  z1 = id + (count_z%id);
  z2 = ((id*3)%count_z)+1;
  z3 = (((id * 3) + id) % count_z)+1;
  printf("%d, %d, %d\n", z1, z2, z3);
  return 0;
}
