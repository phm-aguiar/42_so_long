run:

	cc -Iinclude -ldl -lglfw -pthread -lm main.c src/assets_loader/assets_init.c src/assets_loader/mlx_loader.c src/map_validation/init.c src/map_validation/map_maker.c src/map_validation/map_validator.c src/map_validation/miniprintf.c src/mlx/mlx_move.c src/mlx/mlx_so_long.c src/mlx/mlx_verify_move.c libft.a libmlx42.a -o "src/temp/a.out"

valgrind:
	cd ./src/map_validation && \
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=../temp/valgrind-out.txt \
         --suppressions=../temp/sup.sup \
          -s ../temp/a.out ../temp/ampulheta.ber \

play:
	cd ./src/temp && ./a.out map.ber

.PHONY: run valgrind play teste