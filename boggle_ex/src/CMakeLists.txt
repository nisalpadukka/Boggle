set(BINARY ${CMAKE_PROJECT_NAME}_ex)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY} ${SOURCES})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib)
