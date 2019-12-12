#include <stdio.h>
#include <stdlib.h>

enum state{
  INIT = 0,
  S1,
  S2,
  FINIT
};
enum sig {
  isA = 0,
  elseA,
  _STOP
};

typedef enum sig (* caster) ();
typedef void (* transitionCb) (enum state, enum sig);

struct transition {
  enum state next;
  transitionCb worker;
};

void logger (void * raw) {
  if (raw == NULL) return;
  printf("logger: %c\n", *((char *) raw));
}

void wrkr (enum state s, enum sig sign) {
  printf("%c", (char) (sign + 97));
}

struct transition  map[4][4] = {
  // if
  [INIT][isA] = { S1, NULL },
  [S1][isA] = { S2, NULL },
  [S2][isA] = { FINIT, NULL },
  [FINIT][isA] = { FINIT, NULL },
  // else
  [INIT][elseA] = { INIT, NULL },
  [S1][elseA] = { INIT, NULL },
  [S2][elseA] = { INIT, NULL },
  [FINIT][elseA] = { FINIT, NULL },
};

int FSM (caster cast) {
  enum state curState = INIT;
  enum state nextState;
  enum sig sign;
  transitionCb curWorker;
  struct transition curTransition;
  sign = cast();
  while ((int) sign != _STOP) {
    curTransition = map[curState][sign];
    nextState = curTransition.next;
    curWorker = curTransition.worker;
    if (curWorker != NULL) {
      curWorker(curState, sign);
    }
    curState = nextState;
    sign = cast();
  }
  return (curState == FINIT);
}

void * getter (void) {
  char * c = (char *) malloc (sizeof(char));
  int cond = (scanf("%c", c) != EOF);
  return cond ? (void *) c : NULL;
}

void * mediator (void * raw) {
  char * v = (char *) malloc(sizeof(raw));
  *v = ((int )*(char *) raw) - (int) 'a';
  return (void *) v;
}

enum sig fsmCaster () {
  void * raw = getter();
  if (raw == NULL) return _STOP;
  void * v = mediator(raw);  
  enum sig res = *((int *) v) == 0 ? isA : elseA;
  free(v);
  free(raw);
  return res;
}


int main() {
  enum sig res = FSM(fsmCaster);
  printf("%d\n", res);
  return 0;
}