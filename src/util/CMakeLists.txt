include_directories(${CMAKE_SOURCE_DIR}/src/AST/)
include_directories(${CMAKE_BINARY_DIR}/src/AST/)

# FIXME: This isn't build currently.
#
#

add_executable(measure
    measure.cpp
    Functions.cpp
)
target_link_libraries(measure
    stp
)

add_executable(apply
    apply.cpp
)
target_link_libraries(apply
    stp
)

add_executable(time_cbitp
    time_cbitp.cpp
)
target_link_libraries(time_cbitp
    stp
)

add_executable(test_cbitp
    test_cbitp.cpp
)
target_link_libraries(test_cbitp
    stp
)


