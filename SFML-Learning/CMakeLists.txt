# CMakeList.txt: проект CMake для SFML-Learning; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (SFML-Learning "SFML-Learning.cpp" "SFML-Learning.h")

target_link_libraries(SFML-Learning ${CMAKE_SOURCE_DIR}/library/sfml-audio.lib)
target_link_libraries(SFML-Learning ${CMAKE_SOURCE_DIR}/library/sfml-graphics.lib)
target_link_libraries(SFML-Learning ${CMAKE_SOURCE_DIR}/library/sfml-network.lib)
target_link_libraries(SFML-Learning ${CMAKE_SOURCE_DIR}/library/sfml-system.lib)
target_link_libraries(SFML-Learning ${CMAKE_SOURCE_DIR}/library/sfml-window.lib)

include_directories(${CMAKE_SOURCE_DIR}/include)

set_property(TARGET SFML-Learning PROPERTY CXX_STANDARD 17)
set_property(TARGET SFML-Learning PROPERTY CXX_STANDART_REQUIRED ON)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
