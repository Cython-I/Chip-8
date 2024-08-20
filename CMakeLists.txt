# CMakeList.txt : CMake project for Chip8, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (
	Chip8
	VERSION 0.0.1
	LANGUAGES CXX
)
#target_compile_features(Chip8 PRIVATE cxx_std_17)



include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/extern/SDL2/include ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable (Chip8 source/main.cpp source/Chip8.cpp)
target_link_libraries(Chip8 ${CMAKE_CURRENT_SOURCE_DIR}/extern/SDL2/lib/x64/SDL2.lib ${CMAKE_CURRENT_SOURCE_DIR}/extern/SDL2/lib/x64/SDL2main.lib)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Chip8 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
