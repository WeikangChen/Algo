#include "inline_a.hpp"
#include "inline_b.hpp"

int c()
{
    auto ret1 = static_sum(1, 2);
    printf("a static: sum=%d addr=%p int=%p\n",
           ret1, &static_sum, &static_sum);

    auto ret2 = inline_sum(1, 2);
    printf("a inline: sum=%d addr=%p int=%p\n",
           ret2, &inline_sum, &inline_int);

    return ret1 + ret2;
}
