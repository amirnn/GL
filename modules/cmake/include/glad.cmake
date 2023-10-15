# GLAD

add_subdirectory(glad/cmake)

if(WIN32)
    glad_add_library(glad_gl_core_46 STATIC LOCATION ${GLAD_OUT_DIR} API gl:core=4.6)
    set(glad_lib glad_gl_core_46)
elseif(APPLE)
    glad_add_library(glad_gl_core_41 STATIC LOCATION ${GLAD_OUT_DIR} API gl:core=4.1)
    set(glad_lib glad_gl_core_41)
endif(WIN32)
