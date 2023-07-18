#include "../minirt.h"

t_b set_sphere_intx(t_intx *intx, t_sp *sp, double t, t_b res)
{
    intx->t = t;
    intx->i = sp;
    intx->type = SPHERE;
    intx->col = sp->color;
    return res;
}