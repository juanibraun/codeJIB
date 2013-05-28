PROJECT(dfs)

SET(CMAKE_C_FLAGS "-std=c99 -g -pedantic-errors -Wall -Wextra -Werror")

ADD_EXECUTABLE(dijkstra_test main)

ADD_LIBRARY(dfs bfs)

ADD_LIBRARY(tree tree)

ADD_LIBRARY(heap heap)

ADD_LIBRARY(dijkstra dijkstra)

TARGET_LINK_LIBRARIES(dijkstra_test dfs tree heap dijkstra)

