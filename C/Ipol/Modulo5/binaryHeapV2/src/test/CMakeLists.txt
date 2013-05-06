PROJECT(binaryHeap)

INCLUDE_DIRECTORIES(../heap)

ADD_EXECUTABLE(binaryHeap main)

TARGET_LINK_LIBRARIES(binaryHeap Heap)

ADD_EXECUTABLE(Input input)