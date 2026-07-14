cmake_minimum_required(VERSION 3.31.0)
project(MeshWizardry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# for clangd to recognize libraries
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
	raylib
	GIT_REPOSITORY https://github.com/raysan5/raylib.git
	GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

set(SOURCES
		src/main.cpp
		src/input.cpp
		src/player.cpp
		src/dungeon.cpp
		# src/camera_controller.cpp
)

add_executable(meshWizardry ${SOURCES})

target_link_libraries(meshWizardry PRIVATE raylib)
target_include_directories(meshWizardry PRIVATE include)
