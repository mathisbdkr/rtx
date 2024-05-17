##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compiles program
##

CC		=	g++

SRC		=	main.cpp								\
			src/Camera.cpp							\
			src/Ray.cpp								\
			src/Color.cpp							\
			src/Vector3D.cpp						\
			src/Matrix3D.cpp						\
			src/Interval.cpp						\
			src/IPC.cpp								\
			src/BoundingBox.cpp						\
			src/BoundingVolume.cpp					\
			src/shapes/Scene.cpp					\
			src/shapes/Box.cpp						\
			src/shapes/AShape.cpp					\
			src/shapes/Sphere.cpp					\
			src/shapes/HitRecord.cpp				\
			src/shapes/Cylinder.cpp 				\
			src/shapes/Cone.cpp 					\
			src/shapes/Plane.cpp					\
			src/shapes/Triangle.cpp 				\
			src/shapes/Torus.cpp	 				\
			src/materials/AMaterial.cpp				\
			src/materials/Matte.cpp					\
			src/materials/Dielectric.cpp			\
			src/materials/Metal.cpp					\
			src/light/ALight.cpp					\
			src/light/Light.cpp						\
			src/obj/ObjParser.cpp					\
			src/textures/SolidColor.cpp				\
			src/textures/TextureChecker.cpp			\
			src/parsing/Parsing.cpp					\
			src/factory/Factory.cpp					\
			src/factory/ConeBuilder.cpp				\
			src/factory/CylinderBuilder.cpp			\
			src/factory/SphereBuilder.cpp			\
			src/factory/PlaneBuilder.cpp			\
			src/factory/TriangleBuilder.cpp			\
			src/transformations/ATransformation.cpp	\
			src/transformations/Rotation.cpp		\
			src/transformations/Translation.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	raytracer

CPPFLAGS	=	-std=c++20 -iquote ./interfaces -iquote ./src -iquote ./src/shapes -iquote ./include -iquote ./src/materials -iquote ./src/factory -iquote ./src/parsing -iquote ./src/textures -iquote ./src/transformations -iquote ./src/light -iquote ./src/obj

LIBS	=	-lconfig++

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
