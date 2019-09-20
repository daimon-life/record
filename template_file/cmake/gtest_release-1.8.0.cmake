set(PACKAGE gtest)

set(BUILD_GMOCK OFF)
set(BUILD_GTEST ON)

set(BUILD_SHARED_LIBS ON)

set(argument_list
  "-DCMAKE_INSTALL_PREFIX=${TARGET_OUTPUT_DIR}"
)

# print argument_list
foreach(arg ${argument_list})
    message("> ${arg} - ${${arg}}")
endforeach()

# add googletest release-1.8.0 support
ExternalProject_Add(${PACKAGE}
  PREFIX ${PROJECT_BINARY_DIR}/package/${PACKAGE}
  SOURCE_DIR ${PROJECT_SOURCE_DIR}/package/${PACKAGE}
  URL https://github.com/google/googletest/archive/release-1.8.0.zip
  CMAKE_ARGS "${argument_list}"
)

SET_PROPERTY(TARGET ${PACKAGE} PROPERTY FOLDER "package")
