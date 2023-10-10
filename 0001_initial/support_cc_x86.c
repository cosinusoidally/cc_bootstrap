int puts(char *a) {
  fputs(a,stdout);
  fputs("\n",stdout);
}

void puts_num(int x){
  char *s;
  s=int2str(x,10,0);
  puts(s);
  free(s);
  return;
}

void fputs_num(int n, int stream){
  char *s;
  s=int2str(n,10,0);
  fputs(s,stream);
  free(s);
  return;
}
