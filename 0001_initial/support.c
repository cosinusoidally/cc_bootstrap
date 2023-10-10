int real_main(int argc, int argv);
void init_globals(void);

int heap_size;
int stack_size;
char* heap;

int esp;
int ebp;
int malloc_base;

int v_alloca(int x) {
  esp=esp-x;
  return esp;
}

/* chars are signed but we want unsigned */
int ri8(int o) {
/*  int t=heap[a]; */
  int o1=o>>2;
  int s=o&3;
  int v1;
  int *h=heap;
  v1=h[o1];
  return (v1>>(s*8)) &0xFF;
}

int ri32(int o){
  return ((ri8(o+3)<<24) | (ri8(o+2)<<16) | (ri8(o+1)<<8) |ri8(o));
}

int wi8(int o,int v) {
  heap[o]=v;
  return;
}

int wi32(int o, int v){
  wi8(o,v&0xFF);
  v=v>>8;
  wi8(o+1,v&0xFF);
  v=v>>8;
  wi8(o+2,v&0xFF);
  v=v>>8;
  wi8(o+3,v&0xFF);
}

int mk_argc_argv(int argc, int argv){
  int argc_argv=v_alloca(8);
  wi32(argc_argv, argc);
  return argc_argv;
}

/* initialise the runtime */
int init_runtime(void) {
  heap_size=16*1024*1024;
  stack_size=256*1024;
  heap=malloc(heap_size);
  esp=heap_size-4;
  ebp=esp;
  malloc_base=4;
}

int main(int argc, int argv){
  init_globals();
  init_runtime();
  int args=mk_argc_argv(argc, argv);
  int v_argc=ri32(args);
  int v_argv=ri32(args+4);
  real_main(v_argc,v_argv);
  return 0;
}
