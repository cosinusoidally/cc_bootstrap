load("support.js");


function real_main(argc, argv){
  if (argc != 2) {
    fputs("invalid number of arguments\n", stderr);
    return 1;
  }
  fputs("# generated from real_main\n", stdout);
  fputs(":FUNCTION_main\n", stdout);
  fputs("mov_eax, %", stdout);
  fputs(rptr(ri32(argv+4)), stdout);
  fputs("\n", stdout);
  fputs("ret\n", stdout);
  fputs(":ELF_end\n", stdout);
  return 0;
}
