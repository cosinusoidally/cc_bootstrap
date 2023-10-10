function real_main(argc, argv){
  if (argc != 2) {
    fputs("invalid number of arguments\n", stderr);
    return 1;
  }
  puts("# Hello from js_to_c generated code");
  return 0;
}
