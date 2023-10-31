run:
	cd ./bin/map_validation && \
	cc main.c ft_error.c arg_validator.c map_maker.c map_validator.c variable_initializer.c ../temp/libft.a -o "../temp/a.out"

valgrind:
	cd ./bin/map_validation && \
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=../temp/valgrind-out.txt \
          -s ../temp/a.out ../temp/map.ber

.PHONY: run valgrind