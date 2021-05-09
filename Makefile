all:
	gcc -Iinclude/ src/planet.c src/callbacks.c src/camera.c src/init.c src/main.c src/scene.c src/texture.c src/utils.c -lSOIL -lobj -lopengl32 -lglu32 -lglut32 -lm -o planets.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/planet.c src/callbacks.c src/camera.c src/init.c src/main.c src/scene.c src/texture.c src/utils.c -lSOIL -lobj -lGL -lGLU -lglut -lm -o planets -Wall -Wextra -Wpedantic
