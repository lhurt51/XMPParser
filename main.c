
#include "XPM.h"

int		exit_hook(t_mlx *obj)
{
	free(obj);
	exit(0);
}

int		my_key_press(int keycode, t_mlx *obj)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == 53)
		exit_hook(obj);
	return (0);
}

int		main(void)
{
	t_mlx *obj;
	int size;

	size = 0;
	obj = malloc(sizeof(t_mlx));
	obj->mlx = mlx_init();
	obj->win = mlx_new_window(obj->mlx, W_WIDTH, W_HEIGHT, "Wolf3D");
	obj->ptr[0] = mlx_xpm_file_to_image(obj->mlx, "Brown0.XPM", &size, &size);
	obj->data = mlx_get_data_addr(obj->ptr[0], &obj->bits, &obj->size_line,
		&obj->endian);
	printf("DATA: %s\n", obj->data);
	printf("BITS: %d\n", obj->bits);
	printf("SIZE: %d\n", obj->size_line);
	printf("ENDIAN: %d\n", obj->endian);
	mlx_put_image_to_window(obj->mlx, obj->win, obj->ptr[0], 0, 0);
	obj->ptr[1] = mlx_xpm_file_to_image(obj->mlx, "BrownBlood1.XPM", &size, &size);
	mlx_put_image_to_window(obj->mlx, obj->win, obj->ptr[1], size, 0);
	obj->ptr[2] = mlx_xpm_file_to_image(obj->mlx, "BrownBlood2.XPM", &size, &size);
	mlx_put_image_to_window(obj->mlx, obj->win, obj->ptr[2], size * 2, 0);
	obj->ptr[3] = mlx_xpm_file_to_image(obj->mlx, "BrownBlood3.XPM", &size, &size);
	mlx_put_image_to_window(obj->mlx, obj->win, obj->ptr[3], size * 3, 0);
	obj->ptr[4] = mlx_xpm_file_to_image(obj->mlx, "BrownBlood4.XPM", &size, &size);
	mlx_put_image_to_window(obj->mlx, obj->win, obj->ptr[4], 0, size);
	obj->ptr[5] = mlx_xpm_file_to_image(obj->mlx, "BrownBlood5.XPM", &size, &size);
	mlx_put_image_to_window(obj->mlx, obj->win, obj->ptr[5], size, size);
	obj->img = mlx_new_image(obj->mlx, W_WIDTH, W_HEIGHT);
	// obj->data = mlx_get_data_addr(obj->img, &obj->bits, &obj->size_line,
	// 	&obj->endian);
	//
	// mlx_put_image_to_window(obj->mlx, obj->win, obj->img, 0, 0);
	// mlx_mouse_hook(obj->win, my_mouse_func, obj);
	// mlx_hook(obj->win, 6, 0, my_mouse_movement, obj);
	mlx_hook(obj->win, 2, 0, my_key_press, obj);
	mlx_hook(obj->win, 17, 0, exit_hook, obj);
	mlx_loop(obj->mlx);
}
