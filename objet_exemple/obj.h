#ifndef OBJ
#define OBJ

struct s_obj {
	int attr1;
	char *obj_ptr; // Abstract
}	t_obj;

// Constructeur
struct s_obj	obj_new(void);
struct s_obj	obj_new_attr(int attr1);

// Destructeur
void		obj_delete(t_obj *obj);

// Getters
int		obj_get_attr1(void);

// Setters
void		obj_set_attr1(int attr1);

#endif
