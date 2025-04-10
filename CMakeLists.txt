# this is the build file for project 
# it is autogenerated by the xmake build system.
# do not edit by hand.

# project
cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0091 NEW)
project(motherload LANGUAGES CXX)

# target
add_executable(motherload "")
set_target_properties(motherload PROPERTIES OUTPUT_NAME "motherload")
set_target_properties(motherload PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/macosx/arm64/release")
target_include_directories(motherload SYSTEM PRIVATE
    /Users/alexandregerault/.xmake/packages/l/libsdl3/3.2.8/c6f9b6ceed0d45619fd1426132e877bf/include
    /Users/alexandregerault/.xmake/packages/o/opengl-headers/2024.01.04/bbc26f0283d24abdb1a6b19e861376f2/include
    /Users/alexandregerault/.xmake/packages/e/egl-headers/2023.12.16/fd46ac16f3e442c4a79a6b8b9c4e66d4/include
    /Users/alexandregerault/.xmake/packages/l/libsdl3_image/3.2.0/108ba902f3914fd1b92023ded3c38834/include
)
target_compile_options(motherload PRIVATE
    $<$<COMPILE_LANGUAGE:C>:-target>
    $<$<COMPILE_LANGUAGE:CXX>:-target>
    $<$<COMPILE_LANGUAGE:C>:arm64-apple-macos15.2>
    $<$<COMPILE_LANGUAGE:CXX>:arm64-apple-macos15.2>
    $<$<COMPILE_LANGUAGE:C>:-isysroot>
    $<$<COMPILE_LANGUAGE:CXX>:-isysroot>
    $<$<COMPILE_LANGUAGE:C>:/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.2.sdk>
    $<$<COMPILE_LANGUAGE:CXX>:/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.2.sdk>
    $<$<COMPILE_LANGUAGE:C>:-DNDEBUG>
    $<$<COMPILE_LANGUAGE:CXX>:-DNDEBUG>
    $<$<COMPILE_LANGUAGE:CUDA>:-DNDEBUG>
)
set_target_properties(motherload PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(motherload PRIVATE cxx_std_23)
if(MSVC)
    target_compile_options(motherload PRIVATE $<$<CONFIG:Release>:-O2>)
else()
    target_compile_options(motherload PRIVATE -O3)
endif()
if(MSVC)
else()
    target_compile_options(motherload PRIVATE -fvisibility=hidden)
endif()
if(MSVC)
    set_property(TARGET motherload PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
target_link_libraries(motherload PRIVATE
    SDL3
    SDL3_image
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework CoreAudio"
    "-framework CoreHaptics"
    "-framework CoreMedia"
    "-framework CoreVideo"
    "-framework Foundation"
    "-framework GameController"
    "-framework Metal"
    "-framework QuartzCore"
    "-framework CoreFoundation"
    "-framework UniformTypeIdentifiers"
    "-framework Cocoa"
    "-framework Carbon"
    "-framework ForceFeedback"
    "-framework IOKit"
    "-framework CoreGraphics"
    "-framework ImageIO"
    "-framework CoreServices"
    iconv
)
target_link_directories(motherload PRIVATE
    /Users/alexandregerault/.xmake/packages/l/libsdl3/3.2.8/c6f9b6ceed0d45619fd1426132e877bf/lib
    /Users/alexandregerault/.xmake/packages/l/libsdl3_image/3.2.0/108ba902f3914fd1b92023ded3c38834/lib
)
target_link_options(motherload PRIVATE
    -target
    arm64-apple-macos15.2
    -isysroot
    /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.2.sdk
    -lz
)
target_sources(motherload PRIVATE
    src/game/components/component.cpp
    src/game/components/animated_sprite_component.cpp
    src/game/components/physic_component.cpp
    src/game/components/static_sprite_component.cpp
    src/game/sdl/sdl_renderer.cpp
    src/game/sdl/sdl_texture_registry.cpp
    src/game/texture_registry.cpp
    src/game/maths/rectangle.cpp
    src/game/maths/vec_2.cpp
    src/game/systems/input_system.cpp
    src/game/systems/render_system.cpp
    src/game/systems/system.cpp
    src/game/systems/movement_system.cpp
    src/game/world.cpp
    src/game/animation_registry.cpp
    src/game/game.cpp
    src/main.cpp
)

# target
add_executable(test "")
set_target_properties(test PROPERTIES OUTPUT_NAME "test")
set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/macosx/arm64/release")
target_include_directories(test SYSTEM PRIVATE
    /Users/alexandregerault/.xmake/packages/l/libsdl3/3.2.8/c6f9b6ceed0d45619fd1426132e877bf/include
    /Users/alexandregerault/.xmake/packages/o/opengl-headers/2024.01.04/bbc26f0283d24abdb1a6b19e861376f2/include
    /Users/alexandregerault/.xmake/packages/e/egl-headers/2023.12.16/fd46ac16f3e442c4a79a6b8b9c4e66d4/include
    /Users/alexandregerault/.xmake/packages/l/libsdl3_image/3.2.0/108ba902f3914fd1b92023ded3c38834/include
    /Users/alexandregerault/.xmake/packages/c/catch2/v3.8.0/42f1b8fc9fd24d5996db4a5fb69893f7/include
)
target_compile_options(test PRIVATE
    $<$<COMPILE_LANGUAGE:C>:-target>
    $<$<COMPILE_LANGUAGE:CXX>:-target>
    $<$<COMPILE_LANGUAGE:C>:arm64-apple-macos15.2>
    $<$<COMPILE_LANGUAGE:CXX>:arm64-apple-macos15.2>
    $<$<COMPILE_LANGUAGE:C>:-isysroot>
    $<$<COMPILE_LANGUAGE:CXX>:-isysroot>
    $<$<COMPILE_LANGUAGE:C>:/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.2.sdk>
    $<$<COMPILE_LANGUAGE:CXX>:/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.2.sdk>
    $<$<COMPILE_LANGUAGE:C>:-DNDEBUG>
    $<$<COMPILE_LANGUAGE:CXX>:-DNDEBUG>
    $<$<COMPILE_LANGUAGE:CUDA>:-DNDEBUG>
)
set_target_properties(test PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(test PRIVATE cxx_std_23)
if(MSVC)
    target_compile_options(test PRIVATE $<$<CONFIG:Release>:-O2>)
else()
    target_compile_options(test PRIVATE -O3)
endif()
if(MSVC)
else()
    target_compile_options(test PRIVATE -fvisibility=hidden)
endif()
if(MSVC)
    set_property(TARGET test PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
target_link_libraries(test PRIVATE
    SDL3
    SDL3_image
    Catch2Main
    Catch2
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework CoreAudio"
    "-framework CoreHaptics"
    "-framework CoreMedia"
    "-framework CoreVideo"
    "-framework Foundation"
    "-framework GameController"
    "-framework Metal"
    "-framework QuartzCore"
    "-framework CoreFoundation"
    "-framework UniformTypeIdentifiers"
    "-framework Cocoa"
    "-framework Carbon"
    "-framework ForceFeedback"
    "-framework IOKit"
    "-framework CoreGraphics"
    "-framework ImageIO"
    "-framework CoreServices"
    iconv
)
target_link_directories(test PRIVATE
    /Users/alexandregerault/.xmake/packages/l/libsdl3/3.2.8/c6f9b6ceed0d45619fd1426132e877bf/lib
    /Users/alexandregerault/.xmake/packages/l/libsdl3_image/3.2.0/108ba902f3914fd1b92023ded3c38834/lib
    /Users/alexandregerault/.xmake/packages/c/catch2/v3.8.0/42f1b8fc9fd24d5996db4a5fb69893f7/lib
)
target_link_options(test PRIVATE
    -target
    arm64-apple-macos15.2
    -isysroot
    /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.2.sdk
    -lz
)
target_sources(test PRIVATE
    src/game/components/component.cpp
    src/game/components/animated_sprite_component.cpp
    src/game/components/physic_component.cpp
    src/game/components/static_sprite_component.cpp
    src/game/sdl/sdl_renderer.cpp
    src/game/sdl/sdl_texture_registry.cpp
    src/game/texture_registry.cpp
    src/game/maths/rectangle.cpp
    src/game/maths/vec_2.cpp
    src/game/systems/input_system.cpp
    src/game/systems/render_system.cpp
    src/game/systems/system.cpp
    src/game/systems/movement_system.cpp
    src/game/world.cpp
    src/game/animation_registry.cpp
    src/game/game.cpp
    tests/world.cpp
)

