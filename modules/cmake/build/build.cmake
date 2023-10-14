# Build


# Eigen should be built seperately from the others
# The reason for it is that they introduce same
# targets such as Uninstall

if(SHOULD_BUILD_EIGEN)
    include(cmake/build/eigen.cmake)
elseif(SHOULD_BUILD_GLFW)
    include(cmake/build/glfw.cmake)
endif()


