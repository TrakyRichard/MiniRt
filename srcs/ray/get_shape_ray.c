#include "../minirt.h"

t_ray get_sphere_ray(t_sp *sp, t_ray *normal)
{
    normal->orig = sp->center;
    normal->dir = normalized(vec_minus(normal->orig, sp->center));
    return (*normal);
}

t_ray get_plane_ray(t_pl *pl, t_ray *normal)
{
    normal->orig = pl->pos;
    normal->dir = pl->dir;
    return (*normal);
}

t_ray get_square_ray(t_sq *sq, t_ray *normal)
{
    normal->orig = sq->pos;
    normal->dir = normalized(sq->dir);
    return (*normal);
}

t_ray get_cylinder_ray(t_cy *cy, t_ray *normal)
{
    normal->orig = cy->pos;
    normal->dir = normalized(vec_minus(normal->orig, cy->pos));
    return (*normal);
}

t_ray get_disk_ray(t_di *di, t_ray *normal)
{
    normal->orig = di->pos;
    normal->dir = normalized(vec_minus(normal->orig, di->pos));
    return (*normal);
}

t_ray get_triangle_ray(t_tr *tr, t_ray *normal)
{
    normal->orig = tr->pos1;
    normal->dir = normalized(vec_cross(vec_minus(tr->pos2, tr->pos1), vec_minus(tr->pos3, tr->pos1)));
    return (*normal);
}

t_ray get_shape_ray(void *info, t_shtype type)
{
    t_ray normal;

    if (type == SPHERE)
        return (get_sphere_ray((t_sp *)info, &normal));
    else if (type == PLANE)
        return (get_plane_ray((t_pl *)info, &normal));
    else if (type == SQUARE)
        return (get_square_ray((t_sq *)info, &normal));
    else if (type == CYLINDER)
        return (get_cylinder_ray((t_cy *)info, &normal));
    else if (type == DISK)
        return (get_disk_ray((t_di *)info, &normal));
    else if (type == TRIANGLE)
        return (get_triangle_ray((t_tr *)info, &normal));
    else
    {
        normal.orig = set_vec(0, 0, 0);
        normal.dir = set_vec(0, 0, 0);
        ft_error("Error: Invalid shape type\n");
    }
    return (normal);
}