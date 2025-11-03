#include "obj.h"

// Constructeur
// Cree un nouvel objet
struct s_obj	obj_new(void)
{
	struct s_obj	new_obj;

	new_obj.attr1 = 0;
	new_obj.obj_ptr = NULL;
	return (new_obj);
}

// Cree un nouvel objet avec des valeurs initiales
struct s_obj	obj_new_attr(int attr1)
{
	struct s_obj	new_obj;

	new_obj.attr1 = attr1;
	new_obj.obj_ptr = NULL;
	return (new_obj);
}

// Destructeur
// Supprime un objet
void		obj_delete(t_obj *obj)
{
	if (obj->obj_ptr)
		free(obj->obj_ptr);
}

//// FACADE ATTR1
// Getters
int		obj_get_attr1(struct s_obj obj)
{
	return (obj.attr1);
}

// Setters
void		obj_set_attr1(t_obj *obj, int attr1);
{
	obj->attr1 = attr1;
}

// Public
/*
int		obj_get_imc(t_obj *obj)
{
	return (obj->poids / obj->taille);
}*/
#endif
