#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#include "MLX42.h"

int main(void)
{
	mlx_t *mlx;

	ft_printf("🎨 Test MLX42 - Version simple\n");
	
	mlx = mlx_init(800, 600, "Ma première fenêtre MLX42", true);
	if (!mlx)
	{
		ft_printf("❌ Erreur MLX42\n");
		return (1);
	}
	
	ft_printf("✅ Fenêtre créée ! Fermez-la pour quitter.\n");
	mlx_loop(mlx);
	mlx_terminate(mlx);
	
	return (0);
}