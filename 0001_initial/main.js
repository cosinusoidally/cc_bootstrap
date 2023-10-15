function real_main(argc, argv){
  if (argc != 2) {
    v_fputs(mk_c_string("invalid number of arguments\n"), stderr);
    return 1;
  }
  v_fputs(mk_c_string("# generated from real_main\n"), stdout);
  v_fputs(mk_c_string(":FUNCTION_main\n"), stdout);
  v_fputs(mk_c_string("mov_eax, %"), stdout);
  fputs(rptr(ri32(argv+4)), stdout);
  v_fputs(mk_c_string("\n"), stdout);
  v_fputs(mk_c_string("ret\n"), stdout);
  v_fputs(mk_c_string(":ELF_end\n"), stdout);
  return 0;
}
