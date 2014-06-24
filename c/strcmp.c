int strcmp(const char *s1, const char *s2) {
  // return 1 if s1 is greater, -1 if s2 is greater, 0 if equal
  int val = 0;
  while(!(val = *s1 - *s2) && *s1 && *s2)){
    s1++;
    s2++;
  }
  if(val > 0)
    val = 1;
  else if(val < 0)
    val = -1;

  return val;
}