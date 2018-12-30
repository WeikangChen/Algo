#include "inline_b.hpp"

int b()
{
    auto ret1 = static_sum(1, 2);
    printf("b() static: sum=%d addr=%p int=%p\n",
           ret1, &static_sum, &static_sum);

    auto ret2 = constexpr_sum(1, 2);
    printf("b() cntexp: sum=%d addr=%p int=%p\n",
           ret2, &constexpr_sum, &constexpr_int);

    auto ret3 = inline_sum(1, 2);
    printf("b() inline: sum=%d addr=%p int=%p\n",
           ret3, &inline_sum, &inline_int);

    return ret1 + ret2 + ret3;
}
