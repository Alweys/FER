#include <stdio.h>

struct person_s {
  int code;
  char name[128];
  float salary;
};

void delCharFromName(struct person_s *s, char c) {
    char tmp[128];
    int i, cnt = 0;
    for(i = 0; s->name[i] != '\0'; i++) {
        if(s->name[i] == c) continue;
        tmp[cnt] = s->name[i];
        cnt++;
    }
    tmp[cnt] = '\0';

    for(i = 0; i <= cnt; i++) s->name[i] = tmp[i];
}