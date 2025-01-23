#include "transform.h"

#include "mat.h"
#include "vec.h"

tfm mul_ts(tfm t, float s) {
    return (tfm){mul_ms(t.rotation, s), mul_vs(t.translation, s)};
}

vec mul_tv(tfm t, vec v) { return add(mul_mv(t.rotation, v), t.translation); }

tfm mul_tt(tfm a, tfm b) {
    return (tfm
    ){mul_mm(a.rotation, b.rotation),
      add(a.translation, mul_mv(a.rotation, b.translation))};
}

tfm rotate(tfm t, mat r) { return (tfm){mul_mm(t.rotation, r), t.translation}; }

tfm translate(tfm t, vec v) { return (tfm){t.rotation, add(t.translation, v)}; }
