cmake_minimum_required(VERSION 3.10)
project(WindTermLibs LANGUAGES C)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Both artifacts are exported to the bundled runtime library directory.
set(LIB_OUT ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_OUT})

# --- libssh: shared library -> lib/libssh.so.4 ---
# Pass -DOPENSSL_ROOT_DIR=<openssl-1.1.1m prefix> to link the bundled libcrypto.so.1.1;
# the system OpenSSL (3.x) is used otherwise.
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
set(BUILD_STATIC_LIBS OFF CACHE BOOL "" FORCE)
set(WITH_EXAMPLES OFF CACHE BOOL "" FORCE)
set(UNIT_TESTING OFF CACHE BOOL "" FORCE)
add_subdirectory(src/libssh)
set_target_properties(ssh PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIB_OUT})

# --- Onigmo: static library -> lib/libonig.a (autotools, out-of-tree) ---
set(ONIGMO_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/Onigmo)
set(ONIGMO_BUILD ${CMAKE_BINARY_DIR}/onigmo)
file(MAKE_DIRECTORY ${ONIGMO_BUILD})
add_custom_target(onigmo ALL
  COMMAND bash ${ONIGMO_SRC}/configure --enable-static --disable-shared --prefix=${ONIGMO_BUILD}/install
  COMMAND ${CMAKE_MAKE_PROGRAM} SHELL=/bin/bash install
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ONIGMO_BUILD}/install/lib/libonig.a ${LIB_OUT}/libonig.a
  WORKING_DIRECTORY ${ONIGMO_BUILD}
  VERBATIM)

# --- OpenSSL: bundled lib/libssl.so.1.1 + lib/libcrypto.so.1.1 (no source in
#     repo, headers only under inc/openssl; rebuild requires external 1.1.1m source) ---
