run:
	cd ./src/map_validation && \
	cc -Iinclude -ldl -lglfw -pthread -lm ../../main.c ../assets_loader/assets_init.c miniprintf.c init.c map_maker.c map_validator.c ../../libft.a ../../libmlx42.a -o "../temp/a.out"

valgrind:
	cd ./src/map_validation && \
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=../temp/valgrind-out.txt \
         --suppressions=../temp/sup.sup \
          -s ../temp/a.out ../temp/map.ber \

play:
	cd ./src/temp && ./a.out map.ber

.PHONY: run valgrind play teste