# Modules

if(SHOULD_BUILD_DEPS)
    include(cmake/build/build.cmake)
else()
    include(cmake/include/include.cmake)
endif()


