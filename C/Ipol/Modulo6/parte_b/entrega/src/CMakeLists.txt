PROJECT(dijkstra)

SET(CMAKE_C_FLAGS "-std=c99 -g -pedantic-errors -Wall -Wextra -Werror")

ADD_EXECUTABLE(dijkstra_test main)

ADD_LIBRARY(heap heap)

ADD_LIBRARY(dijkstra dijkstra)

TARGET_LINK_LIBRARIES(dijkstra_test heap dijkstra)

