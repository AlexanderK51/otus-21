cmake_minimum_required(VERSION 3.5)
set(PROJECT_VESRION 0.0.1)
project (ipsort)

add_executable(
    ipsort
    main.cpp
    ipsort.hpp
)
set_target_properties(ipsort PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)