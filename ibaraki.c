int main(){
  char s[] = "Hello, world!\n";

  write(1, s, 14);
  s[0] += 6; s[1] -= 4; s[2] = s[3] += 8;
  write(1, s, 14);
  return (0);
}
