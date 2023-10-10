function real_main(argc, argv){
  if (argc != 2) {
    fputs("invalid number of arguments\n", stderr);
    return 1;
  }
  fputs("# generated from real_main\n", stdout);
  fputs(":FUNCTION_main\n", stdout);
  fputs("mov_eax, %", stdout);
  fputs_num(7, stdout);
  fputs("\n", stdout);
  fputs("ret\n", stdout);
  return 0;
}
