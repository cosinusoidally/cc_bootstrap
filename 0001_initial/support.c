int real_main(int argc, int argv);
void init_globals(void);

int main(int argc, int **argv){
  init_globals();
  real_main(0,0);
  return 0;
}
