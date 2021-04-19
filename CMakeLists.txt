cmake_minimum_required(VERSION 3.19)
project(physicsthingy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(blah
        blah/src/core/app.cpp
        blah/src/core/filesystem.cpp
        blah/src/core/common.cpp
        blah/src/core/time.cpp

        blah/src/graphics/batch.cpp
        blah/src/graphics/blend.cpp
        blah/src/graphics/framebuffer.cpp
        blah/src/graphics/material.cpp
        blah/src/graphics/mesh.cpp
        blah/src/graphics/renderpass.cpp
        blah/src/graphics/shader.cpp
        blah/src/graphics/spritefont.cpp
        blah/src/graphics/subtexture.cpp
        blah/src/graphics/texture.cpp

        blah/src/input/input.cpp
        blah/src/input/binding.cpp
        blah/src/input/binding_registry.cpp

        blah/src/containers/str.cpp

        blah/src/images/aseprite.cpp
        blah/src/images/font.cpp
        blah/src/images/image.cpp
        blah/src/images/packer.cpp

        blah/src/math/calc.cpp
        blah/src/math/circle.cpp
        blah/src/math/color.cpp
        blah/src/math/line.cpp
        blah/src/math/mat3x2.cpp
        blah/src/math/mat4x4.cpp
        blah/src/math/point.cpp
        blah/src/math/quad.cpp
        blah/src/math/rect.cpp
        blah/src/math/rectI.cpp
        blah/src/math/stopwatch.cpp
        blah/src/math/vec2.cpp

        blah/src/streams/bufferstream.cpp
        blah/src/streams/filestream.cpp
        blah/src/streams/memorystream.cpp
        blah/src/streams/stream.cpp

        blah/src/internal/graphics_backend_gl.cpp
        blah/src/internal/graphics_backend_d3d11.cpp
        blah/src/internal/graphics_backend_dummy.cpp
        blah/src/internal/platform_backend_sdl2.cpp
        blah/src/internal/platform_backend_win32.cpp
        )

target_include_directories(blah
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        )

# Platform Variables
set(PLATFORM_SDL2 true CACHE BOOL "Use SDL2 Platform Backend")
set(PLATFORM_WIN32 false CACHE BOOL "Use Win32 Platform Backend")
set(GRAPHICS_OPENGL true CACHE BOOL "Use OpenGL Graphics Backend")
set(GRAPHICS_D3D11 false CACHE BOOL "Use D3D11 Graphics Backend")

set(LIBS "")

# use the OpenGL Graphics Backend
if (GRAPHICS_OPENGL)

    add_compile_definitions(BLAH_GRAPHICS_OPENGL)

    # use the D3D11 Graphics Backend
elseif (GRAPHICS_D3D11)

    add_compile_definitions(BLAH_GRAPHICS_D3D11)
    set(LIBS ${LIBS} d3d11.lib dxguid.lib D3Dcompiler.lib)

endif()

# use the SDL2 Platform Backend
# Link and create SDL2 Definition
if (PLATFORM_SDL2)
    add_compile_definitions(BLAH_PLATFORM_SDL2)

    # Emscripten can import SDL2 directly
    if (EMSCRIPTEN)

        set_target_properties(blah PROPERTIES COMPILE_FLAGS "-s USE_SDL=2")

        # Load SDL2 Normally
    else()

        # Try to find SDL2
        if (DEFINED SDL2_LIBRARIES AND DEFINED SDL2_INCLUDE_DIRS)
            set(SDL2_FOUND true)
        else()
            find_package(SDL2 QUIET)
        endif()

        # If CMake cannot find SDL2 library, then it gets downloaded and compiled that way
        if (NOT ${SDL2_FOUND})

            include(FetchContent)
            FetchContent_Declare(
                    SDL2
                    GIT_REPOSITORY https://github.com/libsdl-org/SDL
                    GIT_TAG release-2.0.14 # grab latest stable release
            )
            FetchContent_GetProperties(SDL2)
            if (NOT sdl2_POPULATED)
                FetchContent_Populate(SDL2)
                add_subdirectory(${sdl2_SOURCE_DIR} ${sdl2_BINARY_DIR})
            endif()

            # statically link SDL2 since we're building it ourselves
            set(LIBS ${LIBS} SDL2main SDL2-static)
            target_include_directories(blah PUBLIC ${sdl2_SOURCE_DIRS}/include)

        else()

            # Add Library and Include Dirs
            set(LIBS ${LIBS} ${SDL2_LIBRARIES})
            target_include_directories(blah PUBLIC ${SDL2_INCLUDE_DIRS})

        endif()

    endif()

    # use the Win32 Platform Backend
elseif (PLATFORM_WIN32)

    add_compile_definitions(BLAH_PLATFORM_WIN32)

endif()

include_directories(${PROJECT_SOURCE_DIR}/blah/include)

add_executable(physicsthingy ${SOURCE_FILES}
        src/main.cpp
        src/actor.h
        src/actor.cpp
        src/solid.h
        src/solid.cpp
        src/controllable.h
        src/controllable.cpp

        blah/src/core/app.cpp
        blah/src/core/filesystem.cpp
        blah/src/core/common.cpp
        blah/src/core/time.cpp

        blah/src/graphics/batch.cpp
        blah/src/graphics/blend.cpp
        blah/src/graphics/framebuffer.cpp
        blah/src/graphics/material.cpp
        blah/src/graphics/mesh.cpp
        blah/src/graphics/renderpass.cpp
        blah/src/graphics/shader.cpp
        blah/src/graphics/spritefont.cpp
        blah/src/graphics/subtexture.cpp
        blah/src/graphics/texture.cpp

        blah/src/input/input.cpp
        blah/src/input/binding.cpp
        blah/src/input/binding_registry.cpp

        blah/src/containers/str.cpp

        blah/src/images/aseprite.cpp
        blah/src/images/font.cpp
        blah/src/images/image.cpp
        blah/src/images/packer.cpp

        blah/src/math/calc.cpp
        blah/src/math/circle.cpp
        blah/src/math/color.cpp
        blah/src/math/line.cpp
        blah/src/math/mat3x2.cpp
        blah/src/math/mat4x4.cpp
        blah/src/math/point.cpp
        blah/src/math/quad.cpp
        blah/src/math/rect.cpp
        blah/src/math/rectI.cpp
        blah/src/math/stopwatch.cpp
        blah/src/math/vec2.cpp

        blah/src/streams/bufferstream.cpp
        blah/src/streams/filestream.cpp
        blah/src/streams/memorystream.cpp
        blah/src/streams/stream.cpp

        blah/src/internal/graphics_backend_gl.cpp
        blah/src/internal/graphics_backend_d3d11.cpp
        blah/src/internal/graphics_backend_dummy.cpp
        blah/src/internal/platform_backend_sdl2.cpp
        blah/src/internal/platform_backend_win32.cpp
        src/floor.cpp src/floor.h src/block.cpp src/block.h src/entity.cpp src/entity.h)

target_link_libraries(physicsthingy PUBLIC ${LIBS} SDL2)