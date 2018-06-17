#include <stdio.h>

int main()
{
    int jui, tu, ji;
    for (jui = 0; jui <= 11; jui++)
        for (tu = 0; tu <= 100; tu++)
            for (ji = 0; ji <= 100; ji++)
                if (9 * jui + tu + ji == 100 && 2 * jui + 2 * ji + 4 * tu)
                    printf("%d %d %d", jui, ji, tu);
    return 0;
}
