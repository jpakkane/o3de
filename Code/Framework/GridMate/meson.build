gridmate_files = []

subdir('GridMate')

gridmate_lib = static_library('GridMate',
    gridmate_files,
    include_directories: 'Platform/Linux',
    dependencies: [azcore_dep])

gridmate_dep = declare_dependency(include_directories: '.')
