int real_main(int argc, int argv);
void init_globals(void);

int heap_size;
int stack_size;
char* heap;

int esp;
int ebp;
int malloc_base;

int ri32(int o){
  return 0;
}

int wi32(int o, int v){
  return 0;
}

int mk_argc_argv(int argc, int argv){
  int argc_argv=v_alloca(8);
  wi32(argc_argv, argc);
  return argc_argv;
}

void init_runtime(void){
  return;
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
