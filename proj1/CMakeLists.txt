file(GLOB LINK_SRC *.cpp)
add_library(linklist ${LINK_SRC})
target_include_directories(linklist PUBLIC .)