set(CPPS
  winapp.cpp
  wincon.cpp
  WinController.cpp
  windata.cpp
  wintask.cpp
)

add_library(win32 STATIC ${CPPS})
add_dependencies(win32 get_git_hash)
target_include_directories(win32 PRIVATE ${PROJECT_BINARY_DIR}/lib)
