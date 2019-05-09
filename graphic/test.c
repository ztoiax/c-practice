/* 心形函数
 * (x^2 + y^2  - 1) - x^3 * y^3 = 0
*/
#include <stdio.h>
int main() {
  float a,x,y;
    for (y = 1.5f; y > -1.5f; y -= 0.1f) {
        for (x = -1.5f; x < 1.5f; x += 0.05f) {
            a = x * x + y * y - 1;
            putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
        }
        putchar('\n');
    }
    return 0;
}
