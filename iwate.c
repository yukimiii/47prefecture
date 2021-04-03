int main(int ac, char**av){
  int i=0, c, r=srand(atoi(av[ac!=1]))%93+33;
  while(read(1, &c, 1) && c!=r && ++i)                                                                                     
    write(1, "soba ", 5);
  printf("\n[%c] %d\n", r, i);
  return 0;
}
