#include "libA/sayHelloWorld.h"
#include "libC/sayHello.h"
#include "libB/sayWorld.h"

void sayHelloWorld() {
  sayHello();
  sayWorld();
}
