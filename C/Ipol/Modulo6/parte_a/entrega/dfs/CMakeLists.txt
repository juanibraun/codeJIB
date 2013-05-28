PROJECT(dfs)

SET(CMAKE_C_FLAGS "-std=c99 -g -pedantic-errors -Wall -Wextra -Werror")

ADD_EXECUTABLE(dfs_test main)

ADD_LIBRARY(dfs bfs)

ADD_LIBRARY(tree tree)

TARGET_LINK_LIBRARIES(dfs_test dfs tree)

